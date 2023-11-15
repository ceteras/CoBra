EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 13
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
L 74xx:74LS04 U53
U 2 1 626D2E45
P 1300 1000
F 0 "U53" H 1300 1317 50  0000 C CNN
F 1 "74LS04" H 1300 1226 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 1300 1000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS04" H 1300 1000 50  0001 C CNN
	2    1300 1000
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS04 U53
U 4 1 626D474E
P 1300 2100
F 0 "U53" H 1300 2417 50  0000 C CNN
F 1 "74LS04" H 1300 2326 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 1300 2100 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS04" H 1300 2100 50  0001 C CNN
	4    1300 2100
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS04 U53
U 5 1 626D5A86
P 1300 1550
F 0 "U53" H 1300 1867 50  0000 C CNN
F 1 "74LS04" H 1300 1776 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 1300 1550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS04" H 1300 1550 50  0001 C CNN
	5    1300 1550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS00 U54
U 2 1 626D9984
P 2600 1250
F 0 "U54" H 2600 1450 50  0000 C CNN
F 1 "74LS00" H 2600 1250 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 2600 1250 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74ls00" H 2600 1250 50  0001 C CNN
	2    2600 1250
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS00 U54
U 3 1 626DBF38
P 2600 1800
F 0 "U54" H 2600 2000 50  0000 C CNN
F 1 "74LS00" H 2600 1800 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 2600 1800 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74ls00" H 2600 1800 50  0001 C CNN
	3    2600 1800
	1    0    0    1   
$EndComp
Wire Wire Line
	2250 1700 2250 1550
Wire Wire Line
	2250 1350 2300 1350
Wire Wire Line
	1600 1550 2250 1550
Connection ~ 2250 1550
Wire Wire Line
	2250 1550 2250 1350
Wire Wire Line
	1600 1000 1700 1000
Wire Wire Line
	1700 1000 1700 1150
Wire Wire Line
	1700 1150 2300 1150
Wire Wire Line
	1600 2100 1700 2100
Wire Wire Line
	1700 2100 1700 1900
Wire Wire Line
	2900 1250 3450 1250
Wire Wire Line
	2900 1800 3450 1800
Wire Wire Line
	1000 1000 650  1000
Wire Wire Line
	1000 1550 650  1550
Wire Wire Line
	1000 2100 650  2100
Wire Wire Line
	1700 1000 1700 800 
Wire Wire Line
	1700 800  3450 800 
Connection ~ 1700 1000
Text Label 650  1000 0    50   ~ 0
bnRD
Text Label 650  1550 0    50   ~ 0
bnIORQ
Text Label 650  2100 0    50   ~ 0
bnWR
Text Label 3300 800  0    50   ~ 0
RD
Text Label 3200 1250 0    50   ~ 0
nIORD
Text Label 3200 1800 0    50   ~ 0
nIOWR
Wire Bus Line
	1100 3300 1050 3300
Text HLabel 1050 3300 0    50   Input ~ 0
PB[0..7]
Wire Bus Line
	1050 3400 1350 3400
Entry Wire Line
	1350 3400 1450 3500
Entry Wire Line
	1350 3500 1450 3600
Wire Wire Line
	1450 3500 1700 3500
Wire Wire Line
	1450 3600 1700 3600
Text Label 1550 3500 0    50   ~ 0
bA0
Text Label 1550 3600 0    50   ~ 0
bA5
Text HLabel 1050 3400 0    50   Input ~ 0
bA[0..15]
Wire Bus Line
	1350 3500 1350 3400
Text Label 1500 3750 0    50   ~ 0
bnRD
Text Label 1500 3850 0    50   ~ 0
bnWR
Text HLabel 1050 3950 0    50   Output ~ 0
nIORQ
Text HLabel 1050 3850 0    50   Input ~ 0
nWR
Text HLabel 1050 3750 0    50   Input ~ 0
bnRD
Text Label 1450 3950 0    50   ~ 0
bnIORQ
Wire Wire Line
	1050 3750 1700 3750
Wire Wire Line
	1050 3850 1700 3850
Wire Wire Line
	1050 3950 1700 3950
Text HLabel 3450 800  2    50   Output ~ 0
RD
Text HLabel 1050 4750 0    50   Input ~ 0
bA[0..15]
Wire Wire Line
	2250 1700 2300 1700
Wire Wire Line
	1700 1900 2300 1900
Text HLabel 1050 4050 0    50   Output ~ 0
O6
Text HLabel 1050 4650 0    50   Output ~ 0
POR
Text HLabel 1050 4150 0    50   Output ~ 0
LS
Text HLabel 1050 4250 0    50   Output ~ 0
SO
Text HLabel 1050 4450 0    50   Output ~ 0
nIORD
Text HLabel 1050 4550 0    50   Output ~ 0
nIOWR
Text HLabel 1050 4350 0    50   Input ~ 0
SI
$EndSCHEMATC
