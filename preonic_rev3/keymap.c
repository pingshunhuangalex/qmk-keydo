#include QMK_KEYBOARD_H
#include "muse.h"
#include "sphs.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: BASE (Colemak-DH)
    * ,-----------------------------------------------------------------------------------------------.
    * |   `   |   6   |   3   |   1   |   2   |   7   |   9   |   4   |   0   |   5   |   8   |  Del  |
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
        KC_GRV,  KC_6,    KC_3,    KC_1,    KC_2,    KC_7,    KC_9,    KC_4,    KC_0,    KC_5,    KC_8,    KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, OSL_FN,
        KC_ESC,  KC_LEFT, KC_RGHT, OSL_NUM, KC_BSPC, KC_LALT, KC_LSFT, SPC_NAV, OSL_SYM, KC_DOWN, KC_UP,   KC_ENT
    ),

    /* Layer 1: NUMBER (Lower)
    * ,-----------------------------------------------------------------------------------------------.
    * |       |       |       |       |       |       |       |       |       |       |       |  Del  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Tab  |       |       |       |       |       |       |       |       |       |       | _NAV  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | Ctrl  |   6   |   3   |   1   |   2   |   7   |   9   |   4   |   0   |   5   |   8   |   =   |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  GUI  |   /   |   *   |   -   |   +   |   (   |   )   |   .   |   ,   |   %   |   ^   | _BASE |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Left  | Right | _NUM  | Bksp  |  Alt  | Shift | _BASE | _BASE | Down  |  Up   | Enter |
    * `-----------------------------------------------------------------------------------------------'
    */
    [_NUM] = LAYOUT_preonic_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SET_NAV,
        _______, KC_6,    KC_3,    KC_1,    KC_2,    KC_7,    KC_9,    KC_4,    KC_0,    KC_5,    KC_8,    KC_EQL,
        _______, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_LPRN, KC_RPRN, KC_DOT,  KC_COMM, KC_PERC, KC_CIRC, SET_BAS,
        _______, _______, _______, SET_NUM, _______, _______, _______, SET_BAS, SET_BAS, _______, _______, _______
    ),

    /* Layer 2: SYMBOL (Raise)
    * ,-----------------------------------------------------------------------------------------------.
    * |       |       |       |       |       |       |       |       |       |       |       |  Del  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Tab  |       |   %   |   [   |   ]   |       |       |   `   |   +   |   $   |       | _BASE |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | Ctrl  |   <   |   >   |   (   |   )   |   |   |   &   |   -   |   =   |   _   |   *   |   "   |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  GUI  |   ~   |   #   |   {   |   }   |   \   |   !   |   ?   |   :   |   @   |   ^   | _BASE |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Left  | Right | _BASE | Bksp  |  Alt  | Shift | _BASE | _SYM  | Down  |  Up   | Enter |
    * `-----------------------------------------------------------------------------------------------'
    */
    [_SYM] = LAYOUT_preonic_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, KC_PERC, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, KC_GRV,  KC_PLUS, KC_DLR,  XXXXXXX, SET_BAS,
        _______, KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, KC_PIPE, KC_AMPR, KC_MINS, KC_EQL,  KC_UNDS, KC_ASTR, KC_DQUO,
        _______, KC_TILD, KC_HASH, KC_LCBR, KC_RCBR, KC_BSLS, KC_EXLM, KC_QUES, KC_COLN, KC_AT,   KC_CIRC, SET_BAS,
        _______, _______, _______, SET_BAS, _______, _______, _______, SET_BAS, SET_SYM, _______, _______, _______
    ),

    /* Layer 3: NAVIGATION + NUMPAD (Space Fn)
    * ,-----------------------------------------------------------------------------------------------.
    * |       |       |       |       |       |       |   %   | NLCK  |   /   |   *   |   -   |  Del  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Tab  |  Ins  | PgUp  |  Up   | PgDn  |  Del  |   (   |   7   |   8   |   9   |   +   | _NAV  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | Ctrl  | Home  | Left  | Down  | Right |  End  |   )   |   4   |   5   |   6   |   +   |   =   |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  GUI  |       |       |       |DEL_HOM|DEL_END|   ,   |   1   |   2   |   3   | Enter | _BASE |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Left  | Right | _BASE | Bksp  |  Alt  | Shift |   0   | Space |   .   | Enter | Enter |
    * `-----------------------------------------------------------------------------------------------'
    */
    [_NAV] = LAYOUT_preonic_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PERC, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______,
        _______, KC_INS,  KC_PGUP, KC_UP,   KC_PGDN, KC_DEL,  KC_LPRN, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, SET_NAV,
        _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_RPRN, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PEQL,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, DEL_HOM, DEL_END, KC_COMM, KC_P1,   KC_P2,   KC_P3,   KC_PENT, SET_BAS,
        _______, _______, _______, SET_BAS, _______, _______, _______, KC_P0,   KC_SPC,  KC_PDOT, KC_PENT, _______
    ),

    /* Layer 4: FUNCTION (Fn)
    * ,-----------------------------------------------------------------------------------------------.
    * | Reset | Debug |EEPRST |       |       |       |       |       |       |       | Wake  | Sleep |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Tab  | CAPS  | NLCK  | SLCK  |       |       |       |       | Print | Menu  | Pause | _BASE |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | Ctrl  |  F6   |  F3   |  F1   |  F2   |  F7   |  F9   |  F4   |  F10  |  F5   |  F8   | Calc  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  GUI  | Brt-  | Brt+  |  F11  |  F12  |       |       | Stop  | Play  |Rewind |Forward|  _FN  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Prev  | Next  | _BASE | Bksp  |  Alt  | Shift | _BASE | _BASE | Vol-  | Vol+  | Mute  |
    * `-----------------------------------------------------------------------------------------------'
    */
    [_FN] = LAYOUT_preonic_grid(
        RESET,   DEBUG,   EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WAKE, KC_SLEP,
        _______, KC_CAPS, KC_NLCK, KC_SLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_APP,  KC_PAUS, SET_BAS,
        _______, KC_F6,   KC_F3,   KC_F1,   KC_F2,   KC_F7,   KC_F9,   KC_F4,   KC_F10,  KC_F5,   KC_F8,   KC_CALC,
        _______, KC_BRID, KC_BRIU, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_MSTP, KC_MPLY, KC_MRWD, KC_MFFD, SET_FN,
        _______, KC_MPRV, KC_MNXT, SET_BAS, _______, _______, _______, SET_BAS, SET_BAS, KC_VOLD, KC_VOLU, KC_MUTE
    )
};
