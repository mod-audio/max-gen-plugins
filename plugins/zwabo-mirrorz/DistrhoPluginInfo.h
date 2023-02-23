/*
 * DPF Max Gen
 * Copyright (C) 2015-2023 Filipe Coelho <falktx@falktx.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with
 * or without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#pragma once

#define DISTRHO_PLUGIN_BRAND   "zwabo"
#define DISTRHO_PLUGIN_NAME    "MIRRORZ"
#define DISTRHO_PLUGIN_URI     "urn:maxgen:zwabo:mirrorz"
#define DISTRHO_PLUGIN_CLAP_ID "maxgen.zwabo.mirrorz"

#define DISTRHO_PLUGIN_HAS_UI        0
#define DISTRHO_PLUGIN_IS_RT_SAFE    1
#define DISTRHO_PLUGIN_NUM_INPUTS    2
#define DISTRHO_PLUGIN_NUM_OUTPUTS   2

#define DISTRHO_PLUGIN_CLAP_FEATURES   "audio-effect", "distortion", "stereo"
#define DISTRHO_PLUGIN_LV2_CATEGORY    "lv2:DelayPlugin"
#define DISTRHO_PLUGIN_VST3_CATEGORIES "Fx|Distortion"

#define DISTRHO_PLUGIN_UNIQUE_ID d_cconst('z', 'w', 'm', 'z')
#define DISTRHO_PLUGIN_VERSION d_version(0, 0, 0)

static constexpr const char DISTRHO_PLUGIN_DESCRIPTION[] = R"DESCRIPTION(
Build with Max gen~ by Zwabo

The TRIGGER function of MIRRORZ allows you to play backward the last chords/melody you just played, same for the LOOP function but looped.
Pressing TRIGGER (momentary ON ) start reading audio backward from the last sampled position within the data/buffer, releasing TRIGGER stop reading audio.

Pressing LOOP (momentary ON ) reads audio backward from the last sampled position within the data/buffer, releasing "LOOP" loop the buffer segment just read.

Pressing TRIGGER stop the loop (if you keep TRIGGER pressed, it reads audio backward from the last sampled position within the data/buffer)
)DESCRIPTION";
