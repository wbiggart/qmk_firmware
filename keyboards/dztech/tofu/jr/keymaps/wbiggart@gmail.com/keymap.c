#include QMK_KEYBOARD_H


/**************** LED BLINK HELPER FUNCTIONS *********************/

/*
Function to set color with hsv arguments
- "hue", "sat" and "val" arguments above 255 will get value from rgb matrix config
- "val_ratio" is used to adjust brightness ratio
*/
void rgb_matrix_set_color_hsv(uint8_t led, uint16_t hue, uint16_t sat, uint16_t val, float val_ratio) {
    const uint8_t h = hue <= 255 ? hue : rgb_matrix_config.hsv.h;
    const uint8_t s = sat <= 255 ? sat : rgb_matrix_config.hsv.s;
    const uint8_t v = val <= 255 ? val * val_ratio : rgb_matrix_config.hsv.v * val_ratio;
    HSV hsv_in = {h, s, v};
    RGB rgb_out = hsv_to_rgb(hsv_in);
    rgb_matrix_set_color(led, rgb_out.r, rgb_out.g, rgb_out.b);
}

/**************** LAYOUT *********************/

/*
[LEDS]
 0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14
15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29
30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,       42,  43
44,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,       56,  57
58,  59,  60,            61,                 62,  63,  64,  65,  66,  67

[KEYS]
ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   -,   =,  BCK, INS
TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   [,   ],    \,PGUP
CPS, A,   S,   D,   F,   G,   H,   J,   K,   L,   COL, QOT,  RETURN,PGDN
SFT, Z,   X,   C,   V,   B,   N,   M,   COM, DOT, SLS, SHIFT,    UP, DEL
CTL, GUI, ALT,           SPACEBAR,           ALT, FN, CTL, LFT, DWN, RIT
*/


enum layers {
    _MAC,
    _WIN,
    _FN
};


enum custom_keycodes {
    SLEEPY = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAC] = LAYOUT_65_ansi(
        QK_GESC,         KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,          KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT,         KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL,         KC_LALT, KC_LGUI,                  KC_SPC,                             KC_RGUI, KC_RCTL, MO(_FN), KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_WIN] = LAYOUT_65_ansi(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LGUI, KC_LALT, KC_TRNS, KC_RALT, MO(_FN), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_FN] = LAYOUT_65_ansi(
        DM_RSTP,   KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,    KC_F6,   KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   SLEEPY,
        KC_NO,     KC_MUTE,  KC_VOLU,  KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME,
        KC_TRNS,   KC_MPRV,  KC_VOLD,  KC_MNXT,  KC_NO,   KC_NO,    KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_END,
        KC_TRNS,   TO(_MAC), TO(_WIN), RGB_TOG,    KC_NO,   QK_BOOT,  KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,            KC_NO,   RGB_VAI, DM_REC1,
        KC_TRNS,   KC_TRNS,  KC_TRNS,                     KC_MPLY,                           KC_TRNS, KC_NO, KC_TRNS,   KC_NO,   RGB_VAD, DM_PLY1
    )
};



//**************** LED CONFIGS *********************//

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_dark);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) == _FN) {
        // uint8_t layer = get_highest_layer(layer_state);

        rgb_matrix_set_color(45, 200, 105, 210); /* WHITE Layer _MAC */
        rgb_matrix_set_color(46, 200, 105, 210); /* WHITE Layer _WIN */
        rgb_matrix_set_color(49, 200, 105, 210); // Light up B on _FN to show reset to bootloader
        rgb_matrix_set_color(50, 200, 105, 210); // Light up N on _FN to show reset EEPROM

    } else if (get_highest_layer(layer_state) == _WIN) {
        rgb_matrix_set_color(46, 200, 105, 210); // WHITE
    }

    if (host_keyboard_led_state().caps_lock) {
        for(uint8_t i = 2; i < 12; i++){
            RGB_MATRIX_INDICATOR_SET_COLOR(i, 255, 255, 255); // assuming caps lock is at led #5
        }
    }
    return false;

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SLEEPY:
        if (record->event.pressed) {
            // when keycode SLEEPY is pressed
            SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_TAP(X_EJCT) SS_UP(X_LGUI) SS_UP(X_LALT));
        }
        return false;
        }

    return true;
}

