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
#define HGUI_A LGUI_T(KC_A)
#define HALT_R LALT_T(KC_R)
#define HSFT_S LSFT_T(KC_S)
#define HCTL_T LCTL_T(KC_T)

#define HCTL_N RCTL_T(KC_N)
#define HSFT_E RSFT_T(KC_E)
#define HALT_I RALT_T(KC_I)
#define HGUI_O RGUI_T(KC_O)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HGUI_A:
        case HALT_R:
        case HSFT_S:
        case HCTL_T:
        case HCTL_N:
        case HSFT_E:
        case HALT_I:
        case HGUI_O:
            return TAPPING_TERM + 50;

        default:
            return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HGUI_A:
        case HALT_R:
        case HSFT_S:
        case HCTL_T:
        case HCTL_N:
        case HSFT_E:
        case HALT_I:
        case HGUI_O:
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
