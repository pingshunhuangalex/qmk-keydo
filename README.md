# QMK Keydo

<a href="https://github.com/qmk/qmk_toolbox/releases/tag/0.3.3"><img align="right" alt="QMK Toolbox" src="https://img.shields.io/badge/QMK%20Toolbox-0.3.3-c792ea?logo=hackthebox&logoColor=fff&style=for-the-badge" /></a>

[![QMK Firmware](https://img.shields.io/badge/QMK%20Firmware-0.33.7-f78c6a?logo=databricks&logoColor=fff&style=for-the-badge)](https://github.com/qmk/qmk_firmware/releases/tag/0.33.7)

A Colemak-DH based QMK firmware with ergo and programming in mind, designed for polyglots (compatible with [Keydo]).

> [!NOTE]
> Only one keymap is allowed for each keyboard profile.
>
> - Each folder represents a keyboard profile named in the form of `<keyboard>.<version>`, which matches with keyboard profiles in [QMK Firmware]
> - The `<keymap>` in this repo defaults to `keydo` unless specified
>
> _e.g. for a keyboard profile of `preonic.rev3_drop`, it has a `<keyboard>` of `preonic` and a `<version>` of `rev3_drop`_

## Install and Flash

- Download [QMK Toolbox]

- Install drivers `menu > Tools > Install Drivers`

- Put your keyboard into DFU (Bootloader) mode (refer to [QMK Flash Guide] if needed)

- Pick your keyboard's MCU (documented in each keyboard profile)

- Pick your compiled keyboard profile (use `QMK Keydo` out of the box via the ready-to-go `<keyboard>.<version>.<keymap>.{hex, bin}` file in [the build folder])

- Flash your keyboard by clicking `Flash`

_For more info, please refer to [QMK Configs]_

> [!WARNING]
> Advanced users only. Expand below sections if you want to hack <code>QMK Keydo</code> and compile your own keyboard profile

<details>
<summary><strong>Mac</strong></summary>

- Install QMK CLI (Use [Homebrew] as dependencies)

    ```console
    curl -fsSL https://install.qmk.fm | sh
    ```

- Set up QMK home in your terminal (`<qmk_home_path>` defaults to `~/qmk_firmware/`). It'll prompt you to clone the [QMK Firmware] repo

    ```console
    qmk setup -H <qmk_home_path>
    ```

- Pick a keyboard profile and move it to `<qmk_home_path>/keyboards/<keyboard>/keymaps/`

- Rename the moved folder to `keydo`, which will become your `<keymap>`

- Clean up the build environment

    ```console
    qmk clean
    ```

- Compile your keyboard profile (the compiled file will locate at `<qmk_home_path>/.build/<keyboard>_<version>_<keymap>.{hex, bin}`)

    ```console
    qmk compile -kb <keyboard>/<version> -km <keymap>
    ```

</details>
<br/>
<details>
<summary><strong>Windows</strong></summary>

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
    qmk clean
    ```

- Compile your keyboard profile (the compiled file will locate at `<qmk_home_path>/.build/<keyboard>_<version>_<keymap>.{hex, bin}`)

    ```console
    qmk compile -kb <keyboard>/<version> -km <keymap>
    ```

</details>

[Homebrew]: https://brew.sh/
[Keydo]: https://github.com/pingshunhuangalex/rime-keydo
[QMK Configs]: https://docs.qmk.fm/#/cli_configuration
[QMK Firmware]: https://github.com/qmk/qmk_firmware
[QMK Flash Guide]: https://docs.qmk.fm/#/newbs_flashing?id=put-your-keyboard-into-dfu-bootloader-mode
[QMK MSYS]: https://github.com/qmk/qmk_distro_msys/releases/latest
[QMK Toolbox]: https://github.com/qmk/qmk_toolbox/releases/latest
[the build folder]: https://github.com/pingshunhuangalex/qmk-keydo/tree/main/.build
