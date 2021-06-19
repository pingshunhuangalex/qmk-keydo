#include QMK_KEYBOARD_H
#include "muse.h"
#include "keycodes_win.c"
#include "profile.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* [Win] Layer 0: BASE (Colemak-DH)
    * ,-----------------------------------------------------------------------------------------------.
    * |   `   |   6   |   3   |   1   |   2   |   7   |   9   |   4   |   0   |   5   |   8   |  Del  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Tab  |   Q   |   W   |   F   |   P   |   B   |   J   |   L   |   U   |   Y   |   ;   |GUI | \|
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | Ctrl  |   A   |   R   |   S   |   T   |   G   |   M   |   N   |   E   |   I   |   O   |   '   |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  |   Z   |   X   |   C   |   D   |   V   |   K   |   H   |   ,   |   .   |   /   |ENT_FNW|
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Left  | Right | Lower |BSP_MKW|  Alt  | Shift |SPC_NVW| Raise | Down  |  Up   | Enter |
    * `-----------------------------------------------------------------------------------------------'
    */
    [_BSW] = LAYOUT_preonic_grid(
        KC_GRV,  KC_6,    KC_3,    KC_1,    KC_2,    KC_7,    KC_9,    KC_4,    KC_0,    KC_5,    KC_8,    KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, BSL_GUI,
        KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_ESC,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, ENT_FNW,
        KC_ESC,  KC_LEFT, KC_RGHT, OSL_NMW, BSP_MKW, KC_LALT, OSM_SFT, SPC_NVW, OSL_SMW, KC_DOWN, KC_UP,   KC_ENT
    ),

    /* [Win] Layer 1: NUMBER (Lower)
    * ,-----------------------------------------------------------------------------------------------.
    * |       |       |       |       |       |       |       |       |       |       |       |  Del  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Tab  |       |       |       |       |       |       |       |       |       |       |  GUI  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | Ctrl  |   6   |   3   |   1   |   2   |   7   |   9   |   4   |   0   |   5   |   8   |   =   |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  |   /   |   *   |   -   |   +   |   (   |   )   |   .   |   ,   |   %   |   ^   | Enter |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Left  | Right |SET_NMW| Bksp  |  Alt  | Shift |SET_BSW|SET_NVW| Down  |  Up   | Enter |
    * `-----------------------------------------------------------------------------------------------'
    */
    [_NMW] = LAYOUT_preonic_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI,
        _______, KC_6,    KC_3,    KC_1,    KC_2,    KC_7,    KC_9,    KC_4,    KC_0,    KC_5,    KC_8,    KC_EQL,
        _______, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_LPRN, KC_RPRN, KC_DOT,  KC_COMM, KC_PERC, KC_CIRC, KC_ENT,
        _______, _______, _______, SET_NMW, KC_BSPC, _______, _______, SET_BSW, SET_NVW, _______, _______, _______
    ),

    /* [Win] Layer 2: SYMBOL (Raise)
    * ,-----------------------------------------------------------------------------------------------.
    * |       |       |       |       |       |       |       |       |       |       |       |  Del  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Tab  |       |   %   |   [   |   ]   |       |       |       |   `   |   $   |       |  GUI  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | Ctrl  |   <   |   >   |   (   |   )   |   |   |   ~   |   -   |   +   |   =   |   _   |   "   |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  |   ^   |   @   |   {   |   }   |   &   |   !   |   ?   |   :   |   *   |   #   | Enter |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Left  | Right |SET_MKW| Bksp  |  Alt  | Shift |SET_BSW|SET_SMW| Down  |  Up   | Enter |
    * `-----------------------------------------------------------------------------------------------'
    */
    [_SMW] = LAYOUT_preonic_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, KC_PERC, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,  KC_DLR,  XXXXXXX, KC_LGUI,
        _______, KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, KC_PIPE, KC_TILD, KC_MINS, KC_PLUS, KC_EQL,  KC_UNDS, KC_DQUO,
        _______, KC_CIRC, KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR, KC_EXLM, KC_QUES, KC_COLN, KC_ASTR, KC_HASH, KC_ENT,
        _______, _______, _______, SET_MKW, KC_BSPC, _______, _______, SET_BSW, SET_SMW, _______, _______, _______
    ),

    /* [Win] Layer 3: MOUSE KEYS (Backspace)
    * ,-----------------------------------------------------------------------------------------------.
    * |       |       |       |       |       |       |       |       |       |       |       |  Del  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Tab  |       |       | MsUp  |       |       |       |MWLeft | MWUp  |MWRight|       |  GUI  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | Ctrl  |       |MsLeft |MsDown |MsRight|       |       |MsBtn1 |MsBtn3 |MsBtn2 |       |SET_FNW|
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  |       |       |       |       |       |       |MsBtn4 |MWDown |MsBtn5 |       | Enter |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Left  | Right |SET_BSW| Bksp  |  Alt  | Shift |SET_BSW|SET_BSW| Down  |  Up   | Enter |
    * `-----------------------------------------------------------------------------------------------'
    */
    [_MKW] = LAYOUT_preonic_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_R, XXXXXXX, KC_LGUI,
        _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, SET_FNW,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN4, KC_WH_D, KC_BTN5, XXXXXXX, KC_ENT,
        _______, _______, _______, SET_BSW, KC_BSPC, _______, _______, SET_BSW, SET_BSW, _______, _______, _______
    ),

    /* [Win] Layer 4: NAVIGATION + MEDIA (Space)
    * ,-----------------------------------------------------------------------------------------------.
    * |       |       |       |       |       |       |       |       |       |       |       |  Del  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Tab  |  Ins  | PgUp  |  Up   | PgDn  |  Del  |       | Prev  | Vol+  | Next  |       |  GUI  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | Ctrl  | Home  | Left  | Down  | Right |  End  |       | Play  | Mute  | Stop  |       |SET_FNW|
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  |       |       |       |DEL_LSW|DEL_LEW|       |Rewind | Vol-  |Forward|       | Enter |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Left  | Right |SET_BSW|DEL_WFW|  Alt  | Shift |SET_BSW|SET_BSW| Down  |  Up   | Enter |
    * `-----------------------------------------------------------------------------------------------'
    */
    [_NVW] = LAYOUT_preonic_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, KC_INS,  KC_PGUP, KC_UP,   KC_PGDN, KC_DEL,  XXXXXXX, KC_MPRV, KC_VOLU, KC_MNXT, XXXXXXX, KC_LGUI,
        _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  XXXXXXX, KC_MPLY, KC_MUTE, KC_MSTP, XXXXXXX, SET_FNW,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, DEL_LSW, DEL_LEW, XXXXXXX, KC_MRWD, KC_VOLD, KC_MFFD, XXXXXXX, KC_ENT,
        _______, _______, _______, SET_BSW, DEL_WFW, _______, _______, SET_BSW, SET_BSW, _______, _______, _______
    ),

    /* [Win] Layer 5: FUNCTION (Enter)
    * ,-----------------------------------------------------------------------------------------------.
    * |       |       |       |       |       |       |       |       |       |       |       |  Del  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Tab  | Reset | Debug |EEPRST |       | NLCK  | SLCK  | CAPS  |       | Wake  | Sleep |  GUI  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | Ctrl  |  F6   |  F3   |  F1   |  F2   |  F7   |  F9   |  F4   |  F10  |  F5   |  F8   |SET_BSW|
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Brt-  | Brt+  |  F11  |  F12  |       |       | Calc  | Print | Menu  | Pause | Enter |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Esc  | Left  | Right |SET_BSW| Bksp  |  Alt  | Shift |SET_BSW|SET_BSW| Down  |  Up   | Enter |
    * `-----------------------------------------------------------------------------------------------'
    */
    [_FNW] = LAYOUT_preonic_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, RESET,   DEBUG,   EEP_RST, XXXXXXX, KC_NLCK, KC_SLCK, KC_CAPS, XXXXXXX, KC_WAKE, KC_SLEP, KC_LGUI,
        _______, KC_F6,   KC_F3,   KC_F1,   KC_F2,   KC_F7,   KC_F9,   KC_F4,   KC_F10,  KC_F5,   KC_F8,   SET_BSW,
        _______, KC_BRID, KC_BRIU, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_CALC, KC_PSCR, KC_APP,  KC_PAUS, KC_ENT,
        _______, _______, _______, SET_BSW, KC_BSPC, _______, _______, SET_BSW, SET_BSW, _______, _______, _______
    )
};
