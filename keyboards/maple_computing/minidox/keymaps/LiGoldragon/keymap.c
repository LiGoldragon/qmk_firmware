#include QMK_KEYBOARD_H

enum layer_names { _QWERTY, _COLEMAK, _LOWER, _RAISE, _ADJUST };

enum custom_keycodes { QWERTY = SAFE_RANGE, COLEMAK, LOWER, RAISE, ADJUST };

// Adding macros to make the keymaps below much easier to read.
#define CTLSCLN RCTL_T(KC_SCLN)
#define CTLSLSH LCTL_T(KC_SLSH)
#define RCTLZED RCTL_T(KC_Z)
#define LCTLZED LCTL_T(KC_Z)
#define ALTDOT RALT_T(KC_DOT)
#define ALTX LALT_T(KC_X)
#define ALTQ LALT_T(KC_Q)
#define ALTV RALT_T(KC_V)
#define GUICOMM RGUI_T(KC_COMM)
#define GUIJ LGUI_T(KC_J)
#define GUIC LGUI_T(KC_C)
#define GUIW RGUI_T(KC_W)

#define RCTLL RCTL_T(KC_L)
#define LCTLS LCTL_T(KC_S)
#define RALTK RALT_T(KC_K)
#define LALTD LALT_T(KC_D)
#define LALT_SPC LALT(KC_SPC)
#define LOWERBSPC LT(LOWER, KC_BSPC)
#define RAISEESC LT(RAISE,KC_ESC)
#define LGUIB LGUI_T(KC_B)
#define RGUIN RGUI_T(KC_N)
#define LSFTA MT(MOD_LSFT, KC_A)
#define RSFT_O MT(MOD_RSFT,KC_O)
#define RSFTSCLN MT(MOD_RSFT,KC_SCLN)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT (
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  LSFTA,   LCTLS,   LALTD,   KC_F,    KC_G,       KC_H,    KC_J,    RALTK,   RCTLL,   RSFTSCLN,
  KC_Z,    KC_X,    KC_C,    KC_V,    LGUIB,      RGUIN,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                  LOWERBSPC, LOWER,   KC_SPC,     KC_ENT,  LALT_SPC,  RAISEESC
),

/* Colemak
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   G  |           |   J  |   L  |   U  |   Y  |   L  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   D  |           |   H  |   N  |   E  |   I  |   S  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |CTL/ Z|ALT/ X|GUI/ C|   V  |   B  |           |   K  |   M  |GUI/ ,|ALT/ .|CTL/ /|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | LOWER| BSPC |      |    |      | Spc  |RAISE |
 *                  `-------------| SHFT |    | Ent  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_COLEMAK] = LAYOUT (
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,       KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
  LCTLZED, ALTX,    GUIC,    KC_V,    KC_B,       KC_K,    KC_M,    GUICOMM, ALTDOT,  CTLSLSH,
                    LOWER,   KC_BSPC, KC_LSFT,    KC_ENT,  KC_SPC,  RAISE
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | CAPS |      |  UP  |      | Home |           | PgDn |   +  |   {  |   }  |   _  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   ~  | Left | Down | Right| End  |           | PgUp | Mute | Vol- | Vol+ |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | Del  |      |    |      |   |  |      |
 *                  `-------------| Esc  |    | Tab  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_LOWER] = LAYOUT (
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  KC_CAPS, _______, KC_UP,   _______, KC_HOME,    KC_PGUP, KC_PLUS, KC_LCBR, KC_RCBR, KC_UNDS,
  KC_TILD, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,     KC_PGDN, KC_MUTE, KC_VOLD, KC_VOLU, KC_SLSH,
                    _______, KC_DEL,  KC_ESC,     KC_TAB,  KC_PIPE, _______
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | CAPS |      |  UP  |      | Home |           | PgDn |   =  |   [  |   ]  |   -  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   `  | Left | Down | Right| End  |           | PgUp | Prev | Play | Next |   ?  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | Del  |      |    |      |   \  |      |
 *                  `-------------| Esc  |    | Tab  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_RAISE] = LAYOUT (
  KC_CAPS, _______, KC_UP,   _______, KC_HOME,    KC_PGUP, KC_EQL,  KC_LBRC, KC_RBRC, KC_MINS,
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_GRV,  KC_LEFT, KC_DOWN, KC_RGHT, KC_END,     KC_PGDN, KC_MPRV, KC_MPLY, KC_MNXT, KC_QUES,
                    _______, KC_DEL,  KC_ESC,     KC_TAB,  KC_BSLS, _______
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |  F7  |  F8  |  F9  | F10  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |      |      |      |      |           |      | PrSc | ScLk | Paus | F12  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |QWERTY|COLEMK|DVORAK|      |           |QK_BOOT |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_ADJUST] =  LAYOUT (
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  KC_F11,  QK_BOOT, _______, _______, _______,    _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_F12,
  _______, QWERTY,  COLEMAK, _______, _______,    QK_BOOT, _______, _______, _______, _______,
                    _______, _______, _______,    _______, _______, _______
  )
};
// clang-format on

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void matrix_init_user(void) {
#ifdef BOOTLOADER_CATERINA
    // This will disable the red LEDs on the ProMicros
    setPinInput(D5);
    setPinInput(B0);
#endif
};

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case QWERTY:
                set_single_persistent_default_layer(_QWERTY);
                return false;
            case COLEMAK:
                set_single_persistent_default_layer(_COLEMAK);
                return false;
        }
    }
    return true;
}
