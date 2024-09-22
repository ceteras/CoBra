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


#ifdef __cplusplus
 extern "C" {
#endif

/*
A0 = bA14 xor (bA13 and L06 and bA15)
A1 = bA15 xor L06
A2 = nPO
A3 = not ((not bnMREQ) and bnRFSH)
O0 = A0 or A1 or A2 or A3
O4 = A0 or A1 or (not A2) or A3
a = not (O0 and O4)
b = not (bnRD and (not L06))
nCS0 = not (a and b)





NCS0=¬(
	    ¬((bA14 ⊕ (bA13∧L06∧bA15)) ∨ (bA15⊕L06) ∨ nPO ∨ (bnMREQ ∨ ¬bnRFSH) ∧ (bA14⊕(bA13∧L06∧bA15))
        ∨
        (bA15⊕L06)
        ∨
        ¬nPO
        ∨
        (bnMREQ∨¬bnRFSH))
        ∧(¬bnRD∨L06)
      )
nCS0=¬(
        ¬(
          (bA14⊕(bA13∧L06∧bA15))
          ∨
          (bA15⊕L06)
          ∨
          nPO
          ∨
          (bnMREQ∨¬bnRFSH)
          ∧
          (bA14⊕(bA13∧L06∧bA15))
          ∨
          (bA15⊕L06)
          ∨
          ¬nPO
          ∨
          (bnMREQ∨¬bnRFSH)
        )
        ∧
        (¬bnRD∨L06)
      )
*/

// Define pins
  static const uint KC08_PIN  = 0;
  static const uint KC09_PIN  = 1;
  static const uint KC10_PIN  = 2;
  static const uint KC11_PIN  = 3;
  static const uint KC12_PIN  = 4;
  static const uint KC13_PIN  = 5;
  static const uint KC14_PIN  = 6;
  static const uint KC15_PIN  = 7;

  static const uint KR0_PIN = 8;
  static const uint KR1_PIN = 9;
  static const uint KR2_PIN = 10;
  static const uint KR3_PIN = 11;
  static const uint KR4_PIN = 12;
  static const uint KR5_PIN = 13;

// this 32bit value means all 6 pins set to "1", used with gpio_set_mask 
  int32_t mask_KR_HI = 63 << KR0_PIN;

/*--------------------------------------------------------------------
 * KEYCODE to CoBra KB Conversion
 *  Expand to array of [256][3]
 *
 *  Used to convert from keycode (key) to Cobra row/column.
 * 
 *  CoBra keyboard is an 8 x 6 array of switches.
 *  8 columns are connected through diodes to Z80 CPU address bus A[8..15]
 *  One of them is active low at a time. 
 *  We read the column port of the keyboard on pins KC[08..15]_PIN (GPIO pins 0..7 here).
 *  When the address bus corresponds to a column on the keyboard, we present the
 *  data on KR[0..5]_PIN's to 8255, same way a keyboard would do: a zero when a key is pressed.
 * 
 *  This data is stored in variable int32_t kb_matrix[8] = {0,0,0,0,0,0,0,0} array (main.c).
 *  8 sets of 32 bit GPIO masks, one for each column.
 *  Here a bit of value one means a key is pressed.
 * 
 *  Because Turbo Spectrum has a routine checking for any key pressed, by clearing A[8..15] (a zero),
 *  we also keep a 32 bit mask where a bit is set whenever any key is pressed on a given column.
 *  This is int32_t any_key = 0 in main.c .
 * 
 *  The code runs in two main loops:
 *  1. a loop reads the usb keyboard and determines which key would need to be pressed on a CoBra keyboard.
 *     so this part writes data to kb_matrix[8] and any_key
 *     
 *  2. a loop that reads the columns from the keyboard port in the CoBra (A[8..15] through diodes)
 *     and writes corresponding data from kb_matrix[8] array (also any_key varaiable) to 8255 input port, bits K[0..5]
 * 
 *  Mapping the typical usb keyboard to CoBra is expected to be more complex.
 *  SHIFT is mapped to Caps Shift.
 *  ALT is mapped to Symbol Shift.
 * 
 *  // declare array
 *  uint8_t const conv_table[256][3] =  { HID_KEYCODE_TO_COBRA_KB };
 *  // KC = conv_table[256][0] is the column on CoBra KB
 *  // there are 8 valid values for KC, corresponding to each column being active
 *  // for this reason we declare an 8 value array
 *  // int32_t kb_matrix[8] = {0,0,0,0,0,0,0,0};
 *  // we store the gpio values to be sent to 8255 in it
 *  // a zero bit value in kb_matrix means the key is not pressed
 *  
 *  
 *  // 
 * 
 *  //  associated with the usb keycode (0..7)(+8)
 *  if (conv_table[key][1] > 0) {
 *      uint8_t KC = conv_table[key][0];
 *      uint8_t KR = conv_table[chr][1] - 1; // row on CoBra KB associated with the usb keycode (0..5)
 *      uint8_t key_type = conv_table[chr][2]
 *  }
 *      0 - HID_KEYCODE_TO_COBRA_KB row/col
 *      1 - other row/col when shift is pressed - CS on - CS_KEYS - eg DEL, CAPS LOCK
 *      2 - HID_KEYCODE_TO_COBRA_KB row/col - CS on if SHIFT pressed - letters
 *      3 - other row/col when shift is not pressed - SS_KEYS - symbols
 *      3 - other row/col when shift is pressed - SS_KEYS_SHIFT - symbols
 *      4 - HID_KEYCODE_TO_COBRA_KB row/col - modeE and SS on - symbols
 *      5 - HID_KEYCODE_TO_COBRA_KB row/col w/o shift, other row/col if shift pressed + SS - numbers
 * 
 *--------------------------------------------------------------------*/

// { usb key_code, CoBra key_code }
#define CS_KEYS \
    { 0x39, 0x1F }, /* CAPS LOCK - CS + 2   */  \
    { 0x2A, 0x27 }, /* BACKSPACE - CS + 0   */  \
    { 0x49, 0x1E }, /* Insert - Edit - CS + 1 */  \
    { 0x4F, 0x25 }, /* Right Arrow - CS + 8 */  \
    { 0x50, 0x22 }, /* Left Arrow - CS + 5  */  \
    { 0x51, 0x23 }, /* Down Arrow - CS + 6  */  \
    { 0x52, 0x24 }, /* Up Arrow - CS + 7    */  \

#define SS_KEYS \
    { 0x1E, 0x1E }, /* 1 - 1 */  \
    { 0x1F, 0x1F }, /* 2 - 2 */  \
    { 0x20, 0x20 }, /* 3 - 3 */  \
    { 0x21, 0x21 }, /* 4 - 4 */  \
    { 0x22, 0x22 }, /* 5 - 5 */  \
    { 0x23, 0x23 }, /* 6 - 6 */  \
    { 0x24, 0x24 }, /* 7 - 7 */  \
    { 0x25, 0x25 }, /* 8 - 8 */  \
    { 0x26, 0x26 }, /* 9 - 9 */  \
    { 0x27, 0x27 }, /* 0 - 0 */  \
    { 0x2D, 0x0D }, /* - - SS + J */  \
    { 0x2E, 0x0F }, /* = - SS + L */  \
    { 0x2F, 0x1C }, /* [ - E + SS + Y */  \
    { 0x30, 0x18 }, /* ] - E + SS + U */  \
    { 0x31, 0x07 }, /* \ - E + SS + D */  \
    { 0x33, 0x12 }, /* ; - SS + O (not 0) */  \
    { 0x34, 0x24 }, /* ' - SS + 7 */  \
    { 0x35, 0x04 }, /* ` - E + SS + A */  \
    { 0x36, 0x11 }, /* , - SS + N */  \
    { 0x37, 0x10 }, /* . - SS + M */  \
    { 0x38, 0x19 }, /* / - SS + V */  \
    { 0x54, 0x19 }, /* KP / - SS + V */  \
    { 0x55, 0x05 }, /* KP * - SS + B */  \
    { 0x56, 0x0D }, /* KP - - SS + J */  \
    { 0x57, 0x0E }, /* KP + - SS + K */  \
    { 0x63, 0x10 }, /* KP . - SS + K */  \
    { 0x65, 0x1B }, /* £ - SS + X */  \

// when SHIFT is pressed
#define SS_KEYS_SHIFT \
    { 0x1E, 0x1E }, /* ! - SS + 1 */  \
    { 0x1F, 0x1F }, /* @ - SS + 2 */  \
    { 0x20, 0x20 }, /* # - SS + 3 */  \
    { 0x21, 0x21 }, /* $ - SS + 4 */  \
    { 0x22, 0x22 }, /* % - SS + 5 */  \
    { 0x23, 0x0B }, /* ^ - SS + H */  \
    { 0x24, 0x23 }, /* & - SS + 6 */  \
    { 0x25, 0x05 }, /* * - SS + B */  \
    { 0x26, 0x25 }, /* ( - SS + 8 */  \
    { 0x27, 0x26 }, /* ) - SS + 9 */  \
    { 0x2D, 0x27 }, /* _ - SS + 0 (not O) */  \
    { 0x2E, 0x0E }, /* + - SS + K */  \
    { 0x2F, 0x09 }, /* { - E + SS + F */  \
    { 0x30, 0x0A }, /* } - E + SS + G */  \
    { 0x31, 0x16 }, /* | - E + SS + S */  \
    { 0x33, 0x1D }, /* : - SS + Z */  \
    { 0x34, 0x13 }, /* " - SS + P */  \
    { 0x35, 0x04 }, /* ~ - E + SS + A */  \
    { 0x36, 0x15 }, /* < - SS + R */  \
    { 0x37, 0x17 }, /* > - SS + T */  \
    { 0x38, 0x06 }, /* ? - SS + C */  \
    { 0x54, 0x19 }, /* KP / - SS + V */  \
    { 0x55, 0x05 }, /* KP * - SS + B */  \
    { 0x56, 0x0D }, /* KP - - SS + J */  \
    { 0x57, 0x0E }, /* KP + - SS + K */  \
    { 0x63, 0x10 }, /* KP . - SS + K */  \

#define HID_KEYCODE_TO_COBRA_KB    \
    { 0, 0, 0 }, /* 0x00 */ \
    { 0, 0, 0 }, /* 0x01 */ \
    { 0, 0, 0 }, /* 0x02 */ \
    { 0, 0, 0 }, /* 0x03 */ \
    { 1, 1, 2 }, /* 0x04 A KC09 KR0 */ \
    { 7, 5, 2 }, /* 0x05 B KC15 KR4 */ \
    { 0, 4, 2 }, /* 0x06 C KC08 KR3 */ \
    { 1, 3, 2 }, /* 0x07 D KC09 KR2 */ \
    { 2, 3, 2 }, /* 0x08 E KC10 KR2 */ \
    { 1, 4, 2 }, /* 0x09 F KC09 KR3 */ \
    { 1, 5, 2 }, /* 0x0a G KC09 KR4 */ \
    { 6, 5, 2 }, /* 0x0b H KC14 KR4 */ \
    { 5, 3, 2 }, /* 0x0c I KC13 KR2 */ \
    { 6, 4, 2 }, /* 0x0d J KC14 KR3 */ \
    { 6, 3, 2 }, /* 0x0e K KC14 KR2 */ \
    { 6, 2, 2 }, /* 0x0f L KC14 KR1 */ \
    { 7, 3, 2 }, /* 0x10 M KC15 KR2 */ \
    { 7, 4, 2 }, /* 0x11 N KC15 KR3 */ \
    { 5, 2, 2 }, /* 0x12 O KC13 KR1 */ \
    { 5, 1, 2 }, /* 0x13 P KC13 KR0 */ \
    { 2, 1, 2 }, /* 0x14 Q KC10 KR0 */ \
    { 2, 4, 2 }, /* 0x15 R KC10 KR3 */ \
    { 1, 2, 2 }, /* 0x16 S KC09 KR1 */ \
    { 2, 5, 2 }, /* 0x17 T KC10 KR4 */ \
    { 5, 4, 2 }, /* 0x18 U KC13 KR3 */ \
    { 0, 5, 2 }, /* 0x19 V KC08 KR4 */ \
    { 2, 2, 2 }, /* 0x1a W KC10 KR1 */ \
    { 0, 3, 2 }, /* 0x1b X KC08 KR2 */ \
    { 5, 5, 2 }, /* 0x1c Y KC13 KR4 */ \
    { 0, 2, 2 }, /* 0x1d Z KC08 KR1 */ \
    { 3, 1, 5 }, /* 0x1e 1 */ \
    { 3, 2, 5 }, /* 0x1f 2 */ \
    { 3, 3, 5 }, /* 0x20 3 */ \
    { 3, 4, 5 }, /* 0x21 4 */ \
    { 3, 5, 5 }, /* 0x22 5 */ \
    { 4, 5, 5 }, /* 0x23 6 */ \
    { 4, 4, 5 }, /* 0x24 7 */ \
    { 4, 3, 5 }, /* 0x25 8 */ \
    { 4, 2, 5 }, /* 0x26 9 */ \
    { 4, 1, 5 }, /* 0x27 0 */ \
    { 6, 1, 0 }, /* 0x28 ENTER KC14 KR0 */ \
    { 3, 6, 0 }, /* 0x29 ESC KC11 KR5 */ \
    { 0, 1, 1 }, /* 0x2a BACKSPACE */ \
    { 0, 0, 0 }, /* 0x2b */ \
    { 7, 1, 0 }, /* 0x2c SPACE KC15 KR0 */ \
    { 0, 0, 3 }, /* 0x2d - _ */ \
    { 0, 0, 3 }, /* 0x2e = + */ \
    { 0, 0, 4 }, /* 0x2f [ { */ \
    { 0, 0, 4 }, /* 0x30 ] } */ \
    { 0, 0, 4 }, /* 0x31 \ | */ \
    { 0, 0, 0 }, /* 0x32 */ \
    { 0, 0, 3 }, /* 0x33 ; : */ \
    { 0, 0, 3 }, /* 0x34 ' " */ \
    { 0, 0, 4 }, /* 0x35 ` ~ */ \
    { 0, 0, 3 }, /* 0x36 , < */ \
    { 0, 0, 3 }, /* 0x37 . > */ \
    { 0, 0, 3 }, /* 0x38 / ? */ \
    { 0, 1, 1 }, /* 0x39 CAPS LOCK */ \
    { 4, 6, 0 }, /* 0x3a F1 KC12 KR5 */ \
    { 5, 6, 0 }, /* 0x3b F2 KC13 KR5 */ \
    { 6, 6, 0 }, /* 0x3c F3 KC14 KR5 */ \
    { 7, 6, 0 }, /* 0x3d F4 KC15 KR5 */ \
    { 0, 0, 0 }, /* 0x3e */ \
    { 0, 0, 0 }, /* 0x3f */ \
    { 0, 0, 0 }, /* 0x40 */ \
    { 0, 0, 0 }, /* 0x41 */ \
    { 0, 0, 0 }, /* 0x42 */ \
    { 0, 0, 0 }, /* 0x43 */ \
    { 0, 0, 0 }, /* 0x44 */ \
    { 0, 0, 0 }, /* 0x45 */ \
    { 1, 6, 0 }, /* 0x46 PRINT SCREEN - NO_SCR KC09 KR5 */ \
    { 2, 6, 0 }, /* 0x47 SCROLL LOCK - LF      KC10 KR5 */ \
    { 0, 0, 0 }, /* 0x48 */ \
    { 0, 0, 1 }, /* 0x49 Insert */ \
    { 0, 0, 0 }, /* 0x4a */ \
    { 0, 0, 0 }, /* 0x4b */ \
    { 0, 0, 0 }, /* 0x4c */ \
    { 0, 0, 0 }, /* 0x4d */ \
    { 0, 0, 0 }, /* 0x4e */ \
    { 0, 0, 1 }, /* 0x4f Right Arrow */ \
    { 0, 0, 1 }, /* 0x50 Left Arrow */ \
    { 0, 0, 1 }, /* 0x51 Down Arrow */ \
    { 0, 0, 1 }, /* 0x52 Up Arrow */ \
    { 0, 0, 0 }, /* 0x53 */ \
    { 0, 0, 3 }, /* 0x54 Keypad / */ \
    { 0, 0, 3 }, /* 0x55 Keypad * */ \
    { 0, 0, 3 }, /* 0x56 Keypad - */ \
    { 0, 0, 3 }, /* 0x57 Keypad + */ \
    { 6, 1, 0 }, /* 0x58 ENTER KP KC14 KR0*/ \
    { 3, 1, 0 }, /* 0x59 1 KC11 KR0 */ \
    { 3, 2, 0 }, /* 0x5a 2 KC11 KR1*/ \
    { 3, 3, 0 }, /* 0x5b 3 KC11 KR2*/ \
    { 3, 4, 0 }, /* 0x5c 4 KC11 KR3*/ \
    { 3, 5, 0 }, /* 0x5d 5 KC11 KR4*/ \
    { 4, 5, 0 }, /* 0x5e 6 KC12 KR4*/ \
    { 4, 4, 0 }, /* 0x5f 7 KC12 KR3*/ \
    { 4, 3, 0 }, /* 0x60 8 KC12 KR2*/ \
    { 4, 2, 0 }, /* 0x61 9 KC12 KR1*/ \
    { 4, 1, 0 }, /* 0x62 0 KC12 KR0*/ \
    { 0, 0, 3 }, /* 0x63 Keypad . */ \
    { 0, 0, 0 }, /* 0x64 */ \
    { 0, 0, 3 }, /* 0x65 App Context Menu */ \
    { 0, 0, 0 }, /* 0x66 */ \
    { 0, 0, 0 }, /* 0x67 */ \
    { 0, 0, 0 }, /* 0x68 */ \
    { 0, 0, 0 }, /* 0x69 */ \
    { 0, 0, 0 }, /* 0x6A */ \
    { 0, 0, 0 }, /* 0x6B */ \
    { 0, 0, 0 }, /* 0x6C */ \
    { 0, 0, 0 }, /* 0x6D */ \
    { 0, 0, 0 }, /* 0x6E */ \
    { 0, 0, 0 }, /* 0x6F */ \
    { 0, 0, 0 }, /* 0x70 */ \
    { 0, 0, 0 }, /* 0x71 */ \
    { 0, 0, 0 }, /* 0x72 */ \
    { 0, 0, 0 }, /* 0x73 */ \
    { 0, 0, 0 }, /* 0x74 */ \
    { 0, 0, 0 }, /* 0x75 */ \
    { 0, 0, 0 }, /* 0x76 Menu */ \
    { 0, 0, 0 }, /* 0x77 */ \
    { 0, 0, 0 }, /* 0x78 */ \
    { 0, 0, 0 }, /* 0x79 */ \
    { 0, 0, 0 }, /* 0x7A */ \
    { 0, 0, 0 }, /* 0x7B */ \
    { 0, 0, 0 }, /* 0x7C */ \
    { 0, 0, 0 }, /* 0x7D */ \
    { 0, 0, 0 }, /* 0x7E */ \
    { 0, 0, 0 }, /* 0x7F */ \
    { 0, 0, 0 }, /* 0x80 */ \
    { 0, 0, 0 }, /* 0x81 */ \
    { 0, 0, 0 }, /* 0x82 */ \
    { 0, 0, 0 }, /* 0x83 */ \
    { 0, 0, 0 }, /* 0x84 */ \
    { 0, 0, 0 }, /* 0x85 */ \
    { 0, 0, 0 }, /* 0x86 */ \
    { 0, 0, 0 }, /* 0x87 */ \
    { 0, 0, 0 }, /* 0x88 */ \
    { 0, 0, 0 }, /* 0x89 */ \
    { 0, 0, 0 }, /* 0x8A */ \
    { 0, 0, 0 }, /* 0x8B */ \
    { 0, 0, 0 }, /* 0x8C */ \
    { 0, 0, 0 }, /* 0x8D */ \
    { 0, 0, 0 }, /* 0x8E */ \
    { 0, 0, 0 }, /* 0x8F */ \
    { 0, 0, 0 }, /* 0x90 */ \
    { 0, 0, 0 }, /* 0x91 */ \
    { 0, 0, 0 }, /* 0x92 */ \
    { 0, 0, 0 }, /* 0x93 */ \
    { 0, 0, 0 }, /* 0x94 */ \
    { 0, 0, 0 }, /* 0x95 */ \
    { 0, 0, 0 }, /* 0x96 */ \
    { 0, 0, 0 }, /* 0x97 */ \
    { 0, 0, 0 }, /* 0x98 */ \
    { 0, 0, 0 }, /* 0x99 */ \
    { 0, 0, 0 }, /* 0x9A */ \
    { 0, 0, 0 }, /* 0x9B */ \
    { 0, 0, 0 }, /* 0x9C */ \
    { 0, 0, 0 }, /* 0x9D */ \
    { 0, 0, 0 }, /* 0x9E */ \
    { 0, 0, 0 }, /* 0x9F */ \
    { 0, 0, 0 }, /* 0xA0 */ \
    { 0, 0, 0 }, /* 0xA1 */ \
    { 0, 0, 0 }, /* 0xA2 */ \
    { 0, 0, 0 }, /* 0xA3 */ \
    { 0, 0, 0 }, /* 0xA4 */ \
    { 0, 0, 0 }, /* 0xA5 */ \
    { 0, 0, 0 }, /* 0xA6 */ \
    { 0, 0, 0 }, /* 0xA7 */ \
    { 0, 0, 0 }, /* 0xA8 */ \
    { 0, 0, 0 }, /* 0xA9 */ \
    { 0, 0, 0 }, /* 0xAA */ \
    { 0, 0, 0 }, /* 0xAB */ \
    { 0, 0, 0 }, /* 0xAC */ \
    { 0, 0, 0 }, /* 0xAD */ \
    { 0, 0, 0 }, /* 0xAE */ \
    { 0, 0, 0 }, /* 0xAF */ \
    { 0, 0, 0 }, /* 0xB0 */ \
    { 0, 0, 0 }, /* 0xB1 */ \
    { 0, 0, 0 }, /* 0xB2 */ \
    { 0, 0, 0 }, /* 0xB3 */ \
    { 0, 0, 0 }, /* 0xB4 */ \
    { 0, 0, 0 }, /* 0xB5 */ \
    { 0, 0, 0 }, /* 0xB6 */ \
    { 0, 0, 0 }, /* 0xB7 */ \
    { 0, 0, 0 }, /* 0xB8 */ \
    { 0, 0, 0 }, /* 0xB9 */ \
    { 0, 0, 0 }, /* 0xBA */ \
    { 0, 0, 0 }, /* 0xBB */ \
    { 0, 0, 0 }, /* 0xBC */ \
    { 0, 0, 0 }, /* 0xBD */ \
    { 0, 0, 0 }, /* 0xBE */ \
    { 0, 0, 0 }, /* 0xBF */ \
    { 0, 0, 0 }, /* 0xC0 */ \
    { 0, 0, 0 }, /* 0xC1 */ \
    { 0, 0, 0 }, /* 0xC2 */ \
    { 0, 0, 0 }, /* 0xC3 */ \
    { 0, 0, 0 }, /* 0xC4 */ \
    { 0, 0, 0 }, /* 0xC5 */ \
    { 0, 0, 0 }, /* 0xC6 */ \
    { 0, 0, 0 }, /* 0xC7 */ \
    { 0, 0, 0 }, /* 0xC8 */ \
    { 0, 0, 0 }, /* 0xC9 */ \
    { 0, 0, 0 }, /* 0xCA */ \
    { 0, 0, 0 }, /* 0xCB */ \
    { 0, 0, 0 }, /* 0xCC */ \
    { 0, 0, 0 }, /* 0xCD */ \
    { 0, 0, 0 }, /* 0xCE */ \
    { 0, 0, 0 }, /* 0xCF */ \
    { 0, 0, 0 }, /* 0xD0 */ \
    { 0, 0, 0 }, /* 0xD1 */ \
    { 0, 0, 0 }, /* 0xD2 */ \
    { 0, 0, 0 }, /* 0xD3 */ \
    { 0, 0, 0 }, /* 0xD4 */ \
    { 0, 0, 0 }, /* 0xD5 */ \
    { 0, 0, 0 }, /* 0xD6 */ \
    { 0, 0, 0 }, /* 0xD7 */ \
    { 0, 0, 0 }, /* 0xD8 */ \
    { 0, 0, 0 }, /* 0xD9 */ \
    { 0, 0, 0 }, /* 0xDA */ \
    { 0, 0, 0 }, /* 0xDB */ \
    { 0, 0, 0 }, /* 0xDC */ \
    { 0, 0, 0 }, /* 0xDD */ \
    { 0, 0, 0 }, /* 0xDE */ \
    { 0, 0, 0 }, /* 0xDF */ \
    { 0, 6, 0 }, /* 0xE0 Left Control  - CTRL KC08 KR5  */ \
    { 0, 1, 0 }, /* 0xE1 Left Shift    - CS   KC08 KR0  */ \
    { 7, 2, 0 }, /* 0xE2 Left Alt      - SS   KC15 KR1  */ \
    { 0, 0, 0 }, /* 0xE3 Left GUI        */ \
    { 0, 6, 0 }, /* 0xE4 Right Control - CTRL KC08 KR5  */ \
    { 0, 1, 0 }, /* 0xE5 Right Shift   - CS   KC08 KR0  */ \
    { 7, 2, 0 }, /* 0xE6 Right Alt     - SS   KC15 KR1  */ \
    { 0, 0, 0 }, /* 0xE7 Right GUI       */ \
    { 0, 0, 0 }, /* 0xE8                 */ \

#ifdef __cplusplus
 }
#endif
