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
         FN1,PSCR,
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
        TRNS, FN0,FN18,FN16,FN19,FN17,
        TRNS, FN1, FN2, FN3, FN4, FN5,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F12,   F6,  F7,  F8,  F9, F10,TRNS,
             TRNS,TRNS,VOLD,  UP,VOLU,TRNS,TRNS,
                  TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,
             TRNS, FN7, FN8, FN9,FN10,FN11,FN12,
                       FN13,FN14,FN15,TRNS,TRNS,
         FN6,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer3: "numpad" with regular number keys
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
    PARENS,
    BRACKETS,
    BRACES,
    FOUR,
};

enum macro_id {
    M_PRIVATE,
    M_PROTECTED,
    M_PUBLIC,
    M_FUNCTION,
    M_CLOSURE,
    M_EMAIL_DOMAIN,
    M_USERNAME,
    M_SMILEY1,
    M_SMILEY2,
    M_SMILEY3,
    M_SMILEY4,
    M_SMILEY5,
    M_SMILEY6,
    M_LOOK_OF_DISAPPROVAL,
    M_MUSIC,
    M_SHRUG,
    M_ARROW,
    M_FAT_ARROW,
    M_THIS_ARROW,
    M_ARRAY,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    // Beginning on 0: Actions that are only needed on layer 0
    [0] =   ACTION_FUNCTION(TEENSY_KEY),                    // FN0  - Teensy key

    [1] =   ACTION_MODS_KEY(MOD_RALT, KC_2),                // FN5  = AltGr + 2 = @

    // Counting downwards from 31: Actions that are needed on all layers (or more than just on layer 0)
    [24] =  ACTION_FUNCTION(PARENS),                        // FN24 = ( normally, ) on shifted
    [25] =  ACTION_FUNCTION(BRACKETS),                      // FN25 = [ normally, ] on shifted
    [26] =  ACTION_FUNCTION(BRACES),                        // FN26  = { normally, } on shifted
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
    [4] =   ACTION_MACRO(M_FUNCTION),                       // FN4  = Type out "function "
    [5] =   ACTION_MACRO(M_CLOSURE),                        // FN5  = Type out "function() {}" and then a left arrow

    [6] =   ACTION_MACRO(M_EMAIL_DOMAIN),                   // FN6  = Type out "@olemartin.org"

    [7] =   ACTION_MACRO(M_SMILEY1),                        // FN7  = Type out ":-)"
    [8] =   ACTION_MACRO(M_SMILEY2),                        // FN8  = Type out ";-)"
    [9] =   ACTION_MACRO(M_SMILEY3),                        // FN9  = Type out ":-P"
    [10] =  ACTION_MACRO(M_SMILEY4),                        // FN10 = Type out ":-D"
    [11] =  ACTION_MACRO(M_SMILEY5),                        // FN11 = Type out ":-O"
    [12] =  ACTION_MACRO(M_SMILEY6),                        // FN12 = Type out ":-/"

    [13] =  ACTION_MACRO(M_LOOK_OF_DISAPPROVAL),            // FN13 = Type out "ಠ_ಠ"
    [14] =  ACTION_MACRO(M_MUSIC),                          // FN14 = Type out "♫♪♫"
    [15] =  ACTION_MACRO(M_SHRUG),                          // FN15 = Type out "¯\_(ツ)_/¯"

    [16] =  ACTION_MACRO(M_FAT_ARROW),                      // FN16 = Type out "=>"
    [17] =  ACTION_MACRO(M_ARRAY),                          // FN17 = Type out "array()" and then left arrow
    [18] =  ACTION_MACRO(M_ARROW),                          // FN18 = Type out "->"
    [19] =  ACTION_MACRO(M_THIS_ARROW),                     // FN19 = Type out "$this->"
};

static const uint16_t PROGMEM fn_actions_3[] = {
    [0] =  ACTION_MACRO(M_USERNAME),                        // FN0  = Type out "olemartinorg"
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
    uint8_t extra_del_key = 0;
    uint8_t extra_del_weak_mod = 0;

    if (id == PARENS && shift_pressed) {
        // If shift is pressed, send the 9 key
        key = KC_9;
        extra_del_key = KC_8;
        weak_mods = MOD_BIT(KC_RSHIFT);
    } else if (id == PARENS) {
        // If shift is not pressed, send the 8 key along with a shift
        key = KC_8;
        extra_del_key = KC_9;
        weak_mods = MOD_BIT(KC_RSHIFT);
    }

    if (id == BRACKETS && shift_pressed) {
        // If shift is pressed, clear it and send the 9 key with a RALT
        key = KC_9;
        extra_del_key = KC_8;
        weak_mods = MOD_BIT(KC_RALT);
    } else if (id == BRACKETS) {
        // If shift is not pressed, send the 8 key along with a RALT
        key = KC_8;
        extra_del_key = KC_9;
        weak_mods = MOD_BIT(KC_RALT);
    }

    if (id == BRACES && shift_pressed) {
        // If shift is pressed, clear it and send the 0 key with a RALT
        key = KC_0;
        extra_del_key = KC_7;
        weak_mods = MOD_BIT(KC_RALT);
    } else if (id == BRACES) {
        // If shift is not pressed, send the 7 key along with a RALT
        key = KC_7;
        extra_del_key = KC_0;
        weak_mods = MOD_BIT(KC_RALT);
    }

    if (id == FOUR && shift_pressed) {
        // If shift is pressed, clear it and send the RALT modifier instead
        key = KC_4;
        weak_mods = MOD_BIT(KC_RALT);
    } else if (id == FOUR) {
        key = KC_4;
        extra_del_weak_mod = MOD_BIT(KC_RALT);
    }

    if (record->event.pressed) {
        add_key(key);
        add_weak_mods(weak_mods);
    } else {
        del_key(key);
        del_key(extra_del_key);
        del_weak_mods(weak_mods);
        del_weak_mods(extra_del_weak_mod);
    }
    if (shift_pressed) {
        del_mods(shift);
    }
    send_keyboard_report();
    if (shift_pressed) {
        add_mods(shift);
    }
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
            case M_FUNCTION:
                return MACRO(T(F), T(U), T(N), T(C), T(T), T(I), T(O), T(N), T(SPC), END);
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
            case M_SMILEY1:
                return MACRO(D(LSHIFT), T(DOT), U(LSHIFT), T(SLASH), D(LSHIFT), T(9), U(LSHIFT), END);
            case M_SMILEY2:
                return MACRO(D(LSHIFT), T(COMMA), U(LSHIFT), T(SLASH), D(LSHIFT), T(9), U(LSHIFT), END);
            case M_SMILEY3:
                return MACRO(D(LSHIFT), T(DOT), U(LSHIFT), T(SLASH), D(LSHIFT), T(P), U(LSHIFT), END);
            case M_SMILEY4:
                return MACRO(D(LSHIFT), T(DOT), U(LSHIFT), T(SLASH), D(LSHIFT), T(D), U(LSHIFT), END);
            case M_SMILEY5:
                return MACRO(D(LSHIFT), T(DOT), U(LSHIFT), T(SLASH), D(LSHIFT), T(O), U(LSHIFT), END);
            case M_SMILEY6:
                return MACRO(D(LSHIFT), T(DOT), U(LSHIFT), T(SLASH), D(LSHIFT), T(7), U(LSHIFT), END);
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
                return MACRO(
                    D(RALT), T(4), U(RALT),
                    T(T), T(H), T(I), T(S),
                    T(SLSH),
                    D(LSHIFT), T(NUBS), U(LSHIFT),
                    END
                );
            case M_ARRAY:
                return MACRO(T(A), T(R), T(R), T(A), T(Y), D(LSHIFT), T(8), T(9), U(LSHIFT), T(LEFT), END);
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