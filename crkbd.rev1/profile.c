enum crkbd_layers {
    /* -------------------------------------------------------------------------------------------- */
    /*                                          Mac Layout                                          */
    /* -------------------------------------------------------------------------------------------- */
    _BSM = 0,
    _NMM,
    _SMM,
    _NVM,
    _MKM,
    _FNM,
    _LLM,
    /* -------------------------------------------------------------------------------------------- */
    /*                                        Windows Layout                                        */
    /* -------------------------------------------------------------------------------------------- */
    _BSW,
    _NMW,
    _SMW,
    _NVW,
    _MKW,
    _FNW,
    _LLW
};

enum crkbd_custom_keycodes {
    /* -------------------------------------------------------------------------------------------- */
    /*                                          Mac Layout                                          */
    /* -------------------------------------------------------------------------------------------- */
    LYT_MAC = SAFE_RANGE,
    MOV_PWM,
    MOV_NWM,
    MOV_LSM,
    MOV_LEM,
    DEL_PWM,
    DEL_LSM,
    DEL_LEM,
    DEL_LNM,
    /* -------------------------------------------------------------------------------------------- */
    /*                                        Windows Layout                                        */
    /* -------------------------------------------------------------------------------------------- */
    LYT_WIN,
    MOV_PWW,
    MOV_NWW,
    DEL_PWW,
    DEL_LSW,
    DEL_LEW,
    DEL_LNW
};

#define OSM_SFT OSM(MOD_LSFT)

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return false;
    }
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSL_MEH:
        case TAB_HYP:
        /* -------------------------------------------------------------------------------------------- */
        /*                                          Mac Layout                                          */
        /* -------------------------------------------------------------------------------------------- */
        case BSP_MKM:
        case ENT_FNM:
        case ESC_LLM:
        case SPC_NVM:
        case QUO_OPT:
        /* -------------------------------------------------------------------------------------------- */
        /*                                        Windows Layout                                        */
        /* -------------------------------------------------------------------------------------------- */
        case BSP_MKW:
        case ENT_FNW:
        case ESC_LLW:
        case SPC_NVW:
        case QUO_WIN:
            return 0;

        default:
            return QUICK_TAP_TERM;
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* -------------------------------------------------------------------------------------------- */
        /*                                          Mac Layout                                          */
        /* -------------------------------------------------------------------------------------------- */
        case LYT_MAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BSM);
            }

            return false;

        case MOV_PWM:
            if (record->event.pressed) {
                tap_code16(LOPT(KC_LEFT));
            }

            return false;

        case MOV_NWM:
            if (record->event.pressed) {
                tap_code16(LOPT(KC_RGHT));
            }

            return false;

        case MOV_LSM:
            if (record->event.pressed) {
                tap_code16(LCMD(KC_LEFT));
            }

            return false;

        case MOV_LEM:
            if (record->event.pressed) {
                tap_code16(LCMD(KC_RGHT));
            }

            return false;

        case DEL_PWM:
            if (record->event.pressed) {
                tap_code16(LOPT(KC_BSPC));
            }

            return false;

        case DEL_LSM:
            if (record->event.pressed) {
                tap_code16(LCMD(KC_BSPC));
            }

            return false;

        case DEL_LEM:
            if (record->event.pressed) {
                tap_code16(S(LCMD(KC_RGHT)));
                tap_code(KC_BSPC);
            }

            return false;

        case DEL_LNM:
            if (record->event.pressed) {
                tap_code16(LCMD(KC_RGHT));
                tap_code16(LCMD(KC_BSPC));
            }

            return false;

        /* -------------------------------------------------------------------------------------------- */
        /*                                        Windows Layout                                        */
        /* -------------------------------------------------------------------------------------------- */
        case LYT_WIN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BSW);
            }

            return false;

        case MOV_PWW:
            if (record->event.pressed) {
                tap_code16(C(KC_LEFT));
            }

            return false;

        case MOV_NWW:
            if (record->event.pressed) {
                tap_code16(C(KC_RGHT));
            }

            return false;

        case DEL_PWW:
            if (record->event.pressed) {
                tap_code16(C(KC_BSPC));
            }

            return false;

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

        case DEL_LNW:
            if (record->event.pressed) {
                tap_code(KC_END);
                tap_code16(S(KC_HOME));
                tap_code(KC_BSPC);
            }

            return false;
    }

    return true;
};
