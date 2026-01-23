// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    BASE,  // default layer
    LT_1,  // First layer
    LT_2   // Second layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | RCTL |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LT2  | LGUI | LALT | LGUI | /Space  /       \Space \  | RGUI | RALT | RGUI | PSCR |
 *            |      |      |      |  LT1 |/       /         \      \ | LT1  |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[BASE] = LAYOUT_split_4x6_5(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_MINUS,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_RCTL,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,   KC_MPLY,    KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
              MO(LT_2), KC_LGUI, KC_LALT, LT(LT_1,KC_LGUI), KC_SPC,  KC_SPC, LT(LT_1,KC_LGUI), KC_RALT, KC_RGUI,  KC_PSCR
),
/* LT_1
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  '   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    | Pause |------+------+------+------+------+------|
 * |LShift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LALT | LGUI | /Enter  /       \Enter \  | RGUI | RALT | RGUI | PSCR |
 *            |      |      |      |  LT1 |/       /         \      \ | LT1  |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[LT_1] = LAYOUT_split_4x6_5(
  KC_QUOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                    _______, _______, _______, _______, KC_ENT,        KC_ENT,  _______, _______, _______, _______
),
/* LT_2
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   /  |   7  |   8  |   9  |   -  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   =  |   4  |   5  |   6  |   +  | RCTL |
 * |------+------+------+------+------+------|  BTN1 |    |  TOGG |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   *  |   1  |   2  |   3  |   ,  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LT2  | LGUI | LALT | LGUI | /Space  /       \Space \  |   0  |   .  | RGUI | PSCR |
 *            |      |      |      |  LT1 |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[LT_2] = LAYOUT_split_4x6_5(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
  _______, _______, _______, _______, _______, _______,                         KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINUS, _______,
  _______, _______, _______, _______, _______, _______,                         KC_EQL,  KC_4,    KC_5,    KC_6,    KC_PLUS,  _______,
  _______, _______, _______, _______, _______, _______, _______,       UG_TOGG, KC_ASTR, KC_1,    KC_2,    KC_3,    KC_COMM,  _______,
                    _______, _______, _______, _______, _______,       _______, KC_0,    KC_DOT,  _______, _______
)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [LT_1] = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP), ENCODER_CCW_CW(KC_DOWN, KC_UP) },
    [LT_2] = { ENCODER_CCW_CW(UG_SATD, UG_SATU), ENCODER_CCW_CW(UG_PREV, UG_NEXT) }
};
#endif

#ifdef RGBLIGHT_ENABLE

/* LED index
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  26  |  25  |  17  |  16  |   7  |   6  |                    |  36  |  37  |  46  |  47  |  55  |  56  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  27  |  24  |  18  |  15  |   8  |   5  |                    |  35  |  38  |  45  |  48  |  54  |  57  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  28  |  23  |  19  |  14  |   9  |   4  |-------.    ,-------|  34  |  39  |  44  |  49  |  53  |  58  |
 * |------+------+------+------+------+------|   0   |    |  30   |------+------+------+------+------+------|
 * |  29  |  22  |  20  |  13  |  10  |   3  |-------|    |-------|  33  |  40  |  43  |  50  |  52  |  59  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  21  |  12  |  11  |   2  | /   1   /       \ 31   \  |  32  |  41  |  42  |  51 |
 *            |      |      |      |      |/       /         \      \ |      |      |      |     |
 *            `----------------------------------'           '------''---------------------------'
 */

// Default Layer
const rgblight_segment_t PROGMEM my_default_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  // left numbers
  {6, 2, HSV_BLUE},
  {16, 2, HSV_BLUE},
  {25, 1, HSV_BLUE},
  // right numbers
  {36, 2, HSV_BLUE},
  {46, 2, HSV_BLUE},
  {55, 1, HSV_BLUE},
  // left mods
  {2, 1, HSV_RED},
  {28, 2, HSV_RED},
  {11, 1, HSV_RED},
  {12, 1, HSV_RED},
  {21, 1, HSV_RED},
  // right mods
  {32, 1, HSV_RED},
  {58, 2, HSV_RED},
  {41, 1, HSV_RED},
  {42, 1, HSV_RED},
  {51, 1, HSV_RED},
  // left misc
  {26, 1, HSV_CYAN}
);

// Layer 1
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  // left numbers
  {5, 1, HSV_BLUE},
  {8, 1, HSV_BLUE},
  {15, 1, HSV_BLUE},
  {18, 1, HSV_BLUE},
  {24, 1, HSV_BLUE},
  // right numbers
  {35, 1, HSV_BLUE},
  {38, 1, HSV_BLUE},
  {45, 1, HSV_BLUE},
  {48, 1, HSV_BLUE},
  {54, 1, HSV_BLUE},
  // left FN keys
  {6, 2, HSV_YELLOW},
  {16, 2, HSV_YELLOW},
  {25, 1, HSV_YELLOW},
  // right FN keys
  {36, 2, HSV_YELLOW},
  {46, 2, HSV_YELLOW},
  {55, 3, HSV_YELLOW},
  // left special characters
  {3, 2, HSV_GREEN},
  {9, 2, HSV_GREEN},
  {13, 2, HSV_GREEN},
  {19, 2, HSV_GREEN},
  {22, 2, HSV_GREEN},
  {26, 2, HSV_GREEN},
  // right special characters
  {33, 2, HSV_GREEN},
  {39, 2, HSV_GREEN},
  {43, 2, HSV_GREEN},
  {49, 2, HSV_GREEN},
  {52, 2, HSV_GREEN},
  {58, 1, HSV_GREEN}
);

// Layer 2
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  // left numbers
  {6, 2, HSV_BLACK},
  {16, 2, HSV_BLACK},
  {25, 1, HSV_BLACK},
  // right numbers
  {36, 2, HSV_BLACK},
  {46, 2, HSV_BLACK},
  {55, 1, HSV_BLACK},
  {32, 1, HSV_BLUE},
  {38, 3, HSV_BLUE},
  {43, 3, HSV_BLUE},
  {48, 3, HSV_BLUE},
  // operators
  {33, 3, HSV_GREEN},
  {52, 3, HSV_GREEN},
  {41, 1, HSV_GREEN}
);

// Combine into a list
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_default_layer,
    my_layer1_layer,
    my_layer2_layer
);

// Initialize in keymap
void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, LT_1));
    rgblight_set_layer_state(2, layer_state_cmp(state, LT_2));
    return state;
}

#endif
