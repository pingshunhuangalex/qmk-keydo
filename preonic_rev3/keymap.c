#include "win/keymaps.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* -------------------------------------------------------------------------------------------- */
    /*                                       Windows Keymaps                                        */
    /* -------------------------------------------------------------------------------------------- */
    [_BSW] = LAYOUT_preonic_grid_win(KM_BSW),
    [_NMW] = LAYOUT_preonic_grid_win(KM_NMW),
    [_SMW] = LAYOUT_preonic_grid_win(KM_SMW),
    [_MKW] = LAYOUT_preonic_grid_win(KM_MKW),
    [_NVW] = LAYOUT_preonic_grid_win(KM_NVW),
    [_FNW] = LAYOUT_preonic_grid_win(KM_FNW)
};
