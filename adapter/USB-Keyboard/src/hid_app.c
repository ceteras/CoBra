/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2021, Ha Thach (tinyusb.org)
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

#include "bsp/board.h"
#include "tusb.h"
#include "stdio.h"
#include "pico/stdlib.h"
//#include "cobra_kb.h"
//--------------------------------------------------------------------+
// MACRO TYPEDEF CONSTANT ENUM DECLARATION
//--------------------------------------------------------------------+

// If your host terminal support ansi escape code such as TeraTerm
// it can be use to simulate mouse cursor movement within terminal
#define USE_ANSI_ESCAPE   0

#define MAX_REPORT  4

extern int32_t kb_matrix[256];
extern bool mode_E;
extern uint8_t CS_KEYCODE;
extern uint8_t SS_KEYCODE;

//extern void cobra_kb_make_matrix(uint8_t *);
extern void cobra_kb_set(uint8_t, uint8_t, uint8_t);
extern void cobra_kb_clear(uint8_t, uint8_t, uint8_t);
extern void cobra_kb_process_report(hid_keyboard_report_t const *, hid_keyboard_report_t *);
extern void cobra_kb_E_mode();
extern void cobra_macro();

// Keyboard address and instance (assumes there is only one)
static uint8_t keybd_dev_addr = 0xFF;
static uint8_t keybd_instance;

// Each HID instance can has multiple reports
static struct
{
  uint8_t report_count;
  tuh_hid_report_info_t report_info[MAX_REPORT];
}hid_info[CFG_TUH_HID];

static void process_kbd_report(hid_keyboard_report_t const *report);
static void process_mouse_report(hid_mouse_report_t const * report);
static void process_generic_report(uint8_t dev_addr, uint8_t instance, uint8_t const* report, uint16_t len);

// look up new key in previous keys
static inline bool find_key_in_report(hid_keyboard_report_t report, uint8_t keycode)
{
  for(uint8_t i=0; i<6; i++)
  {
    if (report.keycode[i] == keycode)  return true;
  }

  return false;
}


void hid_app_task(void)
{

}

//--------------------------------------------------------------------+
// TinyUSB Callbacks
//--------------------------------------------------------------------+

// Invoked when device with hid interface is mounted
// Report descriptor is also available for use. tuh_hid_parse_report_descriptor()
// can be used to parse common/simple enough descriptor.
// Note: if report descriptor length > CFG_TUH_ENUMERATION_BUFSIZE, it will be skipped
// therefore report_desc = NULL, desc_len = 0
void tuh_hid_mount_cb(uint8_t dev_addr, uint8_t instance, uint8_t const* desc_report, uint16_t desc_len)
{
  // Interface protocol (hid_interface_protocol_enum_t)
  //const char* protocol_str[] = { "None", "Keyboard", "Mouse" };
  uint8_t const itf_protocol = tuh_hid_interface_protocol(dev_addr, instance);

  //printf("HID Interface Protocol = %s\r\n", protocol_str[itf_protocol]);

  // By default host stack will use activate boot protocol on supported interface.
  // Therefore for this simple example, we only need to parse generic report descriptor (with built-in parser)
  if ( itf_protocol == HID_ITF_PROTOCOL_NONE )
  {
    hid_info[instance].report_count = tuh_hid_parse_report_descriptor(hid_info[instance].report_info, MAX_REPORT, desc_report, desc_len);
    //printf("HID has %u reports \r\n", hid_info[instance].report_count);
  }

  // request to receive report
  // tuh_hid_report_received_cb() will be invoked when report is available
  if ( !tuh_hid_receive_report(dev_addr, instance) )
  {
    //printf("Error: cannot request to receive report\r\n");
  }

}

// Invoked when device with hid interface is un-mounted
void tuh_hid_umount_cb(uint8_t dev_addr, uint8_t instance)
{
  //printf("HID device address = %d, instance = %d is unmounted\r\n", dev_addr, instance);

}

// Invoked when received report from device via interrupt endpoint
void tuh_hid_report_received_cb(uint8_t dev_addr, uint8_t instance, uint8_t const* report, uint16_t len)
{
  uint8_t const itf_protocol = tuh_hid_interface_protocol(dev_addr, instance);

  switch (itf_protocol)
  {
    case HID_ITF_PROTOCOL_KEYBOARD:
      process_kbd_report( (hid_keyboard_report_t const*) report );
    break;

    case HID_ITF_PROTOCOL_MOUSE:
      process_mouse_report( (hid_mouse_report_t const*) report );
    break;

    default:
      // Generic report requires matching ReportID and contents with previous parsed report info
      process_generic_report(dev_addr, instance, report, len);
    break;
  }

  // continue to request to receive report
  if ( !tuh_hid_receive_report(dev_addr, instance) )
  {
    //printf("Error: cannot request to receive report\r\n");
  }
}

//--------------------------------------------------------------------+
// Keyboard
//--------------------------------------------------------------------+



static void process_kbd_report(hid_keyboard_report_t const *report)
{
  static hid_keyboard_report_t previous_report = { 0, 0, {0,0,0,0,0,0} }; // previous report to check key released

  static uint8_t key_count = 0;
  uint8_t key_type;
  uint8_t key_code = 0;
  //int32_t nokeys[256] = {};

  //bool ss = false;
  //bool cs = false;

  extern uint8_t const conv_table[256][3];
  
//  for(int i=0; i < 256; i++) 
//    nokeys[i] = 0;

  if (
    !( report->modifier & (KEYBOARD_MODIFIER_LEFTALT)) 
    &&   ( previous_report.modifier & (KEYBOARD_MODIFIER_LEFTALT)) 
  ) {
      cobra_kb_clear(CS_KEYCODE, 0, 0); // CS key
      //gpio_clr_mask(1 << 25);
      //cs = false;
  }


  if (
    ( report->modifier & (KEYBOARD_MODIFIER_LEFTALT))
     &&     !( previous_report.modifier & (KEYBOARD_MODIFIER_LEFTALT))
  )
    {
      cobra_kb_set(CS_KEYCODE, 0, 0); // CS key
      //gpio_set_mask(1 << 25);
      //cs = true;
    }

  if (
    !( report->modifier & (KEYBOARD_MODIFIER_RIGHTALT))
    && ( previous_report.modifier & (KEYBOARD_MODIFIER_RIGHTALT))
  )
    {
      cobra_kb_clear(SS_KEYCODE, 0, 0); // SS KEY
      //gpio_clr_mask(1 << 25);
      //ss = false;
    }


  if (
    ( report->modifier & (KEYBOARD_MODIFIER_RIGHTALT))
    && !( previous_report.modifier & (KEYBOARD_MODIFIER_RIGHTALT))
  )
    {
      cobra_kb_set(SS_KEYCODE, 0, 0); // SS KEY
      //gpio_set_mask(1 << 25);
      //ss = true;
    }


    if (
      ( report->modifier & (KEYBOARD_MODIFIER_RIGHTCTRL | KEYBOARD_MODIFIER_LEFTCTRL))
      && !( previous_report.modifier & (KEYBOARD_MODIFIER_RIGHTCTRL | KEYBOARD_MODIFIER_LEFTCTRL))
    )
      {
        cobra_kb_set(0xE0, 0, 0); // L CTRL KEY
        //gpio_set_mask(1 << 25);
        //ss = true;
      }

    if (
      !( report->modifier & (KEYBOARD_MODIFIER_RIGHTCTRL | KEYBOARD_MODIFIER_LEFTCTRL))
      && ( previous_report.modifier & (KEYBOARD_MODIFIER_RIGHTCTRL | KEYBOARD_MODIFIER_LEFTCTRL))
    )
      {
        cobra_kb_clear(0xE0, 0, 0); // L CTRL KEY
        //gpio_clr_mask(1 << 25);
        //ss = false;
      }

/*   if ( cs && ss) {
    gpio_set_mask(1 << 25);
  } else {
    gpio_clr_mask(1 << 25);
  } */

  /* if (
     ( report->modifier & (KEYBOARD_MODIFIER_RIGHTALT) ) 
     &&
     ( report->modifier & (KEYBOARD_MODIFIER_LEFTALT) )
     && !(
     ( previous_report.modifier & (KEYBOARD_MODIFIER_LEFTGUI | KEYBOARD_MODIFIER_RIGHTGUI) ) 
     &&
     ( previous_report.modifier & (KEYBOARD_MODIFIER_LEFTALT | KEYBOARD_MODIFIER_RIGHTALT) )   
     )   
  ) { 
    //mode_E = !mode_E;
    //cobra_kb_E_mode();
    //printf("should toggle mode E\n");
    for(uint8_t x=0; x<8; x++)
      {
        //uint8_t a =  
        printf("kb_matrix[%d]=%d \n",x, (kb_matrix[x])>>8);
      }
    sleep_ms(1000);
    for(uint8_t x=0; x<8; x++)
      {
        //uint8_t a =  
        printf("kb_matrix[%d]=%d \n",x, (kb_matrix[x])>>8);
      } 
    //gpio_xor_mask(1 << 25);
    //gpio_set_mask(1 << 25);
  } else {
    //gpio_clr_mask(1 << 25);
  }
 */

  for( uint8_t i = 0; i < 6; i++ )
  {
    key_code = report->keycode[i];
    if ( key_code ) {
      if ( !find_key_in_report(previous_report, key_code) ) 
      {
        key_count++;
        key_type = conv_table[key_code][2];
        cobra_kb_set(key_code, key_type, report->modifier); // new key press
      }
    }
  }
 

  for( uint8_t j = 0; j < 6; j++ )
  {
    key_code = previous_report.keycode[j];
    if ( key_code )
    {
      if ( !find_key_in_report(*report, key_code) ) 
      {
        key_count--;
        key_type = conv_table[key_code][2];
        cobra_kb_clear(key_code, key_type, previous_report.modifier); // key depressed
        //uart_puts(uart0, " Hello, UART!\n");
      }
    }
  }

/*   if (
      ( key_count == 0) // clear matrix if no keys are pressed
  ) {
    //memcpy(kb_matrix, nokeys, sizeof nokeys);
    printf("- no keys pressed.\n");
  }  */

  if (
      find_key_in_report(*report, 0x4d) 
      &&
      !find_key_in_report(previous_report, 0x4d) 
    ) 
    cobra_kb_E_mode();

  if (
      find_key_in_report(*report, 0x3E) 
      &&
      !find_key_in_report(previous_report, 0x3E) 
    ) 
    cobra_macro(0x3E);
  if (
      find_key_in_report(*report, 0x3F) 
      &&
      !find_key_in_report(previous_report, 0x3F) 
    ) 
    cobra_macro(0x3F);
  previous_report = *report;
}

//--------------------------------------------------------------------+
// Mouse
//--------------------------------------------------------------------+

void cursor_movement(int8_t x, int8_t y, int8_t wheel)
{
#if USE_ANSI_ESCAPE
  // Move X using ansi escape
  if ( x < 0)
  {
    //printf(ANSI_CURSOR_BACKWARD(%d), (-x)); // move left
  }else if ( x > 0)
  {
    //printf(ANSI_CURSOR_FORWARD(%d), x); // move right
  }

  // Move Y using ansi escape
  if ( y < 0)
  {
    //printf(ANSI_CURSOR_UP(%d), (-y)); // move up
  }else if ( y > 0)
  {
    //printf(ANSI_CURSOR_DOWN(%d), y); // move down
  }

  // Scroll using ansi escape
  if (wheel < 0)
  {
    //printf(ANSI_SCROLL_UP(%d), (-wheel)); // scroll up
  }else if (wheel > 0)
  {
    //printf(ANSI_SCROLL_DOWN(%d), wheel); // scroll down
  }

  //printf("\r\n");
#else
  //printf("(%d %d %d)\r\n", x, y, wheel);
#endif
}

static void process_mouse_report(hid_mouse_report_t const * report)
{
  static hid_mouse_report_t prev_report = { 0 };

  //------------- button state  -------------//
  uint8_t button_changed_mask = report->buttons ^ prev_report.buttons;
  if ( button_changed_mask & report->buttons)
  {
    //printf(" %c%c%c ",
    //   report->buttons & MOUSE_BUTTON_LEFT   ? 'L' : '-',
    //   report->buttons & MOUSE_BUTTON_MIDDLE ? 'M' : '-',
    //   report->buttons & MOUSE_BUTTON_RIGHT  ? 'R' : '-');
  }

  //------------- cursor movement -------------//
  cursor_movement(report->x, report->y, report->wheel);
}

//--------------------------------------------------------------------+
// Generic Report
//--------------------------------------------------------------------+
static void process_generic_report(uint8_t dev_addr, uint8_t instance, uint8_t const* report, uint16_t len)
{
  (void) dev_addr;

  uint8_t const rpt_count = hid_info[instance].report_count;
  tuh_hid_report_info_t* rpt_info_arr = hid_info[instance].report_info;
  tuh_hid_report_info_t* rpt_info = NULL;

  if ( rpt_count == 1 && rpt_info_arr[0].report_id == 0)
  {
    // Simple report without report ID as 1st byte
    rpt_info = &rpt_info_arr[0];
  }else
  {
    // Composite report, 1st byte is report ID, data starts from 2nd byte
    uint8_t const rpt_id = report[0];

    // Find report id in the array
    for(uint8_t i=0; i<rpt_count; i++)
    {
      if (rpt_id == rpt_info_arr[i].report_id )
      {
        rpt_info = &rpt_info_arr[i];
        break;
      }
    }

    report++;
    len--;
  }

  if (!rpt_info)
  {
    //printf("Couldn't find the report info for this report !\r\n");
    return;
  }

  // For complete list of Usage Page & Usage checkout src/class/hid/hid.h. For examples:
  // - Keyboard                     : Desktop, Keyboard
  // - Mouse                        : Desktop, Mouse
  // - Gamepad                      : Desktop, Gamepad
  // - Consumer Control (Media Key) : Consumer, Consumer Control
  // - System Control (Power key)   : Desktop, System Control
  // - Generic (vendor)             : 0xFFxx, xx
  if ( rpt_info->usage_page == HID_USAGE_PAGE_DESKTOP )
  {
    switch (rpt_info->usage)
    {
      case HID_USAGE_DESKTOP_KEYBOARD:
      {
        TU_LOG1("HID receive keyboard report\r\n");
        // Assume keyboard follow boot report layout
        process_kbd_report( (hid_keyboard_report_t const*) report );
        keybd_dev_addr = dev_addr;
        keybd_instance = instance;
      }
      break;

      case HID_USAGE_DESKTOP_MOUSE:
        TU_LOG1("HID receive mouse report\r\n");
        // Assume mouse follow boot report layout
        process_mouse_report( (hid_mouse_report_t const*) report );
      break;

      default: break;
    }
  }
}
