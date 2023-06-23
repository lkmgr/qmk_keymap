#include QMK_KEYBOARD_H

enum layers {
    _CLMK,
    _LOWER,
    _RAISE,
    _SYS,
};

// Tap-Hold keys
#define SFT_SPC LSFT_T(KC_SPACE)
#define SFT_ENT RSFT_T(KC_ENTER)
// Layers
#define L_LOWER MO(1)
#define L_RAISE MO(2)
// Word operations
#define WORD_L LCTL(KC_LEFT)
#define WORD_R LCTL(KC_RIGHT)
#define WORD_D LCTL(KC_BSPC)
// Text shortcuts
#define L_UNDO LSFT(KC_Z)
#define L_CUT LSFT(KC_X)
#define L_COPY LSFT(KC_C)
#define L_REDO LSFT(KC_Y)
#define L_PASTE LSFT(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_CLMK] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,               KC_MPLY, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX,    XXXXXXX, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ESC,
                                   XXXXXXX, KC_LGUI, L_LOWER, SFT_SPC,    SFT_ENT, L_RAISE, KC_RALT, KC_APP
    ),

    [_LOWER] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, WORD_D,  WORD_L,  WORD_R,  _______,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        KC_CAPS, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),

    [_RAISE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, _______, _______, _______, _______, _______,                      KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
        _______, L_UNDO,  L_CUT,   L_COPY,  L_REDO,  L_PASTE, _______,    _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),

    [_SYS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,             XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, 1, 2, 3);
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_CLMK] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_LOWER] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_RAISE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_SYS] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) }
};
#endif
