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

#define debug_printf_not ;

uint8_t const conv_table[256][3] =  { HID_KEYCODE_TO_COBRA_KB };
uint8_t const cs_keys[7][2] = { CS_KEYS };
uint8_t const ss_keys_shift[][2] = { SS_KEYS_SHIFT };
uint8_t const ss_keys[][2] = { SS_KEYS };
uint8_t const macro_key_codes[][3] =  { FN_MACRO };

extern bool mode_E;

extern int32_t kb_matrix[256];
extern int32_t any_key;
static uint8_t lvl = 0;
//extern bool caps_lock;


void cobra_kb_set(uint8_t , uint8_t, uint8_t);
void cobra_kb_clear(uint8_t , uint8_t, uint8_t);

void key_delay (uint8_t d) {
    sleep_ms(5*d);
}

bool is_shift_on(uint8_t modifier) {
    return  (modifier & (KEYBOARD_MODIFIER_LEFTSHIFT | KEYBOARD_MODIFIER_RIGHTSHIFT));
}

bool is_cs_on(uint8_t modifier) {
    return  (modifier & (KEYBOARD_MODIFIER_LEFTALT));
}

bool is_ss_on(uint8_t modifier) {
    return  (modifier & (KEYBOARD_MODIFIER_RIGHTALT));
}

uint8_t set_kb_matrix (uint8_t key_column, int32_t set_mask){
    uint8_t index_cmp;
    for(uint8_t i = 0; i < 256; i++) {
        // check i index for <key_column> bit = 0
        index_cmp = i & (1 << key_column);
        if (index_cmp == 0) 
            kb_matrix[i] |= set_mask;
    }
}

uint8_t clear_kb_matrix (uint8_t key_column, int32_t clear_mask){
    uint8_t index_cmp;
    for(uint8_t i = 0; i < 256; i++) {
        // check i index for <key_column> bit = 0
        index_cmp = i & (1 << key_column);
        if (index_cmp == 0) 
            kb_matrix[i] &= clear_mask;
    }
}

void fill_kb_matrix() {
    uint8_t index_cmp;
    uint8_t fill_source_index;
    uint8_t fill_value;
    for (uint8_t i = 0; i < 255; i++) {
        fill_value = 0xFF;
        for (uint8_t j = 0; j < 8; j++){
            index_cmp = i & (1 << j);
            if (index_cmp == 0) {
                fill_source_index = 0xFF & ~(1 << j);
                fill_value &= (0xFF & (kb_matrix[fill_source_index]>>8));
            }
        }
        kb_matrix[i] = fill_value<<8;
    //printf("i=%d, kb120=%d \n", i, 0xFF & kb_matrix[120]>>8);
    }

}

void cobra_kb_E_mode() {
        cobra_kb_set(CS_KEYCODE, 0, 0); //CS
        cobra_kb_set(SS_KEYCODE, 0, 0); //SS for mode E
        mode_E = !mode_E;
        key_delay(5);
        cobra_kb_clear(CS_KEYCODE, 0, 0); //CS
        cobra_kb_clear(SS_KEYCODE, 0, 0); //SS for mode E
}

void cobra_macro(uint8_t key_code) {
    for(uint8_t i = 0; i < (sizeof(macro_key_codes)/sizeof(macro_key_codes[0])); i++) {
        uint8_t macro_key = macro_key_codes[i][0];
        uint8_t type_key = macro_key_codes[i][1];
        uint8_t macro_set = macro_key_codes[i][2];
        if (macro_key == key_code) {
            #ifdef debug_printf
            printf("macrokey: %02x", macro_key);
            #endif
            if (type_key !=0) {
                if (macro_set == 1)
                    cobra_kb_set(type_key, 0, 0);
                else
                    cobra_kb_clear(type_key, 0, 0);
            }
            key_delay(15);
        }
    }
        
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
    }

    return altkeycode;
}

// a key is pressed. a bit is set to 1. it translates to a bit on 8255 port set to 0
void cobra_kb_set(uint8_t  keycode, uint8_t keytype, uint8_t modifier) {
uint8_t altkeycode;
uint8_t row_bit = conv_table[keycode][1] + KR0_PIN - 1; 
    // if a key is pressed while in E mode, E mode must turn off
    if ( mode_E ) {
        keytype = 0;
        mode_E = false;
        if ( is_ss_on(modifier) ) {
            cobra_kb_set(SS_KEYCODE, 0, 0); //SS
            lvl--;
        }
    }
    #ifdef debug_printf
    printf("Pressed: %02x\n", keycode);
    #endif
    switch (keytype)
    {
        case 0:
            uint8_t column = conv_table[keycode][0];
            uint8_t kb_idx = 255 - (1 << column);
            kb_matrix[kb_idx] &= ~(1 << row_bit);
            //set_kb_matrix(column, 1 << row_bit);
            any_key &= ~(1 << row_bit);
            kb_matrix[0] = any_key;
            //kb_matrix[120] = kb_matrix[127] & kb_matrix[253] & kb_matrix[254]; // cobra menu
            fill_kb_matrix();
            #ifdef debug_printf
            printf("set keycode: %02x, column:%d, row:%d\n",keycode, column, row_bit-8);
            for(uint8_t x=0; x<8; x++) 
            printf("  %03d",x);
            printf("\n");
            for(uint8_t x=0; x<8; x++) 
            printf("  %03d",kb_matrix[x]>>8);
            printf("\n");
            #endif
            lvl++;
        break;
        case 1: // 
            altkeycode = find_alternate_keycode(keycode, 1);
            //printf("Alt_key_code: %02x - %02x\n", keycode, altkeycode);
            cobra_kb_set(CS_KEYCODE, 0, 0); //CS
            key_delay(1);
            cobra_kb_set(altkeycode, 0, 0);
        break;
        case 2:
            if ( is_shift_on(modifier) || is_cs_on(modifier) )
                cobra_kb_set(CS_KEYCODE, 0, 0); //CS
            if ( is_ss_on(modifier) ) 
                cobra_kb_set(SS_KEYCODE, 0, 0); //SS
            key_delay(2);
            cobra_kb_set(keycode, 0, 0);
        break;
        case 3:
            if ( is_shift_on(modifier) ) {
                altkeycode = find_alternate_keycode(keycode, 2); // ss_keys_shift
            }
            else {
                altkeycode = find_alternate_keycode(keycode, 3); // ss_keys
            }
            cobra_kb_set(SS_KEYCODE, 0, 0); //SS
            cobra_kb_set(altkeycode, 0, 0);
        break;
        case 4:
            if ( is_shift_on(modifier) ) {
                altkeycode = find_alternate_keycode(keycode, 2); // ss_keys_shift
            }
            else {
                altkeycode = find_alternate_keycode(keycode, 3); // ss_keys
            }
            cobra_kb_set(CS_KEYCODE, 0, 0); //CS
            cobra_kb_set(SS_KEYCODE, 0, 0); //SS for mode E
            for(uint8_t i=0; i< 4; i++) key_delay(1); 
            cobra_kb_clear(CS_KEYCODE, 0, 0); //CS off, SS still on
            cobra_kb_set(altkeycode, 0, 0);
        break;
        case 5:
            if ( is_shift_on(modifier) ) {
                altkeycode = find_alternate_keycode(keycode, 2); // ss_keys_shift
                cobra_kb_set(SS_KEYCODE, 0, 0); //SS
            }
            else if ( is_cs_on(modifier) ) {
                cobra_kb_set(CS_KEYCODE, 0, 0); //CS
                altkeycode = keycode;
            }
            else if ( is_ss_on(modifier) ) {
                cobra_kb_set(SS_KEYCODE, 0, 0); //SS
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
    #ifdef debug_printf
    printf("Depressed: %02x\n", keycode);
    #endif
    switch (kt)
    {
        case 0: // direct translation of keycode to a bit cleared in the matrix
            uint8_t column = conv_table[keycode][0];
            uint8_t kb_idx = 255 - (1 << column);
            kb_matrix[kb_idx] |= (1 << row_bit);
            //clear_kb_matrix(column, ~(1 << row_bit));
            any_key |= 1 << row_bit;
            kb_matrix[0] = any_key;
            fill_kb_matrix();
            #ifdef debug_printf
            printf("clear keycode: %02x, column:%d, row:%d\n",keycode, column, row_bit-8);
            for(uint8_t x=0; x<8; x++) 
            printf("  %03d",x);
            printf("\n");
            for(uint8_t x=0; x<8; x++) 
            printf("  %03d",kb_matrix[x]>>8);
            printf("\n");
            #endif
        break;
        case 1: // alternate keycode for a code that needs CS 
                // eg. DELETE tranlates to alt code for 0 plus CS 
            altkeycode = find_alternate_keycode(keycode, 1);
            cobra_kb_clear(altkeycode, 0, 0);
            key_delay(1);
            cobra_kb_clear(CS_KEYCODE, 0, 0); // CS
        break;
        case 2: // 
            cobra_kb_clear(thekeycode, 0, 0);
        break;
        case 3:
            if ( is_shift_on(modifier) ) {
                altkeycode = find_alternate_keycode(keycode, 2);
            }
            else {
                altkeycode = find_alternate_keycode(keycode, 3);
            }
            cobra_kb_clear(altkeycode, 0, 0);
            //key_delay();
            cobra_kb_clear(SS_KEYCODE, 0, 0); //SS
        break;
        case 4:
            if ( is_shift_on(modifier) ) {
                altkeycode = find_alternate_keycode(keycode, 2); // ss_keys_shift
            }
            else {
                altkeycode = find_alternate_keycode(keycode, 3); // ss_keys
            }
            cobra_kb_clear(altkeycode, 0, 0);
            cobra_kb_clear(SS_KEYCODE, 0, 0); //SS off
        break;
        case 5:
            if ( is_shift_on(modifier) ) {
                altkeycode = find_alternate_keycode(keycode, 2); // ss_keys_shift
            }
            else if ( is_cs_on(modifier) ) {
                altkeycode = keycode;
            }
            else if ( is_ss_on(modifier) ) {
                altkeycode = keycode;
            }
            else {
                altkeycode = find_alternate_keycode(keycode, 3); // ss_keys
            }
            //key_delay();
            cobra_kb_clear(altkeycode, 0, 0);
        break;
    }     

}

void cobra_kb_process_report(hid_keyboard_report_t const *report, hid_keyboard_report_t *prev_report) {

}



void __no_inline_not_in_flash_func(cobra_kb_type)() {
   uint8_t key_column = (gpio_get_all() & 0xFF) ;
   //gpio_clr_mask(kb_matrix[key_column]);
   //gpio_set_mask(~kb_matrix[key_column]);
   gpio_put_masked(mask_KR_HI, kb_matrix[key_column]);
 /*     switch (key_column)
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
  */
}

void cobra_kb_gpio_init() {
    gpio_set_dir_all_bits(0); // all pins set as input at first
    gpio_set_mask(mask_KR_HI); 




    // LED GPIO25
    gpio_init(25);
    gpio_set_function(25, 5) ;
    gpio_set_dir(25, true); // OUT

    for(uint8_t i = 0; i < 6; i++) {
        gpio_init(KR0_PIN + i);
        gpio_set_function(KR0_PIN + i, 5) ;
        gpio_set_dir(KR0_PIN + i, true); // OUT
    }
    gpio_set_mask(mask_KR_HI); 
    for(uint8_t i = 0; i < 8; i++) {
        gpio_init(KC08_PIN + i);
        gpio_set_function(KC08_PIN + i, 5) ; // set function GPIO
        gpio_set_input_hysteresis_enabled(KC08_PIN + i, false);
        gpio_set_dir(KC08_PIN + i, false); // IN 
    }
}


