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
P 5300 2750
F 0 "U1" H 5350 3867 50  0000 C CNN
F 1 "A500 R5" H 5350 3776 50  0000 C CNN
F 2 "Package_DIP:DIP-40_W15.24mm_Socket" H 5300 2750 50  0001 C CNN
F 3 "~" H 5300 2750 50  0001 C CNN
	1    5300 2750
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
Text Label 4650 2950 0    50   ~ 0
~OE
Text Label 4650 2750 0    50   ~ 0
~CE
Wire Wire Line
	5100 2850 4550 2850
$Comp
L power:GND #PWR?
U 1 1 5FC14712
P 4550 2950
F 0 "#PWR?" H 4550 2700 50  0001 C CNN
F 1 "GND" H 4555 2777 50  0000 C CNN
F 2 "" H 4550 2950 50  0001 C CNN
F 3 "" H 4550 2950 50  0001 C CNN
	1    4550 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 2950 4550 2850
Wire Wire Line
	5100 1850 4650 1850
Wire Wire Line
	5100 1950 4650 1950
Wire Wire Line
	5100 2050 4650 2050
Wire Wire Line
	5100 2150 4650 2150
Wire Wire Line
	5100 2250 4650 2250
Wire Wire Line
	5100 2350 4650 2350
Wire Wire Line
	5100 2450 4650 2450
Wire Wire Line
	5100 2550 4650 2550
Wire Wire Line
	5100 2650 4650 2650
Wire Wire Line
	5100 2750 4650 2750
Wire Wire Line
	5100 2950 4650 2950
Wire Wire Line
	5100 3050 4650 3050
Wire Wire Line
	5100 3150 4650 3150
Wire Wire Line
	5100 3250 4650 3250
Wire Wire Line
	5100 3350 4650 3350
Wire Wire Line
	5100 3450 4650 3450
Wire Wire Line
	5100 3550 4650 3550
Wire Wire Line
	5100 3650 4650 3650
Wire Wire Line
	5100 3750 4650 3750
Text Label 4650 3050 0    50   ~ 0
D0
Text Label 4650 3150 0    50   ~ 0
D8
Text Label 4650 3250 0    50   ~ 0
D1
Text Label 4650 3350 0    50   ~ 0
D9
Text Label 4650 3450 0    50   ~ 0
D2
Text Label 4650 3550 0    50   ~ 0
D10
Text Label 4650 3650 0    50   ~ 0
D3
Text Label 4650 3750 0    50   ~ 0
D11
Text Label 6050 2750 2    50   ~ 0
A17
Text Label 4650 1950 0    50   ~ 0
A7
Text Label 4650 2050 0    50   ~ 0
A6
Text Label 4650 2150 0    50   ~ 0
A5
Text Label 4650 2350 0    50   ~ 0
A3
Text Label 4650 2250 0    50   ~ 0
A4
Text Label 4650 2450 0    50   ~ 0
A2
Text Label 4650 2550 0    50   ~ 0
A1
Text Label 4650 2650 0    50   ~ 0
A0
$Comp
L power:GND #PWR?
U 1 1 5FC1BFB2
P 6150 2950
F 0 "#PWR?" H 6150 2700 50  0001 C CNN
F 1 "GND" H 6155 2777 50  0000 C CNN
F 2 "" H 6150 2950 50  0001 C CNN
F 3 "" H 6150 2950 50  0001 C CNN
	1    6150 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 2950 6150 2850
Wire Wire Line
	6050 1850 5600 1850
Wire Wire Line
	6050 1950 5600 1950
Wire Wire Line
	6050 2050 5600 2050
Wire Wire Line
	6050 2150 5600 2150
Wire Wire Line
	6050 2250 5600 2250
Wire Wire Line
	6050 2350 5600 2350
Wire Wire Line
	6050 2450 5600 2450
Wire Wire Line
	6050 2550 5600 2550
Wire Wire Line
	6050 2650 5600 2650
Wire Wire Line
	6050 2750 5600 2750
Wire Wire Line
	6150 2850 5600 2850
Wire Wire Line
	5600 2950 6050 2950
Wire Wire Line
	5600 3050 6050 3050
Wire Wire Line
	5600 3150 6050 3150
Wire Wire Line
	5600 3250 6050 3250
Wire Wire Line
	5600 3350 6050 3350
Wire Wire Line
	5600 3450 6050 3450
Wire Wire Line
	5600 3550 6050 3550
Wire Wire Line
	5600 3650 6050 3650
Wire Wire Line
	5600 3750 6050 3750
Text Label 6050 3750 2    50   ~ 0
EXT_VCC
Text Label 6050 1850 2    50   ~ 0
A8
Text Label 6050 1950 2    50   ~ 0
A9
Text Label 6050 2050 2    50   ~ 0
A10
Text Label 6050 2150 2    50   ~ 0
A11
Text Label 6050 2250 2    50   ~ 0
A12
Text Label 6050 2350 2    50   ~ 0
A13
Text Label 6050 2450 2    50   ~ 0
A14
Text Label 6050 2550 2    50   ~ 0
A15
Text Label 6050 2650 2    50   ~ 0
A16
Text Label 6050 2950 2    50   ~ 0
D15
Text Label 6050 3050 2    50   ~ 0
D7
Text Label 6050 3150 2    50   ~ 0
D14
Text Label 6050 3250 2    50   ~ 0
D6
Text Label 6050 3350 2    50   ~ 0
D13
Text Label 6050 3450 2    50   ~ 0
D5
Text Label 6050 3550 2    50   ~ 0
D12
Text Label 6050 3650 2    50   ~ 0
D4
Wire Wire Line
	4300 2750 4300 2850
Wire Wire Line
	3750 2750 4300 2750
Connection ~ 4300 2850
NoConn ~ 4650 1850
Text Label 7900 1850 2    50   ~ 0
EXT_VCC
Wire Wire Line
	9000 1850 9450 1850
Text Label 9450 1850 2    50   ~ 0
EXT_VCC
Wire Wire Line
	7050 1850 6600 1850
Wire Wire Line
	7050 1950 6600 1950
Wire Wire Line
	7050 2050 6600 2050
Wire Wire Line
	7050 2150 6600 2150
Wire Wire Line
	7050 2250 6600 2250
Wire Wire Line
	7050 2350 6600 2350
Wire Wire Line
	7050 2450 6600 2450
Wire Wire Line
	7050 2550 6600 2550
Wire Wire Line
	7050 2650 6600 2650
Text Label 6600 1850 0    50   ~ 0
A17
Text Label 6600 1950 0    50   ~ 0
A7
Text Label 6600 2050 0    50   ~ 0
A6
Text Label 6600 2150 0    50   ~ 0
A5
Text Label 6600 2350 0    50   ~ 0
A3
Text Label 6600 2250 0    50   ~ 0
A4
Text Label 6600 2450 0    50   ~ 0
A2
Text Label 6600 2550 0    50   ~ 0
A1
Text Label 6600 2650 0    50   ~ 0
A0
Wire Wire Line
	7450 1850 7900 1850
$Comp
L Device:R_Network09 RN1
U 1 1 5FCCDD63
P 7250 2250
F 0 "RN1" V 6633 2250 50  0000 C CNN
F 1 "4k7" V 6724 2250 50  0000 C CNN
F 2 "Resistor_THT:R_Array_SIP10" V 7825 2250 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 7250 2250 50  0001 C CNN
	1    7250 2250
	0    1    1    0   
$EndComp
$Comp
L Device:R_Network09 RN2
U 1 1 5FCDD6B9
P 8800 2250
F 0 "RN2" V 8183 2250 50  0000 C CNN
F 1 "4k7" V 8274 2250 50  0000 C CNN
F 2 "Resistor_THT:R_Array_SIP10" V 9375 2250 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 8800 2250 50  0001 C CNN
	1    8800 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	8150 1850 8600 1850
Wire Wire Line
	8150 1950 8600 1950
Wire Wire Line
	8150 2050 8600 2050
Wire Wire Line
	8150 2150 8600 2150
Wire Wire Line
	8150 2250 8600 2250
Wire Wire Line
	8150 2350 8600 2350
Wire Wire Line
	8150 2450 8600 2450
Wire Wire Line
	8150 2550 8600 2550
Wire Wire Line
	8150 2650 8600 2650
Text Label 8150 1850 0    50   ~ 0
A8
Text Label 8150 1950 0    50   ~ 0
A9
Text Label 8150 2050 0    50   ~ 0
A10
Text Label 8150 2150 0    50   ~ 0
A11
Text Label 8150 2250 0    50   ~ 0
A12
Text Label 8150 2350 0    50   ~ 0
A13
Text Label 8150 2450 0    50   ~ 0
A14
Text Label 8150 2550 0    50   ~ 0
A15
Text Label 8150 2650 0    50   ~ 0
A16
$EndSCHEMATC
