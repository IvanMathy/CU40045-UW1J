# CU40045-UW1J

This repository contains a custom version of the Noritake CUU library for Arduino, built to add support their CU40045-UW1J model. This repository is tailored to my use case and does not implement all the features of the module, though it should support most of it.

## Major changes

- Removed 4bit support. It would probably be easy to add back in.
- Removed non-M68 interfaces


## Unsupported functions

- Reading from the top half should work fine, bottom half most likely does not. I have not tested reading at all so it might need some work.

## How it works

This display contains two different driver modules, which means it behaves the same as two separate displays that just so happen to share the same data pins. The enable pins are separate (noted as `E1` and `E2` in the spec), allowing us to target the modules individually by only raising/lowering the correct pin (or both, if we want the same behavior at once).

