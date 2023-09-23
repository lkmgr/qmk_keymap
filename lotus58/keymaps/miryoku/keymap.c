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
// #define SFT_SPC LSFT_T(KC_SPACE)
// #define SFT_ENT RSFT_T(KC_ENTER)
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
    [_BASE] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, XXXXXXX,
        XXXXXXX, H_GUI_A, H_ALT_R, H_CTL_S, H_SFT_T, KC_G,                         KC_M,    H_SFT_N, H_CTL_E, H_ALT_I, H_GUI_O, XXXXXXX,
        XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX,    XXXXXXX, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
                                   XXXXXXX, SYS_ESC, NAV_SPC, MSE_TAB,    SYM_ENT, NUM_BSP, FUN_DEL, XXXXXXX
    ),

    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                      CW_TOGG, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, _______, KC_ALGR, _______, _______, _______, _______,    _______, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                   _______, _______, _______, _______,    KC_ENT,  KC_BSPC, KC_DEL,  _______
    ),

    [_MOUSE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                      _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
        _______, _______, KC_ALGR, _______, _______, _______, _______,    _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
                                   _______, _______, _______, _______,    KC_BTN2, KC_BTN1, KC_BTN3, _______
    ),

    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                      _______, _______, _______, _______, _______, _______,
        _______, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                       _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
        _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______,    _______, _______, _______, _______, KC_ALGR, _______, _______,
                                   _______, KC_DOT,  KC_0,    KC_MINS,    _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LBRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                      _______, _______, _______, _______, _______, _______,
        _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                      _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
        _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______,    _______, _______, _______, _______, KC_ALGR, _______, _______,
                                   _______, KC_LPRN, KC_RPRN, KC_UNDS,    _______, _______, _______, _______
    ),

    [_FUN] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                      _______, _______, _______, _______, _______, _______,
        _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                      _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
        _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______,    _______, _______, _______, _______, KC_ALGR, _______, _______,
                                   _______, KC_APP,  KC_SPC,  KC_TAB,     _______, _______, _______, _______
    ),

    [_SYS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_RBT,  QK_BOOT,             XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, CM_TOGG, OS_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//    return update_tri_layer_state(state, 1, 2, 3);
// }

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_NAV] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_MOUSE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_NUM] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_SYM] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_FUN] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_SYS] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) }
};
#endif
