enum preonic_layers {
    _BASE = 0,
    _NUM,
    _SYM,
    _NAV,
    _FN,
    _MK
};

enum custom_keycodes {
    DEL_HOM = SAFE_RANGE,
    DEL_END
};

// Modifier Mods
#define OSM_SFT OSM(MOD_LSFT)
#define BS_LALT ALT_T(KC_BSPC)

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

#define OSL_MK OSL(_MK)
#define SET_MK TO(_MK)

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BS_LALT:
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
