# CLAUDE-LOG

Contributor log for this repo (see `mod-publishing-ops/CLAUDE.md`, "Contributor log"). Append, don't rewrite.

## 2026-10-14 — João (joao@mod.audio), MacBook — MIRRORZ → MIRRORZz (zwabo): work in progress, ON HOLD

- zwabo sent the MIRRORZz gen~ export (`gen_exported.cpp/.h`) plus his own bundle, and confirmed
  by email to João that the ISC licence carries over (same as the current Store version).
- Branch `joao/zwabo-mirrorz` (local only: no push access to mod-audio/max-gen-plugins):
  - `plugins/zwabo-mirrorz/gen_exported.*`: new export, as-is. 11 params; gen~ sorts them
    alphabetically, so `RandSpdOn`/`RandSpeed` land at indexes 7–8 and a new `urn` output lands at 14.
    João's call: keep zwabo's order. Symbols are unchanged, so pedalboards load by symbol.
  - `custom-ttl/zwabo-mirrorz/zwabo-mirrorz_dsp.ttl`: zwabo's ports, defaults (ENV 99, dry_wet 0.5)
    and name **MIRRORZz**. The URI stays `urn:maxgen:zwabo:mirrorz`. `lv2:integer` was dropped from
    `speed`, otherwise HALF SPEED (0.5) can't be selected. `minorVersion` 2 → 3.
  - `DistrhoPluginInfo.h`: name MIRRORZz, version 0.3.0.
  - `custom-ttl/zwabo-mirrorz/modgui/`: zwabo's GUI, plus his manual `MIRRORZz.pdf` linked via
    `modgui:documentation`. His template expected a dropdown + 3 knobs but only 3 ports are listed,
    so dry_wet vanished. Switched to the plain 3-knob template (`modgui:panel "3-knobs"`), which
    matches the picture in his PDF.
- Tested on João's Dwarf (v1.14.0.3364) via `/sdk/install`. The DSP is fine (~16% alone, no
  xruns). The old pedalboard "Modulation + Delays V2" restores all values, cables and its MIDI bypass. The manual is served.
  João's quick sound check: OK.
- **On hold:** knob placement still looks wrong to João (zwabo's CSS was written for his own
  layout). João is asking zwabo for new files (knob placement, other controls, updated
  screenshot/thumbnail). The builder recipe (`MAX_GEN_ZWABO_VERSION`) isn't bumped yet, since that
  needs this branch pushed and merged upstream. Not published.

## 2026-10-16 — João (joao@mod.audio), MacBook — MIRRORZz GUI: zwabo's fixed modgui, hold lifted

- zwabo sent an updated `modgui.ttl` and screenshot (his HTML and CSS are unchanged). The new
  `modgui.ttl` lists 4 ports (ENV, dry_wet, speed, RandSpeed), matching his 1-select + 3-knobs
  template, which fixes the missing DRY_WET.
- Reverted the 2026-10-14 3-knob workaround: zwabo's original `icon-mirrorzz.html` again, his
  `modgui.ttl` (`modgui:panel "1-select-3-knobs"`) with only the URI kept as
  `urn:maxgen:zwabo:mirrorz` and the `modgui:documentation` line for `MIRRORZz.pdf`, and his new
  screenshot (DRY_WET · SPEED · RANDSPEED). FILTER is no longer a GUI knob but is still a port.
- Rebuilt for Dwarf, Duo X and Duo (the Duo reuses the Dwarf's `manifest.ttl`, because ttl
  generation can't run for armhf). Installed on João's Dwarf via `/sdk/install`. João checked the
  GUI: correct.
- Still local only (no push access). Next: push + PR, bump `MAX_GEN_ZWABO_VERSION` in
  mod-plugin-builder, then João's beta-or-not call and Gianfranco's OK to replace the live
  plugin. Not published.
