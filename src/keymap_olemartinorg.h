/*
 * Things i have learnt:
 * NUBS = < and >
 */

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(  // Layer0: default
        // left hand
        GRV,    1,   2,   3,   4,   5, ESC,
         TAB,   Q,   W,   E,   R,   T, TAB,
        LCTL,   A,   S,   D,   F,   G,
        LSFT,   Z,   X,   C,   V,   B, DEL,
         FN2,  NO,LALT,  NO,  NO,
                                      HOME, END,
                                           PGUP,
                                 FN1, LGUI,PGDN,
        // right hand
              FN0,6,   7,   8,   9,   0,  NO,
               NO,Y,   U,   I,   O,   P,LBRC,
                  H,   J,   K,   L,SCLN,QUOT,
             BSPC,N,   M,COMM, DOT,SLSH,RCTL,
                      NO,  NO,MINS, EQL,BSLS,
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
             TRNS,TRNS,VOLD,  UP,VOLU,TRNS,TFNS,
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
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
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
    CUSTOM_KEY,
    L_CTRL_ALT_ENT,
    R_CTRL_ALT_ENT,
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


};


void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // print("action_function called\n");
    // print("id  = "); phex(id); print("\n");
    // print("opt = "); phex(opt); print("\n");

    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(50);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }

    if (id == L_CTRL_ALT_ENT || id == R_CTRL_ALT_ENT) {
        if (record->tap.count == 0 || record->tap.interrupted) {
            uint8_t weak_mods;
            uint8_t layer;

            if (id == L_CTRL_ALT_ENT) {
                weak_mods = MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT);
                layer     = 5;
            } else {
                weak_mods = MOD_BIT(KC_RCTL) | MOD_BIT(KC_RALT);
                layer     = 6;
            }

            if (record->event.pressed) {
                layer_on(layer);
                add_weak_mods(weak_mods);
            } else {
                del_weak_mods(weak_mods);
                layer_off(layer);
            }
        } else {
            if (record->event.pressed) {
                add_key(KC_ENT);
                send_keyboard_report();
            } else {
                del_key(KC_ENT);
                send_keyboard_report();
            }
        }
    }

}

