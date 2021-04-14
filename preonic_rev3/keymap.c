#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _BASE,
  _NUM,
  _SYM,
  _NAV,
  _FN
};

enum custom_keycodes {
  DEL_HOM = SAFE_RANGE,
  DEL_END
};

#define SET_BAS TO(_BASE)

#define OSL_NUM OSL(_NUM)
#define SET_NUM TO(_NUM)

#define OSL_SYM OSL(_SYM)
#define SET_SYM TO(_SYM)

#define SPC_NAV LT(_NAV, KC_SPC)
#define SET_NAV TO(_NAV)

#define OSL_FN OSL(_FN)
#define SET_FN TO(_FN)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DEL_HOM:
      if (record->event.pressed) {
        tap_code16(S(KC_HOME));
        register_code(KC_BSPC);
      } else {
        unregister_code(KC_BSPC);
      }

      return false;

    case DEL_END:
      if (record->event.pressed) {
        tap_code16(S(KC_END));
        register_code(KC_DEL);
      } else {
        unregister_code(KC_DEL);
      }

      return false;
  }

  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layer 0: BASE (Colemak-DH)
  * ,-----------------------------------------------------------------------------------------------.
  * |   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |  Del  |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  Tab  |   Q   |   W   |   F   |   P   |   B   |   J   |   L   |   U   |   Y   |   ;   |   \   |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * | Ctrl  |   A   |   R   |   S   |   T   |   G   |   M   |   N   |   E   |   I   |   O   |   '   |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  GUI  |   Z   |   X   |   C   |   D   |   V   |   K   |   H   |   ,   |   .   |   /   |  Fn   |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  Esc  | Left  | Right | Lower | Bksp  |  Alt  | Shift |SpaceFn| Raise | Down  |  Up   | Enter |
  * `-----------------------------------------------------------------------------------------------'
  */
  [_BASE] = LAYOUT_preonic_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
    KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, OSL_FN,
    KC_ESC,  KC_LEFT, KC_RGHT, OSL_NUM, KC_BSPC, KC_LALT, KC_LSFT, SPC_NAV, OSL_SYM, KC_DOWN, KC_UP,   KC_ENT
  ),

  /* Layer 1: NUMBER (Lower)
  * ,-----------------------------------------------------------------------------------------------.
  * |       |       |       |       |       |       |       |       |       |       |       |  Del  |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  Tab  |       |       |       |       |       |       |       |       |       |       | _BASE |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * | Ctrl  |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   =   |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  GUI  |   /   |   *   |   -   |   +   |       |       |   .   |   ,   |       |       | _BASE |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  Esc  | Left  | Right | _NAV  | Bksp  |  Alt  | Shift | _BASE | _BASE | Down  |  Up   | Enter |
  * `-----------------------------------------------------------------------------------------------'
  */
  [_NUM] = LAYOUT_preonic_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SET_BAS,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    _______, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, XXXXXXX, XXXXXXX, KC_DOT,  KC_COMM, XXXXXXX, XXXXXXX, SET_BAS,
    _______, _______, _______, SET_NAV, _______, _______, _______, SET_BAS, SET_BAS, _______, _______, _______
  ),

  /* Layer 2: SYMBOL (Raise)
  * ,-----------------------------------------------------------------------------------------------.
  * |       |       |       |       |       |       |       |       |       |       |       |  Del  |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  Tab  |       |   \   |   |   |   ?   |       |       |   :   |   `   |   ~   |       | _BASE |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * | Ctrl  |   !   |   @   |   #   |   $   |   %   |   ^   |   &   |   *   |   (   |   )   |   "   |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  GUI  |   =   |   +   |   -   |   _   |   <   |   >   |   {   |   }   |   [   |   ]   | _BASE |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  Esc  | Left  | Right | _BASE | Bksp  |  Alt  | Shift | _BASE | _SYM  | Down  |  Up   | Enter |
  * `-----------------------------------------------------------------------------------------------'
  */
  [_SYM] = LAYOUT_preonic_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, KC_BSLS, KC_PIPE, KC_QUES, XXXXXXX, XXXXXXX, KC_COLN, KC_GRV,  KC_TILD, XXXXXXX, SET_BAS,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DQUO,
    _______, KC_EQL,  KC_PLUS, KC_MINS, KC_UNDS, KC_LT,   KC_GT,   KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, SET_BAS,
    _______, _______, _______, SET_BAS, _______, _______, _______, SET_BAS, SET_SYM, _______, _______, _______
  ),

  /* Layer 3: NAVIGATION + NUMPAD (Space Fn)
  * ,-----------------------------------------------------------------------------------------------.
  * |       |       |       |       |       |       |       | NLCK  |   =   |   /   |   *   |   -   |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  Tab  |  Ins  | PgUp  |  Up   | PgDn  |  Del  |       |   (   |   7   |   8   |   9   |   +   |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * | Ctrl  | Home  | Left  | Down  | Right |  End  |       |   )   |   4   |   5   |   6   |   +   |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  GUI  |       |       |       |DEL_HOM|DEL_END|       |   ,   |   1   |   2   |   3   | Enter |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  Esc  | Left  | Right | _NAV  | Bksp  |  Alt  | Shift | _BASE |   0   | Space |   .   | Enter |
  * `-----------------------------------------------------------------------------------------------'
  */
  [_NAV] = LAYOUT_preonic_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, KC_PEQL, KC_PSLS, KC_PAST, KC_PMNS,
    _______, KC_INS,  KC_PGUP, KC_UP,   KC_PGDN, KC_DEL,  XXXXXXX, KC_LPRN, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  XXXXXXX, KC_RPRN, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, DEL_HOM, DEL_END, XXXXXXX, KC_COMM, KC_P1,   KC_P2,   KC_P3,   KC_PENT,
    _______, _______, _______, SET_NAV, _______, _______, _______, SET_BAS, KC_P0,   KC_SPC,  KC_PDOT, _______
  ),

  /* Layer 4: FUNCTION (Fn)
  * ,-----------------------------------------------------------------------------------------------.
  * | Reset | Debug |EEPRST |       |       |       |       |       |       |       | Wake  | Sleep |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  Tab  | CAPS  | NLCK  | SLCK  |       |       |       |       | Print | Menu  | Pause | _BASE |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * | Ctrl  |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  | Calc  |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  GUI  |  F11  |  F12  | Brt-  | Brt+  |       |       | Stop  | Play  |Rewind |Forward|  _FN  |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  Esc  | Prev  | Next  | _BASE | Bksp  |  Alt  | Shift | _BASE | _BASE | Vol-  | Vol+  | Mute  |
  * `-----------------------------------------------------------------------------------------------'
  */
  [_FN] = LAYOUT_preonic_grid(
    RESET,   DEBUG,   EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WAKE, KC_SLEP,
    _______, KC_CAPS, KC_NLCK, KC_SLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_APP,  KC_PAUS, SET_BAS,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_CALC,
    _______, KC_F11,  KC_F12,  KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, KC_MSTP, KC_MPLY, KC_MRWD, KC_MFFD, SET_FN,
    _______, KC_MPRV, KC_MNXT, SET_BAS, _______, _______, _______, SET_BAS, SET_BAS, KC_VOLD, KC_VOLU, KC_MUTE
  )
};
