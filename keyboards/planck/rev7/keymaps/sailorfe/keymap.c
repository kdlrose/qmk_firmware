#include QMK_KEYBOARD_H

enum planck_layers { _QWERTY, _LOWER, _RAISE, _UTF_1, _UTF_2, _SIDER, _VIM, _NUMPAD, _ADJUST };

enum planck_keycodes { QWERTY = SAFE_RANGE };

#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define OPT_UTF MO(_UTF_1) 
#define UTF_SFT MO(_UTF_2)
#define SID     MO(_SIDER)
#define VIM     MO(_VIM)
#define PAD     MO(_NUMPAD)
#define ADJUST  MO(_ADJUST)
#define ALT_SFT RALT(KC_RSFT)
#define GUI_SFT RGUI(KC_RSFT)
#define CTL_SFT RCTL(KC_RSFT)

enum unicode_names { AE, AG, HG, CU, FE, SN, PB, UNS, NPN, PLT, ARIES, TAURUS, GEMINI, CANCER, LEO, VIRGO, LIBRA, SCORPIO, SAGITTARIUS, CAPRICORN, AQUARIUS, PISCES, CJT, STL, SQR, TRN, OPP, NND, SND, END, EMD, DGR };

const uint32_t PROGMEM unicode_map[] = {
    [AE] = 0x2609,  // ☉
    [AG] = 0x263D,  // ☽
    [HG] = 0x263F,  // ☿
    [CU] = 0x2640,  // ♀
    [FE] = 0x2642,  // ♂
    [SN] = 0x2643,  // ♃
    [PB] = 0x2644,  // ♄
    [UNS] = 0x2645, // ♅
    [NPN] = 0x2646, // ♆
    [PLT] = 0x2647, // ♇
    [ARIES] = 0x2648,       // ♈︎
    [TAURUS] = 0x2649,      // ♉︎
    [GEMINI] = 0x264A,      // ♊︎
    [CANCER] = 0x264B,      // ♋︎
    [LEO] = 0x264C,         // ♌︎
    [VIRGO] = 0x264D,       // ♍︎
    [LIBRA] = 0x264E,       // ♎︎
    [SCORPIO] = 0x264F,     // ♏︎
    [SAGITTARIUS] = 0x2650, // ♐︎
    [CAPRICORN] = 0x2651,   // ♑︎
    [AQUARIUS] = 0x2652,    // ♒︎
    [PISCES] = 0x2653,      // ♓︎
    [CJT] = 0x260C, // ☌
    [STL] = 0x26B9, // ⚹
    [SQR] = 0x25A1, // □
    [TRN] = 0x25B3, // △
    [OPP] = 0x260D, // ☍
    [NND] = 0x260A, // ☊
    [SND] = 0x260B, // ☋
    [END] = 0x2013,     // –
    [EMD] = 0x2014,     // —
    [DGR]  = 0x00B0     // °
};

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
        _______,_______,_______,_______,_______,_______,_______,ADJUST, SID,    KC_VOLD,KC_VOLU,_______
    ),
    [_RAISE] = LAYOUT_planck_grid(
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   _______,
        KC_DEL, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_MINS,KC_EQL, KC_LBRC,KC_RBRC,KC_BSLS,
        _______,KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,_______,_______,_______,_______,
        _______,_______,_______,OPT_UTF,ADJUST, _______,_______,_______,_______,_______,_______,_______
    ),
    [_UTF_1] = LAYOUT_planck_grid(
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,       
        _______,_______,_______,_______,_______,_______,_______,UM(END),_______,_______,_______,_______,      
        UTF_SFT,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,      
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______       
    ),
    [_UTF_2] = LAYOUT_planck_grid(
        _______,_______,_______,_______,_______,_______,_______,_______,UM(DGR),_______,_______,_______,       
        _______,_______,_______,_______,_______,_______,_______,UM(EMD),_______,_______,_______,_______,      
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,      
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______       
    ),
    [_SIDER] = LAYOUT_planck_grid(
        /* row 1*/
        _______,
        _______,
        UP(CAPRICORN, AQUARIUS),
        UP(SAGITTARIUS, PISCES),
        UM(LEO),
        _______,
        _______,
        UM(CANCER),
        UP(TAURUS, LIBRA), 
        UP(ARIES, SCORPIO),
        UM(PLT),
        _______,
        /*home row*/    
        _______,
        _______,
        UM(PB),
        UM(SN),
        UM(AE),
        UM(HG),
        UP(GEMINI, VIRGO),
        UM(AG),
        UM(CU),
        UM(FE),
        _______,
        _______,
        /*row 3*/
        _______,
        _______,
        UM(UNS),
        UM(NPN),
        _______,
        _______,
        _______,
        UP(SND, NND),
        UP(STL, TRN),
        UP(SQR, OPP),
        UM(CJT),
        _______,
        /*row 4*/
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______       
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
        EE_CLR, XXXXXXX,MU_NEXT,AU_ON,  AU_OFF, XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,AU_NEXT,AU_PREV,MU_ON,  MU_OFF, XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
    )
};
