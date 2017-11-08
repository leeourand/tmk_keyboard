#include "keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, \
         KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, \
         KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, \
         KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_FN5, KC_FN6,     \
         KC_SPC, KC_FN0, KC_MINS, KC_SLSH, KC_ENT),                     \
  /* 1: punctuation and numbers */
  FN_LAYER,                                     \
  /* 2: arrows and function keys */
  LAYER_TWO,
  /* 3: mouse */
  KEYMAP(KC_NO, KC_NO, KC_FN8, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
         KC_NO, KC_FN10, KC_FN9, KC_FN11, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   \
         KC_NO, KC_NO, KC_FN13, KC_FN12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER),
  [4] = ACTION_LAYER_MOMENTARY(2),  // to Fn overlay
  [5] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
  [6] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_ENT),
  [7] = ACTION_LAYER_MOMENTARY(3),
  [8] = ACTION_MOUSEKEY(KC_MS_U),
  [9] = ACTION_MOUSEKEY(KC_MS_D),
  [10] = ACTION_MOUSEKEY(KC_MS_L),
  [11] = ACTION_MOUSEKEY(KC_MS_R),
  [12] = ACTION_MOUSEKEY(KC_BTN1),
  [13] = ACTION_MOUSEKEY(KC_BTN2),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
