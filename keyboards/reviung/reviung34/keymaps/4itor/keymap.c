#include QMK_KEYBOARD_H
#include "features/layer_lock.h"
#include "features/caps_word.h"

//*** Globals

int Current_DL;

//*** Layer definition

enum custom_layers {
  _QRTY,   // Base Querty Layer
  _NUMB,   // Number and Functions
  _SYMB,   // Symbols
  _NAVI,   // Navigation
  _MOUS,   // Mouse Helper / Mouse Simulation
  _ADJT,   // Adjustments
  _GAME,   // Game Mode
  _XTRA    // Game Extra layer
};

//-- Extra Keycodes
enum custom_keycodes {
  K_LLOCK = SAFE_RANGE,   // Layer Lock
  K_RST_Q,                // For QK_BOOT combo
  K_RST_P,                // For QK_BOOT combo
  K_DOTSL,                // ../
  K_CLNEQ                 // :=
};

// Alternate void key definition
#define _void_ XXXXXXX

// Layer 0 (_QRTY) - Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Layer 0 (_QRTY) - Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

// Layer 1 (_NUMB) - Left-hand home row mods
#define GUI_F5 LGUI_T(KC_F5)
#define ALT_F6 LALT_T(KC_F6)
#define CTL_F7 LCTL_T(KC_F7)
#define SFT_F8 LSFT_T(KC_F8)

// Layer 1 (_NUMB) - Right-hand home row mods
#define SFT_4 RSFT_T(KC_4)
#define CTL_5 RCTL_T(KC_5)
#define ALT_6 LALT_T(KC_6)
#define GUI_PSL RGUI_T(KC_PSLS)

// Layer 3 (_NAVI)
#define K_Undo LGUI(KC_Z)
#define K_Cut LGUI(KC_X)
#define K_Copy LGUI(KC_C)
#define K_Paste LGUI(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QRTY] = LAYOUT_reviung34(
  // Combos:
  //  U+I -> Esc
  //  E+R -> CapsWord
  //  R+T -> (     Y+U -> )
  //  F+G -> {     H+J -> }
  //  V+B -> [     N+M -> ]
  //,--------------------------------------------.  ,--------------------------------------------.
  //|    Q   |    W   |    E   |    R   |    T   |  |    Y   |    U   |    I   |    O   |    P   |
  //|--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
  //|  A,Gui |  S,Alt |  D,Ctl |  F,Sft |    G   |  |    H   |  J,Sft |  K,Ctl |  L,Alt |  ;,Gui |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //|    Z   |    X   |    C   |    V   |    B   |  |    N   |    M   |    ,   |    .   |    /   |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //                           |   Tab  |  Space |  |  Enter | BackSp |
  //                           `-----------------'  `-----------------'
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        GUI_A,   ALT_S,   CTL_D,   SFT_F,    KC_G,       KC_H,   SFT_J,   CTL_K,   ALT_L,GUI_SCLN,
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
             LT(_NUMB, KC_TAB), LT(_MOUS, KC_SPC),  LT(_NAVI, KC_ENT), LT(_SYMB, KC_BSPC)
  ),
  [_NUMB] = LAYOUT_reviung34(
  //,--------------------------------------------.  ,--------------------------------------------.
  //|   F9   |  F10   |   F11  |   F12  |        |  |    +   |    7   |    8   |    9   |    *   |
  //|--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
  //| F5,Gui | F6,Alt | F7,Ctl | F8,Sft |        |  |    -   |  4,Sft |  5,Ctl |  6,Alt |  /,Gui |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //|   F1   |   F2   |   F3   |   F4   |        |  |    0   |    1   |    2   |    3   |    =   |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //                           | (Held) |  Space |  |  Enter | ADJUST |
  //                           `-----------------'  `-----------------'
        KC_F9,  KC_F10,  KC_F11,  KC_F12,  _void_,    KC_PPLS,    KC_7,    KC_8,    KC_9, KC_PAST,
       GUI_F5,  ALT_F6,  CTL_F7,  SFT_F8,  _void_,    KC_PMNS,   SFT_4,   CTL_5,   ALT_6, GUI_PSL,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,  _void_,       KC_0,    KC_1,    KC_2,    KC_3, KC_PEQL,
                               MO(_ADJT),  KC_SPC,     KC_ENT, MO(_ADJT)
  ),
  [_SYMB] = LAYOUT_reviung34(
  //,--------------------------------------------.  ,--------------------------------------------.
  //|    !   |    @   |    #   |    $   |    %   |  |    ^   |    &   |    *   |    (   |    )   |
  //|--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
  //|    ?   |    _   |    -   |    +   |    |   |  |    `   |    "   |    '   |   :=   |    :   |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //|        |   ../  |    ~   |    =   |    \   |  |    /   |        |    <   |    >   |    ?   |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //                           | ADJUST |  Space |  |        | (Held) |
  //                           `-----------------'  `-----------------'
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
       _void_, KC_UNDS, KC_MINS, KC_PLUS, KC_PIPE,     KC_GRV,  KC_DQT, KC_QUOT, K_CLNEQ, KC_COLN,
       _void_, K_DOTSL, KC_TILD,  KC_EQL, KC_BSLS,    KC_SLSH,  _void_,   KC_LT,   KC_GT, KC_QUES,
                               MO(_ADJT),  KC_SPC,     _void_, MO(_ADJT)
  ),
  [_NAVI] = LAYOUT_reviung34(
  //,--------------------------------------------.  ,--------------------------------------------.
  //|        |        |        |        |        |  | (Lock) |   Esc  |        |Hyper(O)|Hyper(P)|
  //|--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
  //|   Gui  |   Alt  |  Crtl  |  Shift |        |  |  Left  |  Down  |   Up   |  Right |        |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //|        |        |        |        |        |  |  Home  |  PgDn  |  PgUp  |  End   |        |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //                           |        | HyprSp |  | (Held) |        |
  //                           `-----------------'  `-----------------'
       _void_,  _void_,  _void_,  _void_,  _void_,    K_LLOCK,  KC_ESC,  _void_,HYPR(KC_O),HYPR(KC_P),
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  _void_,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  _void_,
       _void_,  _void_,  _void_,  _void_,  _void_,    KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  _void_,
                             _void_, HYPR(KC_SPC),     _void_,  _void_
  ),
  [_MOUS] = LAYOUT_reviung34(
  //,--------------------------------------------.  ,--------------------------------------------.
  //|        |  Home  |   End  |  Enter | (Lock) |  |        |        |        |        |        |
  //|--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
  //|   Gui  |   Alt  |  Ctrl  |  Shift | BackSp |  | Mous_L | Mous_D | Mous_U | Mous_R |        |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //|  Undo  |   Cut  |  Copy  |  Paste |   Del  |  | Scrl_L | Scrl_D | Scrl_U | Scrl_R |        |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //                           |   Tab  | (Held) |  | Mouse1 | Mouse2 |
  //                           `-----------------'  `-----------------'
       _void_, KC_HOME,  KC_END,  KC_ENT, K_LLOCK,     _void_,  _void_,  _void_,  _void_,  _void_,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_BSPC,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  _void_,
       K_Undo,   K_Cut,  K_Copy, K_Paste,  KC_DEL,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  _void_,
                                  _void_,  _void_,    KC_BTN1, KC_BTN2
  ),
  [_ADJT] = LAYOUT_reviung34(
  // Combos:
  //  Q+P -> Keyboard Reset
  //,--------------------------------------------.  ,--------------------------------------------.
  //| ResetQ |        |        |BackLght|Breathng|  |  Play  |  Prev  |  Nex   |        | ResetP |
  //|--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
  //|        |        |        |        |        |  |  Mute  |  Vol-  |  Vol+  |        |        |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //|        |        |        |        |        |  |        |  Src-  |  Scr+  |        |  GAME  |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //                           | (Held) |        |  |        | (Held) |
  //                           `-----------------'  `-----------------'
      K_RST_Q,  _void_,  _void_, BL_TOGG, BL_BRTG,    KC_MPLY, KC_MPRV, KC_MNXT,  _void_, K_RST_P,
       _void_,  _void_,  _void_,  _void_,  _void_,    KC_MUTE, KC_VOLD, KC_VOLU,  _void_,  _void_,
       _void_,  _void_,  _void_,  _void_,  _void_,     _void_, KC_BRID, KC_BRIU,  _void_,DF(_GAME),
                                  _void_,  _void_,     _void_,  _void_
  ),
  [_GAME] = LAYOUT_reviung34(
  //,--------------------------------------------.  ,--------------------------------------------.
  //|    Q   |    W   |    E   |    R   |    T   |  |    Y   |    U   |    I   |    O   |    P   |
  //|--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
  //|    A   |    S   |    D   |    F   |    G   |  |    H   |    J   |    K   |    L   |    ;   |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //|    Z   |    X   |    C   |    V   |    B   |  |    N   |    M   |    ,   |    .   |    /   |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //                           |   Tab  |  Space |  |  XTRA  |  Enter |
  //                           `-----------------'  `-----------------'
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
                                  KC_TAB,  KC_SPC,  MO(_XTRA), KC_BSPC
  ),
  [_XTRA] = LAYOUT_reviung34(
  //,--------------------------------------------.  ,--------------------------------------------.
  //|    1   |    2   |    3   |    4   |    5   |  |    6   |    7   |    8   |    9   |    0   |
  //|--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
  //|        |        |        |        |        |  |  Left  |  Down  |   Up   |  Right |        |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //|        |        |        |        |        |  |  Home  |  PgDn  |  PgUp  |  End   |  QRTY  |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //                           |   Tab  |  Space |  | (Held) |        |
  //                           `-----------------'  `-----------------'
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
       _void_,  _void_,  _void_,  _void_,  _void_,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  _void_,
       _void_,  _void_,  _void_,  _void_,  _void_,    KC_HOME, KC_PGDN, KC_PGUP,  KC_END,DF(_QRTY),
                                  _void_,  _void_,     _void_,  _void_
  ),
};

//* Combos!

enum combo_events {
  COMBO_ESC,       //  U+I -> Esc
  COMBO_CAPSW,     //  V+M -> CapsWord
  COMBO_LPRN,      //  R+T -> (
  COMBO_RPRN,      //  Y+U -> )
  COMBO_LCBR,      //  F+G -> {
  COMBO_RCBR,      //  H+J -> }
  COMBO_LBRC,      //  V+B -> [
  COMBO_RBRC,      //  N+M -> ]
  COMBO_RESET,     //  (AdjustLayer) Q+P -> Keyboard Reset
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM combo_ui[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_vm[] = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM combo_rt[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combo_yu[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM combo_fg[] = {SFT_F, KC_G, COMBO_END};
const uint16_t PROGMEM combo_hj[] = {KC_H, SFT_J, COMBO_END};
const uint16_t PROGMEM combo_vb[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM combo_nm[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM combo_adj_qp[] = {K_RST_Q, K_RST_P, COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
    [COMBO_ESC]   = COMBO(combo_ui, KC_ESC),
    [COMBO_CAPSW] = COMBO_ACTION(combo_vm),
    [COMBO_LPRN]  = COMBO(combo_rt, KC_LPRN),
    [COMBO_RPRN]  = COMBO(combo_yu, KC_RPRN),
    [COMBO_LCBR]  = COMBO(combo_fg, KC_LCBR),
    [COMBO_RCBR]  = COMBO(combo_hj, KC_RCBR),
    [COMBO_LBRC]  = COMBO(combo_vb, KC_LBRC),
    [COMBO_RBRC]  = COMBO(combo_nm, KC_RBRC),
    [COMBO_RESET] = COMBO(combo_adj_qp, QK_BOOT)
};

// Functions

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // LayerLock
    if (!process_layer_lock(keycode, record, K_LLOCK)) { return false; }
    // CapsWord
    if (!process_caps_word(keycode, record)) { return false; }
    // Your macros ...
    switch(keycode) {
        case K_CLNEQ:
            if (record->event.pressed) {
                // SEND_STRING(":=");
                register_code(KC_X);
            } else {
                unregister_code(KC_X);
            }
            break;
        case K_DOTSL:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            break;
    }
    return true;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case COMBO_CAPSW:
      if (pressed) {
        caps_word_set(true);  // Activate Caps Word!
      }
      break;
    // Other combos...
  }
}

void matrix_scan_user(void) {
  caps_word_task();
  // Other tasks...
}

void caps_word_set_user(bool active) {
  if (active) {
    // Do something when Caps Word activates.
    sethsv(COLOR_RED, TopLed);
  } else {
    // Do something when Caps Word deactivates.
    sethsv(COLOR_BASE, TopLed);
  }
}

//** LED LIGHTS **

#ifdef RGBLIGHT_ENABLE

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(COLOR_BASE);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    switch(biton32(state)){
        case _QRTY:
            rgblight_sethsv(COLOR_BASE);
            Current_DL = _QRTY;
            break;
        case _GAME:
            rgblight_sethsv(COLOR_MAGENTA);
            Current_DL = _GAME;
            break;
    };
    return state;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _NUMB:
            sethsv(COLOR_BLUE, TopLed);
            break;
        case _SYMB:
            sethsv(COLOR_GREEN, TopLed);
            break;
        case _NAVI:
            sethsv(COLOR_CYAN, TopLed);
            break;
        case _MOUS:
            sethsv(COLOR_VIOLET, TopLed);
            break;
        case _ADJT:
            sethsv(COLOR_RED, TopLed);
            break;
        case _XTRA:
            sethsv(COLOR_YELLOW, TopLed);
            break;
        default: // for any other layers, set based on current default layer
            switch(Current_DL){
                case _QRTY:
                    sethsv(COLOR_BASE, TopLed);
                    break;
                case _GAME:
                    sethsv(COLOR_MAGENTA, TopLed);
                    break;
                default:
                    sethsv(COLOR_OFF, TopLed);
                    break;
            }
            break;
    }
    rgblight_set();
  return state;
}

#endif
