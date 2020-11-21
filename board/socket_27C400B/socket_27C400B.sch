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
Text Label 2800 2950 0    50   ~ 0
~OE
Text Label 2800 2750 0    50   ~ 0
~CE
$Comp
L Connector_Generic:Conn_02x20_Counter_Clockwise U1
U 1 1 5FB99B61
P 5550 2750
F 0 "U1" H 5600 3867 50  0000 C CNN
F 1 "27C400" H 5600 3776 50  0000 C CNN
F 2 "Package_DIP:DIP-40_W15.24mm_Socket" H 5550 2750 50  0001 C CNN
F 3 "~" H 5550 2750 50  0001 C CNN
	1    5550 2750
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x20_Odd_Even J1
U 1 1 5FB9CB9B
P 3450 2750
F 0 "J1" H 3500 3867 50  0000 C CNN
F 1 "Adapter" H 3500 3776 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x20_P2.54mm_Vertical" H 3450 2750 50  0001 C CNN
F 3 "~" H 3450 2750 50  0001 C CNN
	1    3450 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 2850 2700 2850
$Comp
L power:GND #PWR?
U 1 1 5FBA41AE
P 2700 2950
F 0 "#PWR?" H 2700 2700 50  0001 C CNN
F 1 "GND" H 2705 2777 50  0000 C CNN
F 2 "" H 2700 2950 50  0001 C CNN
F 3 "" H 2700 2950 50  0001 C CNN
	1    2700 2950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FBA4704
P 4300 2950
F 0 "#PWR?" H 4300 2700 50  0001 C CNN
F 1 "GND" H 4305 2777 50  0000 C CNN
F 2 "" H 4300 2950 50  0001 C CNN
F 3 "" H 4300 2950 50  0001 C CNN
	1    4300 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 2950 4300 2850
Wire Wire Line
	2700 2950 2700 2850
Wire Wire Line
	3250 1850 2800 1850
Wire Wire Line
	3250 1950 2800 1950
Wire Wire Line
	3250 2050 2800 2050
Wire Wire Line
	3250 2150 2800 2150
Wire Wire Line
	3250 2250 2800 2250
Wire Wire Line
	3250 2350 2800 2350
Wire Wire Line
	3250 2450 2800 2450
Wire Wire Line
	3250 2550 2800 2550
Wire Wire Line
	3250 2650 2800 2650
Wire Wire Line
	3250 2750 2800 2750
Wire Wire Line
	3250 2950 2800 2950
Wire Wire Line
	3250 3050 2800 3050
Wire Wire Line
	3250 3150 2800 3150
Wire Wire Line
	3250 3250 2800 3250
Wire Wire Line
	3250 3350 2800 3350
Wire Wire Line
	3250 3450 2800 3450
Wire Wire Line
	3250 3550 2800 3550
Wire Wire Line
	3250 3650 2800 3650
Wire Wire Line
	3250 3750 2800 3750
Wire Wire Line
	4200 1850 3750 1850
Wire Wire Line
	4200 1950 3750 1950
Wire Wire Line
	4200 2050 3750 2050
Wire Wire Line
	4200 2150 3750 2150
Wire Wire Line
	4200 2250 3750 2250
Wire Wire Line
	4200 2350 3750 2350
Wire Wire Line
	4200 2450 3750 2450
Wire Wire Line
	4200 2550 3750 2550
Wire Wire Line
	4200 2650 3750 2650
Wire Wire Line
	4300 2850 3750 2850
Wire Wire Line
	3750 2950 4200 2950
Wire Wire Line
	3750 3050 4200 3050
Wire Wire Line
	3750 3150 4200 3150
Wire Wire Line
	3750 3250 4200 3250
Wire Wire Line
	3750 3350 4200 3350
Wire Wire Line
	3750 3450 4200 3450
Wire Wire Line
	3750 3550 4200 3550
Wire Wire Line
	3750 3650 4200 3650
Wire Wire Line
	3750 3750 4200 3750
Text Label 4200 3750 2    50   ~ 0
EXT_VCC
Text Label 2800 3050 0    50   ~ 0
D0
Text Label 2800 3150 0    50   ~ 0
D8
Text Label 2800 3250 0    50   ~ 0
D1
Text Label 2800 3350 0    50   ~ 0
D9
Text Label 2800 3450 0    50   ~ 0
D2
Text Label 2800 3550 0    50   ~ 0
D10
Text Label 2800 3650 0    50   ~ 0
D3
Text Label 2800 3750 0    50   ~ 0
D11
Text Label 2800 1850 0    50   ~ 0
A17
Text Label 2800 1950 0    50   ~ 0
A7
Text Label 2800 2050 0    50   ~ 0
A6
Text Label 2800 2150 0    50   ~ 0
A5
Text Label 2800 2350 0    50   ~ 0
A3
Text Label 2800 2250 0    50   ~ 0
A4
Text Label 2800 2450 0    50   ~ 0
A2
Text Label 2800 2550 0    50   ~ 0
A1
Text Label 2800 2650 0    50   ~ 0
A0
Text Label 4200 1850 2    50   ~ 0
A8
Text Label 4200 1950 2    50   ~ 0
A9
Text Label 4200 2050 2    50   ~ 0
A10
Text Label 4200 2150 2    50   ~ 0
A11
Text Label 4200 2250 2    50   ~ 0
A12
Text Label 4200 2350 2    50   ~ 0
A13
Text Label 4200 2450 2    50   ~ 0
A14
Text Label 4200 2550 2    50   ~ 0
A15
Text Label 4200 2650 2    50   ~ 0
A16
Text Label 4200 2750 2    50   ~ 0
A18
Text Label 4200 2950 2    50   ~ 0
D15
Text Label 4200 3050 2    50   ~ 0
D7
Text Label 4200 3150 2    50   ~ 0
D14
Text Label 4200 3250 2    50   ~ 0
D6
Text Label 4200 3350 2    50   ~ 0
D13
Text Label 4200 3450 2    50   ~ 0
D5
Text Label 4200 3550 2    50   ~ 0
D12
Text Label 4200 3650 2    50   ~ 0
D4
Text Label 4900 2950 0    50   ~ 0
~OE
Text Label 4900 2750 0    50   ~ 0
~CE
Wire Wire Line
	5350 2850 4800 2850
$Comp
L power:GND #PWR?
U 1 1 5FC14712
P 4800 2950
F 0 "#PWR?" H 4800 2700 50  0001 C CNN
F 1 "GND" H 4805 2777 50  0000 C CNN
F 2 "" H 4800 2950 50  0001 C CNN
F 3 "" H 4800 2950 50  0001 C CNN
	1    4800 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2950 4800 2850
Wire Wire Line
	5350 1850 4900 1850
Wire Wire Line
	5350 1950 4900 1950
Wire Wire Line
	5350 2050 4900 2050
Wire Wire Line
	5350 2150 4900 2150
Wire Wire Line
	5350 2250 4900 2250
Wire Wire Line
	5350 2350 4900 2350
Wire Wire Line
	5350 2450 4900 2450
Wire Wire Line
	5350 2550 4900 2550
Wire Wire Line
	5350 2650 4900 2650
Wire Wire Line
	5350 2750 4900 2750
Wire Wire Line
	5350 2950 4900 2950
Wire Wire Line
	5350 3050 4900 3050
Wire Wire Line
	5350 3150 4900 3150
Wire Wire Line
	5350 3250 4900 3250
Wire Wire Line
	5350 3350 4900 3350
Wire Wire Line
	5350 3450 4900 3450
Wire Wire Line
	5350 3550 4900 3550
Wire Wire Line
	5350 3650 4900 3650
Wire Wire Line
	5350 3750 4900 3750
Text Label 4900 3050 0    50   ~ 0
D0
Text Label 4900 3250 0    50   ~ 0
D1
Text Label 4900 3450 0    50   ~ 0
D2
Text Label 4900 3650 0    50   ~ 0
D3
Text Label 4900 1850 0    50   ~ 0
A18
Text Label 4900 1950 0    50   ~ 0
A8
Text Label 4900 2050 0    50   ~ 0
A7
Text Label 4900 2150 0    50   ~ 0
A6
Text Label 4900 2350 0    50   ~ 0
A4
Text Label 4900 2250 0    50   ~ 0
A5
Text Label 4900 2450 0    50   ~ 0
A3
Text Label 4900 2550 0    50   ~ 0
A2
Text Label 4900 2650 0    50   ~ 0
A1
$Comp
L power:GND #PWR?
U 1 1 5FC1BFB2
P 6400 2950
F 0 "#PWR?" H 6400 2700 50  0001 C CNN
F 1 "GND" H 6405 2777 50  0000 C CNN
F 2 "" H 6400 2950 50  0001 C CNN
F 3 "" H 6400 2950 50  0001 C CNN
	1    6400 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 2950 6400 2850
Wire Wire Line
	6300 1850 5850 1850
Wire Wire Line
	6300 1950 5850 1950
Wire Wire Line
	6300 2050 5850 2050
Wire Wire Line
	6300 2150 5850 2150
Wire Wire Line
	6300 2250 5850 2250
Wire Wire Line
	6300 2350 5850 2350
Wire Wire Line
	6300 2450 5850 2450
Wire Wire Line
	6300 2550 5850 2550
Wire Wire Line
	6300 2650 5850 2650
Wire Wire Line
	6300 2750 5850 2750
Wire Wire Line
	6400 2850 5850 2850
Wire Wire Line
	5850 2950 6300 2950
Wire Wire Line
	5850 3050 6300 3050
Wire Wire Line
	5850 3150 6300 3150
Wire Wire Line
	5850 3250 6300 3250
Wire Wire Line
	5850 3350 6300 3350
Wire Wire Line
	5850 3450 6300 3450
Wire Wire Line
	5850 3550 6300 3550
Wire Wire Line
	5850 3650 6300 3650
Wire Wire Line
	5850 3750 6300 3750
Text Label 6300 3750 2    50   ~ 0
EXT_VCC
Text Label 6300 1850 2    50   ~ 0
A9
Text Label 6300 1950 2    50   ~ 0
A10
Text Label 6300 2050 2    50   ~ 0
A11
Text Label 6300 2150 2    50   ~ 0
A12
Text Label 6300 2250 2    50   ~ 0
A13
Text Label 6300 2350 2    50   ~ 0
A14
Text Label 6300 2450 2    50   ~ 0
A15
Text Label 6300 2550 2    50   ~ 0
A16
Text Label 6300 2650 2    50   ~ 0
A17
Text Label 6300 2950 2    50   ~ 0
A0
Text Label 6300 3050 2    50   ~ 0
D7
Text Label 6300 3250 2    50   ~ 0
D6
Text Label 6300 3450 2    50   ~ 0
D5
Text Label 6300 3650 2    50   ~ 0
D4
NoConn ~ 6300 2750
Wire Wire Line
	3750 2750 4200 2750
NoConn ~ 4900 3150
NoConn ~ 4900 3350
NoConn ~ 4900 3550
NoConn ~ 4900 3750
NoConn ~ 6300 3550
NoConn ~ 6300 3350
NoConn ~ 6300 3150
$EndSCHEMATC
