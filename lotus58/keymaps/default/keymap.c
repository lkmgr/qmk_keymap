#include QMK_KEYBOARD_H

enum layers {
    _CLMK,
    _LOWER,
    _RAISE,
    _SYS,
};

enum combos {
    ST_ESC,
    NE_BSPC,
};

const uint16_t PROGMEM st_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM ne_combo[] = {KC_N, KC_E, COMBO_END};

combo_t key_combos[] = {
  [ST_ESC] = COMBO(st_combo, KC_ESC),
  [NE_BSPC] = COMBO(ne_combo, KC_BSPC),
};

// Mod-Tap keys
#define SFT_SPC LSFT_T(KC_SPACE)
#define SFT_ENT RSFT_T(KC_ENTER)

// Layers
#define L_LOWER MO(_LOWER)
#define L_RAISE MO(_RAISE)
// #define L_LOWER OSL(_LOWER)
// #define L_RAISE OSL(_RAISE)

// One Shot Keys
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_SFT OSM(MOD_LSFT)

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
        OSM_CTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        OSM_SFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX,    XXXXXXX, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ESC,
                                   XXXXXXX, OSM_GUI, L_LOWER, SFT_SPC,    SFT_ENT, L_RAISE, OSM_ALT, KC_APP
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
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_RBT,  QK_BOOT,             XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, CM_TOGG, OS_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
