#include QMK_KEYBOARD_H
#include "_keycodes.h"
#include "_menu.h"

typedef struct {
    uint16_t keycode;
    const char *label;
} key_label_t;

static const key_label_t kc_labels[] PROGMEM = {
    { KC_A, "a" },
    { KC_B, "b" },
    { KC_C, "c" },
    { KC_D, "d" },
    { KC_E, "e" },
    { KC_F, "f" },
    { KC_G, "g" },
    { KC_H, "h" },
    { KC_I, "i" },
    { KC_J, "j" },
    { KC_K, "k" },
    { KC_L, "l" },
    { KC_M, "m" },
    { KC_N, "n" },
    { KC_O, "o" },
    { KC_P, "p" },
    { KC_Q, "q" },
    { KC_R, "r" },
    { KC_S, "s" },
    { KC_T, "t" },
    { KC_U, "u" },
    { KC_V, "v" },
    { KC_W, "w" },
    { KC_X, "x" },
    { KC_Y, "y" },
    { KC_Z, "z" },
    { KC_1, "1" },
    { KC_2, "2" },
    { KC_3, "3" },
    { KC_4, "4" },
    { KC_5, "5" },
    { KC_6, "6" },
    { KC_7, "7" },
    { KC_8, "8" },
    { KC_9, "9" },
    { KC_0, "0" },
    { KC_MINS, "-" },
    { KC_EQL, "=" },
    { KC_LBRC, "[" },
    { KC_RBRC, "]" },
    { KC_BSLS, "\\" },
    { KC_NUHS, "#" },
    { KC_SCLN, ";" },
    { KC_QUOT, "'" },
    { KC_GRV, "`" },
    { KC_COMM, "," },
    { KC_DOT, "." },
    { KC_SLSH, "/" },
    { KC_ENT, "Return" },
    { KC_ESC, "Escape" },
    { KC_BSPC, "Backspace" },
    { KC_TAB, "Tab" },
    { 44, "Space" },
    { KC_CAPS, "Caps" },
    { KC_DEL, "Delete" },
    { KC_LGUI, "Super" },
    { KC_LALT, "Alt" },
    { KC_LCTL, "Control" },
    { KC_LSFT, "Shift" },
    { KC_LEFT, "Left" },
    { KC_DOWN, "Down" },
    { KC_UP, "Up" },
    { KC_RGHT, "Right" },
    { KC_INS, "Insert" },
    { KC_HOME, "Home" },
    { KC_PGDN, "Page down" },
    { KC_PGUP, "Page up" },
    { KC_END, "End" },
    { MS_WHLL, "Scroll left" },
    { MS_WHLD, "Scroll down" },
    { MS_WHLU, "Scroll up" },
    { MS_WHLR, "Scroll right" },
    { MS_LEFT, "Mouse left" },
    { MS_DOWN, "Mouse down" },
    { MS_UP, "Mouse up" },
    { MS_RGHT, "Mouse right" },
    { MS_BTN1, "Left click" },
    { MS_BTN2, "Right click" },
    { MS_BTN3, "Wheel click" },
    { KC_MRWD, "Rewind" },
    { KC_MFFD, "Forward" },
    { KC_VOLU, "Vol +" },
    { KC_VOLD, "Vol -" },
    { KC_MUTE, "Mute" },
    { KC_MNXT, "Next" },
    { KC_MPRV, "Prev" },
    { KC_MPLY, "Play/Pause" },
    { KC_F1, "F1" },
    { KC_F2, "F2" },
    { KC_F3, "F3" },
    { KC_F4, "F4" },
    { KC_F5, "F5" },
    { KC_F6, "F6" },
    { KC_F7, "F7" },
    { KC_F8, "F8" },
    { KC_F9, "F9" },
    { KC_F10, "F10" },
    { KC_F11, "F11" },
    { KC_F12, "F12" },
    { KC_F13, "F13" },
    { KC_F14, "F14" },
    { KC_F15, "F15" },
    { KC_PWR, "Power" },
    { KC_PSCR, "Print screen" },
    { KC_BRID, "Brigtness -" },
    { KC_BRIU, "Brightnes +" },
    { KC_RCTL, "Compose key" },
    { KC_APP, "Menu" },
    { KC_LCBR, "{" },
    { KC_RBRC, "}" },
    { KC_LPRN, "(" },
    { KC_RPRN, ")" },
    // SETTING MENU KEYS
    {KC_MENU_UP, "Menu up"},
    {KC_MENU_DOWN, "Menu down"},
    {KC_MENU_LEFT, "Menu left"},
    {KC_MENU_RIGHT, "Menu right"},
    {KC_MENU_SELECT, "Menu select"},
    {KC_MENU_ESCAPE, "Menu escape"}
};

const char *keycode_string(uint16_t keycode) {
    if (0 == keycode) {
        return "";
    }

    for (uint16_t i = 0; i < ARRAY_SIZE(kc_labels); i++) {
        key_label_t entry;
        memcpy_P(&entry, &kc_labels[i], sizeof(key_label_t));

        if (keycode == entry.keycode) {
            return entry.label;
        }
    }

    return "?";
}

uint16_t get_keycode(uint16_t keycode) {
    if (IS_QK_MOD_TAP(keycode)) {
        return QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    }

    if (IS_QK_LAYER_TAP(keycode)) {
        return QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    }

    return keycode;
}
