# CU40045-UW1J

This repository contains a custom version of the Noritake CUU library for Arduino, built to add support their CU40045-UW1J model. This repository is tailored to my use case and does not implement all the features of the module, though it should support most of it.

## Major changes

- Removed 4bit support. It would probably be easy to add back in.
- Removed non-M68 interfaces


## Unsupported functions

- Reading from the top half should work fine, bottom half most likely does not. I have not tested reading at all so it might need some work.