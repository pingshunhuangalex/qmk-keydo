enum preonic_layers {
    _BASE = 0,
    _NUM,
    _SYM,
    _NAV,
    _FN
};

enum custom_keycodes {
    DEL_HOM = SAFE_RANGE,
    DEL_END
};

// Layer Switchers
#define SET_BAS TO(_BASE)

#define OSL_NUM OSL(_NUM)
#define SET_NUM TO(_NUM)

#define OSL_SYM OSL(_SYM)
#define SET_SYM TO(_SYM)

#define SPC_NAV LT(_NAV, KC_SPC)
#define SET_NAV TO(_NAV)

#define OSL_FN OSL(_FN)
#define SET_FN TO(_FN)

// Home Row Mods
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
#define CTL_T LCTL_T(KC_T)

#define CTL_N RCTL_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I RALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_A:
        case ALT_R:
        case SFT_S:
        case CTL_T:
        case CTL_N:
        case SFT_E:
        case ALT_I:
        case GUI_O:
            return TAPPING_TERM + 0;

        default:
            return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_A:
        case ALT_R:
        case SFT_S:
        case CTL_T:
        case CTL_N:
        case SFT_E:
        case ALT_I:
        case GUI_O:
            return true;

        default:
            return false;
    }
}

// Macros
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
