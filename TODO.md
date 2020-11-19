## Disable external `/CE` when power from the target board is missing

Ideally, the external `/CE` should be disabled if power from the target board is missing, to avoid injecting voltages on a bus that is currently powered off.

A possible solution would be to implement the following logic on a connection pod:

```text

  oCE   |   VCC   ||    CE
--------+---------++----------
   0    |    0    ||     1
   1    |    0    ||     1
   0    |    1    ||     0
   1    |    1    ||     1


CE = oCE | !VCC
```

**NOTE**: Implemented in pods for now

## Rotate external reset header by 90 degrees

Rotate the external reset header and move it away from the mounting hole.
It's too easy to short the connection with a crocodile right now.

## Add header for ground connection

Add ground connection header on the pcb, similar to the reset one, so it's easier to make a better GND connection to the target board

## Use 1mbyte SRAMs

See if 1Mbyte SRAMs are available and use them for new designs.
