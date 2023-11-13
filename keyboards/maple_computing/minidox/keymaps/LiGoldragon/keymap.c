#include QMK_KEYBOARD_H

enum layer_names { _COLEMAK, _RAISE };

enum custom_keycodes { COLEMAK, RAISE };

// Adding macros to make the keymaps below much easier to read.
#define RCTLI RCTL_T(KC_I)
#define LCTLR LCTL_T(KC_R)
#define RALTE RALT_T(KC_E)
#define LALTS LALT_T(KC_S)
#define LALT_SPC LALT(KC_SPC)
#define RAISEESC LT(RAISE,KC_ESC)
#define RAISESPC LT(RAISE,KC_SPC)
#define RAISEENT LT(RAISE,KC_ENT)
#define LGUIB LGUI_T(KC_B)
#define RGUIK RGUI_T(KC_K)
#define LSFTA MT(MOD_LSFT, KC_A)
#define RSFTO MT(MOD_RSFT,KC_O)
#define LSFT9 MT(MOD_LSFT, KC_9)
#define RSFT4 MT(MOD_RSFT,KC_4)
#define RGUI5 RGUI_T(KC_5)
#define LGUI0 LGUI_T(KC_0)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT (
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,       KC_J,      KC_L,      KC_U,    KC_Y,    KC_SCLN,
  KC_Z,    LCTLR,   LALTS,   KC_T,    KC_D,       KC_H,      KC_N,      RALTE,   RCTLI,   KC_SLSH,
  LSFTA,   KC_X,    KC_C,    KC_V,    LGUIB,      RGUIK,     KC_M,      KC_COMM, KC_DOT,  RSFTO,
                  KC_BSPC, QK_LEAD, RAISESPC,   RAISEENT,  LALT_SPC,  RAISEESC
),

[_RAISE] = LAYOUT (
  KC_GRV,  _______, _______,   KC_PGDN, KC_HOME,   KC_END,   KC_PGUP,  _______, _______, KC_BSLS,
  KC_CAPS, KC_8,    KC_7,      KC_6,    KC_MINS,   KC_EQL,   KC_1,     KC_2,    KC_3,    KC_QUOT,
  LSFT9,   KC_LEFT, KC_DOWN,   KC_LBRC, LGUI0,     RGUI5,    KC_RBRC,  KC_UP,   KC_RIGHT,   RSFT4,
                    _______,   _______, KC_TAB,    KC_ENT,   _______,  _______
  )
};

void leader_end_user(void) {
  // Solar Hand
  if (leader_sequence_one_key(KC_N)) {
    tap_code16(RGUI(KC_N));
  }
  if (leader_sequence_one_key(KC_E)) {
    tap_code16(RGUI(KC_E));
  }

  // Lunar Hand
  if (leader_sequence_one_key(KC_T)) {
    tap_code16(LGUI(KC_T));
  }
  if (leader_sequence_one_key(KC_S)) {
    tap_code16(LGUI(KC_S));
  }
  if (leader_sequence_five_keys(KC_R, KC_E, KC_S, KC_E, KC_T)) {
    reset_keyboard();
  }
  
}


void matrix_init_user(void) {
#ifdef BOOTLOADER_CATERINA
    // This will disable the red LEDs on the ProMicros
    setPinInput(D5);
    setPinInput(B0);
#endif
};
