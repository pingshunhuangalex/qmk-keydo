/* Copyright 2021 Pingshun Huang (Alex) <alex.g.huang@gmail.com> @<pingshunhuangalex>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// #define NO_DEBUG                    // Disable debugging
// #define NO_PRINT                    // Disable printing/debugging using hid_listen

#define FORCE_NKRO                  // NKRO by default requires to be turned on, this forces it on during keyboard startup regardless of EEPROM setting. NKRO can still be turned off but will be turned on again if the keyboard reboots
#define TAP_CODE_DELAY 10           // Sets the delay between register_code and unregister_code, if you're having issues with it registering properly (common on VUSB boards). The value is in milliseconds

#define TAPPING_TERM 200            // How long before a tap becomes a hold, if set above 500, a key tapped during the tapping term will turn it into a hold too
#define TAPPING_TERM_PER_KEY        // Enables handling for per key TAPPING_TERM settings

#define IGNORE_MOD_TAP_INTERRUPT    // Makes it possible to do rolling combos (zx) with keys that convert to other keys on hold, by enforcing the TAPPING_TERM for both keys
#define TAPPING_FORCE_HOLD          // Makes it possible to use a dual role key as modifier shortly after having been tapped
#define TAPPING_FORCE_HOLD_PER_KEY  // Enables handling for per key TAPPING_FORCE_HOLD settings

#ifdef AUDIO_ENABLE
    // #define STARTUP_SONG SONG(PREONIC_SOUND)
    #define STARTUP_SONG SONG(NO_SOUND)
#endif
