EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L power:GND #PWR0101
U 1 1 5FB63D97
P 5400 3350
F 0 "#PWR0101" H 5400 3100 50  0001 C CNN
F 1 "GND" H 5405 3177 50  0000 C CNN
F 2 "" H 5400 3350 50  0001 C CNN
F 3 "" H 5400 3350 50  0001 C CNN
	1    5400 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 2050 6500 2050
Text Label 6500 2050 2    50   ~ 0
VCC_EXT
$Comp
L Connector_Generic:Conn_02x14_Odd_Even J1
U 1 1 5FB64E05
P 3450 2550
F 0 "J1" H 3500 3367 50  0000 C CNN
F 1 "Adapter" H 3500 3276 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x14_P2.54mm_Vertical" H 3450 2550 50  0001 C CNN
F 3 "~" H 3450 2550 50  0001 C CNN
	1    3450 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 2150 2900 2150
Wire Wire Line
	3250 2250 2900 2250
Wire Wire Line
	3250 2350 2900 2350
Wire Wire Line
	3250 2450 2900 2450
Wire Wire Line
	3250 2550 2900 2550
Wire Wire Line
	3250 2650 2900 2650
Wire Wire Line
	3250 2750 2900 2750
Wire Wire Line
	3250 2850 2900 2850
Wire Wire Line
	3250 2950 2900 2950
Wire Wire Line
	3250 3050 2900 3050
Wire Wire Line
	3250 3150 2900 3150
Wire Wire Line
	3250 3250 2900 3250
Wire Wire Line
	4100 1950 3750 1950
Wire Wire Line
	3750 2250 4100 2250
Wire Wire Line
	3750 2350 4100 2350
Wire Wire Line
	3750 2450 4100 2450
Wire Wire Line
	3750 2550 4100 2550
Wire Wire Line
	3750 2650 4100 2650
Wire Wire Line
	3750 2750 4100 2750
Wire Wire Line
	3750 2850 4100 2850
Wire Wire Line
	3750 2950 4100 2950
Wire Wire Line
	3750 3050 4100 3050
Wire Wire Line
	3750 3150 4100 3150
Wire Wire Line
	3750 3250 4100 3250
Wire Wire Line
	5600 2750 5150 2750
Wire Wire Line
	5600 2650 5150 2650
Wire Wire Line
	5600 2550 5150 2550
Wire Wire Line
	5600 2450 5150 2450
Wire Wire Line
	5600 2350 5150 2350
Wire Wire Line
	5600 2250 5150 2250
$Comp
L power:GND #PWR0102
U 1 1 5FB81CDA
P 2900 3400
F 0 "#PWR0102" H 2900 3150 50  0001 C CNN
F 1 "GND" H 2905 3227 50  0000 C CNN
F 2 "" H 2900 3400 50  0001 C CNN
F 3 "" H 2900 3400 50  0001 C CNN
	1    2900 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 3250 2900 3400
Text Label 4100 1950 2    50   ~ 0
VCC_EXT
Text Label 2900 1950 0    50   ~ 0
A15
Text Label 2900 2050 0    50   ~ 0
A12
Text Label 2900 2150 0    50   ~ 0
A7
Text Label 2900 2250 0    50   ~ 0
A6
Text Label 2900 2350 0    50   ~ 0
A5
Text Label 2900 2450 0    50   ~ 0
A4
Text Label 2900 2550 0    50   ~ 0
A3
Text Label 2900 2650 0    50   ~ 0
A2
Text Label 2900 2750 0    50   ~ 0
A1
Text Label 2900 2850 0    50   ~ 0
A0
Text Label 2900 2950 0    50   ~ 0
D0
Text Label 2900 3050 0    50   ~ 0
D1
Text Label 2900 3150 0    50   ~ 0
D2
Text Label 4100 2050 2    50   ~ 0
A14
Text Label 4100 2150 2    50   ~ 0
A13
Text Label 4100 2250 2    50   ~ 0
A8
Text Label 4100 2350 2    50   ~ 0
A9
Text Label 4100 2450 2    50   ~ 0
A11
Text Label 4100 2550 2    50   ~ 0
~OE
Text Label 4100 2650 2    50   ~ 0
A10
Text Label 4100 2750 2    50   ~ 0
~CE
Text Label 4100 2850 2    50   ~ 0
D7
Text Label 4100 2950 2    50   ~ 0
D6
Text Label 4100 3050 2    50   ~ 0
D5
Text Label 4100 3150 2    50   ~ 0
D4
Text Label 4100 3250 2    50   ~ 0
D3
Text Label 5150 2750 0    50   ~ 0
A0
Text Label 5150 2650 0    50   ~ 0
A1
Text Label 5150 2550 0    50   ~ 0
A2
Text Label 5150 2450 0    50   ~ 0
A3
Text Label 5150 2350 0    50   ~ 0
A4
Text Label 5150 2250 0    50   ~ 0
A5
Text Label 5150 2050 0    50   ~ 0
A7
Text Label 6500 2150 2    50   ~ 0
A8
Text Label 6500 2250 2    50   ~ 0
A9
Text Label 6500 2550 2    50   ~ 0
A10
Text Label 6500 2350 2    50   ~ 0
A11
Text Label 5150 2850 0    50   ~ 0
D0
Text Label 5150 2950 0    50   ~ 0
D1
Text Label 5150 3050 0    50   ~ 0
D2
Text Label 6500 3150 2    50   ~ 0
D3
Text Label 6500 3050 2    50   ~ 0
D4
Text Label 6500 2950 2    50   ~ 0
D5
Text Label 6500 2850 2    50   ~ 0
D6
Text Label 6500 2750 2    50   ~ 0
D7
Text Label 6500 2650 2    50   ~ 0
~CE
Text Label 6500 2450 2    50   ~ 0
~OE
Wire Wire Line
	2650 1950 2650 2050
Wire Wire Line
	2650 3250 2900 3250
Wire Wire Line
	2650 1950 3250 1950
Connection ~ 2900 3250
$Comp
L power:GND #PWR0103
U 1 1 5FBA74B2
P 4250 3400
F 0 "#PWR0103" H 4250 3150 50  0001 C CNN
F 1 "GND" H 4255 3227 50  0000 C CNN
F 2 "" H 4250 3400 50  0001 C CNN
F 3 "" H 4250 3400 50  0001 C CNN
	1    4250 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 2150 4250 3400
Wire Wire Line
	3750 2150 4250 2150
Wire Wire Line
	4250 2050 4250 2150
Wire Wire Line
	3750 2050 4250 2050
Connection ~ 4250 2150
$Comp
L Connector_Generic:Conn_02x12_Counter_Clockwise U1
U 1 1 5FBAE2DA
P 5800 2550
F 0 "U1" H 5850 3267 50  0000 C CNN
F 1 "2732" H 5850 3176 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W15.24mm" H 5800 2550 50  0001 C CNN
F 3 "~" H 5800 2550 50  0001 C CNN
	1    5800 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 3150 5400 3150
Wire Wire Line
	5400 3150 5400 3350
Wire Wire Line
	5600 2050 5150 2050
Text Label 5150 2150 0    50   ~ 0
A6
Wire Wire Line
	5600 2150 5150 2150
Wire Wire Line
	5600 2850 5150 2850
Wire Wire Line
	5600 2950 5150 2950
Wire Wire Line
	5600 3050 5150 3050
Wire Wire Line
	6100 2150 6500 2150
Wire Wire Line
	6100 2250 6500 2250
Wire Wire Line
	6100 2350 6500 2350
Wire Wire Line
	6100 2450 6500 2450
Wire Wire Line
	6100 2550 6500 2550
Wire Wire Line
	6100 2650 6500 2650
Wire Wire Line
	6100 2750 6500 2750
Wire Wire Line
	6100 2850 6500 2850
Wire Wire Line
	6100 2950 6500 2950
Wire Wire Line
	6100 3050 6500 3050
Wire Wire Line
	6100 3150 6500 3150
Wire Wire Line
	2650 2050 3250 2050
Connection ~ 2650 2050
Wire Wire Line
	2650 2050 2650 3250
$EndSCHEMATC
