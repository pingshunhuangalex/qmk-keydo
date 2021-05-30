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
