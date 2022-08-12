// Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>
// SPDX-License-Identifier: GPL-2.0+

#pragma once

// Combo Settings
#define COMBO_TERM 40
#define EXTRA_SHORT_COMBOS

// Number of layers
#define DYNAMIC_KEYMAP_LAYER_COUNT 8

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200
#define TAPPING_TERM_PINKY 350
#define TAPPING_TERM_PER_KEY

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Reduce firmware size if not onsehot actions
#define NO_ACTION_ONESHOT

// Max CapsWord lenght
#define CAPS_WORD_IDLE_TIMEOUT 5000
