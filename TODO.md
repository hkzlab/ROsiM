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