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

#define SET_BASE TO(_BASE)

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
  * |  Esc  | Left  | Right |  Alt  | Bksp  | Shift | Lower |SpaceFn| Raise |  Up   | Down  | Enter |
  * `-----------------------------------------------------------------------------------------------'
  */
  [_BASE] = LAYOUT_preonic_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
    KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, OSL_FN,
    KC_ESC,  KC_LEFT, KC_RGHT, KC_LALT, KC_BSPC, KC_LSFT, OSL_NUM, SPC_NAV, OSL_SYM, KC_UP,   KC_DOWN, KC_ENT
  ),

  /* Layer 1: NUMBER (Lower)
  * ,-----------------------------------------------------------------------------------------------.
  * |       |       |       |   =   |   +   |   -   |   *   |   /   |       |       |       |  Del  |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  Tab  |       |       |   ,   |   7   |   8   |   9   |   .   |       |       |       | _BASE |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * | Ctrl  |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |       |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  GUI  |       |       |   0   |   1   |   2   |   3   | Enter |       |       |       |  _FN  |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  Esc  | Left  | Right |  Alt  | Bksp  | Shift | _NUM  | _NAV  | _SYM  |  Up   | Down  | Enter |
  * `-----------------------------------------------------------------------------------------------'
  */
  [_NUM] = LAYOUT_preonic_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, KC_PEQL, KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, KC_PCMM, KC_P7,   KC_P8,   KC_P9,   KC_PDOT, XXXXXXX, XXXXXXX, XXXXXXX, SET_BASE,
    _______, KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,   XXXXXXX,
    _______, XXXXXXX, XXXXXXX, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PENT, XXXXXXX, XXXXXXX, XXXXXXX, SET_FN,
    _______, _______, _______, _______, _______, _______, SET_NUM, SET_NAV, SET_SYM, _______, _______, _______
  ),

  /* Layer 2: SYMBOL (Raise)
  * ,-----------------------------------------------------------------------------------------------.
  * |       |       |       |       |       |       |       |       |       |       |       |  Del  |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  Tab  |   =   |   +   |   -   |   _   |       |       |   <   |   >   |   :   |   ?   | _BASE |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * | Ctrl  |   !   |   @   |   #   |   $   |   %   |   ^   |   &   |   *   |   (   |   )   |       |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  GUI  |   `   |   ~   |   '   |   "   |   \   |   |   |   {   |   }   |   [   |   ]   |  _FN  |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  Esc  | Left  | Right |  Alt  | Bksp  | Shift | _NUM  | _NAV  | _SYM  |  Up   | Down  | Enter |
  * `-----------------------------------------------------------------------------------------------'
  */
  [_SYM] = LAYOUT_preonic_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_EQL,  KC_PLUS, KC_MINS, KC_UNDS, XXXXXXX, XXXXXXX, KC_LT,   KC_GT,   KC_COLN, KC_QUES, SET_BASE,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
    _______, KC_GRV,  KC_TILD, KC_QUOT, KC_DQUO, KC_BSLS, KC_PIPE, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, SET_FN,
    _______, _______, _______, _______, _______, _______, SET_NUM, SET_NAV, SET_SYM, _______, _______, _______
  ),

  /* Layer 3: NAVIGATION (Space Fn)
  * ,-----------------------------------------------------------------------------------------------.
  * |       |       |       |       |       |       |       |       |       |       |       |  Del  |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  Tab  |  INS  | Pg Up |  Up   | Pg Dn |  Del  |       |DEL_HOM|DEL_END|       |       | _BASE |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * | Ctrl  | HOME  | Left  | Down  | Right |  END  |   H   |   J   |   K   |   L   |       |       |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  GUI  |       |       |       |       |       |       |       |       |       |       |  _FN  |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  Esc  | Left  | Right |  Alt  | Bksp  | Shift | _NUM  | _NAV  | _SYM  |  Up   | Down  | Enter |
  * `-----------------------------------------------------------------------------------------------'
  */
  [_NAV] = LAYOUT_preonic_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_INS,  KC_PGUP, KC_UP,   KC_PGDN, KC_DEL,  XXXXXXX, DEL_HOM, DEL_END, XXXXXXX, XXXXXXX, SET_BASE,
    _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_H,    KC_J,    KC_K,    KC_L,    XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SET_FN,
    _______, _______, _______, _______, _______, _______, SET_NUM, SET_NAV, SET_SYM, _______, _______, _______
  ),

  /* Layer 4: FUNCTION (Fn)
  * ,-----------------------------------------------------------------------------------------------.
  * | Reset | Debug |       |       |       |       |       |       |       |       | Wake  | Sleep |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  Tab  | CAPS  | NLCK  | SLCK  |       |       |       |       | Print | Menu  | Pause | _BASE |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * | Ctrl  |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  | Calc  |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |  GUI  |  F11  |  F12  | Brt-  | Brt+  |       |       | Stop  | Play  |Rewind |Forward|  _FN  |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * |EEPRST | Prev  | Next  |  Alt  | Bksp  | Shift | _NUM  | _NAV  | _SYM  | Vol+  | Vol-  | Mute  |
  * `-----------------------------------------------------------------------------------------------'
  */
  [_FN] = LAYOUT_preonic_grid(
    RESET,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WAKE, KC_SLEP,
    _______, KC_CAPS, KC_NLCK, KC_SLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_APP,  KC_PAUS, SET_BASE,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_CALC,
    _______, KC_F11,  KC_F12,  KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, KC_MSTP, KC_MPLY, KC_MRWD, KC_MFFD, SET_FN,
    EEP_RST, KC_MPRV, KC_MNXT, _______, _______, _______, SET_NUM, SET_NAV, SET_SYM, KC_VOLU, KC_VOLD, KC_MUTE
  )
};
