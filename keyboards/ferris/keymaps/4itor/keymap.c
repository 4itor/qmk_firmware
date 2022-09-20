// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "features/layer_lock.h"
#include "features/caps_word.h"

//*** Globals

int  Current_DL        = 0;     // Current Default Layer
bool is_alt_tab_active = false; // Is Alt-Tab engaded?

//*** Layer definition

enum custom_layers {
    _QRTY, // Base Querty Layer
    _NUMB, // Number and Functions
    _SYMB, // Symbols
    _NAVI, // Navigation
    _MOUS, // Mouse Helper / Mouse Simulation
    _ADJT  // Adjustments
    // _GAME, // Game Mode
    // _XTRA  // Game Extra layer
};

//-- Extra Keycodes
enum custom_keycodes {
    K_LLOCK = SAFE_RANGE, // Layer Lock
    K_DOTSL,              // ../
    K_CLNEQ,              // :=
    K_ALTAB,              // Alt+Tab onehanded on Mouse Helper layer
    K_ALTBP               // Previous Window (Alt+Shift+Tab)
};

// Alternate void key definition
#define _void_ XXXXXXX

// Layer 0 (_QRTY) - Left-hand home row mods
#define GUI_A    LGUI_T(KC_A)
#define ALT_S    LALT_T(KC_S)
#define CTL_D    LCTL_T(KC_D)
#define SFT_F    LSFT_T(KC_F)

// Layer 0 (_QRTY) - Right-hand home row mods
#define SFT_J    RSFT_T(KC_J)
#define CTL_K    RCTL_T(KC_K)
#define ALT_L    LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

// Layer 3 (_NAVI)
#define K_Quit   LGUI(KC_Q)
#define K_Close  LGUI(KC_W)
#define K_Undo   LGUI(KC_Z)
#define K_Cut    LGUI(KC_X)
#define K_Copy   LGUI(KC_C)
#define K_Paste  LGUI(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QRTY] = LAYOUT(
  // Combos:
  //  U+I+O -> Esc
  //  W+E+R -> Esc
  //  R+T -> (     Y+U -> )
  //  F+G -> {     H+J -> }
  //  V+B -> [     N+M -> ]
  //  F+J -> CapsWord
  //,--------------------------------------------.  ,--------------------------------------------.
  //|    Q   |    W   |    E   |    R   |    T   |  |    Y   |    U   |    I   |    O   |    P   |
  //|--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
  //|  A,Gui |  S,Alt |  D,Ctl |  F,Sft |    G   |  |    H   |  J,Sft |  K,Ctl |  L,Alt |  ;,Gui |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //|    Z   |    X   |    C   |    V   |    B   |  |    N   |    M   |    ,   |    .   |    /   |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //                           |   Tab  | BackSp |  |  Space |  Enter |
  //                           `-----------------'  `-----------------'
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        GUI_A,   ALT_S,   CTL_D,   SFT_F,    KC_G,       KC_H,   SFT_J,   CTL_K,   ALT_L,GUI_SCLN,
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
            LT(_NUMB, KC_TAB), LT(_MOUS, KC_BSPC),   LT(_NAVI, KC_SPC), LT(_SYMB, KC_ENT)
  ),

 [_NUMB] = LAYOUT(
  //,--------------------------------------------.  ,--------------------------------------------.
  //|    1   |    2   |    3   |    4   |    5   |  |    6   |    7   |    8   |    9   |    0   |
  //|--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
  //|   Gui  |   Alt  |   Ctl  |  Shift |   F11  |  |   F12  |  Shift |  Ctrl  |   Alt  |   Gui  |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //|   F1   |   F2   |   F3   |   F4   |   F5   |  |   F6   |   F7   |   F8   |   F9   |   F10  |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //                           | (Held) | BackSp |  |  Space | ADJUST |
  //                           `-----------------'  `-----------------'
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  KC_F11,     KC_F12, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
                               MO(_ADJT), KC_BSPC,     KC_SPC, MO(_ADJT)
  ),

  [_SYMB] = LAYOUT(
  //,--------------------------------------------.  ,--------------------------------------------.
  //|    !   |    @   |    #   |    $   |    %   |  |    ^   |    &   |    *   |    (   |    )   |
  //|--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
  //|    ?   |    _   |    -   |    +   |    |   |  |    `   |    "   |    '   |   :=   |    :   |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //|        |   ../  |    ~   |    =   |    \   |  |    /   |        |    <   |    >   |    ?   |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //                           | ADJUST | BackSp |  |  Space | (Held) |
  //                           `-----------------'  `-----------------'
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
       _void_, KC_UNDS, KC_MINS, KC_PLUS, KC_PIPE,     KC_GRV,  KC_DQT, KC_QUOT, K_CLNEQ, KC_COLN,
       _void_, K_DOTSL, KC_TILD,  KC_EQL, KC_BSLS,    KC_SLSH,  _void_,   KC_LT,   KC_GT, KC_QUES,
                               MO(_ADJT), KC_BSPC,     KC_SPC, MO(_ADJT)
  ),

  [_NAVI] = LAYOUT(
  //,--------------------------------------------.  ,--------------------------------------------.
  //|  Acc.^ |  Acc.~ |  Acc.' |  Acc.` |        |  |  Home  |  PgDn  |  PgUp  |  End   |Hyper(P)|
  //|--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
  //|   Gui  |   Alt  |  Crtl  |  Shift |        |  |  Left  |  Down  |   Up   |  Right |        |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //|        |        |    Ç   |    Ñ   |        |  |        |        |        |        |        |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //                           | HyprSp | Delete |  | (Held) |        |
  //                           `-----------------'  `-----------------'
       _void_,  _void_,  _void_,  _void_,  _void_,    KC_HOME, KC_PGDN, KC_PGUP,  KC_END,HYPR(KC_P),
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  _void_,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  _void_,
       _void_,  _void_,  _void_,  _void_,  _void_,    _void_,  _void_,   _void_,  _void_,  _void_,
                             HYPR(KC_SPC), KC_DEL,    _void_,  _void_
  ),

  [_MOUS] = LAYOUT(
  //,--------------------------------------------.  ,--------------------------------------------.
  //|  QuitW | CloseW | AltTab-Switcher | (Lock) |  | Accel0 | Accel1 | Accel2 |        |        |
  //|--------|--------|-----------------|--------|  |--------|--------|--------|--------|--------|
  //|   Gui  |   Alt  |  Ctrl  |  Shift | BackSp |  | Mous_L | Mous_D | Mous_U | Mous_R |        |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //|  Undo  |   Cut  |  Copy  |  Paste |   Del  |  | Scrl_L | Scrl_D | Scrl_U | Scrl_R |        |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //                           |   Tab  | (Held) |  | Mouse1 | Mouse2 |
  //                           `-----------------'  `-----------------'
       K_Quit, K_Close, K_ALTBP, K_ALTAB, K_LLOCK,    KC_ACL0, KC_ACL1, KC_ACL2,  _void_,  _void_,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_BSPC,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  _void_,
       K_Undo,   K_Cut,  K_Copy, K_Paste,  KC_DEL,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  _void_,
                                  _void_,  _void_,    KC_BTN1, KC_BTN2
  ),

  [_ADJT] = LAYOUT(
  //,--------------------------------------------.  ,--------------------------------------------.
  //|        |        |        |BackLght|Breathng|  |  Play  |  Prev  |  Next  |        |        |
  //|--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
  //|        |        |        |        |        |  |  Mute  |  Vol-  |  Vol+  |        |        |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //|        |        |        |        |        |  |        |  Src-  |  Scr+  |        |        |
  //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
  //                           | (Held) |        |  |        | (Held) |
  //                           `-----------------'  `-----------------'
       _void_,  _void_,  _void_, BL_TOGG, BL_BRTG,    KC_MPLY, KC_MPRV, KC_MNXT,  _void_,  _void_,
       _void_,  _void_,  _void_,  _void_,  _void_,    KC_MUTE, KC_VOLD, KC_VOLU,  _void_,  _void_,
       _void_,  _void_,  _void_,  _void_,  _void_,     _void_, KC_BRID, KC_BRIU,  _void_,  _void_,
                                  _void_,  _void_,     _void_,  _void_
  ),

//   [_GAME] = LAYOUT(
//   //,--------------------------------------------.  ,--------------------------------------------.
//   //|    Q   |    W   |    E   |    R   |    T   |  |    Y   |    U   |    I   |    O   |    P   |
//   //|--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
//   //|    A   |    S   |    D   |    F   |    G   |  |    H   |    J   |    K   |    L   |    ;   |
//   //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
//   //|    Z   |    X   |    C   |    V   |    B   |  |    N   |    M   |    ,   |    .   |    /   |
//   //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
//   //                           |   Tab  | BackSp |  |  XTRA  |  Enter |
//   //                           `-----------------'  `-----------------'
//          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
//          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
//          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
//                                   KC_TAB,  KC_SPC,   LT(_XTRA, KC_SPC), KC_ENT
//   ),

//   [_XTRA] = LAYOUT(
//   //,--------------------------------------------.  ,--------------------------------------------.
//   //|    1   |    2   |    3   |    4   |    5   |  |    6   |    7   |    8   |    9   |    0   |
//   //|--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
//   //|        |        |        |        |        |  |  Left  |  Down  |   Up   |  Right |        |
//   //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
//   //|        |        |        |        |        |  |  Home  |  PgDn  |  PgUp  |  End   |  QRTY  |
//   //|--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
//   //                           |   Tab  | BackSp |  | (Held) |        |
//   //                           `-----------------'  `-----------------'
//          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
//        _void_,  _void_,  _void_,  _void_,  _void_,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  _void_,
//        _void_,  _void_,  _void_,  _void_,  _void_,    KC_HOME, KC_PGDN, KC_PGUP,  KC_END,DF(_QRTY),
//                                   _void_,  _void_,     _void_,  _void_
//   ),
};

//*** Combos!

enum combo_events {
    COMBO_ESC1,  //  U+I+O -> Esc
    COMBO_ESC2,  //  W+E+R -> Esc
    COMBO_CAPSW, //  F+J -> CapsWord
    // COMBO_LPRN,  //  R+T -> (
    // COMBO_RPRN,  //  Y+U -> )
    // COMBO_LCBR,  //  F+G -> {
    // COMBO_RCBR,  //  H+J -> }
    // COMBO_LBRC,  //  V+B -> [
    // COMBO_RBRC,  //  N+M -> ]
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM combo_uio[]    = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_wer[]    = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_fj[]     = {SFT_F, SFT_J, COMBO_END};
// const uint16_t PROGMEM combo_rt[]     = {KC_R, KC_T, COMBO_END};
// const uint16_t PROGMEM combo_yu[]     = {KC_Y, KC_U, COMBO_END};
// const uint16_t PROGMEM combo_fg[]     = {SFT_F, KC_G, COMBO_END};
// const uint16_t PROGMEM combo_hj[]     = {KC_H, SFT_J, COMBO_END};
// const uint16_t PROGMEM combo_vb[]     = {KC_V, KC_B, COMBO_END};
// const uint16_t PROGMEM combo_nm[]     = {KC_N, KC_M, COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
    [COMBO_ESC1]  = COMBO(combo_uio, KC_ESC),
    [COMBO_ESC2]  = COMBO(combo_wer, KC_ESC),
    [COMBO_CAPSW] = COMBO_ACTION(combo_fj),
    // [COMBO_LPRN]  = COMBO(combo_rt, KC_LPRN),
    // [COMBO_RPRN]  = COMBO(combo_yu, KC_RPRN),
    // [COMBO_LCBR]  = COMBO(combo_fg, KC_LCBR),
    // [COMBO_RCBR]  = COMBO(combo_hj, KC_RCBR),
    // [COMBO_LBRC]  = COMBO(combo_vb, KC_LBRC),
    // [COMBO_RBRC]  = COMBO(combo_nm, KC_RBRC)
};

//*** Functions

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // LayerLock
    // if (!process_layer_lock(keycode, record, K_LLOCK)) {
    //     return false;
    // }
    // CapsWord
    if (!process_caps_word(keycode, record)) {
        return false;
    }
    // Alt-Tab disengage
    if (keycode != K_ALTAB && keycode != K_ALTBP) {
        if (is_alt_tab_active) {
            is_alt_tab_active = false;
            unregister_code(KC_LALT);
        }
    }
    // Macros
    switch (keycode) {
        case K_ALTAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case K_ALTBP:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                register_code(KC_LSFT);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
                unregister_code(KC_LSFT);
            }
            break;
        case K_CLNEQ:
            if (record->event.pressed) {
                SEND_STRING(":=");
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
    switch (combo_index) {
        case COMBO_CAPSW:
            if (pressed) {
                caps_word_set(true); // Activate Caps Word!
            }
            break;
            // Other combos...
    }
}

void matrix_scan_user(void) {
    caps_word_task();
    // Other tasks...
}

//*** Tapping term per key

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_A:
        case GUI_SCLN:
            return TAPPING_TERM_PINKY;
        default:
            return TAPPING_TERM;
    }
}
