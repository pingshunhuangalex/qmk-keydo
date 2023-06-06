#include QMK_KEYBOARD_H
#include "keycodes.c"

#define LAYOUT_crkbd_split_mac(...) LAYOUT_split_3x6_3(__VA_ARGS__)

/* Layer 0: BASE (Colemak-DH)
 * ,-----------------------------------------------.                          ,-----------------------------------------------.
 * |TAB_LLM|   Q   |   W   |   F   |   P   |   B   |                          |   J   |   L   |   U   |   Y   |   ;   |Opt | \|
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |IME_CMD|   A   |   R   |   S   |   T   |   G   |                          |   M   |   N   |   E   |   I   |   O   |   '   |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |  Esc  |   Z   |   X   |   C   |   D   |   V   |                          |   K   |   H   |   ,   |   .   |   /   |ENT_FNM|
 * `-------------------------------+-------+-------+-------.          ,-------+-------+-------+-------------------------------'
 *                                 | Lower |BSP_MKM| Ctrl  |          | Shift |SPC_NVM| Raise |
 *                                 `-----------------------'          `-----------------------'
 */
#define LAYER_BSM \
TAB_LLM, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, BSL_OPT, \
IME_CMD, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
KC_ESC,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                               KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, ENT_FNM, \
                                    OSL_NMM, BSP_MKM, KC_LCTL,          OSM_SFT, SPC_NVM, OSL_SMM

/* Layer 1: NUMBER (Lower)
 * ,-----------------------------------------------.                          ,-----------------------------------------------.
 * |  Tab  | KP 6  | KP 3  | KP 1  | KP 2  | KP 7  |                          | KP 9  | KP 4  | KP 0  | KP 5  | KP 8  |  Opt  |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |  Cmd  |   6   |   3   |   1   |   2   |   7   |                          |   9   |   4   |   0   |   5   |   8   | KP =  |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |  Esc  | KP /  | KP *  | KP -  | KP +  |   (   |                          |   )   | KP .  |   ,   |   %   |   ^   |KPEnter|
 * `-------------------------------+-------+-------+-------.          ,-------+-------+-------+-------------------------------'
 *                                 |SET_NMM| Bksp  | Ctrl  |          | Shift |SET_BSM|SET_BSM|
 *                                 `-----------------------'          `-----------------------'
 */
#define LAYER_NMM \
KC_TAB,  KC_P6,   KC_P3,   KC_P1,   KC_P2,   KC_P7,                              KC_P9,   KC_P4,   KC_P0,   KC_P5,   KC_P8,   KC_LOPT, \
_______, KC_6,    KC_3,    KC_1,    KC_2,    KC_7,                               KC_9,    KC_4,    KC_0,    KC_5,    KC_8,    KC_PEQL, \
_______, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_LPRN,                            KC_RPRN, KC_PDOT, KC_COMM, KC_PERC, KC_CIRC, KC_PENT, \
                                    SET_NMM, KC_BSPC, _______,          _______, SET_BSM, SET_BSM

/* Layer 2: SYMBOL (Raise)
 * ,-----------------------------------------------.                          ,-----------------------------------------------.
 * |  Tab  |       |   %   |   [   |   ]   |       |                          |       |       |   `   |   $   |       |  Opt  |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |  Cmd  |   <   |   >   |   (   |   )   |   |   |                          |   ~   |   -   |   +   |   =   |   _   |   "   |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |  Esc  |   ^   |   @   |   {   |   }   |   &   |                          |   !   |   ?   |   :   |   *   |   #   | Enter |
 * `-------------------------------+-------+-------+-------.          ,-------+-------+-------+-------------------------------'
 *                                 |SET_BSM| Bksp  | Ctrl  |          | Shift |SET_BSM|SET_SMM|
 *                                 `-----------------------'          `-----------------------'
 */
#define LAYER_SMM \
KC_TAB,  XXXXXXX, KC_PERC, KC_LBRC, KC_RBRC, XXXXXXX,                            XXXXXXX, XXXXXXX, KC_GRV,  KC_DLR,  XXXXXXX, KC_LOPT, \
KC_LCMD, KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, KC_PIPE,                            KC_TILD, KC_MINS, KC_PLUS, KC_EQL,  KC_UNDS, KC_DQUO, \
_______, KC_CIRC, KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR,                            KC_EXLM, KC_QUES, KC_COLN, KC_ASTR, KC_HASH, KC_ENT, \
                                    SET_BSM, KC_BSPC, _______,          _______, SET_BSM, SET_SMM

/* Layer 3: MOUSE KEYS (Backspace)
 * ,-----------------------------------------------.                          ,-----------------------------------------------.
 * |  Tab  |       |       | MsUp  |       |       |                          |       |MWLeft | MWUp  |MWRight|       |  Opt  |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |  Cmd  |       |MsLeft |MsDown |MsRight|       |                          |       |MsBtn1 |MsBtn3 |MsBtn2 |       |SET_BSM|
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |  Esc  |       |       |       |       |       |                          |       |MsBtn4 |MWDown |MsBtn5 |       | Enter |
 * `-------------------------------+-------+-------+-------.          ,-------+-------+-------+-------------------------------'
 *                                 |SET_BSM| Bksp  | Ctrl  |          | Shift | Space |SET_BSM|
 *                                 `-----------------------'          `-----------------------'
 */
#define LAYER_MKM \
KC_TAB,  XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_R, XXXXXXX, KC_LOPT, \
KC_LCMD, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                            XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, SET_BSM, \
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_BTN4, KC_WH_D, KC_BTN5, XXXXXXX, KC_ENT, \
                                    SET_BSM, KC_BSPC, _______,          _______, KC_SPC,  SET_BSM

/* Layer 4: NAVIGATION + MEDIA (Space)
 * ,-----------------------------------------------.                          ,-----------------------------------------------.
 * |  Tab  |  Ins  | PgUp  |  Up   | PgDn  |  Del  |                          |       |Rewind | Vol+  |Forward|       |  Opt  |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |  Cmd  |MOV_LSM| Left  | Down  | Right |MOV_LEM|                          |       | Play  | Mute  | Stop  |       |SET_BSM|
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |  Esc  |DEL_LSM|MOV_PWM|DEL_LNM|MOV_NWM|DEL_LEM|                          |       | Home  | Vol-  |  End  |       | Enter |
 * `-------------------------------+-------+-------+-------.          ,-------+-------+-------+-------------------------------'
 *                                 |SET_BSM|DEL_PWM| Ctrl  |          | Shift |SET_BSM|SET_BSM|
 *                                 `-----------------------'          `-----------------------'
 */
#define LAYER_NVM \
KC_TAB,  KC_INS,  KC_PGUP, KC_UP,   KC_PGDN, KC_DEL,                             XXXXXXX, KC_MRWD, KC_VOLU, KC_MFFD, XXXXXXX, KC_LOPT, \
KC_LCMD, MOV_LSM, KC_LEFT, KC_DOWN, KC_RGHT, MOV_LEM,                            XXXXXXX, KC_MPLY, KC_MUTE, KC_MSTP, XXXXXXX, SET_BSM, \
_______, DEL_LSM, MOV_PWM, DEL_LNM, MOV_NWM, DEL_LEM,                            XXXXXXX, KC_HOME, KC_VOLD, KC_END,  XXXXXXX, KC_ENT, \
                                    SET_BSM, DEL_PWM, _______,          _______, SET_BSM, SET_BSM

/* Layer 5: FUNCTION (Enter)
 * ,-----------------------------------------------.                          ,-----------------------------------------------.
 * |  Tab  |       | Brt+  | CAPS  | Brt-  |       |                          |       | Print | Menu  | Calc  |       |  Opt  |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |  Cmd  |  F6   |  F3   |  F1   |  F2   |  F7   |                          |  F9   |  F4   |  F10  |  F5   |  F8   |SET_BSM|
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |  Esc  |LYT_WIN|       |  F11  |  F12  |       |                          |       |       | Pause | NLCK  | SLCK  | Enter |
 * `-------------------------------+-------+-------+-------.          ,-------+-------+-------+-------------------------------'
 *                                 |SET_BSM| Bksp  | Ctrl  |          | Shift |SET_BSM|SET_BSM|
 *                                 `-----------------------'          `-----------------------'
 */
#define LAYER_FNM \
KC_TAB,  XXXXXXX, KC_BRIU, KC_CAPS, KC_BRID, XXXXXXX,                            XXXXXXX, KC_PSCR, KC_APP,  KC_CALC, XXXXXXX, KC_LOPT, \
KC_LCMD, KC_F6,   KC_F3,   KC_F1,   KC_F2,   KC_F7,                              KC_F9,   KC_F4,   KC_F10,  KC_F5,   KC_F8,   SET_BSM, \
_______, LYT_WIN, XXXXXXX, KC_F11,  KC_F12,  XXXXXXX,                            XXXXXXX, XXXXXXX, KC_PAUS, KC_NUM,  KC_SCRL, KC_ENT, \
                                    SET_BSM, KC_BSPC, _______,          _______, SET_BSM, SET_BSM

/* Layer 6: LAYER LOCKS (Tab)
 * ,-----------------------------------------------.                          ,-----------------------------------------------.
 * |SET_BSM| Boot  | EECLR | Debug | Wake  | Sleep |                          |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                          |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                          |       |       |       |       |       |SET_FNM|
 * `-------------------------------+-------+-------+-------.          ,-------+-------+-------+-------------------------------'
 *                                 |SET_NMM|SET_MKM|       |          |       |SET_NVM|SET_SMM|
 *                                 `-----------------------'          `-----------------------'
 */
#define LAYER_LLM \
SET_BSM, QK_BOOT, EE_CLR,  DB_TOGG, KC_WAKE, KC_SLEP,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SET_FNM, \
                                    SET_NMM, SET_MKM, XXXXXXX,          XXXXXXX, SET_NVM, SET_SMM
