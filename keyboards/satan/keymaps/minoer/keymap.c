#include "satan.h"

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum keymap_layout {
    BASE = 0,
    SAFE,
    HHKB_EXTL,
    HHKB_EXTR,
    TENKEY,
    MOUSE,
    LAYER_SET,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap Safe: (Safe Layer) Safty Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| \ | ~ |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|bksp |
   * |-----------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift| fn |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |FN  |Ctrl |
   * `-----------------------------------------------------------'
   */
[SAFE] = KEYMAP_HHKB(
  F(0),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV, \
  LT(TENKEY,KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          MT(MOD_RCTL,KC_ENT),  \
  KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(HHKB_EXTR), \
  KC_CAPS, KC_LALT, MO(HHKB_EXTL),      LT(MOUSE,KC_SPC),                                               KC_RGUI, KC_RALT, KC_MEH, KC_HYPR),

  /* Keymap Base: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| \ | ~ |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|bksp |
   * |-----------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift| fn |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |FN  |Ctrl |
   * `-----------------------------------------------------------'
   */
[BASE] = KEYMAP_HHKB(
  F(0),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV, \
  LT(TENKEY,KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          MT(MOD_RCTL,KC_ENT),  \
  KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(HHKB_EXTR), \
  KC_HYPR, KC_LALT, MO(HHKB_EXTL),      LT(MOUSE,KC_SPC),                                               KC_RGUI, KC_RALT, KC_MEH, KC_HYPR),

  /* Keymap HHKB EXTL: (Left EXT Layer)
   * ,-----------------------------------------------------------.
   * |Pwr | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| \ | ~ |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|bksp |
   * |-----------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift| fn |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |FN  |Ctrl |
   * `-----------------------------------------------------------'
   */
[HHKB_EXTL] = KEYMAP_HHKB(
  KC_POWER,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS, KC_DEL, \
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   _______, KC_DEL,  \
  KC_CAPS, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,          MT(MOD_RCTL,KC_ENT), \
  _______,          _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, KC_UP, MO(LAYER_SET), \
  _______, _______, _______,                   _______,                                     _______, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap HHKB EXTR: (Right EXT Layer)
   * ,-----------------------------------------------------------.
   * |Pwr | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| \ | ~ |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|bksp |
   * |-----------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift| fn |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |FN  |Ctrl |
   * `-----------------------------------------------------------'
   */
[HHKB_EXTR] = KEYMAP_HHKB(
  KC_POWER,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS, KC_DEL, \
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   _______, KC_DEL,  \
  KC_CAPS, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,          MT(MOD_RCTL,KC_ENT), \
  _______,          _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, KC_UP, _______, \
  _______, _______, MO(LAYER_SET),                   _______,                                     _______, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap LAYER Set: (Layer set Layer) 
   * ,-----------------------------------------------------------.
   * |Pwr | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| \ | ~ |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|bksp |
   * |-----------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift| fn |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |FN  |Ctrl |
   * `-----------------------------------------------------------'
   */
[LAYER_SET] = KEYMAP_HHKB(
  DF(SAFE), DF(BASE), DF(MOUSE), DF(TENKEY), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
  _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, \
  _______, _______, _______,                    _______,                                     _______, _______, _______, _______),

  /* Layer: Mouse layer
   * ,-----------------------------------------------------------------------------------------.
   * | Esc | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |     |     |
   * |-----------------------------------------------------------------------------------------|
   * |        |     |     |     |     |     |     | Mb1 | Mb2 | Mb3 | Mb4 |     |     |        |
   * |-----------------------------------------------------------------------------------------|
   * |          |     |     |     |     |     |     | McL | McD | McU | McR |     |            |
   * |-----------------------------------------------------------------------------------------|
   * |             |     |     |     |     |     | MwL | MwD | MwU | MwR |     |         | Fn0 |
   * `-----------------------------------------------------------------------------------------'
   *           |     |  Fn1   |                                   |        |     |
   *           `-----------------------------------------------------------------'
   */
  [MOUSE] = KEYMAP_HHKB(
  KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL, \
  KC_TAB, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_BTN4,KC_BTN5,     _______, \
  KC_CAPS,XXXXXXX,  KC_ACL0,KC_ACL1,KC_ACL2, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,  MT(MOD_RCTL,KC_ENT), \
  KC_LSFT,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_WH_U, _______, \
  _______, _______, _______,                                _______,                            _______, KC_WH_L, KC_WH_D, KC_WH_R),
 /* Layer 6: Tenkey layer
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |     |     |     |     |     |     |     |     |  /  |  *  |  -  |     |     |     |
   * |-----------------------------------------------------------------------------------------|
   * |        |     |     |     |     |     |     |     |  7  |  8  |  9  |  +  |  +  |   BSp  |
   * |-----------------------------------------------------------------------------------------|
   * |          |     |     |     |     |     |     |     |  4  |  5  |  6  | Ent |   Enter    |
   * |-----------------------------------------------------------------------------------------|
   * |             |     |     |     |     |     |     |     |  1  |  2  |  3  |         |     |
   * `-----------------------------------------------------------------------------------------'
   *           |     |        |                                   |   0    |  .  |
   *           `-----------------------------------------------------------------'
   */
  [TENKEY] = KEYMAP_HHKB(
   KC_ESC, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, KC_PSLS,KC_PAST,KC_PMNS, KC_PMNS, KC_PPLS, XXXXXXX, _______, \
   _______,XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, KC_PPLS, KC_PPLS, _______, \
   _______,XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_KP_4, KC_KP_5, KC_KP_6, KC_PENT, KC_PENT, KC_PENT, \
   _______,XXXXXXX, XXXXXXX,KC_CALCULATOR, XXXXXXX, XXXXXXX, XXXXXXX,  KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, KC_PENT, _______, \
   _______, _______, _______,                                                   KC_KP_0, KC_PDOT, _______, _______, _______),
                                                              
};

/*
 * user defined action function
 */
enum function_id {
    SHIFT_ESC,
};


/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    static uint8_t shift_esc_shift_mask;
    switch (id) {
    case SHIFT_ESC:
	shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
	if (record->event.pressed) {
	    if (shift_esc_shift_mask) {
		add_key(KC_GRV);
		send_keyboard_report();
	    } else {
		add_key(KC_ESC);
		send_keyboard_report();
	    }
	} else {
	    if (shift_esc_shift_mask) {
		del_key(KC_GRV);
		send_keyboard_report();
	    } else {
		del_key(KC_ESC);
		send_keyboard_report();
	    }
	}
	break;
    }
}
