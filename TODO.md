## Use 1mbyte SRAMs

See if 1Mbyte SRAMs are available and use them for new designs.

## Add code to invert the external /RESET logic

Revision 1.1 has an header for an OC /RESET and another for a RESET,
but the logic to pilot them is inverted. They're piloted by an
MCU pin. A way to select which type of reset to use in firmware must be implemented.
