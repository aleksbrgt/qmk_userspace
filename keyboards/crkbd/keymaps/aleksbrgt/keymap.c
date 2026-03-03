#include QMK_KEYBOARD_H
#include <stdio.h>
#include "_keycodes.h"
#include "_menu.h"

#define CC_A LGUI_T(KC_A)
#define CC_S LALT_T(KC_S)
#define CC_D LCTL_T(KC_D)
#define CC_F LSFT_T(KC_F)
#define CC_J LSFT_T(KC_J)
#define CC_K LCTL_T(KC_K)
#define CC_L LALT_T(KC_L)
#define CC_QUOT LGUI_T(KC_QUOT)
#define CC_ESC LT(MSC, KC_ESC)
#define CC_SPC LT(NUM, KC_SPC)
#define CC_TAB LT(FUN, KC_TAB)
#define CC_ENT LT(NAV, KC_ENT)
#define CC_BSP LT(PNT, KC_BSPC)
#define CC_DEL LT(MED, KC_DEL)

enum layers {
    HME,
    // Home
    //     > qwerty
    //     > home row with modifiers

    NUM,
    // Numbers and symbols
    //     > keypad like layout on the right side
    //     > number row key codes to easily combine numbers and symbols
    //     > other symbols

    NAV,
    // Cursor movement
    //     > vim style navigation
    //     > insert, home / end, page up / page down

    PNT,
    // Pointer movement
    //     > vim style navigation

    MED,
    //  Media keys
    //     > volume up, down, mute
    //     > previous, next, pause

    FUN,
    // Function keys
    //     > F1 to F9 reuse the NUM layer numbers
    //     > F10 to F12 on the outer right column

	GME,
	// Gaming
	// 	   > Like the Home layer
	//     > No home row modifier

    MSC,
    // Miscellaneous
	//     > keys that don't fit well in other layout
    //     > caps lock
    //     > application menu
    //     > includes the right ctrl key with the intent to use it as the Compose Key
    //         > see https://en.wikipedia.org/wiki/Compose_key

    SET,
    //

    _LAYER_COUNT,
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
        //                         |ESC MSC|SPC NUM|TAB FUN|    |ENT CUR|BSP MSE|DEL MED|
        //                          ------+-------+--------      -------+-------+-------
        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        CC_A,     CC_S,     CC_D,     CC_F,     KC_G,               KC_H,     CC_J,     CC_K,     CC_L,     CC_QUOT,
        KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
					        CC_ESC,   CC_SPC,   CC_TAB,             CC_ENT,   CC_BSP,  CC_DEL
    ),
    [NUM] = LAYOUT_split_3x5_3(
        //   ---------------------------------------                      ---------------------------------------
        //  |   {   |   (   |   )   |   }   |       |                    |  [ {  |  7 &  |  8 *  |   9   |  ] }  |
        //  |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        //  |  GUI  |  ALT  | CTRL  |  SFT  |   -   |                    |  = +  |  4 $  |  5 %  |  6 ^  |  ; :  |
        //  |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        //  |       |       |       |       |   _   |                    |  \ |  |  1 !  |  2 @  |  3 #  |  ` ~  |
        //   -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                          |  ESC  |       |  TAB  |    |       |   0   |       |
        //                           -------+-------+-------      -------+-------+-------
        KC_LCBR,  KC_LPRN,  KC_RPRN,  KC_RCBR,  XXXXXXX,            KC_LBRC,  KC_7,     KC_8,     KC_9,     KC_RBRC,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_MINS,            KC_EQL,   KC_4,     KC_5,     KC_6,     KC_SCLN,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_UNDS,            KC_BSLS,  KC_1,     KC_2,     KC_3,     KC_GRV,
                            KC_ESC,   XXXXXXX,  KC_TAB,             XXXXXXX,  KC_0,     XXXXXXX
    ),
    [NAV] = LAYOUT_split_3x5_3(
        //  ---------------------------------------                      ---------------------------------------
        // |       |       |       |       |       |                    |       |       |       |       |       |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |  GUI  |  ALT  |  CTL  |  SFT  |       |                    |       |   ←   |   ↓   |   ↑   |   →   |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |       |   X   |   C   |   V   |       |                    |  ins  | home  | pgdn  | pgup  |  end  |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |  ESC  |  SPC  |  TAB  |    |       |  BSPC |  DEL  |
        //                          -------+-------+-------      -------+-------+-------
        KC_0,  KC_1,  KC_2,  KC_3,  XXXXXXX,                       XXXXXXX,  KC_1,  KC_2,  KC_3,  KC_0,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,  			XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,
        XXXXXXX,  KC_X,     KC_C,     KC_V,     XXXXXXX,    		KC_INS,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,
                            KC_ESC,   KC_SPC,   KC_TAB,   			XXXXXXX,  KC_BSPC,  KC_DEL
    ),
    [PNT] = LAYOUT_split_3x5_3(
        //  ---------------------------------------                      ---------------------------------------
        // |       |       |       |       |       |                    |       |  ← ←  |  ↓ ↓  |  ↑ ↑  |  → →  |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |  GUI  |  ALT  |  CTL  |  SFT  |       |                    | BTN 3 |   ←   |   ↓   |   ↑   |   →   |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |       |   X   |   C   |   V   |       |                    |       | BTN 1 |       |       | BTN 2 |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         | BTN 1 | BTN 2 | BTN 3 |    |       |       |       |
        //                          -------+-------+-------      -------+-------+-------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  MS_WHLL,  MS_WHLD,  MS_WHLU,  MS_WHLR,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,  			MS_BTN3,  MS_LEFT,  MS_DOWN,  MS_UP,    MS_RGHT,
        XXXXXXX,  KC_X,     KC_C,     KC_V,     XXXXXXX,    		XXXXXXX,  MS_BTN1,  XXXXXXX,  XXXXXXX,  MS_BTN2,
                            MS_BTN1,  MS_BTN2,  MS_BTN3,   			XXXXXXX,  XXXXXXX,  XXXXXXX
    ),
    [MED] = LAYOUT_split_3x5_3(
        //  ---------------------------------------                      ---------------------------------------
        // |       |       |       |       |       |                    |       |       |REWIND |FORWARD|       |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |  GUI  |  ALT  |  CTL  |  SFT  |       |                    |       |  PREV | VOL - | VOL + |  NEXT |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |       |       |       |       |       |                    |       |       |       |       |       |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |  MUTE | PLAY  |       |    |       |       |       |
        //                          -------+-------+-------      -------+-------+-------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  KC_MRWD,  KC_MFFD,  XXXXXXX,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,            XXXXXXX,  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                            KC_MUTE,  KC_MPLY,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX
    ),
    [FUN] = LAYOUT_split_3x5_3(
        //  ---------------------------------------                      ---------------------------------------
        // |       |       |       |       |       |                    |  F13  |   F7  |   F8  |   F9  |  F10  |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |  GUI  |  ALT  |  CTL  |  SFT  |       |                    |  F14  |   F4  |   F5  |   F6  |  F11  |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |       |       |       |       |       |                    |  F15  |   F1  |   F2  |   F3  |  F12  |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |  ESC  |  SPC  |  TAB  |    |       |       |       |
        //                          -------+-------+-------      -------+-------+-------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_F13,   KC_F7,    KC_F8,    KC_F9,    KC_F10,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,            KC_F14,   KC_F4,    KC_F5,    KC_F6,    KC_F11,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_F15,   KC_F1,    KC_F2,    KC_F3,    KC_F12,
                            KC_ESC,   KC_SPC,   KC_TAB,             XXXXXXX,  XXXXXXX,  XXXXXXX
    ),
	[GME] = LAYOUT_split_3x5_3(
		//  ---------------------------------------                      ---------------------------------------
        // |   Q   |   W   |   E   |   R   |   T   |                    |   Y   |   U   |   I   |   0   |   P   |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |   A   |   S   |   D   |   F   |   G   |                    |   H   |   J   |   K   |   L   |   '   |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |   Z   |   X   |   C   |   V   |   B   |                    |   N   |   M   |   ,   |   .   |   /   |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |  ESC  |  SPC  |  TAB  |    |  ENT  |  BSP  |  DEL  |
        //                          ------+-------+--------      -------+-------+-------
        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_QUOT,
        KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
					        CC_ESC,   KC_SPC,   KC_TAB,             KC_ENT,   KC_BSPC,  KC_DEL
	),
	[MSC] = LAYOUT_split_3x5_3(
        //  ---------------------------------------                      ---------------------------------------
        // |       |       |       |       | POWER |                    |  GME  |       |       |       |  PSCR |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |  CAPS |       |       |       |       |                    |       |       |BRIGHT-|BRIGHT+|  RCTL |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |       |       |       |       |       |                    |       |       |       |       |  APP  |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |  ESC  |  SPC  |  TAB  |    |       |       |       |
        //                          -------+-------+-------      -------+-------+-------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PWR,             TG(GME),  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PSCR,
        KC_CAPS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TG(SET),            XXXXXXX,  XXXXXXX,  KC_BRID,  KC_BRIU,  KC_RCTL,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_APP,
                            XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX
    ),
    [SET] = LAYOUT_split_3x5_3(
        //  ---------------------------------------                      ---------------------------------------
        // |       |       |       |       | POWER |                    |  GME  |       |       |       |  PSCR |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |  CAPS |       |       |       |       |                    |       |       |BRIGHT-|BRIGHT+|  RCTL |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |       |       |       |       |       |                    |       |       |       |       |  APP  |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |  ESC  |  SPC  |  TAB  |    |       |       |       |
        //                          -------+-------+-------      -------+-------+-------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TG(SET),            XXXXXXX,  KC_MENU_LEFT,  KC_MENU_UP,  KC_MENU_DOWN,  KC_MENU_RIGHT,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_APP,
                            KC_MENU_ESCAPE,  XXXXXXX,  XXXXXXX,            KC_MENU_SELECT,  XXXXXXX,  XXXXXXX
    )
};

typedef struct {
    uint16_t pressed;
    uint16_t held;
} kc_state_t;

static kc_state_t kc_state = { 0 };

typedef union {
    uint32_t raw;
    struct {
        uint8_t oled_brightness;
        uint8_t oled_brightness_step;
        // uint8_t oled_timeout;
        // bool oled_enabled;
        // timeout mode
    };
} user_configuration_t;

static user_configuration_t user_configuration;

void keyboard_post_init_user(void) {
  user_configuration.raw = eeconfig_read_user();
  user_configuration.oled_brightness_step = 25;
}

static const char * const layer_names[_LAYER_COUNT] PROGMEM = {
    [HME] = "Home",
    [NUM] = "Num",
    [NAV] = "Nav",
    [PNT] = "Pointer",
    [MED] = "Media",
    [FUN] = "Function",
    [GME] = "Gaming",
    [MSC] = "Misc",
    [SET] = "Setting",
};

const char *int_string(uint16_t value) {
    static char buffer[5];
    snprintf(buffer, sizeof(buffer), "%i", value);

    return buffer;
}


const char *layer_string(uint8_t layer) {
    if (layer < _LAYER_COUNT) {
        return (const char *)pgm_read_ptr(&layer_names[layer]);
    }

    return get_u8_str(layer, ' ');
}

void increase_brightness(void)
{
    if (255 < user_configuration.oled_brightness + user_configuration.oled_brightness_step) {
        user_configuration.oled_brightness = 255;

        return;
    }

    user_configuration.oled_brightness = user_configuration.oled_brightness + user_configuration.oled_brightness_step;
}

void decrease_brightness(void)
{
    if (0 > user_configuration.oled_brightness - user_configuration.oled_brightness_step) {
        user_configuration.oled_brightness = 0;

        return;
    }

    user_configuration.oled_brightness = user_configuration.oled_brightness - user_configuration.oled_brightness_step;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (SET == get_highest_layer(state) && !menu_showing()) {
        menu_on();
    }

    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    kc_state.pressed = get_keycode(keycode);

    if (KC_MENU_UP <= keycode && KC_MENU_ESCAPE >= keycode) {
        menu_handle_input(keycode);
    }

    return true;
};

bool oled_task_user(void) {
    if (menu_showing()) {
        menu_draw_on_screen();
        return false;
    }

    oled_write("Layer: ", false);
    oled_write_ln(layer_string(get_highest_layer(layer_state)), false);

    oled_write("Key  : ", false);
//    oled_write_ln(int_string(kc_state.pressed), false);
    oled_write_ln(keycode_string(kc_state.pressed), false);

    // oled_write("EE Oled: ", false);
    // oled_write_ln(keycode_string(user_configuration.oled_brightness), false);

    return false;
}
