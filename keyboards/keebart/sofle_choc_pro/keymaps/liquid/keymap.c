// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include "alias.def"

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
bool rec2_active = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_split_4x6_5(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_LCBR, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RCBR,
  KC_LPRN, HOME_A,  HOME_S,  HOME_D,  HOME_F,  HOME_G,                    HOME_H,  HOME_J,  HOME_K,  HOME_L,  HOME_BS, KC_RPRN,
  KC_LBRC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE, KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
  /*             */ KC_NO,   QK_REP,  KC_GRV,  LL_EQL,  LU_SPC,  LU_SPC,  LL_MINS, KC_QUOT, KC_RGUI, KC_PSCR
),
[LOWER] = LAYOUT_split_4x6_5(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  /*             */ _______, _______, _______, QK_LLCK, LA_SPC,  LA_SPC,  QK_LLCK, _______, _______, _______
),
[UPPER] = LAYOUT_split_4x6_5(
  QK_BOOT, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, QK_BOOT,
  _______, _______, KC_PGUP, KC_UP,   KC_PGDN, KC_VOLU,                   KC_MINS, KC_7,    KC_8,    KC_9,    KC_PLUS, _______,
  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD,                   KC_EQL,  KC_4,    KC_5,    KC_6,    _______, _______,
  _______, _______, _______, _______, _______, KC_MUTE, _______, RM_TOGG, KC_ASTR, KC_1,    KC_2,    KC_3,    _______, _______,
  /*             */ _______, _______, _______, LA_MO,   QK_LLCK, QK_LLCK, LA_0,    KC_DOT,  KC_COMM, _______
),
[ADJUST] = LAYOUT_split_4x6_5(
  _______, QMK_1,   QMK_2,   QMK_3,   QMK_4,   QMK_5,                     QMK_6,   QMK_7,   QMK_8,   QMK_9,   QMK_0,   _______,
  _______, PB_1,    PB_2,    PB_3,    PB_4,    PB_5,                      _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
  _______, PB_6,    PB_7,    PB_8,    PB_9,    PB_10,                     _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
  _______, PB_11,   PB_12,   PB_13,   PB_14,   PB_15,   PB_16,   _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
  /*             */ _______, _______, _______, QK_LLCK, QK_LLCK, QK_LLCK, QK_LLCK, _______, _______, _______
)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [LOWER] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [UPPER] = { ENCODER_CCW_CW(RM_PREV, RM_NEXT), ENCODER_CCW_CW(RM_SPDD, RM_SPDU) },
    [ADJUST] = { ENCODER_CCW_CW(RM_PREV, RM_NEXT), ENCODER_CCW_CW(RM_SPDD, RM_SPDU) },
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
  // layer activity
  switch (get_highest_layer(layer_state | default_layer_state)) {
  case LOWER:
    RGB_MATRIX_INDICATOR_SET_COLOR(2, 255, 255, 255);
    RGB_MATRIX_INDICATOR_SET_COLOR(32, 255, 255, 255);
    break;
  case UPPER:
    RGB_MATRIX_INDICATOR_SET_COLOR(1, 255, 255, 255);
    RGB_MATRIX_INDICATOR_SET_COLOR(31, 255, 255, 255);
    break;
  case ADJUST:
    RGB_MATRIX_INDICATOR_SET_COLOR(1, 255, 255, 255);
    RGB_MATRIX_INDICATOR_SET_COLOR(2, 255, 255, 255);
    RGB_MATRIX_INDICATOR_SET_COLOR(31, 255, 255, 255);
    RGB_MATRIX_INDICATOR_SET_COLOR(32, 255, 255, 255);
    break;
  }

  // dynamic macro recording button
  if (rec1_active) {
    RGB_MATRIX_INDICATOR_SET_COLOR(39, 255, 0, 0);
  }
  if (rec2_active) {
    RGB_MATRIX_INDICATOR_SET_COLOR(44, 255, 0, 0);
  }

  // TODO: Make master sync caps word state to slave
  if (is_caps_word_on()) {
    RGB_MATRIX_INDICATOR_SET_COLOR(14, 255, 255, 255);
    RGB_MATRIX_INDICATOR_SET_COLOR(44, 255, 255, 255);
  }
  return false;
};

bool dynamic_macro_record_start_user(int8_t direction) {
  switch (direction) {
  case 1:
    rec1_active = true;
    break;

  case -1:
    rec2_active = true;
    break;
  }
  return true;
};

bool dynamic_macro_record_end_user(int8_t direction) {
  switch (direction) {
  case 1:
    rec1_active = false;
    break;

  case -1:
    rec2_active = false;
    break;
  }
  return true;
};

#endif
