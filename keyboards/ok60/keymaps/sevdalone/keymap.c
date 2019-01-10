// Keycodes: https://docs.qmk.fm/#/keycodes

#include QMK_KEYBOARD_H

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define _______ KC_TRNS

#define RGB_STA RGB_M_P //rgb static
#define RGB_BRE RGB_M_B //rgb breathe
#define RGB_RAI RGB_M_R //rgb rainbow
#define RGB_SWI RGB_M_SW //rgb swirl
#define RGB_SNA RGB_M_SN //rgb snake
#define RGB_KNI RGB_M_K //rgb knight
#define RGB_GRA RGB_M_G //rgb gradient
#define RGB_XMAS RGB_M_X //rgb xmas


enum custom_keycodes {
  E_PI = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* Keymap: (Base Layer) Default Layer
   * using space cadet: https://docs.qmk.fm/features/space-cadet
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |MO1|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * | Shift |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| Shift |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |MO2 |Ctrl |
   * `-----------------------------------------------------------'
   */

  [0] = LAYOUT_60_ansi(
      F(0),     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0   ,    KC_MINS,    KC_EQL,     KC_BSPC,
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P   ,    KC_LBRC,    KC_RBRC,    KC_BSLS,
      MO(1),    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,    KC_QUOT,    KC_ENT,
      KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,    KC_LSFT,
      KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,   KC_LALT,  KC_RGUI,  MO(2),  KC_LCTL),


	 /* Keymap : Second Layer (WASD and Media)
	* ,-----------------------------------------------------------------------------------------.
	* | ` | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |      Del    |
	* |-----------------------------------------------------------------------------------------+
	* |       |Home |  Up |  End | PgUp |Insert|     |     |     |     |     |     |     |      |
	* |-----------------------------------------------------------------------------------------+
	* |         | Left| Down| Right| PgDn |     |     |     |     |     |     |     |           |
	* |-----------------------------------------------------------------------------------------+
	* |           |     |     |     |     |     |     |     |     |     |           |           |
	* |-----------------------------------------------------------------------------------------+
	* |      |      |      |                Ctrl                 |      |     |     |           |
	* `-----------------------------------------------------------------------------------------'
	*/

  [1] = LAYOUT_60_ansi(
      KC_GRV,   KC_F1,    KC_F2,    KC_F3,  KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,
      _______,  KC_HOME,  KC_UP,    KC_END, KC_PGUP,  KS_INS,  _______,  KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, _______, _______, _______,  KC_INS,
      _______,  KC_LEFT,  KC_DOWN,  KC_RGHT, KC_PGDN, _______, _______, KC_MS_LEFT, KC_MS_DOWN , KC_MS_RIGHT, _______, _______,  _______,
      KC_LSFT,  _______,  _______,  _______, _______, _______, _______, _______, _______,  _______,  _______, KC_LSFT,
      KC_LCTL,          _______, _______,              KC_LCTL          ,_______, _______, _______,          KC_LCTL),



   /* Keymap : Third Layer (RGB / Reset)
   * MUSIC MODE! https://docs.qmk.fm/features/audio
	* ,-----------------------------------------------------------------------------------------.
	* | ` | L1  | L2  | L3  | L4  | L5  | L6  | L7  | L8  | L9  | L10 | L11 | L12 |            |
	* |-----------------------------------------------------------------------------------------+
	* |       |     |     |      |      |     |     |     |     |     |E_PI|     |     |       |
	* |-----------------------------------------------------------------------------------------+
	* |         |     |     |      |      |     |     |     |   | Prev | Play | Next  |         |
	* |-----------------------------------------------------------------------------------------+
	* |           |     |     |    |    |      |     |      | Vol-  | Vol+  |  Mute   |         |
	* |-----------------------------------------------------------------------------------------+
	* |      |      |      |                                     |      |     |     |           |
	* `-----------------------------------------------------------------------------------------'
	*/

  [2] = LAYOUT_60_ansi(
      KC_GRV , M(1), M(2), M(3), M(4), M(5), M(6), M(7), M(8), M(9), M(10), M(11), M(12), _______,
      _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, E_PI, _______, _______, _______,
      _______, RGB_STA, RGB_BRE, RGB_RAI, RGB_SWI, RGB_SNA, RGB_KNI, RGB_GRA, RGB_XMAS, KC_MPRV, KC_MPLY, KC_MNXT, _______,
      _______, _______, BL_DEC , BL_TOGG, BL_INC , BL_STEP, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,
      _______, _______, _______, _______, _______, _______, _______, _______),

};

enum function_id {
    SHIFT_ESC
};

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


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case E_PI:
      if (record->event.pressed) {
        SEND_STRING("planetinnovation.com.au");
      }
      return false;
    default:
      return true;
  }
}
