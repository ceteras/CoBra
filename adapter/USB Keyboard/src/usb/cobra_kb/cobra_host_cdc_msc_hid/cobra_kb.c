/* 
 * The MIT License (MIT)
 *
 * Copyright (c) 2024 Vasile Ceteras
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
#include "pico/stdlib.h"
#include "cobra_kb.h"


uint8_t const conv_table[256][3] =  { HID_KEYCODE_TO_COBRA_KB };
uint8_t const cs_keys[7][2] = { CS_KEYS };
uint8_t const ss_keys_shift[][2] = { SS_KEYS_SHIFT };
uint8_t const ss_keys[][2] = { SS_KEYS };
static bool mode_E = false;

extern int32_t kb_matrix[8];
extern int32_t any_key;
extern bool caps_lock;

// void set_capslock_led();
void cobra_kb_set(uint8_t , uint8_t, uint8_t);
void cobra_kb_clear(uint8_t , uint8_t, uint8_t);

void key_delay () {
    sleep_ms(5);
}

bool is_shift_on(uint8_t modifier) {
    return  (modifier & (KEYBOARD_MODIFIER_LEFTSHIFT | KEYBOARD_MODIFIER_RIGHTSHIFT));
}

bool is_cs_on(uint8_t modifier) {
    return  (modifier & (KEYBOARD_MODIFIER_LEFTGUI | KEYBOARD_MODIFIER_RIGHTGUI));
}

bool is_ss_on(uint8_t modifier) {
    return  (modifier & (KEYBOARD_MODIFIER_LEFTALT | KEYBOARD_MODIFIER_RIGHTALT));
}

void cobra_kb_E_mode() {
        cobra_kb_set(0xE1, 0, 0); //CS
        cobra_kb_set(0xE2, 0, 0); //SS for mode E
        mode_E = !mode_E;
        key_delay();key_delay();key_delay();key_delay();key_delay();
        cobra_kb_clear(0xE1, 0, 0); //CS
        cobra_kb_clear(0xE2, 0, 0); //SS for mode E
}

uint8_t find_alternate_keycode (uint8_t keycode, uint8_t keytype) {
    uint8_t altkeycode;
    
    switch (keytype)
    {
        case 1:
          for (int i = 0; i < (sizeof(cs_keys)/(sizeof(cs_keys[0]))); i++)
            if (cs_keys[i][0] == keycode)
                altkeycode = cs_keys[i][1];
        break;
        case 2:
          for (int i = 0; i < (sizeof(ss_keys_shift)/(sizeof(ss_keys_shift[0]))); i++)
            if (ss_keys_shift[i][0] == keycode)
                altkeycode = ss_keys_shift[i][1];
        break;
        case 3:
          for (int i = 0; i < (sizeof(ss_keys)/(sizeof(ss_keys[0]))); i++)
            if (ss_keys[i][0] == keycode)
                altkeycode = ss_keys[i][1];
        break;
        case 4:

        break;
    }

    return altkeycode;
}

void cobra_kb_set(uint8_t  keycode, uint8_t keytype, uint8_t modifier) {
uint8_t altkeycode;
uint8_t row_bit = conv_table[keycode][1] + KR0_PIN - 1; 

    if ( mode_E ) {
        keytype = 0;
        mode_E = false;
        if ( is_ss_on(modifier) ) 
            cobra_kb_set(0xE2, 0, 0); //SS
    }

    switch (keytype)
    {
        case 0:
            uint8_t column = conv_table[keycode][0];
            kb_matrix[column] |= 1 << row_bit;
            any_key |= 1 << row_bit;
        break;
        case 1: // 
            altkeycode = find_alternate_keycode(keycode, 1);
            cobra_kb_set(0xE1, 0, 0); //CS
            key_delay();
            cobra_kb_set(altkeycode, 0, 0);
        break;
        case 2:
            if ( is_shift_on(modifier) || is_cs_on(modifier) )
                cobra_kb_set(0xE1, 0, 0); //CS
            if ( is_ss_on(modifier) ) 
                cobra_kb_set(0xE2, 0, 0); //SS
            key_delay();
            cobra_kb_set(keycode, 0, 0);
        break;
        case 3:
            if ( is_shift_on(modifier) ) {
                //cobra_kb_clear(0xE1, 0, 0); // turn CS off for type 3 (SS symbols)
                altkeycode = find_alternate_keycode(keycode, 2); // ss_keys_shift
            }
            else {
                altkeycode = find_alternate_keycode(keycode, 3); // ss_keys
            }
            cobra_kb_set(0xE2, 0, 0); //SS
            //key_delay();
            cobra_kb_set(altkeycode, 0, 0);
        break;
        case 4:
            if ( modifier & (KEYBOARD_MODIFIER_LEFTSHIFT | KEYBOARD_MODIFIER_RIGHTSHIFT)) {
//                cobra_kb_clear(0xE1, 0, 0); // turn CS off
                altkeycode = find_alternate_keycode(keycode, 2); // ss_keys_shift
//                cobra_kb_set(0xE2, 0, 0); //SS
            }
            else {
                altkeycode = find_alternate_keycode(keycode, 3); // ss_keys
            }
            cobra_kb_set(0xE1, 0, 0); //CS
            cobra_kb_set(0xE2, 0, 0); //SS for mode E
            for(uint8_t i=0; i< 4; i++) key_delay(); 
            cobra_kb_clear(0xE1, 0, 0); //CS off, SS still on
            cobra_kb_set(altkeycode, 0, 0);
        break;
        case 5:
            if ( is_shift_on(modifier) ) {
                //cobra_kb_clear(0xE1, 0, 0); // turn CS off
                altkeycode = find_alternate_keycode(keycode, 2); // ss_keys_shift
                cobra_kb_set(0xE2, 0, 0); //SS
            }
            else if ( is_cs_on(modifier) ) {
                cobra_kb_set(0xE1, 0, 0); //CS
                altkeycode = keycode;
            }
            else if ( is_ss_on(modifier) ) {
                cobra_kb_set(0xE2, 0, 0); //SS
                altkeycode = keycode;
            }
            else {
                altkeycode = find_alternate_keycode(keycode, 3); // ss_keys
            }
            //key_delay();
            cobra_kb_set(altkeycode, 0, 0);
        break;
    }

}
void cobra_kb_clear(uint8_t  keycode, uint8_t keytype, uint8_t modifier) {
uint8_t altkeycode;
uint8_t thekeycode = keycode;
uint8_t kt = keytype; //[keycode][2];
uint8_t row_bit = conv_table[keycode][1] + KR0_PIN - 1; 
    switch (kt)
    {
        case 0:
            uint8_t column = conv_table[keycode][0];
            kb_matrix[column] &= ~(1 << row_bit);
            any_key &= ~(1 << row_bit);
        break;
        case 1:
            altkeycode = find_alternate_keycode(keycode, 1);
            cobra_kb_clear(altkeycode, 0, 0);
            key_delay();
            cobra_kb_clear(0xE1, 0, 0); // CS
        break;
        case 2:
            cobra_kb_clear(thekeycode, 0, 0);
        break;
        case 3:
            if ( modifier & (KEYBOARD_MODIFIER_LEFTSHIFT | KEYBOARD_MODIFIER_RIGHTSHIFT)) {
                altkeycode = find_alternate_keycode(keycode, 2);
            }
            else {
                altkeycode = find_alternate_keycode(keycode, 3);
            }
            cobra_kb_clear(altkeycode, 0, 0);
            //key_delay();
            cobra_kb_clear(0xE2, 0, 0); //SS
        break;
        case 4:

        break;
    }

    // if ( keycode == 0x2A ) // backspace 
    // {   
    //     cobra_kb_clear(0x27, 0); // 0 - zero
    //     sleep_ms(100);
    //     cobra_kb_clear(0, 0); // CS
    // }             

}

void cobra_kb_process_report(hid_keyboard_report_t const *report, hid_keyboard_report_t *prev_report) {

}



void __no_inline_not_in_flash_func(cobra_kb_type)() {
//void cobra_kb_type() {
    uint8_t key_column = (gpio_get_all() & 0xFF) ;
    switch (key_column)
    {
    case 0:
        gpio_clr_mask(any_key); //TS reads all column at once, hence the zero
        break;
    case 127:
        gpio_clr_mask(kb_matrix[7]);
        break;
    case 191:
        gpio_clr_mask(kb_matrix[6]);
        break;
    case 223:
        gpio_clr_mask(kb_matrix[5]);
        break;
    case 239:
        gpio_clr_mask(kb_matrix[4]);
        break;
    case 247:
        gpio_clr_mask(kb_matrix[3]);
        break;
    case 251:
        gpio_clr_mask(kb_matrix[2]);
        break;
    case 253:
        gpio_clr_mask(kb_matrix[1]);
        break;
    case 254:
        gpio_clr_mask(kb_matrix[0]);
        break;
    default:
        gpio_set_mask(mask_KR_HI);

        break;
    }
}

void cobra_kb_gpio_init() {
    gpio_set_dir_all_bits(0); // all pins set as input at first
    gpio_set_mask(mask_KR_HI); 

    for(uint8_t i = 0; i < 6; i++) {
        gpio_init(KR0_PIN + i);
        gpio_set_function(KR0_PIN + i, 5) ;
        gpio_set_dir(KR0_PIN + i, true); // OUT
    }
//    gpio_set_mask(mask_KR_HI); 
    for(uint8_t i = 0; i < 8; i++) {
        gpio_init(KC08_PIN + i);
        gpio_set_function(KC08_PIN + i, 5) ; // set function GPIO
        gpio_set_input_hysteresis_enabled(KC08_PIN + i, false);
        gpio_set_dir(KC08_PIN + i, false); // IN 
    }
}



