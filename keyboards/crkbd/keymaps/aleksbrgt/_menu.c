#include QMK_KEYBOARD_H
#include "_menu.h"

static const char * const menu_item_names[_MENU_ITEM_COUNT] PROGMEM = {
    [MENU_ITEM_NONE] = "Settings",
    // Oled
    [MENU_ITEM_OLED] = "Oled",
    [MENU_ITEM_OLED_BRIGHTNESS] = "Brightness",
    [MENU_ITEM_OLED_TIMEOUT_DELAY] = "Timeout delay",
    [MENU_ITEM_OLED_TIMEOUT_MODE] = "Timeout mode",
    [MENU_ITEM_OLED_ENABLE] = "Enable",

    // Eeprom
    [MENU_ITEM_EEPROM] = "Eeprom"
};

//static const uint8_t * const menu_sections[4] = {
//    MENU_ITEM_NONE = {
//        MENU_ITEM_OLED,
//        MENU_ITEM_EEPROM
//    },
//    MENU_ITEM_OLED = {
//        MENU_ITEM_OLED_BRIGHTNESS,
//        MENU_ITEM_OLED_TIMEOUT_DELAY,
//        MENU_ITEM_OLED_TIMEOUT_MODE,
//        MENU_ITEM_OLED_ENABLE
//    }
//};

static menu_state_t menu_state;

typedef struct {
    uint8_t menu_item;
    uint8_t section_items[];
} menu_section_t;

void menu_on(void) {
    oled_clear();

    menu_state.show = true;
    menu_state.current_menu_item = MENU_ITEM_NONE;
    menu_state.selected_menu_item = MENU_ITEM_NONE;
}

void menu_off(void) {
    menu_state.show = false;
    oled_clear();
    layer_clear();
}

bool menu_showing(void) {
    return menu_state.show;
}

void menu_handle_input(uint16_t keycode) {
    switch (keycode) {
//        case KC_MENU_UP:
//            if (MENU_ITEM_NONE < menu_state.selected_menu_item) {
//                menu_state.selected_menu_item--;
//            }
//            break;
//        case KC_MENU_DOWN:
//            menu_state.selected_menu_item =  (menu_state.selected_menu_item + 1) % sizeof(menu_none_items);
//            break;
//        case KC_MENU_LEFT:
//            break;
//        case KC_MENU_RIGHT:
//            break;
//        case KC_MENU_SELECT:
//            break;
        case KC_MENU_ESCAPE:
            if (MENU_ITEM_NONE == menu_state.current_menu_item) {
                menu_off();
            }
            break;
    }
}

bool menu_is_item_active(uint8_t menu_item) {
    return menu_state.selected_menu_item == menu_item;
}

char *menu_item_string(uint8_t menu_item) {
    return (char *)pgm_read_ptr(&menu_item_names[menu_item]);
};

void menu_draw_item(uint8_t menu_item) {
    oled_write("> ", true);
    oled_write_ln(menu_item_string(menu_item), menu_is_item_active(menu_item));
}

void menu_draw_on_screen(void) {
    oled_write_ln("SETTINGS", false);

//    for (uint8_t i = 0; i < sizeof(menu_sections[menu_state.current_menu_item]); i++) {
//        menu_draw_item(menu_sections[menu_state.current_menu_item][i]);
//    }





//
//    if (menu_state.current_menu_item == MENU_ITEM_NONE) {
//        if (0 == menu_state.selected_menu_item) {
//            menu_state.selected_menu_item = MENU_ITEM_OLED;
//        }
//
//        for (uint8_t i = 0; i < sizeof(menu_none_items); i++) {
//            menu_draw_item(menu_none_items[i]);
//        }

//        oled_write_ln(menu_item_string(MENU_ITEM_OLED), menu_is_item_active(MENU_ITEM_OLED));
//        oled_write_ln(menu_item_string(MENU_ITEM_EEPROM), menu_is_item_active(MENU_ITEM_EEPROM));
//    }
}
