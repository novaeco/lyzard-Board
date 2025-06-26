# Lyzard Board

This repository provides a minimal ESP‑IDF project intended as a starting point for a reptile breeding management application. It uses [LVGL](https://lvgl.io) for the touch interface, a local database and modules for generating French legal documents (CERFA, I‑FAP, CITES, etc.).

**Planned features**

- Manage animals, terrariums, life cycles and health events.
- Inventory and transactions with the related legal paperwork.
- LVGL graphical interface (800×480, light/dark theme, multi‑language).
- Local authentication and encryption of sensitive data.
- CSV/JSON import/export and backup to SD card or via Wi‑Fi.

Only a minimal implementation is provided. The full documentation is available in `docs/README_FR.md` (French). In short it explains the project tree:

- `main/` – application entry point
- `components/database/` – SQLite or file‑based storage
- `components/ui/` – LVGL user interface
- `components/legal/` – tools for CERFA, I‑FAP and CITES forms
- `docs/` – project documentation

and outlines the following quick steps:

1. Install ESP‑IDF and set up the environment.
2. Run `idf.py menuconfig` to adjust the configuration.
3. Build and flash with `idf.py flash monitor`.

## Environment setup

Follow the [ESP‑IDF getting started guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/) to install the tools and export the environment variables (e.g. `IDF_PATH`). Open a terminal where `idf.py` is available before using the commands below.

## Fetching LVGL

The LVGL component is not included in the repository. Fetch it with the component manager:

```bash
idf.py add-dependency lvgl/lvgl
```

This downloads the component and updates `dependencies.lock`.

## Configure, build and flash

From the project root execute:

```bash
idf.py menuconfig      # configure the project
idf.py build           # compile the firmware
idf.py flash monitor   # flash then open the serial monitor
```

## License

This project is licensed under the [MIT License](LICENSE).
