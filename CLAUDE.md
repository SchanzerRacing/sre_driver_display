# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a **Formula Student race car driver display** — a GTK4 GUI application written in C17 for a Raspberry Pi running Linux. It shows live telemetry (battery, motor temps, pressures, errors, states) on an 800×480 touchscreen by reading CAN bus messages.

## Build Commands

All commands run from `gtkWorkspace/`:

```sh
make              # build → build/driver-display.out
make rebuild      # clean + build
make clean        # remove build artifacts
```

Requires GTK4 (`pkg-config --cflags --libs gtk4`) and GCC.

## Architecture

The application has two concurrent threads:

1. **CAN thread** (`sre_can.c`): opens a SocketCAN socket, reads raw CAN frames continuously, calls `sre_dbc.c` to decode them into the global `SRE_*` data structs.
2. **GUI thread** (`main.c`): GTK event loop + a 50ms timer (`GUI_UPDATE_INTERVALL`) that calls `sre_logic.c` to derive errors/info from the shared structs, then pushes values into the currently visible panel's GTK widgets.

```
CAN Bus → sre_can.c → sre_dbc.c (decode) → SRE_* global structs
                                                      ↓ (50ms timer)
                                              sre_logic.c (errors, states)
                                                      ↓
                        active panel (endurance / debug / vehicleinfo / parameters)
                                                      ↓
                                           GTK widgets on 800×480 screen
```

**Thread safety note:** The CAN thread writes to shared structs while the GUI thread reads them. There are no explicit locks — the code relies on struct-level atomic read/write behaviour. Keep this constraint in mind when adding fields.

## Key Files

| File | Role |
|------|------|
| `main.c` | GTK app init, 50ms update timer, panel switching, keyboard debug input |
| `sre_logic.c/h` | All data structs (`SRE_*`), state enums, error/info management, threshold constants |
| `sre_can.c/h` | SocketCAN thread, `can_mappings[]` array wiring CAN IDs to DBC functions |
| `sre_dbc.c/h` | **Auto-generated** from `resources/DBC-Conversion/BODY-CAN_24.dbc` via `dbcConv.py` — do not edit by hand |
| `*_panel.c/h` | Per-panel widget cache globals and `update_*_panel()` functions |
| `designs/*.ui` | GTK Builder XML defining widget trees for each panel |
| `designs/dd.css` | Application stylesheet (dark theme) |
| `config.h` | Architecture flag (`#define ARCH_RPI`) |

## CAN / Debug Mode

`USE_CAN` in `sre_logic.h` controls runtime mode:

- `USE_CAN 1` — real SocketCAN, fullscreen
- `USE_CAN 0` — keyboard-driven demo mode (keys `u i o p k t r f g b e d c w`)

## Panel System

Four panels cycle on screen-tap: **Endurance → Debug → Vehicleinfo → Parameters**.  
Each panel is a GTK Builder XML file loaded once at startup; widget handles are cached as module-level globals in the corresponding `*_panel.c` file for fast 50ms updates.

## DBC Regeneration

When the DBC file changes, regenerate `sre_dbc.c/h`:

```sh
python3 resources/DBC-Conversion/dbcConv.py
```

Then update `can_mappings[]` in `sre_can.c` if new message IDs were added.

## VS Code Setup

`.vscode/c_cpp_properties.json` sets C17, includes GTK4 headers at `/usr/include/gtk-4.0`.  
`.vscode/settings.json` enforces 2-space indent, 99-char ruler, format-on-save.
