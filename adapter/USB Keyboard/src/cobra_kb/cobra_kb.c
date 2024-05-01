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

uint8_t const conv_table[256][2] =  { HID_KEYCODE_TO_COBRA_KB };
extern int32_t kb_matrix[8];

void cobra_kb_set(uint8_t const keycode) {
    if ( keycode == 0x2A ) // backspace 
    {   
        cobra_kb_set(0); // CS
        sleep_ms(100);
        cobra_kb_set(0x27); // 0 - zero
    }
    uint8_t column = conv_table[keycode][0];
    kb_matrix[column] |= 1 << (conv_table[keycode][1] + KR0_PIN);
}
void cobra_kb_clear(uint8_t const keycode) {
    if ( keycode == 0x2A ) // backspace 
    {   
        cobra_kb_clear(0x27); // 0 - zero
        sleep_ms(100);
        cobra_kb_clear(0); // CS
        
    }             
    uint8_t column = conv_table[keycode][0];
    kb_matrix[column] &= ~(1 << (conv_table[keycode][1] + KR0_PIN));
}
void __no_inline_not_in_flash_func(cobra_kb_type)() {
//void cobra_kb_type() {
    uint8_t key_column = (gpio_get_all() & 0xFF) ;
    switch (key_column)
    {
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
    for(uint8_t i = 0; i < 8; i++) {
        gpio_init(KC08_PIN + i);
        gpio_set_function(KC08_PIN + i, 5) ;
        gpio_set_input_hysteresis_enabled(KC08_PIN + i, false);
        gpio_set_dir(KC08_PIN + i, false); // IN 
    }
    gpio_set_mask(mask_KR_HI); 
}



