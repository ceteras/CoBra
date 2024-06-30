EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 13
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 2950 900  1000 850 
U 61414750
F0 "Interface" 50
F1 "Interface.sch" 50
F2 "D[0..7]" B L 2950 950 50 
F3 "K[0..5]" I R 3950 1300 50 
F4 "PB[0..7]" O R 3950 1000 50 
F5 "bA[0..15]" I L 2950 1050 50 
F6 "nIORQ" I L 2950 1250 50 
F7 "nWR" I L 2950 1350 50 
F8 "nRD" I L 2950 1450 50 
F9 "RD" O R 3950 1700 50 
F10 "O6" O R 3950 1600 50 
F11 "POR" O R 3950 1100 50 
F12 "LS" O R 3950 1200 50 
F13 "bnRD" I L 2950 1550 50 
F14 "SO" O R 3950 1500 50 
F15 "nIORD" O L 2950 1650 50 
F16 "nIOWR" O L 2950 1150 50 
F17 "SI" I R 3950 1400 50 
$EndSheet
$Sheet
S 850  900  1100 2300
U 61413045
F0 "Z80_CPU" 50
F1 "Z80_CPU.sch" 50
F2 "CLK" I R 1950 1300 50 
F3 "D[0..7]" B R 1950 950 50 
F4 "bA[0..15]" O R 1950 1050 50 
F5 "nINT" I R 1950 2100 50 
F6 "nNMI" I R 1950 2200 50 
F7 "nCLK" O R 1950 2300 50 
F8 "nRST" I R 1950 2400 50 
F9 "bnIORQ" O R 1950 1400 50 
F10 "bnMREQ" O R 1950 1500 50 
F11 "bnWR" O R 1950 1600 50 
F12 "bnRD" O R 1950 1700 50 
F13 "nWAIT" I R 1950 2500 50 
F14 "bnRFSH" O R 1950 1900 50 
F15 "bnM1" O R 1950 2000 50 
F16 "Vbb" U R 1950 3100 50 
F17 "O6" I L 850 950 50 
F18 "POR" I L 850 1050 50 
F19 "nKBI" O R 1950 2600 50 
F20 "nIOWR" O R 1950 2700 50 
F21 "nVS" O R 1950 2800 50 
F22 "nIORD" O R 1950 1150 50 
F23 "TI" O L 850 1150 50 
F24 "TO" I L 850 1250 50 
F25 "SI" O L 850 1350 50 
F26 "SO" I L 850 1450 50 
F27 "STB" I L 850 1550 50 
F28 "LS" B L 850 1650 50 
F29 "Vcc" U L 850 1750 50 
F30 "B0" O L 850 1850 50 
F31 "B1" O L 850 1950 50 
F32 "B2" O L 850 2050 50 
F33 "DIF" O L 850 2150 50 
$EndSheet
Wire Wire Line
	1950 1400 2300 1400
Wire Wire Line
	2650 1250 2950 1250
Wire Wire Line
	1950 1600 2300 1600
Wire Wire Line
	2650 1350 2950 1350
Wire Wire Line
	1950 1700 2300 1700
$Sheet
S 4950 900  900  2200
U 6286979D
F0 "config_selection" 50
F1 "config_selection.sch" 50
F2 "nPO" I L 4950 2000 50 
F3 "bA[0..15]" I L 4950 1100 50 
F4 "bnM1" I L 4950 1300 50 
F5 "bnRFSH" I L 4950 1400 50 
F6 "bnMREQ" I L 4950 1500 50 
F7 "nCS[0..3]" I R 5850 950 50 
F8 "CS1" O R 5850 1050 50 
F9 "nOEB" O R 5850 1150 50 
F10 "nOES" O R 5850 1250 50 
F11 "HS" I R 5850 1350 50 
F12 "HB" I R 5850 1450 50 
F13 "nHB" I R 5850 1550 50 
F14 "HLD" I R 5850 1650 50 
F15 "nHLD" I R 5850 1750 50 
F16 "VLD" I R 5850 1850 50 
F17 "nVLD" I R 5850 1950 50 
F18 "SCR" I R 5850 2050 50 
F19 "nSCR" I R 5850 2150 50 
F20 "nKBI" I R 5850 2250 50 
F21 "nRST" I R 5850 2350 50 
F22 "nVS" I R 5850 2450 50 
F23 "POR" I R 5850 2550 50 
F24 "AC[0..7]" I R 5850 2650 50 
F25 "AR[0..2]" I R 5850 2750 50 
F26 "AT[0..2]" I R 5850 2850 50 
F27 "nVMA" I R 5850 2950 50 
F28 "nS" O R 5850 3050 50 
F29 "O6" O L 4950 1600 50 
F30 "bnRD" I L 4950 1200 50 
$EndSheet
$Sheet
S 2950 2000 1000 800 
U 6301C001
F0 "ROM" 50
F1 "ROM.sch" 50
F2 "nPO" O R 3950 2150 50 
F3 "D[0..7]" B L 2950 2150 50 
F4 "bA[0..15]" I L 2950 2250 50 
F5 "nOES" I L 2950 2400 50 
$EndSheet
Wire Bus Line
	2950 2250 2600 2250
Wire Wire Line
	4950 2000 4800 2000
Wire Bus Line
	4950 1100 4600 1100
Wire Wire Line
	1950 2000 2700 2000
Wire Wire Line
	2700 2000 2700 1900
Wire Wire Line
	2700 1900 4450 1900
Wire Wire Line
	4450 1300 4950 1300
Wire Wire Line
	4600 1500 4950 1500
Wire Wire Line
	1950 1900 2300 1900
Wire Wire Line
	4800 2150 3950 2150
Wire Wire Line
	4800 2000 4800 2150
Wire Wire Line
	2950 2400 2600 2400
Text Label 2600 2400 0    50   ~ 0
nOES
Wire Wire Line
	5850 1250 6100 1250
Text Label 5900 1250 0    50   ~ 0
nOES
$Sheet
S 900  3750 1050 900 
U 641BF61E
F0 "RAM_48" 50
F1 "RAM_48.sch" 50
F2 "bA[0..15]" I R 1950 3900 50 
F3 "RD" I R 1950 4000 50 
F4 "D[0..7]" B R 1950 4100 50 
F5 "nS" I R 1950 4200 50 
F6 "bnMREQ" I R 1950 4300 50 
F7 "nCS[0..3]" I R 1950 4400 50 
F8 "Vbb" U R 1950 4550 50 
$EndSheet
Wire Wire Line
	3950 1700 4100 1700
Wire Wire Line
	1950 4300 2300 4300
Wire Bus Line
	1950 4400 2350 4400
Wire Bus Line
	6250 950  5850 950 
$Sheet
S 2950 3200 1200 650 
U 660BA801
F0 "Memory_arbiter_cmd" 50
F1 "Memory_arbiter_cmd.sch" 50
F2 "CLK" O L 2950 3350 50 
F3 "nQD" O R 4150 3300 50 
F4 "VNCS" O R 4150 3750 50 
F5 "VNRS" O R 4150 3650 50 
F6 "AV10" O R 4150 3550 50 
F7 "SCLK" O L 2950 3400 50 
F8 "SLD" O L 2950 3500 50 
F9 "SM" O R 4150 3400 50 
F10 "QB" O L 2950 3600 50 
F11 "bnRD" O L 2950 3700 50 
F12 "nCS1" I L 2950 3800 50 
F13 "STB" O R 4150 3800 50 
F14 "nVMA" O R 4150 3500 50 
F15 "AL2" I R 4150 3250 50 
F16 "VNW" O L 2950 3250 50 
F17 "S0" O L 2950 3450 50 
$EndSheet
Wire Wire Line
	2100 4000 1950 4000
Wire Wire Line
	2950 3350 2800 3350
$Sheet
S 7000 1550 1100 800 
U 665A1D5B
F0 "Video_address_gen" 50
F1 "Video_address_gen.sch" 50
F2 "AC[0..7]" O R 8100 1650 50 
F3 "AL[0..2]" O R 8100 1750 50 
F4 "AR[0..2]" O R 8100 1850 50 
F5 "AT[0..2]" O R 8100 1950 50 
F6 "nQD" I L 7000 2300 50 
F7 "VLD" I L 7000 1850 50 
F8 "nVLD" I L 7000 1950 50 
F9 "HLD" I L 7000 1750 50 
F10 "SCR" I L 7000 2050 50 
F11 "nHLD" I L 7000 1650 50 
F12 "HB" I R 8100 2050 50 
$EndSheet
Wire Bus Line
	8100 1650 8450 1650
Wire Bus Line
	8100 1850 8450 1850
Wire Bus Line
	8100 1950 8450 1950
Wire Wire Line
	5850 1950 7000 1950
Wire Wire Line
	5850 1850 7000 1850
Wire Wire Line
	5850 2050 7000 2050
Wire Wire Line
	4150 3300 6300 3300
Wire Wire Line
	6300 3300 6300 2300
Wire Wire Line
	6300 2300 7000 2300
$Sheet
S 6950 3050 1150 800 
U 666752BF
F0 "Mux_video_address" 50
F1 "Mux_video_address.sch" 50
F2 "VA[0..6]" O R 8100 3200 50 
F3 "bA[0..15]" I L 6950 3250 50 
F4 "AC[0..7]" I L 6950 3350 50 
F5 "AR[0..2]" I L 6950 3450 50 
F6 "AL[0..2]" I L 6950 3550 50 
F7 "AT[0..1]" I L 6950 3650 50 
F8 "AV10" I L 6950 3800 50 
F9 "QB" I R 8100 3100 50 
F10 "STB" I L 6950 3150 50 
F11 "S0" I L 6950 3750 50 
$EndSheet
Wire Bus Line
	6600 3250 6950 3250
Wire Bus Line
	6600 3350 6950 3350
Wire Bus Line
	6950 3450 6600 3450
Wire Bus Line
	8100 1750 8450 1750
Wire Bus Line
	6600 3550 6950 3550
Wire Bus Line
	6950 3650 6600 3650
$Sheet
S 8450 3050 1300 750 
U 6673B7F1
F0 "Video_memory" 50
F1 "Video_memory.sch" 50
F2 "VA[0..6]" I L 8450 3200 50 
F3 "D[0..7]" B L 8450 3300 50 
F4 "VNW" I L 8450 3400 50 
F5 "VNRS" I L 8450 3500 50 
F6 "VNCS" I L 8450 3600 50 
F7 "VD[0..7]" O R 9750 3150 50 
F8 "Vbb" U R 9750 3700 50 
F9 "CS1" I R 9750 3600 50 
F10 "bnRD" I R 9750 3500 50 
F11 "STB" I L 8450 3700 50 
$EndSheet
Wire Bus Line
	8100 3200 8450 3200
Wire Bus Line
	8150 3300 8450 3300
Wire Wire Line
	4150 3750 6150 3750
Wire Wire Line
	6150 3750 6150 4050
Wire Wire Line
	6150 4050 8200 4050
Wire Wire Line
	8200 4050 8200 3600
Wire Wire Line
	8200 3600 8450 3600
Wire Wire Line
	4150 3650 6250 3650
Wire Wire Line
	6250 3650 6250 4000
Wire Wire Line
	8150 4000 8150 3500
Wire Wire Line
	8150 3500 8450 3500
Wire Wire Line
	6250 4000 8150 4000
Wire Wire Line
	4150 3550 6500 3550
Wire Wire Line
	6500 3550 6500 3800
Wire Wire Line
	6500 3800 6950 3800
$Sheet
S 8700 1350 1050 1300
U 67342299
F0 "video_generator" 50
F1 "video_generator.sch" 50
F2 "nVS" I R 9750 1450 50 
F3 "VD[0..7]" I R 9750 2550 50 
F4 "SCLK" I R 9750 1600 50 
F5 "SLD" I R 9750 1750 50 
F6 "VNY" O R 9750 1900 50 
F7 "I" O R 9750 2000 50 
F8 "SM" I L 8700 2600 50 
F9 "R" O R 9750 2100 50 
F10 "G" O R 9750 2200 50 
F11 "B" O R 9750 2300 50 
F12 "nHB" I R 9750 2400 50 
F13 "VVS" O L 8700 1400 50 
F14 "B0" I L 8700 2300 50 
F15 "B1" I L 8700 2400 50 
F16 "B2" I L 8700 2500 50 
$EndSheet
$Sheet
S 900  4950 1050 750 
U 6AD1FB49
F0 "voltage-level-adapters" 50
F1 "voltage-level-adapters.sch" 50
F2 "TI" O R 1950 5050 50 
F3 "TO" I R 1950 5150 50 
F4 "SI" O R 1950 5250 50 
F5 "SO" I R 1950 5350 50 
F6 "STB" I R 1950 5450 50 
F7 "LS" B R 1950 5550 50 
F8 "Vcc" U R 1950 5650 50 
$EndSheet
$Sheet
S 5050 4700 1250 750 
U 6AE0AB9C
F0 "monitor" 50
F1 "monitor.sch" 50
F2 "HS" I L 5050 4800 50 
F3 "nVS" I L 5050 4900 50 
F4 "R" I L 5050 5000 50 
F5 "G" I L 5050 5100 50 
F6 "B" I L 5050 5200 50 
F7 "I" I L 5050 5300 50 
F8 "VVS" I L 5050 5400 50 
F9 "VVM" O R 6300 4800 50 
F10 "Vc" O R 6300 4900 50 
F11 "VNY" I R 6300 5400 50 
$EndSheet
Wire Bus Line
	9750 3150 9850 3150
Wire Bus Line
	9850 3150 9850 2550
Wire Bus Line
	9850 2550 9750 2550
Wire Wire Line
	9950 1450 9750 1450
Wire Wire Line
	2950 3500 2650 3500
Wire Wire Line
	2650 3500 2650 3950
Wire Wire Line
	2650 3950 6100 3950
Wire Wire Line
	6100 3950 6100 4150
Wire Wire Line
	6100 4150 10050 4150
Wire Wire Line
	10050 4150 10050 1750
Wire Wire Line
	10050 1750 9750 1750
Wire Wire Line
	9750 1600 10100 1600
Wire Wire Line
	10100 1600 10100 4250
Wire Wire Line
	2600 4250 2600 3400
Wire Wire Line
	2600 3400 2950 3400
Wire Wire Line
	2600 4250 10100 4250
Wire Wire Line
	4150 3400 6450 3400
Wire Wire Line
	6450 3400 6450 2600
Wire Wire Line
	6450 2600 8700 2600
Text Label 2000 950  0    50   ~ 0
D[0..7]
Text Label 2650 950  0    50   ~ 0
D[0..7]
Text Label 2650 2150 0    50   ~ 0
D[0..7]
Wire Bus Line
	2600 2150 2950 2150
Wire Bus Line
	2650 950  2950 950 
Text Label 1950 1050 0    50   ~ 0
bA[0..15]
Text Label 2000 3900 0    50   ~ 0
bA[0..15]
Wire Bus Line
	1950 3900 2350 3900
Wire Bus Line
	1950 1050 2300 1050
Text Label 2000 4100 0    50   ~ 0
D[0..7]
Wire Bus Line
	1950 4100 2300 4100
Wire Bus Line
	1950 950  2250 950 
Text Label 8150 3300 0    50   ~ 0
D[0..7]
Text Label 4600 1100 0    50   ~ 0
bA[0..15]
Wire Bus Line
	2600 1050 2950 1050
Text Label 2600 2250 0    50   ~ 0
bA[0..15]
Text Label 2600 1050 0    50   ~ 0
bA[0..15]
Text Label 4000 1300 0    50   ~ 0
K[0..5]
Text Label 2000 1300 0    50   ~ 0
CLK
Text Label 2800 3350 0    50   ~ 0
CLK
Text Label 2000 1500 0    50   ~ 0
bnMREQ
Text Label 2000 4300 0    50   ~ 0
bnMREQ
Wire Wire Line
	1950 1500 2300 1500
Text Label 2000 1900 0    50   ~ 0
bnRFSH
Wire Wire Line
	4600 1400 4950 1400
Wire Wire Line
	4450 1900 4450 1300
Text Label 4600 1400 0    50   ~ 0
bnRFSH
Text Label 4600 1500 0    50   ~ 0
bnMREQ
Text Label 2000 1600 0    50   ~ 0
bnWR
Text Label 2000 1700 0    50   ~ 0
bnRD
Text Label 4000 1700 0    50   ~ 0
RD
Text Label 2000 4000 0    50   ~ 0
RD
Text Label 6000 3050 0    50   ~ 0
nS
Text Label 2000 4200 0    50   ~ 0
nS
Wire Wire Line
	1950 4200 2100 4200
Text Label 2000 4400 0    50   ~ 0
nCS[0..3]
Text Label 5900 950  0    50   ~ 0
nCS[0..3]
Text Label 5950 2450 0    50   ~ 0
nVS
Text Label 9800 1450 0    50   ~ 0
nVS
Wire Wire Line
	5850 2450 6100 2450
Text Label 8150 1650 0    50   ~ 0
AC[0..7]
Text Label 8150 1750 0    50   ~ 0
AL[0..2]
Text Label 8150 1850 0    50   ~ 0
AR[0..2]
Text Label 8150 1950 0    50   ~ 0
AT[0..2]
Text Label 5900 2650 0    50   ~ 0
AC[0..7]
Text Label 5900 2750 0    50   ~ 0
AR[0..2]
Text Label 5900 2850 0    50   ~ 0
AT[0..2]
Text Label 6600 3650 0    50   ~ 0
AT[0..2]
Wire Bus Line
	5850 2850 6200 2850
Text Label 6600 3550 0    50   ~ 0
AL[0..2]
Text Label 6600 3450 0    50   ~ 0
AR[0..2]
Wire Bus Line
	5850 2750 6200 2750
Text Label 6600 3350 0    50   ~ 0
AC[0..7]
Wire Bus Line
	5850 2650 6200 2650
Text Label 6600 3250 0    50   ~ 0
bA[0..15]
Text Label 9900 2100 0    50   ~ 0
R
Text Label 9900 2200 0    50   ~ 0
G
Text Label 9900 2300 0    50   ~ 0
B
Wire Wire Line
	5050 5000 4800 5000
Wire Wire Line
	5050 5100 4800 5100
Wire Wire Line
	5050 5200 4800 5200
Wire Wire Line
	5050 5300 4800 5300
Text Label 4800 5000 0    50   ~ 0
R
Text Label 4800 5100 0    50   ~ 0
G
Text Label 4800 5200 0    50   ~ 0
B
Text Label 4800 5300 0    50   ~ 0
I
Wire Wire Line
	1950 3100 2150 3100
Text Label 2000 3100 0    50   ~ 0
Vbb
Text Label 9850 3700 0    50   ~ 0
Vbb
Wire Wire Line
	1950 4550 2350 4550
Text Label 2200 4550 0    50   ~ 0
Vbb
Wire Wire Line
	5850 1750 6650 1750
Wire Wire Line
	6650 1750 6650 1650
Wire Wire Line
	6650 1650 7000 1650
Wire Wire Line
	3950 1600 4100 1600
Text Label 4000 1600 0    50   ~ 0
O6
Wire Wire Line
	4950 1600 4600 1600
Text Label 4600 1600 0    50   ~ 0
O6
Wire Wire Line
	850  950  650  950 
Text Label 650  950  0    50   ~ 0
O6
Text Label 9850 3600 0    50   ~ 0
CS1
Wire Wire Line
	5850 1050 6250 1050
Text Label 6050 1050 0    50   ~ 0
CS1
Wire Wire Line
	8100 3100 8250 3100
Text Label 8150 3100 0    50   ~ 0
QB
Wire Wire Line
	2950 3600 2800 3600
Text Label 2800 3600 0    50   ~ 0
QB
Wire Wire Line
	8100 2050 8450 2050
Text Label 8350 2050 0    50   ~ 0
HB
Wire Wire Line
	5850 1450 6100 1450
Wire Wire Line
	5850 1550 6100 1550
Wire Wire Line
	5850 1650 6100 1650
Wire Wire Line
	5850 1350 6100 1350
Wire Wire Line
	5850 1150 6100 1150
Text Label 5900 1150 0    50   ~ 0
nOEB
Text Label 6000 1350 0    50   ~ 0
HS
Text Label 6000 1450 0    50   ~ 0
HB
Text Label 5950 1550 0    50   ~ 0
nHB
Text Label 5950 1650 0    50   ~ 0
HLD
Wire Wire Line
	5850 2150 6100 2150
Wire Wire Line
	5850 2250 6100 2250
Wire Wire Line
	5850 2350 6100 2350
Wire Wire Line
	5850 2550 6100 2550
Text Label 5900 2150 0    50   ~ 0
nSCR
Text Label 5900 2250 0    50   ~ 0
nKBI
Text Label 5900 2350 0    50   ~ 0
nRST
Text Label 5900 2550 0    50   ~ 0
POR
Wire Wire Line
	5850 2950 6100 2950
Wire Wire Line
	5850 3050 6100 3050
Text Label 5900 2950 0    50   ~ 0
nVMA
Wire Wire Line
	850  1050 650  1050
Text Label 650  1050 0    50   ~ 0
POR
Wire Wire Line
	1950 2100 2300 2100
Wire Wire Line
	1950 2200 2300 2200
Wire Wire Line
	1950 2300 2300 2300
Wire Wire Line
	1950 2400 2300 2400
Wire Wire Line
	1950 2500 2300 2500
Text Label 2050 2100 0    50   ~ 0
nINT
Text Label 2050 2200 0    50   ~ 0
nNMI
Text Label 2050 2300 0    50   ~ 0
nCLK
Text Label 2050 2400 0    50   ~ 0
nRST
Text Label 2050 2500 0    50   ~ 0
nWAIT
Wire Wire Line
	1950 2600 2300 2600
Text Label 2050 2600 0    50   ~ 0
nKBI
Wire Wire Line
	1950 2700 2300 2700
Text Label 2050 2700 0    50   ~ 0
nIOWR
Wire Wire Line
	3950 1100 4250 1100
Text Label 4100 1100 0    50   ~ 0
POR
Wire Wire Line
	3950 1200 4250 1200
Text Label 4150 1200 0    50   ~ 0
LS
Wire Wire Line
	1950 5550 2250 5550
Text Label 2150 5550 0    50   ~ 0
LS
Text Label 2650 1550 0    50   ~ 0
bnRD
Wire Wire Line
	9750 3500 10000 3500
Text Label 9800 3500 0    50   ~ 0
bnRD
Wire Wire Line
	9750 2400 9950 2400
Text Label 9800 2400 0    50   ~ 0
nHB
Wire Wire Line
	3950 1500 4100 1500
Text Label 4000 1500 0    50   ~ 0
SO
Wire Wire Line
	1950 5350 2250 5350
Text Label 2150 5350 0    50   ~ 0
SO
Wire Wire Line
	5050 4900 4800 4900
Text Label 4800 4900 0    50   ~ 0
nVS
Text Label 4250 3300 0    50   ~ 0
nQD
Text Label 2750 3700 0    50   ~ 0
bnRD
Wire Wire Line
	2750 3700 2950 3700
Wire Wire Line
	1950 2800 2300 2800
Text Label 2150 2800 0    50   ~ 0
nVS
Text Label 2000 1150 0    50   ~ 0
nIORD
Wire Wire Line
	1950 1150 2300 1150
Text Label 2650 1650 0    50   ~ 0
nIORD
Wire Wire Line
	2950 1150 2650 1150
Text Label 2650 1150 0    50   ~ 0
nIOWR
Text Label 2000 1400 0    50   ~ 0
bnIORQ
Text Label 2650 1250 0    50   ~ 0
bnIORQ
Text Label 2650 1350 0    50   ~ 0
bnWR
Text Label 2050 2000 0    50   ~ 0
bnM1
Text Label 4600 1300 0    50   ~ 0
bnM1
Wire Wire Line
	1950 5050 2250 5050
Wire Wire Line
	1950 5150 2250 5150
Wire Wire Line
	1950 5250 2250 5250
Wire Wire Line
	1950 5450 2250 5450
Wire Wire Line
	1950 5650 2250 5650
Text Label 2100 5650 0    50   ~ 0
Vcc
Text Label 2100 5450 0    50   ~ 0
STB
Text Label 2150 5250 0    50   ~ 0
SI
Text Label 2150 5050 0    50   ~ 0
TI
Text Label 2150 5150 0    50   ~ 0
TO
Wire Wire Line
	6300 4800 6550 4800
Wire Wire Line
	6300 4900 6550 4900
Text Label 6450 4900 0    50   ~ 0
Vc
Text Label 6400 4800 0    50   ~ 0
VVM
Wire Wire Line
	5050 5400 4800 5400
Wire Wire Line
	5050 4800 4800 4800
Text Label 4800 4800 0    50   ~ 0
HS
Text Label 4800 5400 0    50   ~ 0
VVS
Wire Wire Line
	8450 3400 8150 3400
Text Label 8150 3400 0    50   ~ 0
VNW
Text Label 8150 3500 0    50   ~ 0
VNRS
Text Label 8200 3600 0    50   ~ 0
VNCS
Wire Wire Line
	9750 3600 10000 3600
Wire Wire Line
	9750 3700 10000 3700
Wire Wire Line
	9750 1900 9950 1900
Wire Wire Line
	9750 2000 9950 2000
Text Label 9900 2000 0    50   ~ 0
I
Text Label 9800 1900 0    50   ~ 0
VNY
Wire Wire Line
	9750 2100 9950 2100
Wire Wire Line
	9750 2200 9950 2200
Wire Wire Line
	9750 2300 9950 2300
Text Label 9800 1600 0    50   ~ 0
SCLK
Text Label 9800 1750 0    50   ~ 0
SLD
Text Label 4250 3400 0    50   ~ 0
SM
Text Label 6800 2300 0    50   ~ 0
nQD
Text Label 8550 2600 0    50   ~ 0
SM
Wire Bus Line
	3950 1000 4250 1000
Text Label 3950 1000 0    50   ~ 0
PB[0..7]
Wire Wire Line
	2950 1450 2650 1450
Text Label 2650 1450 0    50   ~ 0
nRD
Wire Wire Line
	2650 1550 2950 1550
Wire Wire Line
	2650 1650 2950 1650
Wire Wire Line
	1950 1300 2300 1300
Wire Wire Line
	6300 5400 6550 5400
Text Label 6400 5400 0    50   ~ 0
VNY
Wire Bus Line
	3950 1300 4250 1300
Wire Wire Line
	3950 1400 4100 1400
Text Label 4000 1400 0    50   ~ 0
SI
Wire Wire Line
	2950 3800 2750 3800
Text Label 2750 3800 0    50   ~ 0
nCS1
Wire Wire Line
	6950 3150 6600 3150
Text Label 6600 3150 0    50   ~ 0
STB
Wire Wire Line
	4150 3800 4350 3800
Text Label 4350 3850 0    50   ~ 0
STB
Wire Wire Line
	4150 3500 4400 3500
Text Label 4200 3500 0    50   ~ 0
nVMA
Wire Wire Line
	4950 1200 4600 1200
Text Label 4600 1200 0    50   ~ 0
bnRD
Wire Wire Line
	4150 3250 4200 3250
Wire Wire Line
	4200 3250 4200 3150
Wire Wire Line
	4200 3150 4400 3150
Text Label 4250 3150 0    50   ~ 0
AL2
Wire Wire Line
	8700 1400 8450 1400
Text Label 8450 1400 0    50   ~ 0
VVS
Wire Wire Line
	2950 3250 2800 3250
Text Label 2800 3250 0    50   ~ 0
VNW
Wire Wire Line
	4350 3800 4350 3850
Wire Wire Line
	4500 3850 4350 3850
Wire Wire Line
	8450 3700 8250 3700
Text Label 8250 3700 0    50   ~ 0
STB
Wire Wire Line
	2950 3450 2800 3450
Text Label 2800 3450 0    50   ~ 0
S0
Wire Wire Line
	6950 3750 6800 3750
Text Label 6800 3750 0    50   ~ 0
S0
Wire Wire Line
	8700 2500 8500 2500
Wire Wire Line
	8700 2400 8500 2400
Wire Wire Line
	8700 2300 8500 2300
Text Label 8500 2300 0    50   ~ 0
B0
Text Label 8500 2400 0    50   ~ 0
B1
Text Label 8500 2500 0    50   ~ 0
B2
Wire Wire Line
	850  1850 700  1850
Wire Wire Line
	850  1950 700  1950
Wire Wire Line
	850  2050 700  2050
Text Label 700  1850 0    50   ~ 0
B0
Text Label 700  1950 0    50   ~ 0
B1
Text Label 700  2050 0    50   ~ 0
B2
$EndSCHEMATC
