// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum layers {
    BASE,  // default layer
    LT_1,  // First layer
    LT_2   // Second layer
};

enum custom_keycodes {
  QMK_0 = SAFE_RANGE,
  QMK_1,
  QMK_2,
  QMK_3,
  QMK_4,
  QMK_5,
  QMK_6,
  QMK_7,
  QMK_8,
  QMK_9
};

bool rec1_active = false;

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)
#define CMP_G RALT_T(KC_G)

// Right-hand home row mods
#define CMP_H RALT_T(KC_H)
#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_BSP RGUI_T(KC_BSPC)

// layer mods
#define L1_EQL LT(LT_1, KC_EQUAL)
#define L1_MINS LT(LT_1, KC_MINUS)
#define L2_SPC LT(LT_2, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_split_4x6_5(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_LCBR, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RCBR,
  KC_LPRN, GUI_A,   ALT_S,   SFT_D,   CTL_F,   CMP_G,                     CMP_H,   CTL_J,   SFT_K,   ALT_L,   GUI_BSP, KC_RPRN,
  KC_LBRC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE, KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
                    KC_NO,   QK_REP,  KC_GRV,  L1_EQL,  L2_SPC,  L2_SPC,  L1_MINS, KC_QUOT, KC_RGUI, KC_PSCR
),
[LT_1] = LAYOUT_split_4x6_5(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[LT_2] = LAYOUT_split_4x6_5(
  QK_BOOT, QMK_1,   QMK_2,   QMK_3,   QMK_4,   QMK_5,                     QMK_6,   QMK_7,   QMK_8,   QMK_9,   QMK_0,   QK_BOOT,
  _______, PB_1,    PB_2,    PB_3,    PB_4,    PB_5,                      KC_MINS, KC_7,    KC_8,    KC_9,    KC_PLUS, _______,
  _______, PB_6,    PB_7,    PB_8,    PB_9,    PB_10,                     KC_EQL,  KC_4,    KC_5,    KC_6,    _______, _______,
  _______, PB_11,   PB_12,   PB_13,   PB_14,   PB_15,   PB_16,   RM_TOGG, KC_ASTR, KC_1,    KC_2,    KC_3,    _______, _______,
                    _______, _______, _______, DM_PLY1, _______, QK_LLCK, KC_0,    KC_DOT,  KC_COMM, _______
)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [LT_1] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LT_2] = { ENCODER_CCW_CW(RM_PREV, RM_NEXT), ENCODER_CCW_CW(RM_SPDD, RM_SPDU) }
};
#endif

#ifdef COMBO_MUST_TAP_PER_COMBO
bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
  // makes all combos to be tap-only
  return true;
};
#endif

#ifdef RGB_MATRIX_ENABLE

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

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // layer 1 activity
    if (LT_1 == get_highest_layer(layer_state)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(2, 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(32, 255, 255, 255);
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(2, 0, 0, 0);
        RGB_MATRIX_INDICATOR_SET_COLOR(32, 0, 0, 0);
    }

    // layer 2 activity
    if (LT_2 == get_highest_layer(layer_state)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(1, 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(31, 255, 255, 255);
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(1, 0, 0, 0);
        RGB_MATRIX_INDICATOR_SET_COLOR(31, 0, 0, 0);
    }

    // dynamic macro recording button
    if (rec1_active) {
        RGB_MATRIX_INDICATOR_SET_COLOR(39, 255, 0, 0);
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(39, 0, 0, 0);
    }

    // TODO: Make master sync caps word state to slave
    if (is_caps_word_on()) {
      //RGB_MATRIX_INDICATOR_SET_COLOR(14, 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(44, 255, 255, 255);
    } else {
      //RGB_MATRIX_INDICATOR_SET_COLOR(14, 0, 0, 0);
        RGB_MATRIX_INDICATOR_SET_COLOR(44, 0, 0, 0);
    }
    return false;
};

bool dynamic_macro_record_start_user(int8_t direction) {
  rec1_active = true;
  return true;
};

bool dynamic_macro_record_end_user(int8_t direction) {
  rec1_active = false;
  return true;
};

#endif
