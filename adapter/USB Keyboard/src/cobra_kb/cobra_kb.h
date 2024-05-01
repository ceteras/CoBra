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
 *  Expand to array of [256][2] (ascii without shift, ascii with shift)
 *
 * Usage: example to convert ascii from keycode (key) to Cobra.
 * 
 *
 *  uint8_t const conv_table[128][2] =  { HID_KEYCODE_TO_COBRA_KB };
 *  uint8_t KC = conv_table[chr][0]; // column on CoBra KB associated with the usb keycode (0..7)(+8)
 *  uint8_t KR = conv_table[chr][1]; // row on CoBra KB associated with the usb keycode (0..5)
 *
 *--------------------------------------------------------------------*/
#define HID_KEYCODE_TO_COBRA_KB    \
    {0     , 0    }, /* 0x00 */ \
    {0     , 0    }, /* 0x01 */ \
    {0     , 0    }, /* 0x02 */ \
    {0     , 0    }, /* 0x03 */ \
    {1     , 0    }, /* 0x04 A KC09 KR0 */ \
    {7     , 4    }, /* 0x05 B KC15 KR4 */ \
    {0     , 3    }, /* 0x06 C KC08 KR3 */ \
    {1     , 2    }, /* 0x07 D KC09 KR2 */ \
    {2     , 2    }, /* 0x08 E KC10 KR2 */ \
    {1     , 3    }, /* 0x09 F KC09 KR3 */ \
    {1     , 4    }, /* 0x0a G KC09 KR4 */ \
    {6     , 4    }, /* 0x0b H KC14 KR4 */ \
    {5     , 2    }, /* 0x0c I KC13 KR2 */ \
    {6     , 3    }, /* 0x0d J KC14 KR3 */ \
    {6     , 2    }, /* 0x0e K KC14 KR2 */ \
    {6     , 1    }, /* 0x0f L KC14 KR1 */ \
    {7     , 2    }, /* 0x10 M KC15 KR2 */ \
    {7     , 3    }, /* 0x11 N KC15 KR3 */ \
    {5     , 1    }, /* 0x12 O KC13 KR1 */ \
    {5     , 0    }, /* 0x13 P KC13 KR0 */ \
    {2     , 0    }, /* 0x14 Q KC10 KR0 */ \
    {2     , 3    }, /* 0x15 R KC10 KR3 */ \
    {1     , 1    }, /* 0x16 S KC09 KR1 */ \
    {2     , 4    }, /* 0x17 T KC10 KR4 */ \
    {5     , 3    }, /* 0x18 U KC13 KR3 */ \
    {0     , 4    }, /* 0x19 V KC08 KR4 */ \
    {2     , 1    }, /* 0x1a W KC10 KR1 */ \
    {0     , 2    }, /* 0x1b X KC08 KR2 */ \
    {5     , 4    }, /* 0x1c Y KC13 KR4 */ \
    {0     , 1    }, /* 0x1d Z KC08 KR1 */ \
    {3     , 0    }, /* 0x1e 1 */ \
    {3     , 1    }, /* 0x1f 2 */ \
    {3     , 2    }, /* 0x20 3 */ \
    {3     , 3    }, /* 0x21 4 */ \
    {3     , 4    }, /* 0x22 5 */ \
    {4     , 4    }, /* 0x23 6 */ \
    {4     , 3    }, /* 0x24 7 */ \
    {4     , 2    }, /* 0x25 8 */ \
    {4     , 1    }, /* 0x26 9 */ \
    {4     , 0    }, /* 0x27 0 */ \
    {6     , 0    }, /* 0x28 \r KC14 KR0  ENTER */ \
    {3     , 5    }, /* 0x29 ESC KC11 KR5 */ \
    {0     , 0    }, /* 0x2a */ \
    {0     , 0    }, /* 0x2b */ \
    {7     , 0    }, /* 0x2c SPACE KC15 KR0 */ \
    {0     , 0    }, /* 0x2d */ \
    {0     , 0    }, /* 0x2e */ \
    {0     , 0    }, /* 0x2f */ \
    {0     , 0    }, /* 0x30 */ \
    {0     , 0    }, /* 0x31 */ \
    {0     , 0    }, /* 0x32 */ \
    {0     , 0    }, /* 0x33 */ \
    {0     , 0   }, /* 0x34 */ \
    {0     , 0    }, /* 0x35 */ \
    {0     , 0    }, /* 0x36 */ \
    {0     , 0    }, /* 0x37 */ \
    {0     , 0    }, /* 0x38 */ \
    {0     , 0      }, /* 0x39 */ \
    {0     , 0      }, /* 0x3a F1 KC12 KR5 */ \
    {0     , 0      }, /* 0x3b F2 KC13 KR5 */ \
    {0     , 0      }, /* 0x3c F3 KC14 KR5 */ \
    {0     , 0      }, /* 0x3d F4 KC15 KR5 */ \
    {0     , 0      }, /* 0x3e */ \
    {0     , 0      }, /* 0x3f */ \
    {0     , 0      }, /* 0x40 */ \
    {0     , 0      }, /* 0x41 */ \
    {0     , 0      }, /* 0x42 */ \
    {0     , 0      }, /* 0x43 */ \
    {0     , 0      }, /* 0x44 */ \
    {0     , 0      }, /* 0x45 */ \
    {1     , 5      }, /* 0x46 PRINT SCREEN - NO_SCR KC09 KR5 */ \
    {0     , 0      }, /* 0x47 SCROLL LOCK - LF      KC10 KR5 */ \
    {0     , 0      }, /* 0x48 */ \
    {0     , 0      }, /* 0x49 */ \
    {0     , 0      }, /* 0x4a */ \
    {0     , 0      }, /* 0x4b */ \
    {0     , 0      }, /* 0x4c */ \
    {0     , 0      }, /* 0x4d */ \
    {0     , 0      }, /* 0x4e */ \
    {0     , 0      }, /* 0x4f */ \
    {0     , 0      }, /* 0x50 */ \
    {0     , 0      }, /* 0x51 */ \
    {0     , 0      }, /* 0x52 */ \
    {0     , 0      }, /* 0x53 */ \
    {0     , 0      }, /* 0x54 */ \
    {0     , 0      }, /* 0x55 */ \
    {0     , 0      }, /* 0x56 */ \
    {0     , 0      }, /* 0x57 */ \
    {6     , 0      }, /* 0x58 ENTER KP KC14 KR0*/ \
    {3     , 0      }, /* 0x59 1 KC11 KR0 */ \
    {3     , 1      }, /* 0x5a 2 KC11 KR1*/ \
    {3     , 2      }, /* 0x5b 3 KC11 KR2*/ \
    {3     , 3      }, /* 0x5c 4 KC11 KR3*/ \
    {3     , 4      }, /* 0x5d 5 KC11 KR4*/ \
    {4     , 4      }, /* 0x5e 6 KC12 KR4*/ \
    {4     , 3      }, /* 0x5f 7 KC12 KR3*/ \
    {4     , 2      }, /* 0x60 8 KC12 KR2*/ \
    {4     , 1      }, /* 0x61 9 KC12 KR1*/ \
    {4     , 0      }, /* 0x62 0 KC12 KR0*/ \
    {0     , 0      }, /* 0x63 */ \
    {0     , 0      }, /* 0x64 */ \
    {0     , 0      }, /* 0x65 */ \
    {0     , 0      }, /* 0x66 */ \
    {0     , 0      }, /* 0x67 103*/ \
    {0     , 0      },  /* 0x68 */ \
    {0     , 0      },  /* 0x69 */ \
    {0     , 0      },  /* 0x6A */ \
    {0     , 0      },  /* 0x6B */ \
    {0     , 0      },  /* 0x6C */ \
    {0     , 0      },  /* 0x6D */ \
    {0     , 0      },  /* 0x6E */ \
    {0     , 0      },  /* 0x6F */ \
    {0     , 0      },  /* 0x70 */ \
    {0     , 0      },  /* 0x71 */ \
    {0     , 0      },  /* 0x72 */ \
    {0     , 0      },  /* 0x73 */ \
    {0     , 0      },  /* 0x74 */ \
    {0     , 0      },  /* 0x75 */ \
    {0     , 0      },  /* 0x76 */ \
    {0     , 0      },  /* 0x77 */ \
    {0     , 0      },  /* 0x78 */ \
    {0     , 0      },  /* 0x79 */ \
    {0     , 0      },  /* 0x7A */ \
    {0     , 0      },  /* 0x7B */ \
    {0     , 0      },  /* 0x7C */ \
    {0     , 0      },  /* 0x7D */ \
    {0     , 0      },  /* 0x7E */ \
    {0     , 0      },  /* 0x7F */ \
    {0     , 0      },  /* 0x80 */ \
    {0     , 0      },  /* 0x81 */ \
    {0     , 0      },  /* 0x82 */ \
    {0     , 0      },  /* 0x83 */ \
    {0     , 0      },  /* 0x84 */ \
    {0     , 0      },  /* 0x85 */ \
    {0     , 0      },  /* 0x86 */ \
    {0     , 0      },  /* 0x87 */ \
    {0     , 0      },  /* 0x88 */ \
    {0     , 0      },  /* 0x89 */ \
    {0     , 0      },  /* 0x8A */ \
    {0     , 0      },  /* 0x8B */ \
    {0     , 0      },  /* 0x8C */ \
    {0     , 0      },  /* 0x8D */ \
    {0     , 0      },  /* 0x8E */ \
    {0     , 0      },  /* 0x8F */ \
    {0     , 0      },  /* 0x90 */ \
    {0     , 0      },  /* 0x91 */ \
    {0     , 0      },  /* 0x92 */ \
    {0     , 0      },  /* 0x93 */ \
    {0     , 0      },  /* 0x94 */ \
    {0     , 0      },  /* 0x95 */ \
    {0     , 0      },  /* 0x96 */ \
    {0     , 0      },  /* 0x97 */ \
    {0     , 0      },  /* 0x98 */ \
    {0     , 0      },  /* 0x99 */ \
    {0     , 0      },  /* 0x9A */ \
    {0     , 0      },  /* 0x9B */ \
    {0     , 0      },  /* 0x9C */ \
    {0     , 0      },  /* 0x9D */ \
    {0     , 0      },  /* 0x9E */ \
    {0     , 0      },  /* 0x9F */ \
    {0     , 0      },  /* 0xA0 */ \
    {0     , 0      },  /* 0xA1 */ \
    {0     , 0      },  /* 0xA2 */ \
    {0     , 0      },  /* 0xA3 */ \
    {0     , 0      },  /* 0xA4 */ \
    {0     , 0      },  /* 0xA5 */ \
    {0     , 0      },  /* 0xA6 */ \
    {0     , 0      },  /* 0xA7 */ \
    {0     , 0      },  /* 0xA8 */ \
    {0     , 0      },  /* 0xA9 */ \
    {0     , 0      },  /* 0xAA */ \
    {0     , 0      },  /* 0xAB */ \
    {0     , 0      },  /* 0xAC */ \
    {0     , 0      },  /* 0xAD */ \
    {0     , 0      },  /* 0xAE */ \
    {0     , 0      },  /* 0xAF */ \
    {0     , 0      },  /* 0xB0 */ \
    {0     , 0      },  /* 0xB1 */ \
    {0     , 0      },  /* 0xB2 */ \
    {0     , 0      },  /* 0xB3 */ \
    {0     , 0      },  /* 0xB4 */ \
    {0     , 0      },  /* 0xB5 */ \
    {0     , 0      },  /* 0xB6 */ \
    {0     , 0      },  /* 0xB7 */ \
    {0     , 0      },  /* 0xB8 */ \
    {0     , 0      },  /* 0xB9 */ \
    {0     , 0      },  /* 0xBA */ \
    {0     , 0      },  /* 0xBB */ \
    {0     , 0      },  /* 0xBC */ \
    {0     , 0      },  /* 0xBD */ \
    {0     , 0      },  /* 0xBE */ \
    {0     , 0      },  /* 0xBF */ \
    {0     , 0      },  /* 0xC0 */ \
    {0     , 0      },  /* 0xC1 */ \
    {0     , 0      },  /* 0xC2 */ \
    {0     , 0      },  /* 0xC3 */ \
    {0     , 0      },  /* 0xC4 */ \
    {0     , 0      },  /* 0xC5 */ \
    {0     , 0      },  /* 0xC6 */ \
    {0     , 0      },  /* 0xC7 */ \
    {0     , 0      },  /* 0xC8 */ \
    {0     , 0      },  /* 0xC9 */ \
    {0     , 0      },  /* 0xCA */ \
    {0     , 0      },  /* 0xCB */ \
    {0     , 0      },  /* 0xCC */ \
    {0     , 0      },  /* 0xCD */ \
    {0     , 0      },  /* 0xCE */ \
    {0     , 0      },  /* 0xCF */ \
    {0     , 0      },  /* 0xD0 */ \
    {0     , 0      },  /* 0xD1 */ \
    {0     , 0      },  /* 0xD2 */ \
    {0     , 0      },  /* 0xD3 */ \
    {0     , 0      },  /* 0xD4 */ \
    {0     , 0      },  /* 0xD5 */ \
    {0     , 0      },  /* 0xD6 */ \
    {0     , 0      },  /* 0xD7 */ \
    {0     , 0      },  /* 0xD8 */ \
    {0     , 0      },  /* 0xD9 */ \
    {0     , 0      },  /* 0xDA */ \
    {0     , 0      },  /* 0xDB */ \
    {0     , 0      },  /* 0xDC */ \
    {0     , 0      },  /* 0xDD */ \
    {0     , 0      },  /* 0xDE */ \
    {0     , 0      },  /* 0xDF */ \
    {0     , 5      },  /* 0xE0 Left Control  - CTRL KC08 KR5  */ \
    {0     , 0      },  /* 0xE1 Left Shift    - CS   KC08 KR0  */ \
    {7     , 1      },  /* 0xE2 Left Alt      - SS   KC15 KR1  */ \
    {0     , 0      },  /* 0xE3 Left GUI        */ \
    {0     , 5      },  /* 0xE4 Right Control - CTRL KC08 KR5  */ \
    {0     , 0      },  /* 0xE5 Right Shift   - CS   KC08 KR0  */ \
    {7     , 1      },  /* 0xE6 Right Alt     - SS   KC15 KR1  */ \
    {0     , 0      },  /* 0xE7 Right GUI       */ \
    {0     , 0      },  /* 0xE8                 */ \



#ifdef __cplusplus
 }
#endif
