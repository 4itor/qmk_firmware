#pragma once

// #define VIAL_KEYBOARD_UID {0xB8, 0x68, 0xB9, 0x6C, 0x13, 0x2E, 0xA7, 0xDD}
// #define VIAL_UNLOCK_COMBO_ROWS {0, 3}
// #define VIAL_UNLOCK_COMBO_COLS {0, 5}

// Combo Settings
#define COMBO_TERM 40
#define EXTRA_SHORT_COMBOS

// the non split version
#define RGB_DI_PIN D3
#ifdef RGB_DI_PIN
  #define RGBLED_NUM 9
  #define RGBLIGHT_HUE_STEP 16
  #define RGBLIGHT_SAT_STEP 16
  #define RGBLIGHT_VAL_STEP 16
  #define RGBLIGHT_LIMIT_VAL 255
  #define RGBLIGHT_SLEEP
  // /*== all animations enable ==*/
  #undef RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  //#define RGBLIGHT_MODE_BREATHING
  //#define RGBLIGHT_MODE_RAINBOW_MOOD
  //#define RGBLIGHT_MODE_RAINBOW_SWIRL
  #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_GRADIENT
  #undef RGBLIGHT_LAYERS
  #undef RGB_MATRIX_ENABLE

  // Led HSV colors (half intensity)
  #define HUE(hue) hue,255,128
  #define COLOR_ORANGE HUE(24)
  #define COLOR_RED HUE(0)
  #define COLOR_YELLOW HUE(55)
  #define COLOR_GREEN HUE(85)
  #define COLOR_CYAN HUE(127)
  #define COLOR_BLUE HUE(169)
  #define COLOR_VIOLET HUE(190)
  #define COLOR_MAGENTA HUE(211)
  #define COLOR_WHITE 0,0,255
  #define COLOR_OFF 0,0,0

  // Lighting Layers
  #define RgbLed(LedNo) (LED_TYPE *)&led[LedNo]
  #define TopLed RgbLed(8)
#endif

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


