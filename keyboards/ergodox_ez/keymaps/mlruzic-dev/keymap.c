#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define DVORAK 1
#define SYM 2 // symbols
#define SHRT 3 // shortcuts and arrow keys

#define M_FNAME 1
#define M_GMAIL 2
#define M_VAR 3
#define M_FUNC 4
#define M_GIT_STS 5
#define M_GIT_PLL 6
#define M_GIT_CMT 7
#define M_GIT_PSH 8
#define M_GIT_CKT 9

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |L_dvorak|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ~L3    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | LGui | Alt  |   [  |  '"  |                                       | Grv  |   ]  |  Alt | App  | Ctrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Left | Right|       | Up   | Down |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       | PgDn |        |      |
 *                                 |Space/|Backsp|------|       |------| Delete |Space |
 *                                 | ~L2  |ace   | Home |       | End  |        |      |
 *                                 `--------------------'       `----------------------'
 */
 [BASE] = KEYMAP(
    // left hand
    KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_NO,
    KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_NO,
    MO(SHRT),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_NO,
    KC_LCTL,    KC_LGUI, KC_LALT, KC_LBRC, KC_QUOT,
                                                       KC_LEFT, KC_RIGHT,
                                                                KC_PGUP,
                                      LT(SYM, KC_SPC), KC_BSPC, KC_HOME,
    // right hand
    KC_NO, KC_6, KC_7,   KC_8,    KC_9,    KC_0,    TG(DVORAK),
    KC_NO, KC_Y, KC_U,   KC_I,    KC_O,    KC_P,    KC_EQL,
           KC_H, KC_J,   KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_NO, KC_N, KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                 KC_GRV, KC_RBRC, KC_RALT, KC_APP,  KC_RCTL,
    KC_UP,  KC_DOWN,
    KC_PGDN,
    KC_END, KC_DELETE, KC_SPC
),

/* Keymap 1: Dvorak layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   '  |   ,  |   .  |   P  |   Y  |      |           |      |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   :  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |     |
 *   `----------------------------------'                                       `---------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[DVORAK] = KEYMAP(
    // left hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_TRNS,
    KC_TRNS, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
    KC_TRNS, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                        KC_TRNS, KC_TRNS,
                                                                 KC_TRNS,
                                               KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
             KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_TRNS,
    KC_TRNS, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),

 /* Keymap 1: Symbol Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   \  |      |      |      |      |      |           |      |      |      |      |      |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   [  |   <  |   (  |   {  |   |  |------|           |------|      |   }  |   )  |   >  |   ]  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |   ~  |      |           |      |      |   /  |   *  |   -  |   +  |        |
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
    KC_TRNS, KC_F1,   KC_F2,         KC_F3,      KC_F4,         KC_F5,         KC_TRNS,
    KC_TRNS, KC_BSLS, KC_TRNS,       KC_TRNS,    KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS, KC_LBRC, LSFT(KC_COMM), LSFT(KC_9), LSFT(KC_LBRC), LSFT(KC_BSLS),
    KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,    KC_TRNS,       KC_TILD,       KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,    KC_TRNS,
                                                                          KC_TRNS, KC_TRNS,
                                                                                   KC_TRNS,
                                                                 KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    KC_TRNS, KC_F6,   KC_F7,         KC_F8,      KC_F9,        KC_F10,  KC_F11,
    KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,    KC_TRNS,      KC_TRNS, KC_F12,
             KC_TRNS, LSFT(KC_RBRC), LSFT(KC_0), LSFT(KC_DOT), KC_RBRC, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_SLSH,       KC_ASTR,    KC_MINS,      KC_PLUS, KC_TRNS,
                      KC_TRNS,       KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),

 /* Keymap 2: Arrows and shortcuts layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |GitSts|GitPll|GitCmt|GitPsh|GitChk|      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      | Full |           |      |      |      |  Up  |      |      |        |
 * |--------+------+------+------+------+------| name |           |      |------+------+------+------+------+--------|
 * |        |      |      |      | func |      |------|           |------|      | Left | Down | Right|      |        |
 * |--------+------+------+------+------+------| Full |           |      |------+------+------+------+------+--------|
 * |        |      |      |      | var  |      | email|           |      |      |      |      |      |      |        |
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
 [SHRT] = KEYMAP(
    // left hand
    KC_TRNS, M(M_GIT_STS), M(M_GIT_PLL), M(M_GIT_CMT), M(M_GIT_PSH), M(M_GIT_CKT), KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, M(M_FNAME),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M(M_FUNC), KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M(M_VAR),  KC_TRNS, M(M_GMAIL),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                     KC_TRNS, KC_TRNS,
                                                              KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS, KC_TRNS,
             KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
)
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt){
    switch(id) {
        case M_FNAME:
            if (record->event.pressed) {
                return MACRO( D(LSFT), T(M), U(LSFT), T(L), T(A), T(D), T(E), T(N), T(SPACE), D(LSFT), T(R), U(LSFT), T(U), T(Z), T(I), T(C), END);
            } 
            break;
        case M_GMAIL:
            if (record->event.pressed) {
                return MACRO( T(M), T(L), T(A), T(D), T(E), T(N), T(DOT), T(R), T(U), T(Z), T(I), T(C), D(LSFT), T(2), U(LSFT), T(G), T(M), T(A), T(I), T(L), T(DOT), T(C), T(O), T(M), END);
            } 
            break;
        case M_VAR:
            if (record->event.pressed) {
                return MACRO( T(V), T(A), T(R), T(SPACE), END);
            } 
            break;
        case M_FUNC:
            if (record->event.pressed) {
                return MACRO( T(F), T(U), T(N), T(C), T(T), T(I), T(O), T(N), D(LSFT), T(9), T(0), T(LBRC), T(RBRC), U(LSFT), END);
            } 
            break;
        case M_GIT_STS:
            if (record->event.pressed) {
                return MACRO( T(G), T(I), T(T), T(SPC), T(S), T(T), T(A), T(T), T(U), T(S), END);
            }
            break;
        case M_GIT_PLL:
            if (record->event.pressed) {
                return MACRO( T(G), T(I), T(T), T(SPC), T(P), T(U), T(L), T(L), END);
            }
            break;
        case M_GIT_CMT:
            if (record->event.pressed) {
                return MACRO( T(G), T(I), T(T), T(SPC), T(C), T(O), T(M), T(M), T(I), T(T), T(SPC), T(MINS), T(M), T(SPC), D(LSFT), T(QUOT), U(LSFT), END);
            }
            break;
        case M_GIT_PSH:
            if (record->event.pressed) {
                return MACRO( T(G), T(I), T(T), T(SPC), T(P), T(U), T(S), T(H), END);
            }
            break;
        case M_GIT_CKT:
            if (record->event.pressed) {
                return MACRO( T(G), T(I), T(T), T(SPC), T(C), T(H), T(E), T(C), T(K), T(O), T(U), T(T), END);
            }
            break;
    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    if(IS_LAYER_ON(DVORAK)){
        ergodox_right_led_3_on();
    }

    switch (layer) {
        case SYM:
            ergodox_right_led_1_on();
            break;
        case SHRT:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
