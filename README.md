# ROsiM - ROM simulator

## Introduction

The ROsiM is a ROM simulation / emulation board: it uses ywo 512k/8bit SRAM chips to simulate an 8/16 bit ROM (up to 512k bytes or 512k words in size).

The board is based around an ATMega328P chip @20Mhz, controlled via RS232 connection.

![Rev. 1.1 PCB](pics/rev_11_pcb.png)

I made this out of my personal need of a simple way to quickly test ROM images on boards I repair or hack. Often, these boards use big 16bit EPROMs and the projects I found around did not cater to my needs.

While I might help you with quick questions, there is NOT going to be hand-holding for this one.

## Board

This board is designed around relatively cheap through hole components, and should be buildable by anyone with minimum soldering skills.

You'll need a way to program your 328P MCU with the bootloader (you can then load the firmware via serial port).

I recommend [optiboot](https://github.com/Optiboot/optiboot). Remember to set the AVR frequency to 20Mhz and baudrate to 115200bps. I might provide prebuilt binaries of this in the future.

### Connections

#### J1 - ISP 6 pin header

This is used for in-circuit programming of the MCU. You won't really use after burning the bootloader to the chip. You can leave this out if you pre-program the ATMega.

#### J2 - DB9 female - RS232 Serial port

Connect your RS232 cable here, you don't need to invert TX/RX, so a straight-through cable will work.

The Interface runs at 115200bps 8-n-1. The protocol is mainly ASCII based, but meant to be used with an external software.

#### J3 - Barrel jack for power

Connect your DC power supply here, **center tip positive**.
Anything between 7 to 9V will be good, 12V will work, but the regulator might get hotter. 500mA should be enough.

#### J4 - Address header

A 40 pin header:

- Odd pins 1 thru 37 on the left side will bring out the address lines (A0-A18).
- Pin 39 will be this board's VCC.
- All even pins on the right are GND.

#### J5 - Data header

A 40 pin header: 

- Odd pins 1 thru 31 on the left side will bring out the data lines (D0-D15).
- Pin 33 will be the /CE signal input.
- Pin 35 will be the /OE signal input.
- Pin 39 will be this board's VCC.
- All even pins on the right are GND.

#### J6 - /RESET header

An active-low OC signal will be present on this header. You can use to pilot the /RESET of your target board.

Solder an arc of rigid wire on this one, so you can attach a small crocodile clip to it.

#### J7 - RESET header

An active-high signal (either high or disconnected) will be present on this header.

Solder an arc of rigid wire on this one, so you can attach a small crocodile clip to it.
## Software

### Protocol

**TODO**
