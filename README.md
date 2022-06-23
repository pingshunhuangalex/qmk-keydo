# QMK Keydo

A Colemak-DH based QMK firmware with ergo and programming in mind, designed for polyglots.

> Only one keymap is allowed for each keyboard profile.
>
> - Each folder represents a keyboard profile named in the form of `<keyboard>.<version>` that matches with profiles in [QMK Firmware]
> - The `<keymap>` in this repo defaults to `keydo` unless specified
>
> *e.g. for a keyboard profile of `preonic.rev3_drop`, it has a `<keyboard>` of `preonic` and a `<version>` of `rev3_drop`*

---

## How to use

<details open>
  <summary>Windows</summary>

  <blockquote><details>
    <summary>Advanced users only. Expand this section if you want to hack <code>QMK Keydo</code> and compile your own keyboard profile</summary>

- Download [QMK MSYS]

- Set up QMK home in [QMK MSYS] (`<qmk_home_path>` defaults to `~/qmk_firmware/`). It'll prompt you to clone the [QMK Firmware] repo

  ```console
  qmk setup -H <qmk_home_path>
  ```

- Pick a keyboard profile and move it to `<qmk_home_path>/keyboards/<keyboard>/keymaps/`

- Rename the moved folder to `keydo`, which will become your `<keymap>`

- Navigate to your QMK home in [QMK MSYS]

  ```console
  cd <qmk_home_path>
  ```

- Clean up the build environment

  ```console
  make clean
  ```

- Compile your profile (the compiled profile will locate at `<qmk_home_path>/.build/<keyboard>_<version>_<keymap>.bin`)

  ```console
  qmk compile -kb <keyboard>/<version> -km <keymap>
  ```

  </details></blockquote>

  - Download [QMK Toolbox]

  - Install drivers `menu > Tools > Install Drivers`

  - Put your keyboard into DFU (Bootloader) mode (refer to [QMK Flash Guide] if needed)

  - Pick your keyboard's MCU (documented in each keyboard profile)

  - Pick your compiled keyboard profile (use `QMK Keydo` out of the box via the ready-to-go `<keyboard>_<version>_<keymap>.bin` file in [the build folder])

  - Flash your keyboard by clicking `Flash`

</details>

*For more info, please refer to [QMK Configs]*

[QMK MSYS]: https://github.com/qmk/qmk_distro_msys/releases/latest
[QMK Firmware]: https://github.com/qmk/qmk_firmware
[QMK Toolbox]: https://github.com/qmk/qmk_toolbox/releases/latest
[QMK Flash Guide]: https://docs.qmk.fm/#/newbs_flashing?id=put-your-keyboard-into-dfu-bootloader-mode
[the build folder]: https://github.com/pingshunhuangalex/qmk-keydo/tree/main/.build
[QMK Configs]: https://docs.qmk.fm/#/cli_configuration
