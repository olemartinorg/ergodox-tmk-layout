static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(  // Layer0: default
        // left hand
        GRV,    1,   2,   3,FN27,   5, ESC,
        LALT,   Q,   W,   E,   R,   T, TAB,
        LCTL,   A,   S,   D,   F,   G,
        LSFT,   Z,   X,   C,   V,   B, DEL,
        FN30,FN31,  NO,NUBS,FN24,
                                      HOME, END,
                                           PGUP,
                                FN29, LGUI,PGDN,
        // right hand
             FN28,6,   7,   8,   9,   0,NUHS,
              TAB,Y,   U,   I,   O,   P,LBRC,
                  H,   J,   K,   L,SCLN,QUOT,
             BSPC,N,   M,COMM, DOT,SLSH,RCTL,
                    FN26,FN25,MINS, EQL,RBRC,
         FN1,  NO,
         INS,
        RALT, ENT, SPC
    ),

    KEYMAP(  // Layer1: Tarmak 1
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,   J,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,   N,   E,TRNS,TRNS,TRNS,
             TRNS,   K,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),


    KEYMAP(  // Layer2: F-keys, arrows, media buttons
        // left hand
        TRNS,  F1,  F2,  F3,  F4,  F5, F11,
        TRNS,MPRV,MPLY,MNXT,TRNS,TRNS,TRNS,
        TRNS, FN0,FN12,FN10,FN13,FN14,
        TRNS, FN1, FN2, FN3, FN4, FN5,FN11,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F12,   F6,  F7,  F8,  F9, F10,TRNS,
             TRNS,WH_U,VOLD,  UP,VOLU,TRNS,TRNS,
                  WH_D,LEFT,DOWN,RGHT,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                        FN7, FN8, FN9,TRNS,TRNS,
         FN6,PSCR,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer3: "numpad" with regular number keys + recording
        // left hand
        TRNS, FN1, FN2, FN3, FN4, FN5,TRNS,
        TRNS, FN6, FN7, FN8, FN9,FN10,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,FN11,FN12,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,   7,   8,   9,TRNS,TRNS,
                  TRNS,   4,   5,   6,TRNS,TRNS,
             TRNS,TRNS,   1,   2,   3,TRNS,TRNS,
                          0,COMM, DOT,TRNS,TRNS,
         FN0,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer4: mouse layer
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,ACL0,ACL1,ACL2,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,WH_U,TRNS,MS_U,TRNS,TRNS,TRNS,
                  WH_D,MS_L,MS_D,MS_R,TRNS,TRNS,
             TRNS,TRNS,BTN1,BTN3,BTN2,TRNS,TRNS,
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
    FOUR,
};

enum macro_id {
    M_PRIVATE,
    M_PROTECTED,
    M_PUBLIC,
    M_STATIC,
    M_CLOSURE,
    M_EMAIL_DOMAIN,
    M_USERNAME,
    M_LOOK_OF_DISAPPROVAL,
    M_MUSIC,
    M_SHRUG,
    M_ARROW,
    M_FAT_ARROW,
    M_THIS_ARROW,
    M_ARRAY,
    M_SELF,
    M_PARENS,
    M_BRACKETS,
    M_BRACES,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    // Beginning on 0: Actions that are only needed on layer 0
    [0] =   ACTION_FUNCTION(TEENSY_KEY),                    // FN0  - Teensy key

    [1] =   ACTION_MODS_KEY(MOD_RALT, KC_2),                // FN5  = AltGr + 2 = @

    // Counting downwards from 31: Actions that are needed on all layers (or more than just on layer 0)
    [24] =  ACTION_MACRO(M_PARENS),                         // FN24 = Prints out () and left arrow
    [25] =  ACTION_MACRO(M_BRACKETS),                       // FN25 = Prints out [] and left arrow
    [26] =  ACTION_MACRO(M_BRACES),                         // FN26 = Prints out {} and left arrow
    [27] =  ACTION_FUNCTION(FOUR),                          // FN27 = 4 normally, $ on shifted (the norwegian keyboard layout used ¤ instead)

    [28] =  ACTION_LAYER_TOGGLE(1),                         // FN28 = Tap to toggle on/off colemak/tarmak
    [29] =  ACTION_LAYER_TAP_TOGGLE(2),                     // FN29 = Hold to use layer 2, serial taps to toggle
    [30] =  ACTION_LAYER_TAP_TOGGLE(3),                     // FN30 = Hold to use layer 3, serial taps to toggle
    [31] =  ACTION_LAYER_TAP_TOGGLE(4),                     // FN31 = Hold to use layer 4, serial taps to toggle
};

static const uint16_t PROGMEM fn_actions_2[] = {
    [0] =   ACTION_MODS_KEY(MOD_LSFT, KC_COMM),             // FN0  = Shift + , = ;

    [1] =   ACTION_MACRO(M_PRIVATE),                        // FN1  = Type out "private "
    [2] =   ACTION_MACRO(M_PROTECTED),                      // FN2  = Type out "protected "
    [3] =   ACTION_MACRO(M_PUBLIC),                         // FN3  = Type out "public "
    [4] =   ACTION_MACRO(M_STATIC),                         // FN4  = Type out "static "
    [5] =   ACTION_MACRO(M_CLOSURE),                        // FN5  = Type out "function() {}" and then a left arrow

    [6] =   ACTION_MACRO(M_EMAIL_DOMAIN),                   // FN6  = Type out "@olemartin.org"

    [7] =   ACTION_MACRO(M_LOOK_OF_DISAPPROVAL),            // FN7  = Type out "ಠ_ಠ"
    [8] =   ACTION_MACRO(M_MUSIC),                          // FN8  = Type out "♫♪♫"
    [9] =   ACTION_MACRO(M_SHRUG),                          // FN9  = Type out "¯\_(ツ)_/¯"

    [10] =  ACTION_MACRO(M_FAT_ARROW),                      // FN10 = Type out "=>"
    [11] =  ACTION_MACRO(M_ARRAY),                          // FN11 = Type out "array()" and then left arrow
    [12] =  ACTION_MACRO(M_ARROW),                          // FN12 = Type out "->"
    [13] =  ACTION_MACRO(M_THIS_ARROW),                     // FN13 = Type out "$this->"
    [14] =  ACTION_MACRO(M_SELF),                           // FN14 = Type out "self::"
};

static const uint16_t PROGMEM fn_actions_3[] = {
    [0] =  ACTION_MACRO(M_USERNAME),                        // FN0  = Type out "olemartinorg"

    [1] =  ACTION_RECORD_TOGGLE(0),                         // FN1  = Toggle recording on slot 0
    [2] =  ACTION_RECORD_TOGGLE(1),                         // FN2  = Toggle recording on slot 1
    [3] =  ACTION_RECORD_TOGGLE(2),                         // FN3  = Toggle recording on slot 2
    [4] =  ACTION_RECORD_TOGGLE(3),                         // FN4  = Toggle recording on slot 3
    [5] =  ACTION_RECORD_TOGGLE(4),                         // FN5  = Toggle recording on slot 4

    [6] =  ACTION_RECORD_PLAY(0),                           // FN6  = Play recording on slot 0
    [7] =  ACTION_RECORD_PLAY(1),                           // FN7  = Play recording on slot 1
    [8] =  ACTION_RECORD_PLAY(2),                           // FN8  = Play recording on slot 2
    [9] =  ACTION_RECORD_PLAY(3),                           // FN9  = Play recording on slot 3
    [10] = ACTION_RECORD_PLAY(4),                           // FN10 = Play recording on slot 4

    [11] = ACTION_RECORD_SET_INTERVAL(0),                   // FN11 = Set playback interval to 0ms
    [12] = ACTION_RECORD_SET_INTERVAL(3),                   // FN12 = Set playback interval to 16*3ms
};

void action_function_custom(keyrecord_t *record, uint8_t key, uint8_t weak_mod,
                            uint8_t key_when_shifted, uint8_t weak_mod_when_shifted)
{
    uint8_t shift = MOD_BIT(KC_LSHIFT);
    bool shift_pressed = get_mods() & shift;

    if (record->event.pressed && shift_pressed) {
        add_key(key);
        if(weak_mod_when_shifted) {
            add_weak_mods(MOD_BIT(weak_mod_when_shifted));
        }
    } else if(record->event.pressed && !shift_pressed) {
        add_key(key);
        if(weak_mod) {
            add_weak_mods(MOD_BIT(weak_mod));
        }
    } else if (!record->event.pressed && shift_pressed) {
        del_key(key);
        if(weak_mod_when_shifted) {
            del_weak_mods(MOD_BIT(weak_mod_when_shifted));
        }
    } else {
        del_key(key);
        if(weak_mod) {
            del_weak_mods(MOD_BIT(weak_mod));
        }
    }

    if (shift_pressed) {
        del_mods(shift);
    }
    send_keyboard_report();
    if (shift_pressed) {
        add_mods(shift);
    }
}

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

    if (id == FOUR)
        action_function_custom(record, KC_4, 0, KC_4, KC_RALT);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch (id) {
            case M_PRIVATE:
                return MACRO(T(P), T(R), T(I), T(V), T(A), T(T), T(E), T(SPC), END);
            case M_PROTECTED:
                return MACRO(T(P), T(R), T(O), T(T), T(E), T(C), T(T), T(E), T(D), T(SPC), END);
            case M_PUBLIC:
                return MACRO(T(P), T(U), T(B), T(L), T(I), T(C), T(SPC), END);
            case M_STATIC:
                return MACRO(T(S), T(T), T(A), T(T), T(I), T(C), T(SPC), END);
            case M_CLOSURE:
                return MACRO(
                    T(F), T(U), T(N), T(C), T(T), T(I), T(O), T(N),
                    D(LSHIFT), T(8), T(9), U(LSHIFT), T(SPC), D(RALT),
                    T(7), T(0), U(RALT), T(LEFT), END
                );
            case M_EMAIL_DOMAIN:
                return MACRO(
                    D(RALT), T(2), U(RALT), T(O), T(L), T(E), T(M), T(A),
                    T(R), T(T), T(I), T(N), T(DOT), T(O), T(R), T(G), END
                );
            case M_USERNAME:
                return MACRO(
                    T(O), T(L), T(E), T(M), T(A), T(R), T(T), T(I), T(N), T(O), T(R), T(G), END
                );
            case M_LOOK_OF_DISAPPROVAL:
                return MACRO(
                    D(LCTRL), D(LSHIFT), T(U), T(0), T(C), T(A), T(0), U(LCTRL),
                    T(SLASH),
                    D(LCTRL), T(U), T(0), T(C), T(A), T(0), U(LSHIFT), U(LCTRL),
                    END
                );
            case M_MUSIC:
                return MACRO(
                    D(LCTRL), D(LSHIFT), T(U), T(2), T(6), T(6), T(B), U(LCTRL),
                    D(LCTRL), T(U), T(2), T(6), T(6), T(A), U(LCTRL),
                    D(LCTRL), T(U), T(2), T(6), T(6), T(B), U(LCTRL), U(LSHIFT),
                    END
                );
            case M_SHRUG:
                return MACRO(
                    D(LSHIFT),
                        D(LCTRL),
                            T(U), T(A), T(F),
                        U(LCTRL),
                    U(LSHIFT),
                    T(EQL),
                    D(LSHIFT),
                        T(SLASH),
                        T(8),
                        D(LCTRL),
                            T(U), T(3), T(0), T(C), T(4),
                        U(LCTRL),
                        T(9),
                        T(SLASH),
                        T(7),
                        D(LCTRL),
                            T(U), T(A), T(F),
                        U(LCTRL),
                    U(LSHIFT),
                    END
                );
            case M_ARROW:
                return MACRO(T(SLSH), D(LSHIFT), T(NUBS), U(LSHIFT), END);
            case M_FAT_ARROW:
                return MACRO(D(LSHIFT), T(0), T(NUBS), U(LSHIFT), END);
            case M_THIS_ARROW:
                return MACRO(D(RALT), T(4), U(RALT), T(T), T(H), T(I), T(S), END);
            case M_ARRAY:
                return MACRO(T(A), T(R), T(R), T(A), T(Y), D(LSHIFT), T(8), T(9), U(LSHIFT), T(LEFT), END);
            case M_SELF:
                return MACRO(T(S), T(E), T(L), T(F), D(LSHIFT), T(DOT),  T(DOT), U(LSHIFT), END);
            case M_PARENS:
                return MACRO(D(LSHIFT), T(8), T(9), U(LSHIFT), T(LEFT), END);
            case M_BRACKETS:
                return MACRO(D(RALT), T(8), T(9), U(RALT), T(LEFT), END);
            case M_BRACES:
                return MACRO(D(RALT), T(7), T(0), U(RALT), T(LEFT), END);

        }
    }
    return MACRO_NONE;
}

#define FN_ACTIONS_SIZE (sizeof(fn_actions) / sizeof(fn_actions[0]))
#define FN_ACTIONS_2_SIZE (sizeof(fn_actions_2) / sizeof(fn_actions_2[0]))
#define FN_ACTIONS_3_SIZE (sizeof(fn_actions_3) / sizeof(fn_actions_3[0]))

/*
* translates Fn keycode to action
* for some layers, use different translation table
*/
action_t keymap_fn_to_action(uint8_t keycode)
{
    uint8_t layer = biton32(layer_state);
    action_t action;
    action.code = ACTION_NO;

    if (layer == 3 && FN_INDEX(keycode) < FN_ACTIONS_3_SIZE) {
        action.code = pgm_read_word(&fn_actions_3[FN_INDEX(keycode)]);
    }
    if (layer == 2 && FN_INDEX(keycode) < FN_ACTIONS_2_SIZE) {
        action.code = pgm_read_word(&fn_actions_2[FN_INDEX(keycode)]);
    }

    // by default, use fn_actions from default layer 0
    // this is needed to get mapping for same key, that was used switch to some layer,
    // to have possibility to switch layers back
    if (action.code == ACTION_NO && FN_INDEX(keycode) < FN_ACTIONS_SIZE) {
        action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
    }
    return action;
}