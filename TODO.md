## Disable external `/CE` when power from the target board is missing

Ideally, the external `/CE` should be disabled if power from the target board is missing, to avoid injecting voltages on a bus that is currently powered off.

A possible solution would be to implement the following logic on a connection pod:

```text

ext /CE | ext VCC || ROsiM /CE  
--------+---------++----------
   0    |    0    ||     1
   1    |    0    ||     1
   0    |    1    ||     0
   1    |    1    ||     1


ROsiM /CE = !(ext /CE) & (ext VCC)

We can implement it using a single 74xx00 (maybe best to use an ACT):
             ____
ext. /CE ---|    \        ____            ____
            |     |o-----|    \      ,---|    \
ext. /CE ---|____/       |     |o---+    |     |o---- ROsiM /CE
             ext. VCC -+-|____/      `---|____/
                       |
                       `---^v^v^v^--| GND
                          pull-down
```