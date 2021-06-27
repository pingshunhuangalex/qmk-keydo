enum preonic_layers {
    _BSW = 0,
    _BSM,
    _NMW,
    _NMM,
    _SMW,
    _SMM,
    _MKW,
    _MKM,
    _NVW,
    _NVM,
    _FNW,
    _FNM
};

enum preonic_custom_keycodes {
    LYT_WIN = SAFE_RANGE,
    LYT_MAC,
    MOV_PWW,
    MOV_PWM,
    MOV_NWW,
    MOV_NWM,
    DEL_PWW,
    DEL_PWM,
    DEL_LSW,
    DEL_LSM,
    DEL_LEW,
    DEL_LEM
};

#define OSM_SFT OSM(MOD_LSFT)

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSL_WIN:
        case BSL_OPT:
            return true;

        default:
            return false;
    }
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSL_WIN:
        case BSL_OPT:
        case SPC_NVW:
        case SPC_NVM:
        case ENT_FNW:
        case ENT_FNM:
            return true;

        default:
            return false;
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LYT_WIN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BSW);
            }

            return false;

        case LYT_MAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BSM);
            }

            return false;

        case MOV_PWW:
            if (record->event.pressed) {
                tap_code16(C(KC_LEFT));
            }

            return false;

        case MOV_PWM:
            if (record->event.pressed) {
                tap_code16(LOPT(KC_LEFT));
            }

            return false;

        case MOV_NWW:
            if (record->event.pressed) {
                tap_code16(C(KC_RGHT));
            }

            return false;

        case MOV_NWM:
            if (record->event.pressed) {
                tap_code16(LOPT(KC_RGHT));
            }

            return false;

        case DEL_PWW:
            if (record->event.pressed) {
                tap_code16(C(KC_BSPC));
            }

            return false;

        case DEL_PWM:
            if (record->event.pressed) {
                tap_code16(LOPT(KC_BSPC));
            }

            return false;

        case DEL_LSW:
            if (record->event.pressed) {
                tap_code16(S(KC_HOME));
                tap_code(KC_BSPC);
            }

            return false;

        case DEL_LSM:
            if (record->event.pressed) {
                tap_code16(LCMD(KC_BSPC));
            }

            return false;

        case DEL_LEW:
            if (record->event.pressed) {
                tap_code16(S(KC_END));
                tap_code(KC_BSPC);
            }

            return false;

        case DEL_LEM:
            if (record->event.pressed) {
                tap_code16(S(LCMD(KC_RGHT)));
                tap_code(KC_BSPC);
            }

            return false;
    }

    return true;
};
