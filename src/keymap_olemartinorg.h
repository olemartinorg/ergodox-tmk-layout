static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(  // Layer0: default
        // left hand
        GRV,    1,   2,   3,   4,   5, ESC,
         TAB,   Q,   W,   E,   R,   T, TAB,
        LCTL,   A,   S,   D,   F,   G,
        LSFT,   Z,   X,   C,   V,   B, DEL,
         FN2,  NO,LALT,NUBS, FN5,
                                      HOME, END,
                                           PGUP,
                                 FN1, LGUI,PGDN,
        // right hand
              FN0,6,   7,   8,   9,   0,NUHS,
               NO,Y,   U,   I,   O,   P,LBRC,
                  H,   J,   K,   L,SCLN,QUOT,
             BSPC,N,   M,COMM, DOT,SLSH,RCTL,
                     FN7, FN6,MINS, EQL,RBRC,
         FN3,PSCR,
         INS,
        RALT, ENT, SPC
    ),

    KEYMAP(  // Layer1: F-keys, arrows, media buttons
        // left hand
        TRNS,  F1,  F2,  F3,  F4,  F5, F11,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS, FN4,MPRV,MPLY,MNXT,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F12,   F6,  F7,  F8,  F9, F10,TRNS,
             TRNS,TRNS,VOLD,  UP,VOLU,TRNS,TRNS,
                  TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,
             TRNS,TRNS,MENU,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer2: "numpad" with regular number keys
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,   7,   8,   9,TRNS,TRNS,
             TRNS,TRNS,   4,   5,   6,TRNS,TRNS,
                  TRNS,   1,   2,   3,TRNS,TRNS,
             TRNS,TRNS,   0,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

/*
    // template to copy from

    KEYMAP(  // LayerN: fully transparent
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
*/

};

/* id for user defined functions & macros */
enum function_id {
    TEENSY_KEY,
    PARENS,
    BRACKETS,
    BRACES
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [0] =   ACTION_FUNCTION(TEENSY_KEY),                    // FN0  - Teensy key

    [1] =   ACTION_LAYER_TAP_TOGGLE(1),                     // FN1  = Hold to use layer 1, serial taps to toggle
    [2] =   ACTION_LAYER_TAP_TOGGLE(2),                     // FN2  = Hold to use layer 2, serial taps to toggle

    [3] =   ACTION_MODS_KEY(MOD_RALT, KC_2),                // FN3  = AltGr + 2 = @
    [4] =   ACTION_MODS_KEY(MOD_LSFT, KC_COMM),             // FN4  = Shift + , = ;

    [5] =   ACTION_FUNCTION(PARENS),                        // FN5  = ( normally, ) on shifted
    [6] =   ACTION_FUNCTION(BRACKETS),                      // FN6  = [ normally, ] on shifted
    [7] =   ACTION_FUNCTION(BRACES),                        // FN7  = { normally, } on shifted
};


void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(50);
        bootloader_jump(); // should not return
        print("not supported.\n");
        return;
    }

    uint8_t mods = get_mods();
    uint8_t shift = MOD_BIT(KC_LSHIFT);
    bool shift_pressed = mods & shift;
    uint8_t weak_mods = 0;
    uint8_t key = 0;

    if (id == PARENS && shift_pressed) {
        // If shift is pressed, send the 9 key
        key = KC_9;
        weak_mods = MOD_BIT(KC_RSHIFT);
    } else if (id == PARENS) {
        // If shift is not pressed, send the 8 key along with a shift
        key = KC_8;
        weak_mods = MOD_BIT(KC_RSHIFT);
    }

    if (id == BRACKETS && shift_pressed) {
        // If shift is pressed, clear it and send the 9 key with a RALT
        key = KC_9;
        weak_mods = MOD_BIT(KC_RALT);
    } else if (id == BRACKETS) {
        // If shift is not pressed, send the 8 key along with a RALT
        key = KC_8;
        weak_mods = MOD_BIT(KC_RALT);
    }

    if (id == BRACES && shift_pressed) {
        // If shift is pressed, clear it and send the 0 key with a RALT
        key = KC_0;
        weak_mods = MOD_BIT(KC_RALT);
    } else if (id == BRACES) {
        // If shift is not pressed, send the 7 key along with a RALT
        key = KC_7;
        weak_mods = MOD_BIT(KC_RALT);
    }

    if (record->event.pressed) {
        add_key(key);
        add_weak_mods(weak_mods);
    } else {
        del_key(key);
        del_weak_mods(weak_mods);
    }
    if (shift_pressed) {
        del_mods(shift);
    }
    send_keyboard_report();
    if (shift_pressed) {
        add_mods(shift);
    }
}

