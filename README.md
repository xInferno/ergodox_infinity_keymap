# QMK Layout for the ErgoDox Infinity

Tweaked from the 'default' input-club layout on the QMK repo.

## Features

Base Layers

- QWERTY
- Function
- Numpad

## Local Setup

1. Clone this repo somewhere
2. Clone the QMK repo
3. Link the keymap repo to `~/qmk_firmware/keyboards/ergodox_infinity/keymaps`

## Building and flashing

* If you've reset the EEPROM you have to reflash each side:
  * Plug in the left half and flash it with `make ergodox_infinity:default:dfu-util-split-left`
  * Hit the top vertical 1.5U key (second from the top in the rightmost column) once, and then hit the bottom left 1U key
  * Plug in the right half and flash with `make ergodox_infinity:default:dfu-util-split-right`
  * Hit the top vertical 1.5U key (second from the top in the leftmost column) once, and then hit the bottom right 1U key
  * Make sure to put `#define EE_HANDS` to your config.h in the keymap folder
* If you're only doing a simple keymap change, you can just flash one half of the keyboard:
  * Put the keyboard into flash mode
  * Run `qmk flash` (this assumes you've set up the qmk command already)

