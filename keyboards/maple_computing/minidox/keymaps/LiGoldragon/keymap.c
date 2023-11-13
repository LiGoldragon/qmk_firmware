#include QMK_KEYBOARD_H

enum layer_names { _COLEMAK, _LOWER };

enum custom_keycodes { COLEMAK, LOWER };

// Adding macros to make the keymaps below much easier to read.
#define RCTLI RCTL_T(KC_I)
#define LCTLR LCTL_T(KC_R)
#define RALTE RALT_T(KC_E)
#define LALTS LALT_T(KC_S)
#define LALT_SPC LALT(KC_SPC)
#define LOWERBSPC LT(LOWER, KC_BSPC)
#define RAISEESC LT(RAISE,KC_ESC)
#define RAISESPC LT(RAISE,KC_SPC)
#define RAISEENT LT(RAISE,KC_ENT)
#define LGUIB LGUI_T(KC_B)
#define RGUIK RGUI_T(KC_K)
#define LSFTA MT(MOD_LSFT, KC_A)
#define RSFTO MT(MOD_RSFT,KC_O)

// (DeadCode) 
// QWERTY artifacts
#define RCTLL RCTL_T(KC_L)
#define LCTLS LCTL_T(KC_S)
#define RALTK RALT_T(KC_K)
#define LALTD LALT_T(KC_D)
#define RGUIN RGUI_T(KC_N)
#define RSFTSCLN MT(MOD_RSFT,KC_SCLN)
// Former numbers
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
                  LOWERBSPC, QK_LEAD, RAISESPC,   RAISEENT,  LALT_SPC,  RAISEESC
),

[_LOWER] = LAYOUT (
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  KC_CAPS, _______, KC_UP,   _______, KC_HOME,    KC_PGUP, KC_PLUS, KC_LCBR, KC_RCBR, KC_UNDS,
  KC_TILD, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,     KC_PGDN, KC_MUTE, KC_VOLD, KC_VOLU, KC_SLSH,
                    _______, _______, KC_ESC,     KC_TAB,  KC_PIPE, _______
),

void leader_end_user(void) {
  if (leader_sequence_one_key(KC_1)) {
    SEND_STRING("¯\\_(ツ)_/¯");
  }

  if (leader_sequence_one_key(KC_2)) {
    SEND_STRING("凸(ツ)凸");
  }
}


void matrix_init_user(void) {
#ifdef BOOTLOADER_CATERINA
    // This will disable the red LEDs on the ProMicros
    setPinInput(D5);
    setPinInput(B0);
#endif
};

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, ); };
