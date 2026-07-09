// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include "alias.def"
#include "transactions.h"

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

const int ch2rgbidx[] = {26, 25, 17, 16, 7, 6, 36, 37, 46, 47, 55, 56};

bool rec1_active = false;
bool rec2_active = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_split_4x6_5(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
  _______, HOME_A,  HOME_S,  HOME_D,  HOME_F,  HOME_G,                    HOME_H,  HOME_J,  HOME_K,  HOME_L,  HOME_BS, _______,
  _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE, KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
  /*             */ LM_MO,   QK_REP,  _______, LL_EQL,  LU_SPC,  LU_SPC,  LL_MINS, _______, _______, KC_PSCR
),
[LOWER] = LAYOUT_split_4x6_5(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, _______,
  _______, _______, KC_LCBR, KC_LBRC, KC_LPRN, _______, _______, _______, _______, KC_RPRN, KC_RBRC, KC_RCBR, _______, _______,
  /*             */ _______, _______, _______, QK_LLCK, LA_SPC,  LA_SPC,  QK_LLCK, _______, _______, _______
),
[UPPER] = LAYOUT_split_4x6_5(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, KC_PGUP, KC_UP,   KC_PGDN, KC_VOLU,                   KC_MINS, KC_7,    KC_8,    KC_9,    KC_PLUS, _______,
  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD,                   KC_EQL,  KC_4,    KC_5,    KC_6,    _______, _______,
  _______, _______, _______, _______, _______, KC_MUTE, _______, RM_TOGG, KC_ASTR, KC_1,    KC_2,    KC_3,    _______, _______,
  /*             */ _______, _______, _______, LA_MO,   QK_LLCK, QK_LLCK, LA_0,    KC_DOT,  KC_COMM, _______
),
[ADJUST] = LAYOUT_split_4x6_5(
  QK_BOOT, QMK_1,   QMK_2,   QMK_3,   QMK_4,   QMK_5,                     QMK_6,   QMK_7,   QMK_8,   QMK_9,   QMK_0,   QK_BOOT,
  _______, PB_1,    PB_2,    PB_3,    PB_4,    PB_5,                      _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
  _______, PB_6,    PB_7,    PB_8,    PB_9,    PB_10,                     _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
  _______, PB_11,   PB_12,   PB_13,   PB_14,   PB_15,   PB_16,   _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
  /*             */ _______, _______, _______, QK_LLCK, QK_LLCK, QK_LLCK, QK_LLCK, _______, _______, _______
),
[MIDI] = LAYOUT_split_4x6_5(
  MI_CH1,  MI_CH2,  MI_CH3,  MI_CH4,  MI_CH5,  MI_CH6,                    MI_CH7,  MI_CH8,  MI_CH9,  MI_CH10, MI_CH11, MI_CH12,
  MI_C2,   MI_Cs2,  MI_D2,   MI_Ds2,  MI_E2,   MI_F2,                     MI_Fs2,  MI_G2,   MI_Gs2,  MI_A2,   MI_As2,  MI_B2,
  MI_C3,   MI_Cs3,  MI_D3,   MI_Ds3,  MI_E3,   MI_F3,                     MI_Fs3,  MI_G3,   MI_Gs3,  MI_A3,   MI_As3,  MI_B3,
  MI_C4,   MI_Cs4,  MI_D4,   MI_Ds4,  MI_E4,   MI_F4,   _______, _______, MI_Fs4,  MI_G4,   MI_Gs4,  MI_A4,   MI_As4,  MI_B4,
  /*             */ _______, _______, _______, QK_LLCK, QK_LLCK, QK_LLCK, QK_LLCK, _______, _______, _______
)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [LOWER] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [UPPER] = { ENCODER_CCW_CW(RM_PREV, RM_NEXT), ENCODER_CCW_CW(RM_SPDD, RM_SPDU) },
    [ADJUST] = { ENCODER_CCW_CW(RM_PREV, RM_NEXT), ENCODER_CCW_CW(RM_SPDD, RM_SPDU) },
    [MIDI] = { ENCODER_CCW_CW(MI_VELU, MI_VELD), ENCODER_CCW_CW(MI_OCTU, MI_OCTD) },
};
#endif

#ifdef COMBO_MUST_TAP_PER_COMBO
bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
  // makes all combos to be tap-only
  return true;
};
#endif

#ifdef MIDI_ADVANCED
typedef struct _master_to_slave_user_a_t {
  uint8_t midi_channel;
} master_to_slave_user_a_t;

void user_sync_a_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
  const master_to_slave_user_a_t *m2s = (const master_to_slave_user_a_t*)in_data;
  midi_config.channel = m2s->midi_channel;
}
#endif

#ifdef CAPS_WORD_ENABLE
bool caps_word_active = false;

typedef struct _master_to_slave_user_b_t {
  bool caps_word_active;
} master_to_slave_user_b_t;

void user_sync_b_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
  const master_to_slave_user_b_t *m2s = (const master_to_slave_user_b_t*)in_data;
  caps_word_active = m2s->caps_word_active;
}

void caps_word_set_user(bool active) {
  caps_word_active = active;

  if (is_keyboard_master()) {
    master_to_slave_user_b_t m2s = {active};
    transaction_rpc_send(USER_SYNC_B, sizeof(m2s), &m2s);
  }
}
#endif

void keyboard_post_init_user(void) {
#ifdef MIDI_ADVANCED
  transaction_register_rpc(USER_SYNC_A, user_sync_a_slave_handler);
#endif

#ifdef CAPS_WORD_ENABLE
  transaction_register_rpc(USER_SYNC_B, user_sync_b_slave_handler);
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
#ifdef MIDI_ADVANCED
  case MIDI_CHANNEL_MIN ... MIDI_CHANNEL_MAX:
    if (record->event.pressed && is_keyboard_master()) {
      master_to_slave_user_a_t m2s = {keycode - MIDI_CHANNEL_MIN};
      transaction_rpc_send(USER_SYNC_A, sizeof(m2s), &m2s);
    }
#endif
  }

  return true;
}

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
  case MIDI:
    RGB_MATRIX_INDICATOR_SET_COLOR(21, 255, 255, 255);
    RGB_MATRIX_INDICATOR_SET_COLOR(ch2rgbidx[midi_config.channel], 255, 255, 255);
    break;
  }

  // dynamic macro recording button
  if (rec1_active) {
    RGB_MATRIX_INDICATOR_SET_COLOR(39, 255, 0, 0);
  }
  if (rec2_active) {
    RGB_MATRIX_INDICATOR_SET_COLOR(44, 255, 0, 0);
  }

#ifdef CAPS_WORD_ENABLE
  if (caps_word_active) {
    RGB_MATRIX_INDICATOR_SET_COLOR(14, 255, 255, 255);
    RGB_MATRIX_INDICATOR_SET_COLOR(44, 255, 255, 255);
  }
#endif

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
