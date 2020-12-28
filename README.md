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

1. If you've reset the EEPROM you have to reflash each side:
  1. Plug in the left half and flash it with `make ergodox_infinity:default:dfu-util-split-left`
  2. Hit the top vertical 1.5U key (second from the top in the rightmost column) once, and then hit the bottom left 1U key
  3. Plug in the right half and flash with `make ergodox_infinity:default:dfu-util-split-right`
  4. Hit the top vertical 1.5U key (second from the top in the leftmost column) once, and then hit the bottom right 1U key
  5. Make sure to put `#define EE_HANDS` to your config.h in the keymap folder
2. If you're only doing a simple keymap change, you can just flash one half of the keyboard:
  1. Put the keyboard into flash mode
  2. Run `qmk flash` (this assumes you've set up the qmk command already)

