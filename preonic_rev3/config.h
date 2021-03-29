#pragma once

#define NO_DEBUG             // Disable debugging
#define NO_PRINT             // Disable printing/debugging using hid_listen

#define FORCE_NKRO           // NKRO by default requires to be turned on, this forces it on during keyboard startup regardless of EEPROM setting. NKRO can still be turned off but will be turned on again if the keyboard reboots.
#define TAP_CODE_DELAY 10    // Sets the delay between register_code and unregister_code, if you're having issues with it registering properly (common on VUSB boards). The value is in milliseconds.

#ifdef AUDIO_ENABLE
    // #define STARTUP_SONG SONG(PREONIC_SOUND)
    #define STARTUP_SONG SONG(NO_SOUND)
#endif
