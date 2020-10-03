
<p align="center">
  <img src="img/header.png?raw=true" alt="Schematics">
</p>

# CU40045-UW1J

This repository contains a custom version of the Noritake CUU library for Arduino, built to add support their CU40045-UW1J model. This repository is tailored to my use case and does not implement all the features of the module, though it should support most of it.

## Major changes

- Added 2 modules support
- Removed 4bit support. It would probably be easy to add back in.
- Removed non-M68 interfaces
- Removed CU20045-UW4J support and brightness boost
- Reading returns the value from the current targeted module, defaulting to top if both modules are targeted.

## How it works

This display contains two different driver modules, which means it behaves the same as two separate displays that just so happen to share the same data pins. The enable pins are separate (noted as `E1` and `E2` in the spec), allowing us to target the modules individually by only raising/lowering the correct pin (or both, if we want the same behavior at once).


## Wiring

You will need at least 14 available pins to wire this display. RX/TX pins do not like being used so consider starting at GPIO2. Wires need to be soldered to the board as it does not come with pre-installed headers.

Here's the wiring for the included examples (though you might want to reorder them in a more logical way):

| Pin (Display)  | Pin (board)  | Description  |
| :------------- | :----------: | -----------: |
| 1              | GPIO 10      | DB7          |
| 2              | GPIO 9       | DB6          |
| 3              | GPIO 8       | DB5          |
| 4              | GPIO 7       | DB4          |
| 5              | GPIO 6       | DB3          |
| 6              | GPIO 5       | DB2          |
| 7              | GPIO 4       | DB1          |
| 8              | GPIO 3       | DB0          |
| 9              | GPIO 11      | E1           |
| 10             | GPIO 12      | R/W          |
| 11             | GPIO 13      | RS           |
| 12             | Not Used     | N/C          |
| 13             | GND          | GND          |
| 14             | 5V Power     | Vcc          |
| 15             | GPIO 2       | E2           |
| 16             | Not Used     | N/C          |


Once you're all wired up, you can tweak the pin numbers in the interface:

```cpp
// RS, RW, E1, E2, D0, D1, D2, D3, D4, D5, D6, D7
CUU_Parallel_M68 interface(13,12, 11, 2, 3,4,5,6,7,8,9,10);
```

# Samples

The sample code can be found in the `/CU40045/examples/` directory.

## Ticker

<p align="center">
  <img src="img/ticker.gif?raw=true" alt="Ticker">
</p>

This sample demonstrates how to emulate keyboard entry by showing the built-in cursor, randomizing time between key presses, and ending on an emulated blinking state.

