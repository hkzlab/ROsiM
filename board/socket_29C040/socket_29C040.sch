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
L power:GND #PWR0102
U 1 1 5FB81CDA
P 2200 3450
F 0 "#PWR0102" H 2200 3200 50  0001 C CNN
F 1 "GND" H 2205 3277 50  0000 C CNN
F 2 "" H 2200 3450 50  0001 C CNN
F 3 "" H 2200 3450 50  0001 C CNN
	1    2200 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 3300 2200 3450
Text Label 3500 1800 2    50   ~ 0
VCC_EXT
Text Label 2200 2000 0    50   ~ 0
A15
Text Label 2200 2200 0    50   ~ 0
A7
Text Label 2200 2300 0    50   ~ 0
A6
Text Label 2200 2400 0    50   ~ 0
A5
Text Label 2200 2500 0    50   ~ 0
A4
Text Label 2200 2600 0    50   ~ 0
A3
Text Label 2200 2700 0    50   ~ 0
A2
Text Label 2200 2800 0    50   ~ 0
A1
Text Label 2200 2900 0    50   ~ 0
A0
Text Label 2200 3000 0    50   ~ 0
D0
Text Label 2200 3100 0    50   ~ 0
D1
Text Label 2200 3200 0    50   ~ 0
D2
Text Label 3500 2100 2    50   ~ 0
A14
Text Label 3500 2200 2    50   ~ 0
A13
Text Label 3500 2300 2    50   ~ 0
A8
Text Label 3500 2400 2    50   ~ 0
A9
Text Label 3500 2500 2    50   ~ 0
A11
Text Label 3500 2600 2    50   ~ 0
~OE
Text Label 3500 2700 2    50   ~ 0
A10
Text Label 3500 2800 2    50   ~ 0
~CE
Text Label 3500 2900 2    50   ~ 0
D7
Text Label 3500 3000 2    50   ~ 0
D6
Text Label 3500 3100 2    50   ~ 0
D5
Text Label 3500 3200 2    50   ~ 0
D4
Text Label 3500 3300 2    50   ~ 0
D3
$Comp
L Connector_Generic:Conn_02x16_Odd_Even J1
U 1 1 5FB988BB
P 2800 2500
F 0 "J1" H 2850 3417 50  0000 C CNN
F 1 "Adapter" H 2850 3326 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x16_P2.54mm_Vertical" H 2800 2500 50  0001 C CNN
F 3 "~" H 2800 2500 50  0001 C CNN
	1    2800 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 1800 2200 1800
Wire Wire Line
	2600 1900 2200 1900
Wire Wire Line
	2600 2000 2200 2000
Wire Wire Line
	2600 2100 2200 2100
Wire Wire Line
	2600 2200 2200 2200
Wire Wire Line
	2600 2300 2200 2300
Wire Wire Line
	2600 2400 2200 2400
Wire Wire Line
	2600 2500 2200 2500
Wire Wire Line
	2600 2600 2200 2600
Wire Wire Line
	2600 2700 2200 2700
Wire Wire Line
	2600 2800 2200 2800
Wire Wire Line
	2600 2900 2200 2900
Wire Wire Line
	2600 3000 2200 3000
Wire Wire Line
	2600 3100 2200 3100
Wire Wire Line
	2600 3200 2200 3200
Wire Wire Line
	2600 3300 2200 3300
Wire Wire Line
	3500 1800 3100 1800
Wire Wire Line
	3100 1900 3500 1900
Wire Wire Line
	3100 2000 3500 2000
Wire Wire Line
	3100 2100 3500 2100
Wire Wire Line
	3100 2200 3500 2200
Wire Wire Line
	3100 2300 3500 2300
Wire Wire Line
	3100 2400 3500 2400
Wire Wire Line
	3100 2500 3500 2500
Wire Wire Line
	3100 2600 3500 2600
Wire Wire Line
	3100 2700 3500 2700
Wire Wire Line
	3100 2800 3500 2800
Wire Wire Line
	3100 2900 3500 2900
Wire Wire Line
	3100 3000 3500 3000
Wire Wire Line
	3100 3100 3500 3100
Wire Wire Line
	3100 3200 3500 3200
Wire Wire Line
	3100 3300 3500 3300
NoConn ~ 2200 1800
Text Label 2200 1900 0    50   ~ 0
A16
Text Label 2200 2100 0    50   ~ 0
A12
Text Label 3500 2000 2    50   ~ 0
A17
Text Label 3500 1900 2    50   ~ 0
A18
$Comp
L Connector_Generic:Conn_02x16_Counter_Clockwise U1
U 1 1 5FC54110
P 5450 2500
F 0 "U1" H 5500 3417 50  0000 C CNN
F 1 "29C040" H 5500 3326 50  0000 C CNN
F 2 "Package_DIP:DIP-32_W15.24mm" H 5450 2500 50  0001 C CNN
F 3 "~" H 5450 2500 50  0001 C CNN
	1    5450 2500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FC55EC4
P 4850 3450
F 0 "#PWR?" H 4850 3200 50  0001 C CNN
F 1 "GND" H 4855 3277 50  0000 C CNN
F 2 "" H 4850 3450 50  0001 C CNN
F 3 "" H 4850 3450 50  0001 C CNN
	1    4850 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3300 4850 3450
Text Label 4850 2000 0    50   ~ 0
A15
Text Label 4850 2200 0    50   ~ 0
A7
Text Label 4850 2300 0    50   ~ 0
A6
Text Label 4850 2400 0    50   ~ 0
A5
Text Label 4850 2500 0    50   ~ 0
A4
Text Label 4850 2600 0    50   ~ 0
A3
Text Label 4850 2700 0    50   ~ 0
A2
Text Label 4850 2800 0    50   ~ 0
A1
Text Label 4850 2900 0    50   ~ 0
A0
Text Label 4850 3000 0    50   ~ 0
D0
Text Label 4850 3100 0    50   ~ 0
D1
Text Label 4850 3200 0    50   ~ 0
D2
Wire Wire Line
	5250 1900 4850 1900
Wire Wire Line
	5250 2000 4850 2000
Wire Wire Line
	5250 2100 4850 2100
Wire Wire Line
	5250 2200 4850 2200
Wire Wire Line
	5250 2300 4850 2300
Wire Wire Line
	5250 2400 4850 2400
Wire Wire Line
	5250 2500 4850 2500
Wire Wire Line
	5250 2600 4850 2600
Wire Wire Line
	5250 2700 4850 2700
Wire Wire Line
	5250 2800 4850 2800
Wire Wire Line
	5250 2900 4850 2900
Wire Wire Line
	5250 3000 4850 3000
Wire Wire Line
	5250 3100 4850 3100
Wire Wire Line
	5250 3200 4850 3200
Wire Wire Line
	5250 3300 4850 3300
Text Label 4850 1900 0    50   ~ 0
A16
Text Label 4850 2100 0    50   ~ 0
A12
Text Label 6150 1800 2    50   ~ 0
VCC_EXT
Text Label 6150 2100 2    50   ~ 0
A14
Text Label 6150 2200 2    50   ~ 0
A13
Text Label 6150 2300 2    50   ~ 0
A8
Text Label 6150 2400 2    50   ~ 0
A9
Text Label 6150 2500 2    50   ~ 0
A11
Text Label 6150 2600 2    50   ~ 0
~OE
Text Label 6150 2700 2    50   ~ 0
A10
Text Label 6150 2800 2    50   ~ 0
~CE
Text Label 6150 2900 2    50   ~ 0
D7
Text Label 6150 3000 2    50   ~ 0
D6
Text Label 6150 3100 2    50   ~ 0
D5
Text Label 6150 3200 2    50   ~ 0
D4
Text Label 6150 3300 2    50   ~ 0
D3
Wire Wire Line
	6150 1800 5750 1800
Wire Wire Line
	5750 1900 6150 1900
Wire Wire Line
	5750 2000 6150 2000
Wire Wire Line
	5750 2100 6150 2100
Wire Wire Line
	5750 2200 6150 2200
Wire Wire Line
	5750 2300 6150 2300
Wire Wire Line
	5750 2400 6150 2400
Wire Wire Line
	5750 2500 6150 2500
Wire Wire Line
	5750 2600 6150 2600
Wire Wire Line
	5750 2700 6150 2700
Wire Wire Line
	5750 2800 6150 2800
Wire Wire Line
	5750 2900 6150 2900
Wire Wire Line
	5750 3000 6150 3000
Wire Wire Line
	5750 3100 6150 3100
Wire Wire Line
	5750 3200 6150 3200
Wire Wire Line
	5750 3300 6150 3300
Text Label 6150 2000 2    50   ~ 0
A17
Text Label 4850 1800 0    50   ~ 0
A18
Wire Wire Line
	5250 1800 4850 1800
NoConn ~ 6150 1900
$EndSCHEMATC
