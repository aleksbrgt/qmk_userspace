#include QMK_KEYBOARD_H
#include <stdio.h>

#define _KC_A LGUI_T(KC_A)
#define _KC_S LALT_T(KC_S)
#define _KC_D LCTL_T(KC_D)
#define _KC_F LSFT_T(KC_F)
#define _KC_J LSFT_T(KC_J)
#define _KC_K LCTL_T(KC_K)
#define _KC_L LALT_T(KC_L)
#define _KC_QUOT LGUI_T(KC_QUOT)

#define _KC_ESC LT(MSC, KC_ESC)
#define _KC_SPC LT(NUM, KC_SPC)
#define _KC_TAB LT(MED, KC_TAB)
#define _KC_ENT LT(CUR, KC_ENT)
#define _KC_DEL LT(FUN, KC_DEL)

enum custom_keycodes {
	OLED_BD = SAFE_RANGE,
	OLED_BU
};

enum {
    // Home
    //     > qwerty
    //     > home row with modifiers
    HME,
    // Numbers and symbols
    //     > keypad like layout on the right side
    //     > number row key codes to easily combine numbers and symbols
    //     > other symbols
    NUM,
    // Cursor movement
    //     > vi style arrow  keys
    //     > home / end, page up / page down
    CUR,
    //  Media keys
    //     > volume up, down, mute
    //     > previous, next, pause 
    MED,
    // Function keys
    //     > F1 to F9 reuse the NUM layer numbers
    //     > F10 to F12 on the outer right column
    FUN,
    // Misc, keys that don't fit well in other layout
    //     > Caps Lock
    //     > App Menu
    //     > Includes the right ctrl key with the intent to use it as the Compose Key
    //         > See https://en.wikipedia.org/wiki/Compose_key
    MSC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [HME] = LAYOUT_split_3x5_3(
        //  ---------------------------------------                      ---------------------------------------
        // |   Q   |   W   |   E   |   R   |   T   |                    |   Y   |   U   |   I   |   0   |   P   |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // | A GUI | S ALT | D CTL | F SFT |   G   |                    |   H   | J SFT | K CTL | L ALT | ' GUI |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |   Z   |   X   |   C   |   V   |   B   |                    |   N   |   M   |   ,   |   .   |   /   |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |ESC MSC|SPC NUM|TAB MED|    |ENT CUR|  BSP  |DEL FUN|
        //                          ------+-------+-------      -------+-------+-------
        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        _KC_A,    _KC_S,    _KC_D,    _KC_F,    KC_G,               KC_H,     _KC_J,    _KC_K,    _KC_L,    _KC_QUOT,
        KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
					        _KC_ESC,  _KC_SPC,  _KC_TAB,            _KC_ENT,  KC_BSPC,  _KC_DEL
    ),
    [NUM] = LAYOUT_split_3x5_3(
        //   ---------------------------------------                      ---------------------------------------
        //  |   {   |   (   |   )   |   }   |       |                    |  [ {  |  7 &  |  8 *  |   9   |  ] }  |
        //  |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        //  |  GUI  |  ALT  | CTRL  |  SFT  |   -   |                    |  = +  |  4 $  |  5 %  |  6 ^  |  ; :  |
        //  |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        //  |       |       |       |       |   _   |                    |  \ |  |  1 !  |  2 @  |  3 #  |  ` ~  |
        //   -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                          |  ESC  |  SPC  |  TAB  |    |       |   0   |       |
        //                           -------+-------+-------      -------+-------+-------
        KC_LCBR,  KC_LPRN,  KC_RPRN,  KC_RCBR,  XXXXXXX,            KC_LBRC,  KC_7,     KC_8,     KC_9,     KC_RBRC,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_MINS,            KC_EQL,   KC_4,     KC_5,     KC_6,     KC_SCLN,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_UNDS,            KC_BSLS,  KC_1,     KC_2,     KC_3,     KC_GRV,
                            KC_ESC,   KC_SPC,   KC_TAB,             XXXXXXX,  KC_0,     XXXXXXX
    ),
    [CUR] = LAYOUT_split_3x5_3(
        //  ---------------------------------------                      ---------------------------------------
        // |       |       |       |       |       |                    |       |       |       |       |       |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |  GUI  |  ALT  |  CTL  |  SFT  |       |                    |       |   ←   |   ↓   |   ↑   |   →   |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |       |       |       |       |       |                    |  ins  | home  | pgdn  | pgup  |  end  |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |  ESC  |  SPC  |  TAB  |    |  ENT  |  BSPC |  DEL  |
        //                          -------+-------+-------      -------+-------+-------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,  			XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    		KC_INS,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,
                            KC_ESC,   KC_SPC,   KC_TAB,   			KC_ENT,   KC_BSPC,  KC_DEL
    ),
    [MED] = LAYOUT_split_3x5_3(
        //  ---------------------------------------                      ---------------------------------------
        // |       |       |       |       |       |                    |       |       | OLED- | OLED+ |       |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |  GUI  |  ALT  |  CTL  |  SFT  |       |                    |       |  PREV | VOL - | VOL + |  NEXT |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |       |       |       |       |       |                    |       |       |       |       |       |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |  ESC  |  SPC  |  TAB  |    |       | PLAY  |  MUTE |
        //                          -------+-------+-------      -------+-------+-------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  OLED_BD,  OLED_BU,  XXXXXXX,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,            XXXXXXX,  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                            KC_ESC,   KC_SPC,   KC_TAB,             XXXXXXX,  KC_MPLY,  KC_MUTE
    ),
    [FUN] = LAYOUT_split_3x5_3(
        //  ---------------------------------------                      ---------------------------------------
        // |       |       |       |       |       |                    |       |  F 7  |  F 8  |  F 9  |  F10  |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |  GUI  |  ALT  |  CTL  |  SFT  |       |                    |       |  F 4  |  F 5  |  F 6  |  F11  |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |       |       |       |       |       |                    |       |  F 1  |  F 2  |  F 3  |  F12  |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |  ESC  |  SPC  |  TAB  |    |       |       |       |
        //                          -------+-------+-------      -------+-------+-------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_F7,    KC_F8,    KC_F9,    KC_F10,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,            XXXXXXX,  KC_F4,    KC_F5,    KC_F6,    KC_F11,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F12,
                            KC_ESC,   KC_SPC,   KC_TAB,             XXXXXXX,  XXXXXXX,  XXXXXXX
    ),
    [MSC] = LAYOUT_split_3x5_3(
        //  ---------------------------------------                      ---------------------------------------
        // |       |       |       |       |       |                    |       |       |       |       |  PSCR |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |  CAPS |       |       |       |       |                    |       |       |       |       |  RCTL |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |       |  CUT  | COPY  | PASTE |       |                    |       |       |       |       |  APP  |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |  ESC  |  SPC  |  TAB  |    |       |       |       |
        //                          -------+-------+-------      -------+-------+-------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PSCR,
        KC_CAPS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_RCTL,
        XXXXXXX,  KC_CUT,   KC_COPY,  KC_PASTE, XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_APP,
                            KC_ESC,   KC_SPC,   KC_TAB,             XXXXXXX,  XXXXXXX,  XXXXXXX
    )
};

const uint16_t PROGMEM combo_ralt[] = {KC_I, KC_O, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_ralt, KC_RALT)
};

typedef struct {
	bool has_brightness_change;
	uint8_t brightness_step;
} state_t;

state_t state;

typedef union {
	uint32_t raw;
	struct {
		uint8_t oled_brightness;
        uint32_t press_count;
	};
} user_config_t;

user_config_t user_config;

void keyboard_post_init_user(void) {
	user_config.raw = eeconfig_read_user();
	state.has_brightness_change = false;
	state.brightness_step = 10;
	oled_set_brightness(user_config.oled_brightness);
}

uint8_t get_new_brightness(int8_t change) {
	if (255 < user_config.oled_brightness + change) {
		return 255;
	}

	if (0 > user_config.oled_brightness + change) {
		return 0;
	}

	return user_config.oled_brightness + change;
}

void register_brightness_change(int8_t change) {
	uint8_t new_brightness = get_new_brightness(change);
	if (new_brightness != user_config.oled_brightness) {
		state.has_brightness_change = true;
		user_config.oled_brightness = new_brightness;
		eeconfig_update_user(user_config.raw);
	}
}

int8_t _row = 0;
int8_t _col = 0;
int16_t _keycode = 0;
char _character = '?';

const char code_to_name[60] = {
    '?', '?', '?', '?', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', '?', '?', '?'
};

void set_keycode_values(uint16_t keycode) {
    _keycode = keycode;
    _character = '?';
    if ((_keycode >= QK_MOD_TAP && _keycode <= QK_MOD_TAP_MAX)
      || (_keycode >= QK_LAYER_TAP && _keycode <= QK_LAYER_TAP_MAX)
    ) {
        _keycode = _keycode & 0xFF;
    }

    if (_keycode < 60) {
        _character = code_to_name[_keycode];
    }

    if (_keycode > 99 && _keycode != 0) {
        _keycode = 0;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
		return true;
    }

    user_config.press_count += 1;
    eeconfig_update_user(user_config.raw);

    _row = record->event.key.row;
    _col = record->event.key.col;
    set_keycode_values(keycode);

    if (99 <= _keycode) {
        _keycode = 99;
    }

	switch (keycode) {
		case OLED_BU:
			register_brightness_change(state.brightness_step);
		break;
		case OLED_BD:
			register_brightness_change(state.brightness_step * -1);
		break;
	}

	return true;
}

char* get_layer_name(void) {
    switch (get_highest_layer(layer_state)) {
        case HME:
            return "Home";
            break;

        case NUM:
            return "Numpad";
            break;

        case CUR:
            return "Cursor";
            break;

        case MED:
            return "Media";
            break;

        case FUN:
            return "Function";
            break;

        case MSC:
            return "Other";
            break;
    }

    return "n/a";
}

bool is_current_layer_home(void) {
    return HME == get_highest_layer(layer_state);
}


bool oled_task_user(void) {
	char layer[10] = "";
    sprintf(layer, "%-9s", get_layer_name());
    oled_write_ln(layer, !is_current_layer_home());

    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("Caps     "), led_state.caps_lock);

    char matrix[20] = "";
    sprintf(matrix, "%dx%d %02d %c %07li", _row, _col, _keycode, _character, user_config.press_count);
    oled_write(matrix, false);
    oled_write_ln_P(PSTR(" "), false);

    char brightness[10] = "";
    sprintf(brightness, "%03d/255  ", user_config.oled_brightness);
    oled_write(brightness, state.has_brightness_change);

    if (state.has_brightness_change) {
        oled_set_brightness(user_config.oled_brightness);
        state.has_brightness_change = false;
    }

	return false;
}
