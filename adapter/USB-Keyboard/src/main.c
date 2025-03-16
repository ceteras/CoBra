/* 
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ha Thach (tinyusb.org)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pico/multicore.h"
#include "pico/stdlib.h"
#include "bsp/board.h"
#include "tusb.h"
//#include "cdc_app.c"
#include "hardware/clocks.h" 
#include "hardware/uart.h"

#define CLOCK_SPEED 270000

#define UART_ID uart0
#define BAUD_RATE 115200 / (CLOCK_SPEED / 133000)
//#define BAUD_RATE 76608 // 115200 for overclocking to 200000
//#define BAUD_RATE 60800 // 115200 for overclocking to 252000
//#define BAUD_RATE 115200 // 115200 for spped set to 133000

#define UART_TX_PIN 16
#define UART_RX_PIN 17



extern void cdc_app_task(void);
extern void hid_app_task(void);
extern void cobra_kb_gpio_init(void);
extern void __no_inline_not_in_flash_func(cobra_kb_type)();


int32_t kb_matrix[256] = {};
int32_t any_key = 0xFF<<8;  // TS
bool mode_E = false;

// core1_entry is confined to a dedicated bank in RAM, scratch_y
#define __core1_func(x) __scratch_y(__STRING(x)) x
void __core1_func(core1_entry)() {
    // this function performs the actual IO operation of typing on the cobra keyboard
    while (1)
      cobra_kb_type();
}

/*------------- MAIN -------------*/
int main(void)
{
  // UART
  // Set up our UART with the required speed.

  // uart_init(UART_ID, BAUD_RATE);

  // Set the TX and RX pins by using the function select on the GPIO
  // Set datasheet for more information on function select
  //gpio_set_function(UART_TX_PIN, UART_FUNCSEL_NUM(UART_ID, UART_TX_PIN));
  //gpio_set_function(UART_RX_PIN, UART_FUNCSEL_NUM(UART_ID, UART_RX_PIN));

  for(int i=0; i < 256; i++) 
    kb_matrix[i] = 0xFF<<8;

  multicore_launch_core1(core1_entry);

  board_init();
  cobra_kb_gpio_init();

  //set_sys_clock_khz(252000, true);
  set_sys_clock_khz(200000, true);

  // init host stack on configured roothub port
  tuh_init(BOARD_TUH_RHPORT);
  #define debug_printf ;
  #ifdef debug_printf
  //stdio_init_all();
  //printf("Hello World From Pi Pico UART\n");
  #endif
  
  while (1)
  {
    // tinyusb host task
    tuh_task();
    hid_app_task();
  }

  return 0;
}

//--------------------------------------------------------------------+
// TinyUSB Callbacks
//--------------------------------------------------------------------+

void tuh_mount_cb(uint8_t dev_addr)
{
  // application set-up
  #ifdef debug_printf
  printf("A device with address %d is mounted\r\n", dev_addr);
  #endif
}

void tuh_umount_cb(uint8_t dev_addr)
{
  // application tear-down
  #ifdef debug_printf
  printf("A device with address %d is unmounted \r\n", dev_addr);
  #endif
}



