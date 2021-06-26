enum preonic_layers {
    _BSW = 0,
    _NMW,
    _SMW,
    _MKW,
    _NVW,
    _FNW
};

enum preonic_custom_keycodes {
    DEL_LSW = SAFE_RANGE,
    DEL_LEW,
    DEL_WFW
};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSL_GUI:
            return true;

        default:
            return false;
    }
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSL_GUI:
        case SPC_NVW:
        case ENT_FNW:
            return true;

        default:
            return false;
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DEL_LSW:
            if (record->event.pressed) {
                tap_code16(S(KC_HOME));
                tap_code(KC_BSPC);
            }

            return false;

        case DEL_LEW:
            if (record->event.pressed) {
                tap_code16(S(KC_END));
                tap_code(KC_BSPC);
            }

            return false;

        case DEL_WFW:
            if (record->event.pressed) {
                tap_code16(C(KC_BSPC));
            }

            return false;
    }

    return true;
};
