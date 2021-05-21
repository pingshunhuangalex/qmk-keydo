enum preonic_layers {
    _BASE = 0,
    _NUM,
    _SYM,
    _MK,
    _NAV,
    _FN
};

enum custom_keycodes {
    DEL_HOM = SAFE_RANGE,
    DEL_END
};

// Modifier Mods
#define OSM_SFT OSM(MOD_LSFT)

#define SQT_GUI GUI_T(KC_QUOT)
#define DQT_GUI GUI_T(KC_DQUO)
#define EQL_GUI GUI_T(KC_EQL)

// Layer Switchers
#define SET_BAS TO(_BASE)

#define OSL_NUM OSL(_NUM)
#define SET_NUM TO(_NUM)

#define OSL_SYM OSL(_SYM)
#define SET_SYM TO(_SYM)

#define BSPC_MK LT(_MK, KC_BSPC)
#define SET_MK TO(_MK)

#define SPC_NAV LT(_NAV, KC_SPC)
#define SET_NAV TO(_NAV)

#define ENT_FN LT(_FN, KC_ENT)
#define SET_FN TO(_FN)

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SQT_GUI:
        case DQT_GUI:
        case EQL_GUI:
            return true;

        default:
            return false;
    }
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SQT_GUI:
        case DQT_GUI:
        case EQL_GUI:
            return true;

        default:
            return false;
    }
};

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
