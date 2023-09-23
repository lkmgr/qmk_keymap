#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NAV,
    _MOUSE,
    _NUM,
    _SYM,
    _FUN,
    _SYS
};

// Mod-Tap keys
#define H_GUI_A LGUI_T(KC_A)
#define H_ALT_R LALT_T(KC_R)
#define H_CTL_S LCTL_T(KC_S)
#define H_SFT_T LSFT_T(KC_T)

#define H_SFT_N LSFT_T(KC_N)
#define H_CTL_E LCTL_T(KC_E)
#define H_ALT_I LALT_T(KC_I)
#define H_GUI_O LGUI_T(KC_O)

// Layers
#define NAV_SPC LT(_NAV,KC_SPC)
#define MSE_TAB LT(_MOUSE,KC_TAB)
#define NUM_BSP LT(_NUM,KC_BSPC)
#define SYM_ENT LT(_SYM,KC_ENT)
#define FUN_DEL LT(_FUN,KC_DEL)
// #define MED_ESC LT(U_MEDIA,KC_ESC)
#define SYS_ESC LT(_SYS,KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        H_GUI_A, H_ALT_R, H_CTL_S, H_SFT_T, KC_G,                         KC_M,    H_SFT_N, H_CTL_E, H_ALT_I, H_GUI_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                   SYS_ESC, NAV_SPC, MSE_TAB,    SYM_ENT, NUM_BSP, FUN_DEL
    )
};
