#include QMK_KEYBOARD_H

enum planck_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _VIM,
    _NUMPAD,
    _ADJUST,
    _CELLO,
    _GUITAR
};

enum planck_keycodes {
    QWERTY = SAFE_RANGE
};

#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define VIM     MO(_VIM)
#define PAD     MO(_NUMPAD)
#define ADJUST  MO(_ADJUST)
#define CELLO   TG(_CELLO)
#define GUITAR  TG(_GUITAR)

#define ALT_SFT RALT(KC_RSFT)
#define GUI_SFT RGUI(KC_RSFT)
#define CTL_SFT RCTL(KC_RSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_planck_grid(
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC,
        KC_ESC, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_ENT,
        PAD,    KC_LCTL,KC_LGUI,KC_LALT,LOWER,  VIM,    KC_SPC, RAISE,  ALT_SFT,GUI_SFT,CTL_SFT,CW_TOGG
    ),
    [_LOWER] = LAYOUT_planck_grid(
        KC_TILD,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,_______,
        KC_DEL, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,KC_PIPE,
        _______,KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,ADJUST, KC_MUTE,KC_VOLD,KC_VOLU,KC_MPLY
    ),
    [_RAISE] = LAYOUT_planck_grid(
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   _______,
        KC_DEL, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_MINS,KC_EQL, KC_LBRC,KC_RBRC,KC_BSLS,
        _______,KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,_______,_______,_______,_______,
        _______,_______,_______,_______,ADJUST, _______,_______,_______,_______,_______,_______,_______
    ),
    [_VIM] = LAYOUT_planck_grid(
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        KC_ESC, _______,_______,_______,KC_PGDN,KC_HOME,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,_______,_______,
        _______,_______,_______,_______,_______,KC_PGUP,KC_END, _______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
    ),
    [_NUMPAD] = LAYOUT_planck_grid(
        _______,_______,KC_UP,  _______,_______,_______,_______,_______,KC_7,   KC_8,   KC_9,   KC_SLSH,
        _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,_______,_______,KC_4,   KC_5,   KC_6,   KC_ASTR,
        _______,_______,_______,_______,_______,_______,_______,_______,KC_1,   KC_2,   KC_3,   KC_MINS,
        _______,_______,_______,_______,_______,_______,_______,_______,KC_DOT, KC_0,   KC_ENT, KC_PLUS 
    ),
    [_ADJUST] = LAYOUT_planck_grid(
        XXXXXXX,QK_BOOT,DB_TOGG,XXXXXXX,RGB_TOG,RGB_HUI,RGB_HUD,RGB_SAI,RGB_SAD,RGB_VAI,RGB_VAD,XXXXXXX,
        EE_CLR, XXXXXXX,MU_NEXT,AU_ON,  AU_OFF, XXXXXXX,XXXXXXX,GUITAR, XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,AU_NEXT,AU_PREV,MU_ON,  MU_OFF, MI_ON,  MI_OFF, CELLO,  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
    ),
    [_CELLO] = LAYOUT_planck_grid(
        MI_C2,  MI_Cs2, MI_D2,  MI_Ds2, MI_E2,  MI_F2,  MI_Fs2, MI_G2,  MI_Gs2, MI_A2,  MI_As2, MI_B2,
        MI_C1,  MI_Cs1, MI_D1,  MI_Ds1, MI_E1,  MI_F1,  MI_Fs1, MI_G1,  MI_Gs1, MI_A1,  MI_As1, MI_B1,
        MI_C,   MI_Cs,  MI_D,   MI_Ds,  MI_E,   MI_F,   MI_Fs,  MI_G,   MI_Gs,  MI_A,   MI_As,  MI_B,
        CELLO,  _______,_______,_______,MI_OCTD,MI_OC1, MI_OC3, MI_OCTU,MI_TRN2,MI_TRN1,MI_TR1, MI_TR2    
    ),
    [_GUITAR] = LAYOUT_planck_grid(
        MI_E2,  MI_F2,  MI_Fs2, MI_G2,  MI_Gs2, MI_A2,  MI_As2, MI_B2,  MI_C3,  MI_Cs3, MI_D3,  MI_Ds3,
        MI_E1,  MI_F1,  MI_Fs1, MI_G1,  MI_Gs1, MI_A1,  MI_As1, MI_B1,  MI_C2,  MI_Cs2, MI_D2,  MI_Ds2,
        MI_E,   MI_F,   MI_Fs,  MI_G,   MI_Gs,  MI_A,   MI_As,  MI_B,   MI_C1,  MI_Cs1, MI_D1,  MI_Ds1,
        GUITAR, _______,_______,_______,MI_OCTD,MI_OC1, MI_OC3, MI_OCTU,MI_TRN2,MI_TRN1,MI_TR1, MI_TR2
    )
};
