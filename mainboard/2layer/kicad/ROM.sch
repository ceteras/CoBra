EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 13
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L cobra:MMN2716 U91
U 1 1 6302A82C
P 4650 700
F 0 "U91" H 4900 600 50  0000 C CNN
F 1 "MMN2716" H 4650 -800 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W15.24mm" H 4650 700 50  0001 C CNN
F 3 "" H 4650 700 50  0001 C CNN
	1    4650 700 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 950  4000 950 
Wire Wire Line
	4200 1050 4000 1050
Wire Wire Line
	4200 1150 4000 1150
Wire Wire Line
	4200 1250 4000 1250
Wire Wire Line
	4200 1350 4000 1350
Wire Wire Line
	4200 1450 4000 1450
Wire Wire Line
	4200 1550 4000 1550
Wire Wire Line
	4200 1650 4000 1650
Wire Wire Line
	4200 1750 4000 1750
Wire Wire Line
	4200 1850 4000 1850
Wire Wire Line
	4200 1950 4000 1950
Wire Wire Line
	4200 2050 4000 2050
Text Label 4000 1650 0    50   ~ 0
bA0
Text Label 4000 1550 0    50   ~ 0
bA1
Text Label 4000 1450 0    50   ~ 0
bA2
Text Label 4000 1350 0    50   ~ 0
bA3
Text Label 4000 1250 0    50   ~ 0
bA4
Text Label 4000 1150 0    50   ~ 0
bA5
Text Label 4000 1050 0    50   ~ 0
bA6
Text Label 4000 950  0    50   ~ 0
bA7
Text Label 4000 1750 0    50   ~ 0
D0
Text Label 4000 1850 0    50   ~ 0
D1
Text Label 4000 1950 0    50   ~ 0
D2
$Comp
L cobra:MMN2716 U42
U 1 1 6303C168
P 4650 2350
F 0 "U42" H 4900 2250 50  0000 C CNN
F 1 "MMN2716" H 4650 850 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W15.24mm" H 4650 2350 50  0001 C CNN
F 3 "" H 4650 2350 50  0001 C CNN
	1    4650 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 2600 4000 2600
Wire Wire Line
	4200 2700 4000 2700
Wire Wire Line
	4200 2800 4000 2800
Wire Wire Line
	4200 2900 4000 2900
Wire Wire Line
	4200 3000 4000 3000
Wire Wire Line
	4200 3100 4000 3100
Wire Wire Line
	4200 3200 4000 3200
Wire Wire Line
	4200 3300 4000 3300
Wire Wire Line
	4200 3400 4000 3400
Wire Wire Line
	4200 3500 4000 3500
Wire Wire Line
	4200 3600 4000 3600
Wire Wire Line
	4200 3700 4000 3700
Text Label 4000 3300 0    50   ~ 0
bA0
Text Label 4000 3200 0    50   ~ 0
bA1
Text Label 4000 3100 0    50   ~ 0
bA2
Text Label 4000 3000 0    50   ~ 0
bA3
Text Label 4000 2900 0    50   ~ 0
bA4
Text Label 4000 2800 0    50   ~ 0
bA5
Text Label 4000 2700 0    50   ~ 0
bA6
Text Label 4000 2600 0    50   ~ 0
bA7
Text Label 4000 3400 0    50   ~ 0
D0
Text Label 4000 3500 0    50   ~ 0
D1
Text Label 4000 3600 0    50   ~ 0
D2
Text HLabel 1350 4100 0    50   Input ~ 0
nPO
Wire Wire Line
	1350 4100 1500 4100
Text Label 1350 4100 0    50   ~ 0
nPO
$Comp
L Device:Jumper_NC_Small JP1
U 1 1 6314259C
P 1400 5250
F 0 "JP1" H 1400 5350 50  0001 C CNN
F 1 "Jumper_NC_Small" H 1400 5371 50  0001 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" H 1400 5250 50  0001 C CNN
F 3 "~" H 1400 5250 50  0001 C CNN
	1    1400 5250
	1    0    0    -1  
$EndComp
$Comp
L Device:Jumper_NO_Small JP2
U 1 1 63142F1C
P 1400 5350
F 0 "JP2" H 1400 5400 50  0001 C CNN
F 1 "Jumper_NO_Small" H 1400 5444 50  0001 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" H 1400 5350 50  0001 C CNN
F 3 "~" H 1400 5350 50  0001 C CNN
	1    1400 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:Jumper_NC_Small JP3
U 1 1 631DC241
P 1400 5450
F 0 "JP3" H 1400 5550 50  0001 C CNN
F 1 "Jumper_NC_Small" H 1400 5571 50  0001 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" H 1400 5450 50  0001 C CNN
F 3 "~" H 1400 5450 50  0001 C CNN
	1    1400 5450
	1    0    0    -1  
$EndComp
$Comp
L Device:Jumper_NO_Small JP4
U 1 1 631DC247
P 1400 5550
F 0 "JP4" H 1400 5600 50  0001 C CNN
F 1 "Jumper_NO_Small" H 1400 5644 50  0001 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" H 1400 5550 50  0001 C CNN
F 3 "~" H 1400 5550 50  0001 C CNN
	1    1400 5550
	1    0    0    -1  
$EndComp
$Comp
L Device:Jumper_NC_Small JP5
U 1 1 631F202A
P 1400 5650
F 0 "JP5" H 1400 5750 50  0001 C CNN
F 1 "Jumper_NC_Small" H 1400 5771 50  0001 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" H 1400 5650 50  0001 C CNN
F 3 "~" H 1400 5650 50  0001 C CNN
	1    1400 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:Jumper_NO_Small JP6
U 1 1 631F2030
P 1400 5750
F 0 "JP6" H 1400 5800 50  0001 C CNN
F 1 "Jumper_NO_Small" H 1400 5844 50  0001 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" H 1400 5750 50  0001 C CNN
F 3 "~" H 1400 5750 50  0001 C CNN
	1    1400 5750
	1    0    0    -1  
$EndComp
$Comp
L Device:Jumper_NC_Small JP7
U 1 1 631F2036
P 1400 5850
F 0 "JP7" H 1400 5950 50  0001 C CNN
F 1 "Jumper_NC_Small" H 1400 5971 50  0001 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" H 1400 5850 50  0001 C CNN
F 3 "~" H 1400 5850 50  0001 C CNN
	1    1400 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:Jumper_NO_Small JP8
U 1 1 631F203C
P 1400 5950
F 0 "JP8" H 1400 6000 50  0001 C CNN
F 1 "Jumper_NO_Small" H 1400 6044 50  0001 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" H 1400 5950 50  0001 C CNN
F 3 "~" H 1400 5950 50  0001 C CNN
	1    1400 5950
	1    0    0    -1  
$EndComp
$Comp
L Device:Jumper_NC_Small JP9
U 1 1 63207627
P 1400 6050
F 0 "JP9" H 1400 6150 50  0001 C CNN
F 1 "Jumper_NC_Small" H 1400 6171 50  0001 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" H 1400 6050 50  0001 C CNN
F 3 "~" H 1400 6050 50  0001 C CNN
	1    1400 6050
	1    0    0    -1  
$EndComp
$Comp
L Device:Jumper_NO_Small JP10
U 1 1 6320762D
P 1400 6150
F 0 "JP10" H 1400 6200 50  0001 C CNN
F 1 "Jumper_NO_Small" H 1400 6244 50  0001 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" H 1400 6150 50  0001 C CNN
F 3 "~" H 1400 6150 50  0001 C CNN
	1    1400 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 5200 1250 5250
Wire Wire Line
	1250 5250 1300 5250
Wire Wire Line
	950  5350 1200 5350
Text Label 950  5350 0    50   ~ 0
bA11
Wire Wire Line
	1500 5250 1550 5250
Wire Wire Line
	1500 5350 1550 5350
Wire Wire Line
	1550 5350 1550 5250
Connection ~ 1550 5250
Wire Wire Line
	1550 5250 1950 5250
Wire Wire Line
	1500 5550 1550 5550
Wire Wire Line
	1550 5550 1550 5450
Connection ~ 1550 5450
Wire Wire Line
	1550 5450 1500 5450
Wire Wire Line
	1500 5650 1550 5650
Wire Wire Line
	1500 5750 1550 5750
Wire Wire Line
	1550 5750 1550 5650
Connection ~ 1550 5650
Wire Wire Line
	1500 5850 1550 5850
Wire Wire Line
	1500 5950 1550 5950
Wire Wire Line
	1550 5950 1550 5850
Connection ~ 1550 5850
Wire Wire Line
	1500 6050 1550 6050
Wire Wire Line
	1500 6150 1550 6150
Wire Wire Line
	1550 6150 1550 6050
Connection ~ 1550 6050
Wire Wire Line
	1300 5450 1250 5450
Wire Wire Line
	1250 5450 1250 5250
Connection ~ 1250 5250
Wire Wire Line
	1300 5550 1200 5550
Wire Wire Line
	1200 5550 1200 5650
Wire Wire Line
	1200 5650 1300 5650
Wire Wire Line
	1200 5550 1200 5350
Connection ~ 1200 5550
Connection ~ 1200 5350
Wire Wire Line
	1200 5350 1300 5350
Wire Wire Line
	1300 5750 1200 5750
Wire Wire Line
	1200 5750 1200 5850
Wire Wire Line
	1200 5850 1300 5850
Wire Wire Line
	1300 5950 1200 5950
Wire Wire Line
	1200 5950 1200 6050
Wire Wire Line
	1200 6050 1300 6050
Wire Wire Line
	1200 5950 950  5950
Connection ~ 1200 5950
Wire Wire Line
	1200 5750 950  5750
Connection ~ 1200 5750
Text Label 950  5750 0    50   ~ 0
bA12
Text Label 950  5950 0    50   ~ 0
bA13
Wire Wire Line
	1300 6150 1200 6150
Wire Wire Line
	1200 6150 1200 6200
$Comp
L power:GNDD #PWR0141
U 1 1 634E67CD
P 1200 6200
F 0 "#PWR0141" H 1200 5950 50  0001 C CNN
F 1 "GNDD" H 1204 6045 50  0000 C CNN
F 2 "" H 1200 6200 50  0001 C CNN
F 3 "" H 1200 6200 50  0001 C CNN
	1    1200 6200
	1    0    0    -1  
$EndComp
Text Label 1600 5250 0    50   ~ 0
Boot_A11
Wire Wire Line
	1550 5450 1950 5450
Text Label 1600 5450 0    50   ~ 0
BAS_A11
$Comp
L 74xx:74LS42 U70
U 1 1 6359020D
P 2450 6050
F 0 "U70" H 2650 6600 50  0000 C CNN
F 1 "74LS42" H 2400 5900 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 2450 6050 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS42" H 2450 6050 50  0001 C CNN
	1    2450 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 5650 1950 5650
Wire Wire Line
	1950 5750 1750 5750
Wire Wire Line
	1750 5750 1750 5850
Wire Wire Line
	1550 5850 1750 5850
Wire Wire Line
	1850 6050 1850 5850
Wire Wire Line
	1850 5850 1950 5850
Wire Wire Line
	1550 6050 1850 6050
Wire Wire Line
	2950 5650 3450 5650
Wire Wire Line
	2950 5750 3450 5750
Wire Wire Line
	2950 5850 3450 5850
Wire Wire Line
	2950 5950 3450 5950
Wire Wire Line
	2950 6050 3450 6050
Wire Wire Line
	2950 6150 3450 6150
Wire Wire Line
	2950 6250 3450 6250
Wire Wire Line
	2950 6350 3450 6350
Text Label 3100 5650 0    50   ~ 0
BAS_OE0
Text Label 3100 5750 0    50   ~ 0
BAS_OE1
Text Label 3100 5850 0    50   ~ 0
BAS_OE2
Text Label 3100 5950 0    50   ~ 0
BAS_OE3
Text Label 3100 6050 0    50   ~ 0
BAS_OE4
Text Label 3100 6150 0    50   ~ 0
BAS_OE5
Text Label 3100 6250 0    50   ~ 0
BAS_OE6
Text Label 3100 6350 0    50   ~ 0
BAS_OE7
NoConn ~ 2950 6450
NoConn ~ 2950 6550
$Comp
L power:GNDD #PWR0142
U 1 1 638A50CA
P 2450 6900
F 0 "#PWR0142" H 2450 6650 50  0001 C CNN
F 1 "GNDD" H 2454 6745 50  0000 C CNN
F 2 "" H 2450 6900 50  0001 C CNN
F 3 "" H 2450 6900 50  0001 C CNN
	1    2450 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 6900 2450 6850
Text Label 10050 3000 0    50   ~ 0
BAS_OE7
Text Label 8400 3000 0    50   ~ 0
BAS_OE6
Text Label 5100 3000 0    50   ~ 0
BAS_OE4
Text Label 10050 1350 0    50   ~ 0
BAS_OE3
Text Label 8400 1350 0    50   ~ 0
BAS_OE2
Text Label 6750 1350 0    50   ~ 0
BAS_OE1
Text Label 5100 1350 0    50   ~ 0
BAS_OE0
Text Label 5100 2900 0    50   ~ 0
BAS_A11
Text Label 8400 2900 0    50   ~ 0
BAS_A11
Text Label 10050 2900 0    50   ~ 0
BAS_A11
Text Label 10050 1250 0    50   ~ 0
BAS_A11
Text Label 8400 1250 0    50   ~ 0
BAS_A11
Text Label 6750 1250 0    50   ~ 0
BAS_A11
Text Label 5100 1250 0    50   ~ 0
BAS_A11
Text Label 6800 1550 0    50   ~ 0
nPO
Text Label 8450 1550 0    50   ~ 0
nPO
Text Label 10100 1550 0    50   ~ 0
nPO
Text Label 10100 3200 0    50   ~ 0
nPO
Text Label 8450 3200 0    50   ~ 0
nPO
Text Label 6800 3200 0    50   ~ 0
nPO
Text Label 5150 3200 0    50   ~ 0
nPO
Text Label 5150 1550 0    50   ~ 0
nPO
Text Label 10150 3300 0    50   ~ 0
D7
Text Label 10150 3400 0    50   ~ 0
D6
Text Label 10150 3500 0    50   ~ 0
D5
Text Label 10150 3600 0    50   ~ 0
D4
Text Label 10150 3700 0    50   ~ 0
D3
Text Label 8950 3600 0    50   ~ 0
D2
Text Label 8950 3500 0    50   ~ 0
D1
Text Label 8950 3400 0    50   ~ 0
D0
Text Label 10100 3100 0    50   ~ 0
bA10
Text Label 10100 2800 0    50   ~ 0
bA9
Text Label 10100 2700 0    50   ~ 0
bA8
Text Label 8950 2600 0    50   ~ 0
bA7
Text Label 8950 2700 0    50   ~ 0
bA6
Text Label 8950 2800 0    50   ~ 0
bA5
Text Label 8950 2900 0    50   ~ 0
bA4
Text Label 8950 3000 0    50   ~ 0
bA3
Text Label 8950 3100 0    50   ~ 0
bA2
Text Label 8950 3200 0    50   ~ 0
bA1
Text Label 8950 3300 0    50   ~ 0
bA0
Wire Wire Line
	10250 3700 10050 3700
Wire Wire Line
	10250 3600 10050 3600
Wire Wire Line
	10250 3500 10050 3500
Wire Wire Line
	10250 3400 10050 3400
Wire Wire Line
	10250 3300 10050 3300
Wire Wire Line
	10250 3200 10050 3200
Wire Wire Line
	10250 3100 10050 3100
Wire Wire Line
	10250 3000 10050 3000
Wire Wire Line
	10250 2900 10050 2900
Wire Wire Line
	10250 2800 10050 2800
Wire Wire Line
	10250 2700 10050 2700
Wire Wire Line
	10250 2600 10050 2600
Wire Wire Line
	9150 3700 8950 3700
Wire Wire Line
	9150 3600 8950 3600
Wire Wire Line
	9150 3500 8950 3500
Wire Wire Line
	9150 3400 8950 3400
Wire Wire Line
	9150 3300 8950 3300
Wire Wire Line
	9150 3200 8950 3200
Wire Wire Line
	9150 3100 8950 3100
Wire Wire Line
	9150 3000 8950 3000
Wire Wire Line
	9150 2900 8950 2900
Wire Wire Line
	9150 2800 8950 2800
Wire Wire Line
	9150 2700 8950 2700
Wire Wire Line
	9150 2600 8950 2600
$Comp
L cobra:MMN2716 U1
U 1 1 630667C2
P 9600 2350
F 0 "U1" H 9850 2250 50  0000 C CNN
F 1 "MMN2716" H 9600 850 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W15.24mm" H 9600 2350 50  0001 C CNN
F 3 "" H 9600 2350 50  0001 C CNN
	1    9600 2350
	1    0    0    -1  
$EndComp
Text Label 8500 3300 0    50   ~ 0
D7
Text Label 8500 3400 0    50   ~ 0
D6
Text Label 8500 3500 0    50   ~ 0
D5
Text Label 8500 3600 0    50   ~ 0
D4
Text Label 8500 3700 0    50   ~ 0
D3
Text Label 7300 3600 0    50   ~ 0
D2
Text Label 7300 3500 0    50   ~ 0
D1
Text Label 7300 3400 0    50   ~ 0
D0
Text Label 8450 3100 0    50   ~ 0
bA10
Text Label 8450 2800 0    50   ~ 0
bA9
Text Label 8450 2700 0    50   ~ 0
bA8
Text Label 7300 2600 0    50   ~ 0
bA7
Text Label 7300 2700 0    50   ~ 0
bA6
Text Label 7300 2800 0    50   ~ 0
bA5
Text Label 7300 2900 0    50   ~ 0
bA4
Text Label 7300 3000 0    50   ~ 0
bA3
Text Label 7300 3100 0    50   ~ 0
bA2
Text Label 7300 3200 0    50   ~ 0
bA1
Text Label 7300 3300 0    50   ~ 0
bA0
Wire Wire Line
	8600 3700 8400 3700
Wire Wire Line
	8600 3600 8400 3600
Wire Wire Line
	8600 3500 8400 3500
Wire Wire Line
	8600 3400 8400 3400
Wire Wire Line
	8600 3300 8400 3300
Wire Wire Line
	8600 3200 8400 3200
Wire Wire Line
	8600 3100 8400 3100
Wire Wire Line
	8600 3000 8400 3000
Wire Wire Line
	8600 2900 8400 2900
Wire Wire Line
	8600 2800 8400 2800
Wire Wire Line
	8600 2700 8400 2700
Wire Wire Line
	8600 2600 8400 2600
Wire Wire Line
	7500 3700 7300 3700
Wire Wire Line
	7500 3600 7300 3600
Wire Wire Line
	7500 3500 7300 3500
Wire Wire Line
	7500 3400 7300 3400
Wire Wire Line
	7500 3300 7300 3300
Wire Wire Line
	7500 3200 7300 3200
Wire Wire Line
	7500 3100 7300 3100
Wire Wire Line
	7500 3000 7300 3000
Wire Wire Line
	7500 2900 7300 2900
Wire Wire Line
	7500 2800 7300 2800
Wire Wire Line
	7500 2700 7300 2700
Wire Wire Line
	7500 2600 7300 2600
$Comp
L cobra:MMN2716 U18
U 1 1 63056320
P 7950 2350
F 0 "U18" H 8200 2250 50  0000 C CNN
F 1 "MMN2716" H 7950 850 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W15.24mm" H 7950 2350 50  0001 C CNN
F 3 "" H 7950 2350 50  0001 C CNN
	1    7950 2350
	1    0    0    -1  
$EndComp
Text Label 6850 3300 0    50   ~ 0
D7
Text Label 6850 3400 0    50   ~ 0
D6
Text Label 6850 3500 0    50   ~ 0
D5
Text Label 6850 3600 0    50   ~ 0
D4
Text Label 6850 3700 0    50   ~ 0
D3
Text Label 5650 3600 0    50   ~ 0
D2
Text Label 5650 3500 0    50   ~ 0
D1
Text Label 5650 3400 0    50   ~ 0
D0
Text Label 6800 3100 0    50   ~ 0
bA10
Text Label 6800 2800 0    50   ~ 0
bA9
Text Label 6800 2700 0    50   ~ 0
bA8
Text Label 5650 2600 0    50   ~ 0
bA7
Text Label 5650 2700 0    50   ~ 0
bA6
Text Label 5650 2800 0    50   ~ 0
bA5
Text Label 5650 2900 0    50   ~ 0
bA4
Text Label 5650 3000 0    50   ~ 0
bA3
Text Label 5650 3100 0    50   ~ 0
bA2
Text Label 5650 3200 0    50   ~ 0
bA1
Text Label 5650 3300 0    50   ~ 0
bA0
Wire Wire Line
	6950 3700 6750 3700
Wire Wire Line
	6950 3600 6750 3600
Wire Wire Line
	6950 3500 6750 3500
Wire Wire Line
	6950 3400 6750 3400
Wire Wire Line
	6950 3300 6750 3300
Wire Wire Line
	6950 3200 6750 3200
Wire Wire Line
	6950 3100 6750 3100
Wire Wire Line
	6950 3000 6750 3000
Wire Wire Line
	6950 2900 6750 2900
Wire Wire Line
	6950 2800 6750 2800
Wire Wire Line
	6950 2700 6750 2700
Wire Wire Line
	6950 2600 6750 2600
Wire Wire Line
	5850 3700 5650 3700
Wire Wire Line
	5850 3600 5650 3600
Wire Wire Line
	5850 3500 5650 3500
Wire Wire Line
	5850 3400 5650 3400
Wire Wire Line
	5850 3300 5650 3300
Wire Wire Line
	5850 3200 5650 3200
Wire Wire Line
	5850 3100 5650 3100
Wire Wire Line
	5850 3000 5650 3000
Wire Wire Line
	5850 2900 5650 2900
Wire Wire Line
	5850 2800 5650 2800
Wire Wire Line
	5850 2700 5650 2700
Wire Wire Line
	5850 2600 5650 2600
$Comp
L cobra:MMN2716 U23
U 1 1 630485EA
P 6300 2350
F 0 "U23" H 6550 2250 50  0000 C CNN
F 1 "MMN2716" H 6300 850 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W15.24mm" H 6300 2350 50  0001 C CNN
F 3 "" H 6300 2350 50  0001 C CNN
	1    6300 2350
	1    0    0    -1  
$EndComp
Text Label 5200 3300 0    50   ~ 0
D7
Text Label 5200 3400 0    50   ~ 0
D6
Text Label 5200 3500 0    50   ~ 0
D5
Text Label 5200 3600 0    50   ~ 0
D4
Text Label 5200 3700 0    50   ~ 0
D3
Text Label 5150 3100 0    50   ~ 0
bA10
Text Label 5150 2800 0    50   ~ 0
bA9
Text Label 5150 2700 0    50   ~ 0
bA8
Wire Wire Line
	5300 3700 5100 3700
Wire Wire Line
	5300 3600 5100 3600
Wire Wire Line
	5300 3500 5100 3500
Wire Wire Line
	5300 3400 5100 3400
Wire Wire Line
	5300 3300 5100 3300
Wire Wire Line
	5300 3200 5100 3200
Wire Wire Line
	5300 3100 5100 3100
Wire Wire Line
	5300 3000 5100 3000
Wire Wire Line
	5300 2900 5100 2900
Wire Wire Line
	5300 2800 5100 2800
Wire Wire Line
	5300 2700 5100 2700
Wire Wire Line
	5300 2600 5100 2600
Text Label 10150 1650 0    50   ~ 0
D7
Text Label 10150 1750 0    50   ~ 0
D6
Text Label 10150 1850 0    50   ~ 0
D5
Text Label 10150 1950 0    50   ~ 0
D4
Text Label 10150 2050 0    50   ~ 0
D3
Text Label 8950 1950 0    50   ~ 0
D2
Text Label 8950 1850 0    50   ~ 0
D1
Text Label 8950 1750 0    50   ~ 0
D0
Text Label 10100 1450 0    50   ~ 0
bA10
Text Label 10100 1150 0    50   ~ 0
bA9
Text Label 10100 1050 0    50   ~ 0
bA8
Text Label 8950 950  0    50   ~ 0
bA7
Text Label 8950 1050 0    50   ~ 0
bA6
Text Label 8950 1150 0    50   ~ 0
bA5
Text Label 8950 1250 0    50   ~ 0
bA4
Text Label 8950 1350 0    50   ~ 0
bA3
Text Label 8950 1450 0    50   ~ 0
bA2
Text Label 8950 1550 0    50   ~ 0
bA1
Text Label 8950 1650 0    50   ~ 0
bA0
Wire Wire Line
	10250 2050 10050 2050
Wire Wire Line
	10250 1950 10050 1950
Wire Wire Line
	10250 1850 10050 1850
Wire Wire Line
	10250 1750 10050 1750
Wire Wire Line
	10250 1650 10050 1650
Wire Wire Line
	10250 1550 10050 1550
Wire Wire Line
	10250 1450 10050 1450
Wire Wire Line
	10250 1350 10050 1350
Wire Wire Line
	10250 1250 10050 1250
Wire Wire Line
	10250 1150 10050 1150
Wire Wire Line
	10250 1050 10050 1050
Wire Wire Line
	10250 950  10050 950 
Wire Wire Line
	9150 2050 8950 2050
Wire Wire Line
	9150 1950 8950 1950
Wire Wire Line
	9150 1850 8950 1850
Wire Wire Line
	9150 1750 8950 1750
Wire Wire Line
	9150 1650 8950 1650
Wire Wire Line
	9150 1550 8950 1550
Wire Wire Line
	9150 1450 8950 1450
Wire Wire Line
	9150 1350 8950 1350
Wire Wire Line
	9150 1250 8950 1250
Wire Wire Line
	9150 1150 8950 1150
Wire Wire Line
	9150 1050 8950 1050
Wire Wire Line
	9150 950  8950 950 
$Comp
L cobra:MMN2716 U59
U 1 1 63034ED6
P 9600 700
F 0 "U59" H 9850 600 50  0000 C CNN
F 1 "MMN2716" H 9600 -800 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W15.24mm" H 9600 700 50  0001 C CNN
F 3 "" H 9600 700 50  0001 C CNN
	1    9600 700 
	1    0    0    -1  
$EndComp
Text Label 8500 1650 0    50   ~ 0
D7
Text Label 8500 1750 0    50   ~ 0
D6
Text Label 8500 1850 0    50   ~ 0
D5
Text Label 8500 1950 0    50   ~ 0
D4
Text Label 8500 2050 0    50   ~ 0
D3
Text Label 7300 1950 0    50   ~ 0
D2
Text Label 7300 1850 0    50   ~ 0
D1
Text Label 7300 1750 0    50   ~ 0
D0
Text Label 8450 1450 0    50   ~ 0
bA10
Text Label 8450 1150 0    50   ~ 0
bA9
Text Label 8450 1050 0    50   ~ 0
bA8
Text Label 7300 950  0    50   ~ 0
bA7
Text Label 7300 1050 0    50   ~ 0
bA6
Text Label 7300 1150 0    50   ~ 0
bA5
Text Label 7300 1250 0    50   ~ 0
bA4
Text Label 7300 1350 0    50   ~ 0
bA3
Text Label 7300 1450 0    50   ~ 0
bA2
Text Label 7300 1550 0    50   ~ 0
bA1
Text Label 7300 1650 0    50   ~ 0
bA0
Wire Wire Line
	8600 2050 8400 2050
Wire Wire Line
	8600 1950 8400 1950
Wire Wire Line
	8600 1850 8400 1850
Wire Wire Line
	8600 1750 8400 1750
Wire Wire Line
	8600 1650 8400 1650
Wire Wire Line
	8600 1550 8400 1550
Wire Wire Line
	8600 1450 8400 1450
Wire Wire Line
	8600 1350 8400 1350
Wire Wire Line
	8600 1250 8400 1250
Wire Wire Line
	8600 1150 8400 1150
Wire Wire Line
	8600 1050 8400 1050
Wire Wire Line
	8600 950  8400 950 
Wire Wire Line
	7500 2050 7300 2050
Wire Wire Line
	7500 1950 7300 1950
Wire Wire Line
	7500 1850 7300 1850
Wire Wire Line
	7500 1750 7300 1750
Wire Wire Line
	7500 1650 7300 1650
Wire Wire Line
	7500 1550 7300 1550
Wire Wire Line
	7500 1450 7300 1450
Wire Wire Line
	7500 1350 7300 1350
Wire Wire Line
	7500 1250 7300 1250
Wire Wire Line
	7500 1150 7300 1150
Wire Wire Line
	7500 1050 7300 1050
Wire Wire Line
	7500 950  7300 950 
$Comp
L cobra:MMN2716 U75
U 1 1 630306EC
P 7950 700
F 0 "U75" H 8200 600 50  0000 C CNN
F 1 "MMN2716" H 7950 -800 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W15.24mm" H 7950 700 50  0001 C CNN
F 3 "" H 7950 700 50  0001 C CNN
	1    7950 700 
	1    0    0    -1  
$EndComp
Text Label 6850 1650 0    50   ~ 0
D7
Text Label 6850 1750 0    50   ~ 0
D6
Text Label 6850 1850 0    50   ~ 0
D5
Text Label 6850 1950 0    50   ~ 0
D4
Text Label 6850 2050 0    50   ~ 0
D3
Text Label 5650 1950 0    50   ~ 0
D2
Text Label 5650 1850 0    50   ~ 0
D1
Text Label 5650 1750 0    50   ~ 0
D0
Text Label 6800 1450 0    50   ~ 0
bA10
Text Label 6800 1150 0    50   ~ 0
bA9
Text Label 6800 1050 0    50   ~ 0
bA8
Text Label 5650 950  0    50   ~ 0
bA7
Text Label 5650 1050 0    50   ~ 0
bA6
Text Label 5650 1150 0    50   ~ 0
bA5
Text Label 5650 1250 0    50   ~ 0
bA4
Text Label 5650 1350 0    50   ~ 0
bA3
Text Label 5650 1450 0    50   ~ 0
bA2
Text Label 5650 1550 0    50   ~ 0
bA1
Text Label 5650 1650 0    50   ~ 0
bA0
Wire Wire Line
	6950 2050 6750 2050
Wire Wire Line
	6950 1950 6750 1950
Wire Wire Line
	6950 1850 6750 1850
Wire Wire Line
	6950 1750 6750 1750
Wire Wire Line
	6950 1650 6750 1650
Wire Wire Line
	6950 1550 6750 1550
Wire Wire Line
	6950 1450 6750 1450
Wire Wire Line
	6950 1350 6750 1350
Wire Wire Line
	6950 1250 6750 1250
Wire Wire Line
	6950 1150 6750 1150
Wire Wire Line
	6950 1050 6750 1050
Wire Wire Line
	5850 2050 5650 2050
Wire Wire Line
	5850 1950 5650 1950
Wire Wire Line
	5850 1850 5650 1850
Wire Wire Line
	5850 1750 5650 1750
Wire Wire Line
	5850 1650 5650 1650
Wire Wire Line
	5850 1550 5650 1550
Wire Wire Line
	5850 1450 5650 1450
Wire Wire Line
	5850 1350 5650 1350
Wire Wire Line
	5850 1250 5650 1250
Wire Wire Line
	5850 1150 5650 1150
Wire Wire Line
	5850 1050 5650 1050
Wire Wire Line
	5850 950  5650 950 
$Comp
L cobra:MMN2716 U84
U 1 1 6302CDAE
P 6300 700
F 0 "U84" H 6550 600 50  0000 C CNN
F 1 "MMN2716" H 6300 -800 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W15.24mm" H 6300 700 50  0001 C CNN
F 3 "" H 6300 700 50  0001 C CNN
	1    6300 700 
	1    0    0    -1  
$EndComp
Text Label 5200 1650 0    50   ~ 0
D7
Text Label 5200 1750 0    50   ~ 0
D6
Text Label 5200 1850 0    50   ~ 0
D5
Text Label 5200 1950 0    50   ~ 0
D4
Text Label 5200 2050 0    50   ~ 0
D3
Text Label 5150 1450 0    50   ~ 0
bA10
Text Label 5150 1150 0    50   ~ 0
bA9
Text Label 5150 1050 0    50   ~ 0
bA8
Wire Wire Line
	5300 2050 5100 2050
Wire Wire Line
	5300 1950 5100 1950
Wire Wire Line
	5300 1850 5100 1850
Wire Wire Line
	5300 1750 5100 1750
Wire Wire Line
	5300 1650 5100 1650
Wire Wire Line
	5300 1550 5100 1550
Wire Wire Line
	5300 1450 5100 1450
Wire Wire Line
	5300 1350 5100 1350
Wire Wire Line
	5300 1250 5100 1250
Wire Wire Line
	5300 1150 5100 1150
Wire Wire Line
	5300 1050 5100 1050
Wire Wire Line
	5300 950  5100 950 
Wire Wire Line
	5300 950  5300 900 
Wire Wire Line
	8600 950  8600 900 
Wire Wire Line
	10250 950  10250 900 
Wire Wire Line
	10250 2600 10250 2550
Wire Wire Line
	8600 2600 8600 2550
Wire Wire Line
	5300 2600 5300 2550
Wire Wire Line
	6950 2600 6950 2550
Wire Wire Line
	2450 5350 2450 5300
$Comp
L power:GNDD #PWR0152
U 1 1 63B4D403
P 2300 3600
F 0 "#PWR0152" H 2300 3350 50  0001 C CNN
F 1 "GNDD" H 2304 3445 50  0000 C CNN
F 2 "" H 2300 3600 50  0001 C CNN
F 3 "" H 2300 3600 50  0001 C CNN
	1    2300 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 3600 2300 3550
$Comp
L power:GNDD #PWR0153
U 1 1 63B6EDBC
P 4000 2100
F 0 "#PWR0153" H 4000 1850 50  0001 C CNN
F 1 "GNDD" H 4004 1945 50  0000 C CNN
F 2 "" H 4000 2100 50  0001 C CNN
F 3 "" H 4000 2100 50  0001 C CNN
	1    4000 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 2100 4000 2050
$Comp
L power:GNDD #PWR0154
U 1 1 63B90A3D
P 5650 2100
F 0 "#PWR0154" H 5650 1850 50  0001 C CNN
F 1 "GNDD" H 5654 1945 50  0000 C CNN
F 2 "" H 5650 2100 50  0001 C CNN
F 3 "" H 5650 2100 50  0001 C CNN
	1    5650 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 2100 5650 2050
$Comp
L power:GNDD #PWR0155
U 1 1 63BB24A1
P 7300 2100
F 0 "#PWR0155" H 7300 1850 50  0001 C CNN
F 1 "GNDD" H 7304 1945 50  0000 C CNN
F 2 "" H 7300 2100 50  0001 C CNN
F 3 "" H 7300 2100 50  0001 C CNN
	1    7300 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 2100 7300 2050
$Comp
L power:GNDD #PWR0156
U 1 1 63BD419E
P 8950 2100
F 0 "#PWR0156" H 8950 1850 50  0001 C CNN
F 1 "GNDD" H 8954 1945 50  0000 C CNN
F 2 "" H 8950 2100 50  0001 C CNN
F 3 "" H 8950 2100 50  0001 C CNN
	1    8950 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 2100 8950 2050
$Comp
L power:GNDD #PWR0157
U 1 1 63BF5D31
P 8950 3750
F 0 "#PWR0157" H 8950 3500 50  0001 C CNN
F 1 "GNDD" H 8954 3595 50  0000 C CNN
F 2 "" H 8950 3750 50  0001 C CNN
F 3 "" H 8950 3750 50  0001 C CNN
	1    8950 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 3750 8950 3700
$Comp
L power:GNDD #PWR0158
U 1 1 63C17A13
P 7300 3750
F 0 "#PWR0158" H 7300 3500 50  0001 C CNN
F 1 "GNDD" H 7304 3595 50  0000 C CNN
F 2 "" H 7300 3750 50  0001 C CNN
F 3 "" H 7300 3750 50  0001 C CNN
	1    7300 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 3750 7300 3700
$Comp
L power:GNDD #PWR0159
U 1 1 63C39867
P 5650 3750
F 0 "#PWR0159" H 5650 3500 50  0001 C CNN
F 1 "GNDD" H 5654 3595 50  0000 C CNN
F 2 "" H 5650 3750 50  0001 C CNN
F 3 "" H 5650 3750 50  0001 C CNN
	1    5650 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 3750 5650 3700
$Comp
L power:GNDD #PWR0160
U 1 1 63C5B58B
P 4000 3750
F 0 "#PWR0160" H 4000 3500 50  0001 C CNN
F 1 "GNDD" H 4004 3595 50  0000 C CNN
F 2 "" H 4000 3750 50  0001 C CNN
F 3 "" H 4000 3750 50  0001 C CNN
	1    4000 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 3750 4000 3700
Wire Wire Line
	6750 950  6950 950 
Wire Wire Line
	6950 950  6950 900 
Text HLabel 1350 4300 0    50   BiDi ~ 0
D[0..7]
Text HLabel 1350 4450 0    50   Input ~ 0
bA[0..15]
Wire Wire Line
	1950 5950 1900 5950
Wire Wire Line
	1900 5950 1900 6500
Wire Wire Line
	1900 6500 950  6500
Text Label 950  6500 0    50   ~ 0
nOES
Text HLabel 1350 3950 0    50   Input ~ 0
nOES
Connection ~ 5300 2600
Wire Wire Line
	5300 2600 5450 2600
$Comp
L power:GNDD #PWR0170
U 1 1 640BF72B
P 5450 3000
F 0 "#PWR0170" H 5450 2750 50  0001 C CNN
F 1 "GNDD" H 5454 2845 50  0000 C CNN
F 2 "" H 5450 3000 50  0001 C CNN
F 3 "" H 5450 3000 50  0001 C CNN
	1    5450 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 2850 5450 3000
Wire Wire Line
	5450 2600 5450 2650
$Comp
L Device:C_Small C31
U 1 1 640BF723
P 5450 2750
F 0 "C31" V 5350 2700 50  0000 C CNN
F 1 "C_Small" V 5312 2750 50  0001 C CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 5450 2750 50  0001 C CNN
F 3 "~" H 5450 2750 50  0001 C CNN
	1    5450 2750
	-1   0    0    1   
$EndComp
Connection ~ 6950 2600
Wire Wire Line
	6950 2600 7100 2600
$Comp
L power:GNDD #PWR0169
U 1 1 6409A3E7
P 7100 3000
F 0 "#PWR0169" H 7100 2750 50  0001 C CNN
F 1 "GNDD" H 7104 2845 50  0000 C CNN
F 2 "" H 7100 3000 50  0001 C CNN
F 3 "" H 7100 3000 50  0001 C CNN
	1    7100 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 2850 7100 3000
Wire Wire Line
	7100 2600 7100 2650
$Comp
L Device:C_Small C22
U 1 1 6409A3DF
P 7100 2750
F 0 "C22" V 7000 2700 50  0000 C CNN
F 1 "C_Small" V 6962 2750 50  0001 C CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 7100 2750 50  0001 C CNN
F 3 "~" H 7100 2750 50  0001 C CNN
	1    7100 2750
	-1   0    0    1   
$EndComp
Text Label 6750 2900 0    50   ~ 0
BAS_A11
Text Label 6750 3000 0    50   ~ 0
BAS_OE5
Connection ~ 8600 2600
Wire Wire Line
	8600 2600 8750 2600
$Comp
L power:GNDD #PWR0168
U 1 1 64074E0F
P 8750 3000
F 0 "#PWR0168" H 8750 2750 50  0001 C CNN
F 1 "GNDD" H 8754 2845 50  0000 C CNN
F 2 "" H 8750 3000 50  0001 C CNN
F 3 "" H 8750 3000 50  0001 C CNN
	1    8750 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 2850 8750 3000
Wire Wire Line
	8750 2600 8750 2650
$Comp
L Device:C_Small C16
U 1 1 64074E07
P 8750 2750
F 0 "C16" V 8650 2700 50  0000 C CNN
F 1 "C_Small" V 8612 2750 50  0001 C CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 8750 2750 50  0001 C CNN
F 3 "~" H 8750 2750 50  0001 C CNN
	1    8750 2750
	-1   0    0    1   
$EndComp
Connection ~ 10250 2600
Wire Wire Line
	10250 2600 10400 2600
$Comp
L power:GNDD #PWR0167
U 1 1 640503C6
P 10400 3000
F 0 "#PWR0167" H 10400 2750 50  0001 C CNN
F 1 "GNDD" H 10404 2845 50  0000 C CNN
F 2 "" H 10400 3000 50  0001 C CNN
F 3 "" H 10400 3000 50  0001 C CNN
	1    10400 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	10400 2850 10400 3000
Wire Wire Line
	10400 2600 10400 2650
$Comp
L Device:C_Small C5
U 1 1 640503BE
P 10400 2750
F 0 "C5" V 10300 2700 50  0000 C CNN
F 1 "C_Small" V 10262 2750 50  0001 C CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 10400 2750 50  0001 C CNN
F 3 "~" H 10400 2750 50  0001 C CNN
	1    10400 2750
	-1   0    0    1   
$EndComp
Wire Wire Line
	10400 1200 10400 1350
$Comp
L power:GNDD #PWR0165
U 1 1 63F2B1E8
P 10400 1350
F 0 "#PWR0165" H 10400 1100 50  0001 C CNN
F 1 "GNDD" H 10404 1195 50  0000 C CNN
F 2 "" H 10400 1350 50  0001 C CNN
F 3 "" H 10400 1350 50  0001 C CNN
	1    10400 1350
	1    0    0    -1  
$EndComp
Connection ~ 10250 950 
Wire Wire Line
	10250 950  10400 950 
Wire Wire Line
	10400 950  10400 1000
$Comp
L Device:C_Small C35
U 1 1 63F2B1E0
P 10400 1100
F 0 "C35" V 10300 1050 50  0000 C CNN
F 1 "C_Small" V 10262 1100 50  0001 C CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 10400 1100 50  0001 C CNN
F 3 "~" H 10400 1100 50  0001 C CNN
	1    10400 1100
	-1   0    0    1   
$EndComp
Connection ~ 8600 950 
Wire Wire Line
	8600 950  8750 950 
$Comp
L power:GNDD #PWR0164
U 1 1 63EE25A9
P 8750 1350
F 0 "#PWR0164" H 8750 1100 50  0001 C CNN
F 1 "GNDD" H 8754 1195 50  0000 C CNN
F 2 "" H 8750 1350 50  0001 C CNN
F 3 "" H 8750 1350 50  0001 C CNN
	1    8750 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 1200 8750 1350
Wire Wire Line
	8750 950  8750 1000
$Comp
L Device:C_Small C38
U 1 1 63EE25A1
P 8750 1100
F 0 "C38" V 8650 1050 50  0000 C CNN
F 1 "100n" V 8612 1100 50  0001 C CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 8750 1100 50  0001 C CNN
F 3 "~" H 8750 1100 50  0001 C CNN
	1    8750 1100
	-1   0    0    1   
$EndComp
Connection ~ 6950 950 
Wire Wire Line
	6950 950  7100 950 
$Comp
L power:GNDD #PWR0162
U 1 1 63E523FB
P 7100 1350
F 0 "#PWR0162" H 7100 1100 50  0001 C CNN
F 1 "GNDD" H 7104 1195 50  0000 C CNN
F 2 "" H 7100 1350 50  0001 C CNN
F 3 "" H 7100 1350 50  0001 C CNN
	1    7100 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 1200 7100 1350
Wire Wire Line
	7100 950  7100 1000
$Comp
L Device:C_Small C40
U 1 1 63E523F3
P 7100 1100
F 0 "C40" V 7000 1050 50  0000 C CNN
F 1 "C_Small" V 6962 1100 50  0001 C CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 7100 1100 50  0001 C CNN
F 3 "~" H 7100 1100 50  0001 C CNN
	1    7100 1100
	-1   0    0    1   
$EndComp
Connection ~ 5300 950 
Wire Wire Line
	5450 950  5300 950 
$Comp
L power:GNDD #PWR0161
U 1 1 63D7E181
P 5450 1350
F 0 "#PWR0161" H 5450 1100 50  0001 C CNN
F 1 "GNDD" H 5454 1195 50  0000 C CNN
F 2 "" H 5450 1350 50  0001 C CNN
F 3 "" H 5450 1350 50  0001 C CNN
	1    5450 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 1200 5450 1350
Wire Wire Line
	5450 950  5450 1000
$Comp
L Device:C_Small C48
U 1 1 63CD1301
P 5450 1100
F 0 "C48" V 5350 1050 50  0000 C CNN
F 1 "C_Small" V 5312 1100 50  0001 C CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 5450 1100 50  0001 C CNN
F 3 "~" H 5450 1100 50  0001 C CNN
	1    5450 1100
	-1   0    0    1   
$EndComp
$Comp
L Memory_EPROM:27C128 U89
U 1 1 6B1917A2
P 2300 2450
F 0 "U89" H 2450 3500 50  0000 C CNN
F 1 "27C128" H 2500 1400 50  0000 C CNN
F 2 "Package_DIP:DIP-28_W15.24mm" H 2300 2450 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/devicedoc/11003L.pdf" H 2300 2450 50  0001 C CNN
	1    2300 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 1300 2300 1350
Wire Wire Line
	2700 1550 2950 1550
Wire Wire Line
	2700 1650 2950 1650
Wire Wire Line
	2700 1750 2950 1750
Wire Wire Line
	2700 1850 2950 1850
Wire Wire Line
	2700 1950 2950 1950
Wire Wire Line
	2700 2050 2950 2050
Wire Wire Line
	2700 2150 2950 2150
Wire Wire Line
	2700 2250 2950 2250
Wire Wire Line
	1900 1550 1650 1550
Wire Wire Line
	1900 1650 1650 1650
Wire Wire Line
	1900 1750 1650 1750
Wire Wire Line
	1900 1850 1650 1850
Wire Wire Line
	1900 1950 1650 1950
Wire Wire Line
	1900 2050 1650 2050
Wire Wire Line
	1900 2150 1650 2150
Wire Wire Line
	1900 2250 1650 2250
Wire Wire Line
	1900 2350 1650 2350
Wire Wire Line
	1900 2450 1650 2450
Wire Wire Line
	1900 2550 1650 2550
Wire Wire Line
	1900 2750 1650 2750
Wire Wire Line
	1900 3250 1650 3250
Wire Wire Line
	1900 3350 1650 3350
Text Label 1650 1550 0    50   ~ 0
bA0
Text Label 1650 1650 0    50   ~ 0
bA1
Text Label 1650 1750 0    50   ~ 0
bA2
Text Label 1650 1850 0    50   ~ 0
bA3
Text Label 1650 1950 0    50   ~ 0
bA4
Text Label 1650 2050 0    50   ~ 0
bA5
Text Label 1650 2150 0    50   ~ 0
bA6
Text Label 1650 2250 0    50   ~ 0
bA7
Text Label 1650 2350 0    50   ~ 0
bA8
Text Label 1650 2450 0    50   ~ 0
bA9
Text Label 1650 2550 0    50   ~ 0
bA10
Text Label 1450 2650 0    50   ~ 0
Boot_A11
Text Label 1650 2750 0    50   ~ 0
bA12
$Comp
L power:VCC #PWR0143
U 1 1 6BB17FBA
P 2300 1300
F 0 "#PWR0143" H 2300 1150 50  0001 C CNN
F 1 "VCC" H 2315 1473 50  0000 C CNN
F 2 "" H 2300 1300 50  0001 C CNN
F 3 "" H 2300 1300 50  0001 C CNN
	1    2300 1300
	1    0    0    -1  
$EndComp
Text Label 2850 1550 0    50   ~ 0
D0
Text Label 2850 1650 0    50   ~ 0
D1
Text Label 2850 1750 0    50   ~ 0
D2
Text Label 2850 1850 0    50   ~ 0
D3
Text Label 2850 1950 0    50   ~ 0
D4
Text Label 2850 2050 0    50   ~ 0
D5
Text Label 2850 2150 0    50   ~ 0
D6
Text Label 2850 2250 0    50   ~ 0
D7
$Comp
L power:VCC #PWR0144
U 1 1 6BD8DC49
P 5300 900
F 0 "#PWR0144" H 5300 750 50  0001 C CNN
F 1 "VCC" H 5315 1073 50  0000 C CNN
F 2 "" H 5300 900 50  0001 C CNN
F 3 "" H 5300 900 50  0001 C CNN
	1    5300 900 
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0145
U 1 1 6BD8E3AF
P 6950 900
F 0 "#PWR0145" H 6950 750 50  0001 C CNN
F 1 "VCC" H 6965 1073 50  0000 C CNN
F 2 "" H 6950 900 50  0001 C CNN
F 3 "" H 6950 900 50  0001 C CNN
	1    6950 900 
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0146
U 1 1 6BD8EBAE
P 8600 900
F 0 "#PWR0146" H 8600 750 50  0001 C CNN
F 1 "VCC" H 8615 1073 50  0000 C CNN
F 2 "" H 8600 900 50  0001 C CNN
F 3 "" H 8600 900 50  0001 C CNN
	1    8600 900 
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0147
U 1 1 6BD8F5F4
P 10250 900
F 0 "#PWR0147" H 10250 750 50  0001 C CNN
F 1 "VCC" H 10265 1073 50  0000 C CNN
F 2 "" H 10250 900 50  0001 C CNN
F 3 "" H 10250 900 50  0001 C CNN
	1    10250 900 
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0148
U 1 1 6BD8FF7D
P 5300 2550
F 0 "#PWR0148" H 5300 2400 50  0001 C CNN
F 1 "VCC" H 5315 2723 50  0000 C CNN
F 2 "" H 5300 2550 50  0001 C CNN
F 3 "" H 5300 2550 50  0001 C CNN
	1    5300 2550
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0149
U 1 1 6BD90911
P 6950 2550
F 0 "#PWR0149" H 6950 2400 50  0001 C CNN
F 1 "VCC" H 6965 2723 50  0000 C CNN
F 2 "" H 6950 2550 50  0001 C CNN
F 3 "" H 6950 2550 50  0001 C CNN
	1    6950 2550
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0150
U 1 1 6BD90EC0
P 8600 2550
F 0 "#PWR0150" H 8600 2400 50  0001 C CNN
F 1 "VCC" H 8615 2723 50  0000 C CNN
F 2 "" H 8600 2550 50  0001 C CNN
F 3 "" H 8600 2550 50  0001 C CNN
	1    8600 2550
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0151
U 1 1 6BD916DF
P 10250 2550
F 0 "#PWR0151" H 10250 2400 50  0001 C CNN
F 1 "VCC" H 10265 2723 50  0000 C CNN
F 2 "" H 10250 2550 50  0001 C CNN
F 3 "" H 10250 2550 50  0001 C CNN
	1    10250 2550
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0163
U 1 1 6BD92089
P 2450 5300
F 0 "#PWR0163" H 2450 5150 50  0001 C CNN
F 1 "VCC" H 2465 5473 50  0000 C CNN
F 2 "" H 2450 5300 50  0001 C CNN
F 3 "" H 2450 5300 50  0001 C CNN
	1    2450 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 3150 1600 3150
$Comp
L power:VCC #PWR0411
U 1 1 623ECAF2
P 1450 3150
F 0 "#PWR0411" H 1450 3000 50  0001 C CNN
F 1 "VCC" H 1465 3323 50  0000 C CNN
F 2 "" H 1450 3150 50  0001 C CNN
F 3 "" H 1450 3150 50  0001 C CNN
	1    1450 3150
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0140
U 1 1 623FFDD3
P 1250 5200
F 0 "#PWR0140" H 1250 5050 50  0001 C CNN
F 1 "VCC" H 1265 5373 50  0000 C CNN
F 2 "" H 1250 5200 50  0001 C CNN
F 3 "" H 1250 5200 50  0001 C CNN
	1    1250 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 2650 1900 2650
Wire Wire Line
	1600 2850 1600 3050
Wire Wire Line
	1600 2850 1900 2850
Connection ~ 1600 3150
Wire Wire Line
	1600 3150 1900 3150
Wire Wire Line
	1600 3050 1900 3050
Connection ~ 1600 3050
Wire Wire Line
	1600 3050 1600 3150
$EndSCHEMATC
