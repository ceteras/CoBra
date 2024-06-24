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

extern void cdc_app_task(void);
extern void hid_app_task(void);
extern void cobra_kb_gpio_init(void);
extern void __no_inline_not_in_flash_func(cobra_kb_type)();


int32_t kb_matrix[8] = {0,0,0,0,0,0,0,0};
int32_t any_key = 0;  // TS
bool caps_lock = false;


void __no_inline_not_in_flash_func(core1_entry)() {
    while (1)
        cobra_kb_type();
}

//--------------------------------------------------------------------+
// MACRO CONSTANT TYPEDEF PROTYPES
//--------------------------------------------------------------------+
void led_blinking_task(void);


//extern void cobra_kb_type();
/*------------- MAIN -------------*/
int main(void)
{
  // GPIO SETUP

  //static const uint GPIO_HI = 1;
  //static const uint GPIO_LO = 0;

//  any_key = 63 << 8;

  multicore_launch_core1(core1_entry);

  board_init();
  cobra_kb_gpio_init();

  set_sys_clock_khz(252000, true);
  //set_sys_clock_khz(200000, true);

  //printf("TinyUSB Host CDC MSC HID Example\r\n");

  // init host stack on configured roothub port
  tuh_init(BOARD_TUH_RHPORT);

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
  //printf("A device with address %d is mounted\r\n", dev_addr);
}

void tuh_umount_cb(uint8_t dev_addr)
{
  // application tear-down
  //printf("A device with address %d is unmounted \r\n", dev_addr);
}


//--------------------------------------------------------------------+
// Blinking Task
//--------------------------------------------------------------------+
void led_blinking_task(void)
{
// commented out, as I use RP2040 Zero, different LED

 // const uint32_t interval_ms = 950;
 // static uint32_t start_ms = 0;
 // static bool led_state = false;
 // Blink every interval ms
 // if ( board_millis() - start_ms < interval_ms) return; // not enough time
 // start_ms += (interval_ms );
 // board_led_write(led_state);
 // led_state = 1 - led_state; // toggle
}
