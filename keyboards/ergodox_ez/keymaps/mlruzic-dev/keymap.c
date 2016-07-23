#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define COLEMAK 1
#define SYM 2 // symbols

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |  L2  |           | CLMK |   6  |   7  |   8  |   9  |   0  | Home   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |INSERT|           |      |   Y  |   U  |   I  |   O  |   P  | End    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | '"     |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------| CAPS |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | LOCK |           |      |   N  |   M  |   ,  |   .  |  /?  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/CT| LGui | Alt  | Left | Right|                                       |  Up  | Down |      |      |'/Crtl|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  F10 | F11  |       | Left | Right|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |Space |       | Up   |      |      |
 *                                 | ~L2  |Backsp|------|       |------|Enter |Space |
 *                                 |      |ace   |Delete|       | Down |      |      |
 *                                 `--------------------'       `--------------------'
 */
 [BASE] = KEYMAP(
	// left hand
	KC_ESC,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5, TG(SYM),
	KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_INS,
	KC_QUOT,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
	KC_LSFT,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_CAPS,
	CTL_T(KC_GRV),KC_LGUI, KC_LALT, KC_LEFT, KC_RIGHT,
													   KC_F10,  KC_F11,
																KC_SPC,
									          MO(SYM), KC_BSPC, KC_DELETE,
	// right hand
	TG(COLEMAK),KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_HOME,
	KC_NO,      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_END,
		        KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_ENT,
	KC_NO,      KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                KC_UP,   KC_DOWN,  KC_NO, KC_NO,   CTL_T(KC_QUOT),
	KC_LEFT,  KC_RIGHT,
	KC_UP,
	KC_DOWN, KC_ENT, KC_SPC
),

/* Keymap 1: Colemak layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   F  |   P  |   G  |      |           |      |   J  |   L  |   U  |   Y  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[COLEMAK] = KEYMAP(
    // left hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,   KC_TRNS,
    KC_TRNS, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,
    KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                        KC_TRNS, KC_TRNS,
                                                                 KC_TRNS,
                                               KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_J,    KC_L,    KC_U,    KC_Y,    KC_NO,   KC_TRNS,
             KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_TRNS,
    KC_TRNS, KC_K,    KC_M,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),

 /* Keymap 1: Symbol Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | PrtScr |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   \  |   @  |   {  |   }  |   ^  |      |           |      |      |      |      |      |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | "      |   |  |   &  |   (  |   )  |   `  |------|           |------|   /  |   *  |   -  |   +  |   :  |CTRL_ENT|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   #  |   [  |   ]  |   _  |      |           |      |      |   =  |   <  |   >  |   ?  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
 [SYM] = KEYMAP(
	// left hand
    KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
    KC_TRNS, KC_BSLS, KC_AT,   KC_LCBR, KC_RCBR, KC_CIRC, KC_TRNS,
    KC_DQUO, KC_PIPE, KC_AMPR, KC_LPRN, KC_RPRN, KC_GRV,
    KC_TRNS, KC_PERC, KC_HASH, KC_LBRC, KC_RBRC, KC_UNDS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_TRNS, KC_TRNS,
                                                          KC_TRNS,
                                         KC_TRNS,KC_TRNS, KC_TRNS,
    // right hand
    KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12,
             KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_COLN, LCTL(KC_ENT),
    KC_TRNS, KC_TRNS, KC_EQL,  KC_LABK, KC_RABK, KC_QUES, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
)
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt){
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    if(IS_LAYER_ON(SYM)){
        ergodox_right_led_1_on();
    }
    if(host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_2_on();
    }
    if(IS_LAYER_ON(COLEMAK)){
        ergodox_right_led_3_on();
    }
};
