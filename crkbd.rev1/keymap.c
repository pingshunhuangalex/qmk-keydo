#include "win/layers.c"
#include "mac/layers.c"
#include "profile.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* -------------------------------------------------------------------------------------------- */
    /*                                        Windows Layout                                        */
    /* -------------------------------------------------------------------------------------------- */
    [_BSW] = LAYOUT_crkbd_split_win(LAYER_BSW),
    [_NMW] = LAYOUT_crkbd_split_win(LAYER_NMW),
    [_SMW] = LAYOUT_crkbd_split_win(LAYER_SMW),
    [_NVW] = LAYOUT_crkbd_split_win(LAYER_NVW),
    [_MKW] = LAYOUT_crkbd_split_win(LAYER_MKW),
    [_FNW] = LAYOUT_crkbd_split_win(LAYER_FNW),
    [_LLW] = LAYOUT_crkbd_split_win(LAYER_LLW),

    /* -------------------------------------------------------------------------------------------- */
    /*                                         MacOS Layout                                         */
    /* -------------------------------------------------------------------------------------------- */
    [_BSM] = LAYOUT_crkbd_split_mac(LAYER_BSM),
    [_NMM] = LAYOUT_crkbd_split_mac(LAYER_NMM),
    [_SMM] = LAYOUT_crkbd_split_mac(LAYER_SMM),
    [_NVM] = LAYOUT_crkbd_split_mac(LAYER_NVM),
    [_MKM] = LAYOUT_crkbd_split_mac(LAYER_MKM),
    [_FNM] = LAYOUT_crkbd_split_mac(LAYER_FNM),
    [_LLM] = LAYOUT_crkbd_split_mac(LAYER_LLM)
};
