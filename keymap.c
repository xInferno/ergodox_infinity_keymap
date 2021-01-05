#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#include "layers.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_ergodox(  // layer 0 : base typing layer
/*
 * left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |  ESC  |  1  |  2  |  3  |  4  |  5  |  [  |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |  TAB  |  Q  |  W  |  E  |  R  |  T  |  {  |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    | LGUI  |  A  |  S  |  D  |  F  |  G  +-----+
 *    +-------+-----+-----+-----+-----+-----+  (  |
 *    | LSHIFT|  Z  |  X  |  C  |  V  |  B  |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |LCTRL|LALT |COPY |  `  |CGI-L| 
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |CTL-A|TO(1)|
 *                                  +-----+-----+-----+
 *                                  |     |     |TT(3)|
 *                                  |BKSPC| DEL +-----+
 *                                  |     |     |TT(2)|
 *                                  +-----+-----+-----+
 */
        KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5, KC_LBRC,
        KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T, KC_LCBR,
        KC_LGUI, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LPRN,
        KC_LCTL, KC_LALT, C(KC_C), KC_GRV, LCTL(LGUI(KC_LEFT)),
                                                      C(KC_A), TO(_GAME),
                                                               TT(_NUM),
                                             KC_BSPC, KC_DEL,  MO(_NAV),
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |  ]  |  6  |  7  |  8  |  9  |  0  |   -   |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |  }  |  Y  |  U  |  I  |  O  |  P  |   =   |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+  H  |  J  |  K  |  L  |  ;  |   '   |
 *        |  )  +-----+-----+-----+-----+-----+-------+
 *        |     |  N  |  M  |  ,  |  .  |  /  | RSHIFT|
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |CGI-R|  `  |PASTE| RALT|RCTRL|
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |TO(1)|CTL-A|
 *    +-----+-----+-----+
 *    |TT(2)|     |     |
 *    +-----+ENTER|SPACE|
 *    |TT(3)|     |     |
 *    +-----+-----+-----+
 */
             KC_RBRC, KC_6,   KC_7,    KC_8,    KC_9,   KC_0,     KC_MINS,
             KC_RCBR, KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,     KC_EQL,
                      KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
             KC_RPRN, KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,
                              LCTL(LGUI(KC_RGHT)), KC_GRV, C(KC_V),  KC_RALT, KC_RCTL,
             TO(_GAME), C(KC_A),
             TT(_NAV),
             TT(_NUM), KC_ENT, KC_SPC
    ),
[_GAME] = LAYOUT_ergodox(  // layer 1 : Gaming layer
/*
 * left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     |     |     |     |     |TO(0)|
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     |     |     |     |     |SH_OF|
 *    +-------+-----+-----+-----+-----+-----+     |
 *    | xxxxx |     |     |     |     |     +-----+
 *    +-------+-----+-----+-----+-----+-----+SH_OS|
 *    |       |     |     |     |     |     |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |xxxxx|     |xxxxx| 
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  |SPACE|ENTER+-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(_BASE),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SH_OFF,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SH_OS,
        KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_NO, 
                                                      KC_TRNS, KC_TRNS,
                                                               KC_TRNS,
                                              KC_SPC, KC_ENT,  KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |TO(0)|     |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |SH_OF|     |     |     |     |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+     |     |     |     |     |       |
 *        |SH_OS+-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |xxxxx|     |xxxxx|     |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     |     |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
             TO(_BASE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             SH_OFF,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             SH_OS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                               KC_NO,   KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, 
             KC_TRNS, KC_TRNS,
             KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS
    ),


[_NAV] = LAYOUT_ergodox( // layer 1 : function, nav, media
/* left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    | TO(0) | F1  | F2  | F3  | F4  | F5  | F11 |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     |     |     |     +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     |     |     |     |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  |     |     +-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
     TO(_BASE), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                      KC_TRNS, KC_TRNS,
                                                               KC_TRNS,
                                             KC_TRNS, KC_TRNS, KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        | F12 | F6  | F7  | F8  | F9  | F10 | SLEEP |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |VOLUP|PREV |PLAY |PAUSE|NEXT |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+LEFT |DOWN | UP  |RIGHT|     |       |
 *        |VOLDN+-----+-----+-----+-----+-----+-------+
 *        |     |HOME |PGDN |PGUP | END |     |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     |     |     |     |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+MUTE |     |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
       KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_SLEP,
       KC_VOLU, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, KC_TRNS, KC_TRNS,
                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
       KC_VOLD, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_MUTE, KC_TRNS
),
[_NUM] = LAYOUT_ergodox(
/* Left hand - symbols
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    | TO(0) |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |  !  |  @  |  #  |  $  |  `  |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |  %  |  ^  |  &  |  *  |  |  +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |  -  |  _  |  =  |  +  |  \  |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  |     |     +-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
     TO(_BASE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_GRV,  KC_TRNS,
       KC_TRNS, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE,
       KC_TRNS, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS, KC_BSLS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |NMLCK| P/  | P*  | P-  |       |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     | P7  | P8  | P9  | P+  |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+     | P4  | P5  | P6  | P+  |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     |     | P1  | P2  | P3  |PENT |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    | P0  | P0  | P.  |PENT |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     |     |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
       KC_TRNS,  KC_TRNS, KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_KP_7,    KC_KP_8,     KC_KP_9,        KC_KP_PLUS,  KC_TRNS,
                 KC_TRNS, KC_KP_4,    KC_KP_5,     KC_KP_6,        KC_KP_PLUS,  KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_KP_1,    KC_KP_2,     KC_KP_3,        KC_KP_ENTER, KC_TRNS,
                          KC_KP_0,    KC_KP_0,     KC_KP_DOT,      KC_KP_ENTER, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
