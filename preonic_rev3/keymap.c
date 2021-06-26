#include "win/layers.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* -------------------------------------------------------------------------------------------- */
    /*                                        Windows Layout                                        */
    /* -------------------------------------------------------------------------------------------- */
    [_BSW] = LAYOUT_preonic_grid_win(LAYER_BSW),
    [_NMW] = LAYOUT_preonic_grid_win(LAYER_NMW),
    [_SMW] = LAYOUT_preonic_grid_win(LAYER_SMW),
    [_MKW] = LAYOUT_preonic_grid_win(LAYER_MKW),
    [_NVW] = LAYOUT_preonic_grid_win(LAYER_NVW),
    [_FNW] = LAYOUT_preonic_grid_win(LAYER_FNW)
};
