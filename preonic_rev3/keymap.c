#include QMK_KEYBOARD_H
#include "muse.h"
#include "sphs.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: BASE (Colemak-DH)
    * ,-----------------------------------------------------------------------------------------------.
    * |   `   |   6   |   3   |   1   |   2   |   7   |   9   |   4   |   0   |   5   |   8   |  Del  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Tab  |   Q   |   W   |   F   |   P   |   B   |   J   |   L   |   U   |   Y   |   ;   |GUI | \|
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | Ctrl  |   A   |   R   |   S   |   T   |   G   |   M   |   N   |   E   |   I   |   O   |   '   |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  |   Z   |   X   |   C   |   D   |   V   |   K   |   H   |   ,   |   .   |   /   |EnterFn|
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Left  | Right | Lower |BkspMk |  Alt  | Shift |SpaceFn| Raise | Down  |  Up   | Enter |
    * `-----------------------------------------------------------------------------------------------'
    */
    [_BASE] = LAYOUT_preonic_grid(
        KC_GRV,  KC_6,    KC_3,    KC_1,    KC_2,    KC_7,    KC_9,    KC_4,    KC_0,    KC_5,    KC_8,    KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, BSL_GUI,
        KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_ESC,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, ENT_FN,
        KC_ESC,  KC_LEFT, KC_RGHT, OSL_NUM, BSPC_MK, KC_LALT, OSM_SFT, SPC_NAV, OSL_SYM, KC_DOWN, KC_UP,   KC_ENT
    ),

    /* Layer 1: NUMBER (Lower)
    * ,-----------------------------------------------------------------------------------------------.
    * |       |       |       |       |       |       |       |       |       |       |       |  Del  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Tab  |       |       |       |       |       |       |       |       |       |       |  GUI  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | Ctrl  |   6   |   3   |   1   |   2   |   7   |   9   |   4   |   0   |   5   |   8   |   =   |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  |   /   |   *   |   -   |   +   |   (   |   )   |   .   |   ,   |   %   |   ^   | Enter |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Left  | Right | _NUM  | Bksp  |  Alt  | Shift | _BASE | _NAV  | Down  |  Up   | Enter |
    * `-----------------------------------------------------------------------------------------------'
    */
    [_NUM] = LAYOUT_preonic_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI,
        _______, KC_6,    KC_3,    KC_1,    KC_2,    KC_7,    KC_9,    KC_4,    KC_0,    KC_5,    KC_8,    KC_EQL,
        _______, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_LPRN, KC_RPRN, KC_DOT,  KC_COMM, KC_PERC, KC_CIRC, KC_ENT,
        _______, _______, _______, SET_NUM, KC_BSPC, _______, _______, SET_BAS, SET_NAV, _______, _______, _______
    ),

    /* Layer 2: SYMBOL (Raise)
    * ,-----------------------------------------------------------------------------------------------.
    * |       |       |       |       |       |       |       |       |       |       |       |  Del  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Tab  |       |   %   |   [   |   ]   |       |       |       |   `   |   $   |       |  GUI  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | Ctrl  |   <   |   >   |   (   |   )   |   |   |   ~   |   -   |   +   |   =   |   _   |   "   |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  |   ^   |   @   |   {   |   }   |   &   |   !   |   ?   |   :   |   *   |   #   | Enter |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Left  | Right |  _MK  | Bksp  |  Alt  | Shift | _BASE | _SYM  | Down  |  Up   | Enter |
    * `-----------------------------------------------------------------------------------------------'
    */
    [_SYM] = LAYOUT_preonic_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, KC_PERC, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,  KC_DLR,  XXXXXXX, KC_LGUI,
        _______, KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, KC_PIPE, KC_TILD, KC_MINS, KC_PLUS, KC_EQL,  KC_UNDS, KC_DQUO,
        _______, KC_CIRC, KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR, KC_EXLM, KC_QUES, KC_COLN, KC_ASTR, KC_HASH, KC_ENT,
        _______, _______, _______, SET_MK,  KC_BSPC, _______, _______, SET_BAS, SET_SYM, _______, _______, _______
    ),

    /* Layer 3: MOUSE KEYS (Mk)
    * ,-----------------------------------------------------------------------------------------------.
    * |       |       |       |       |       |       |       |       |       |       |       |  Del  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Tab  |       |       | MsUp  |       |       |       |MWLeft | MWUp  |MWRight|       |  GUI  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | Ctrl  |       |MsLeft |MsDown |MsRight|       |       |MsBtn1 |MsBtn3 |MsBtn2 |       |  _FN  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  |       |       |       |       |       |       |       |MWDown |       |       | Enter |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Left  | Right | _BASE | Bksp  |  Alt  | Shift | _BASE | _BASE | Down  |  Up   | Enter |
    * `-----------------------------------------------------------------------------------------------'
    */
    [_MK] = LAYOUT_preonic_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_R, XXXXXXX, KC_LGUI,
        _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, SET_FN,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX, KC_ENT,
        _______, _______, _______, SET_BAS, KC_BSPC, _______, _______, SET_BAS, SET_BAS, _______, _______, _______
    ),

    /* Layer 4: NAVIGATION + MEDIA (Space Fn)
    * ,-----------------------------------------------------------------------------------------------.
    * |       |       |       |       |       |       |       |       |       |       |       |  Del  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Tab  |  Ins  | PgUp  |  Up   | PgDn  |  Del  |       | Prev  | Vol+  | Next  |       |  GUI  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | Ctrl  | Home  | Left  | Down  | Right |  End  |       | Play  | Mute  | Stop  |       |  _FN  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  |       |       |       |DEL_HOM|DEL_END|       |Rewind | Vol-  |Forward|       | Enter |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Left  | Right | _BASE | Bksp  |  Alt  | Shift | _BASE | _BASE | Down  |  Up   | Enter |
    * `-----------------------------------------------------------------------------------------------'
    */
    [_NAV] = LAYOUT_preonic_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, KC_INS,  KC_PGUP, KC_UP,   KC_PGDN, KC_DEL,  XXXXXXX, KC_MPRV, KC_VOLU, KC_MNXT, XXXXXXX, KC_LGUI,
        _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  XXXXXXX, KC_MPLY, KC_MUTE, KC_MSTP, XXXXXXX, SET_FN,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, DEL_HOM, DEL_END, XXXXXXX, KC_MRWD, KC_VOLD, KC_MFFD, XXXXXXX, KC_ENT,
        _______, _______, _______, SET_BAS, KC_BSPC, _______, _______, SET_BAS, SET_BAS, _______, _______, _______
    ),

    /* Layer 5: FUNCTION (Fn)
    * ,-----------------------------------------------------------------------------------------------.
    * |       |       |       |       |       |       |       |       |       |       |       |  Del  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Tab  | Reset | Debug |EEPRST |       | NLCK  | SLCK  | CAPS  |       | Wake  | Sleep |  GUI  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | Ctrl  |  F6   |  F3   |  F1   |  F2   |  F7   |  F9   |  F4   |  F10  |  F5   |  F8   | _BASE |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Brt-  | Brt+  |  F11  |  F12  |       |       | Calc  | Print | Menu  | Pause | Enter |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Left  | Right | _BASE | Bksp  |  Alt  | Shift | _BASE | _BASE | Down  |  Up   | Enter |
    * `-----------------------------------------------------------------------------------------------'
    */
    [_FN] = LAYOUT_preonic_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, RESET,   DEBUG,   EEP_RST, XXXXXXX, KC_NLCK, KC_SLCK, KC_CAPS, XXXXXXX, KC_WAKE, KC_SLEP, KC_LGUI,
        _______, KC_F6,   KC_F3,   KC_F1,   KC_F2,   KC_F7,   KC_F9,   KC_F4,   KC_F10,  KC_F5,   KC_F8,   SET_BAS,
        _______, KC_BRID, KC_BRIU, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_CALC, KC_PSCR, KC_APP,  KC_PAUS, KC_ENT,
        _______, _______, _______, SET_BAS, KC_BSPC, _______, _______, SET_BAS, SET_BAS, _______, _______, _______
    )
};
