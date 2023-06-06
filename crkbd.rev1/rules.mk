# Build Options
# Change to "no" to disable the options, or define them in the Makefile in
# the appropriate keymap folder that will get included automatically
BACKLIGHT_ENABLE  = no          # Enables keyboard backlight functionality
BOOTLOADER        = atmel-dfu   # AVR MCU options for bootloader type
BOOTMAGIC_ENABLE  = no          # Virtual DIP switch configuration
COMMAND_ENABLE    = no          # Commands for debug and configuration
CONSOLE_ENABLE    = no          # Console for debug
EXTRAKEY_ENABLE   = yes         # Enables audio control and system control
LTO_ENABLE        = yes         # Enables Link Time Optimization (LTO) when compiling the keyboard. This makes the process take longer, but it can significantly reduce the compiled size (and since the firmware is small, the added time is not noticeable)
MOUSEKEY_ENABLE   = yes         # Mouse keys
NKRO_ENABLE       = yes         # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
OLED_DRIVER       = SSD1306     # OLED type
OLED_ENABLE       = yes         # Enables the OLED feature
RGB_MATRIX_ENABLE = no          # Enables RGB matrix lighting
RGBLIGHT_ENABLE   = no          # Enables WS2812 RGB underlight - Enable keyboard underlight functionality
SLEEP_LED_ENABLE  = no          # Breathing sleep LED during USB suspend
SPLIT_KEYBOARD    = yes         # Enables split keyboard support (dual MCU like the let's split and bakingpy's boards) and includes all necessary files located at quantum/split_common
WPM_ENABLE        = yes         # Uses time between keystrokes to compute a rolling average words per minute rate and makes this available for various uses
