enum menu_items {
    MENU_ITEM_NONE,
    // Oled
    MENU_ITEM_OLED,
    MENU_ITEM_OLED_BRIGHTNESS,
    MENU_ITEM_OLED_TIMEOUT_DELAY,
    MENU_ITEM_OLED_TIMEOUT_MODE,
    MENU_ITEM_OLED_ENABLE,
    // Eeprom
    MENU_ITEM_EEPROM,
    MENU_ITEM_EEPROM_RESET,
    _MENU_ITEM_COUNT
};

enum menu_keycodes {
    KC_MENU_UP = 3232, // 3232 = SAFE_RANGE
    KC_MENU_DOWN,
    KC_MENU_LEFT,
    KC_MENU_RIGHT,
    KC_MENU_SELECT,
    KC_MENU_ESCAPE
};

typedef struct {
    bool show;
    uint8_t current_menu_item;
    uint8_t selected_menu_item;
} menu_state_t;

void menu_on(void);
void menu_off(void);
bool menu_showing(void);
void menu_handle_input(uint16_t keycode);
void menu_draw_on_screen(void);
