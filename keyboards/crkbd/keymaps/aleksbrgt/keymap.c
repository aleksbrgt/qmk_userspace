#include QMK_KEYBOARD_H
#include <stdio.h>

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
#define CC_TAB LT(MED, KC_TAB)
#define CC_ENT LT(CUR, KC_ENT)
#define CC_DEL LT(FUN, KC_DEL)

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
        CC_A,     CC_S,     CC_D,     CC_F,     KC_G,               KC_H,     CC_J,     CC_K,     CC_L,     CC_QUOT,
        KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
					        CC_ESC,   CC_SPC,   CC_TAB,             CC_ENT,   KC_BSPC,  CC_DEL
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
        // |       |       |       |       |       |                    |       |       |       |       |       |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |  GUI  |  ALT  |  CTL  |  SFT  |       |                    |       |  PREV | VOL - | VOL + |  NEXT |
        // |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
        // |       |       |       |       |       |                    |       |       |       |       |       |
        //  -------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------
        //                         |  ESC  |  SPC  |  TAB  |    |       | PLAY  |  MUTE |
        //                          -------+-------+-------      -------+-------+-------
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
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