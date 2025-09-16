/*

                                        █         █    █            ▄▄▄▀▀▀▀▀▀▄▄▄        █▀▀▀▀▀▀▀▀▀▀█
                                        █        █     █          ▄▀            ▀▄      █          █
                                        █       █      █        ▄▀                ▀▄    █          █
                                        █      █       █        █                  █    █          █
                                        █     █        █       █                    █   █          █
                                        █    █         █       █                    █   █▄▄▄▄▄▄▄▄▄▄█
                                        █   █ █        █       █                    █   █      █
                                        █  █   █       █        █                  █    █       █
                                        █ █     █      █        ▀▄                ▄▀    █        █
                                        ██       █     █          ▀▄            ▄▀      █         █
                                        █         █    █▄▄▄▄▄▄▄▄    ▀▀▀▄▄▄▄▄▄▀▀▀        █          █

                                        ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
                                        D E F A U L T

*/
#include "klor_layers.h"
#include <stdio.h>
#include <string.h>
#ifdef HAPTIC_ENABLE
#    include "drivers/haptic/DRV2605L.h"
#endif // HAPTIC ENABLE

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                                      │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s                         │
// └───────────────────────────────────────────────────────────┘

// QWERTY
// LEFT HAND HOME ROW MODS ├───────────────────────────────────┐

#define HRM_A MT(MOD_LCTL, KC_A)
#define HRM_S MT(MOD_LALT, KC_S)
#define HRM_D MT(MOD_LGUI, KC_D)
#define HRM_F MT(MOD_LSFT, KC_F)

// RIGHT HAND HOME ROW MODS ├───────────────────────────────────┐

#define HRM_J MT(MOD_RSFT, KC_J)
#define HRM_K MT(MOD_LGUI, KC_K)
#define HRM_L MT(MOD_LALT, KC_L)
#define HRM_SCLN MT(MOD_LCTL, KC_SCLN)

// EXTRA

#define ESC_GUI LGUI_T(KC_ESC)

// THUMBKEYS
#define NAV LT(_NAV, KC_SPACE)
#define NUM LT(_NUM, KC_BSPC)
#define FUN LT(_FUN, KC_DEL)
#define MOUSE LT(_MOUSE, KC_TAB)
#define SYM LT(_SYM, KC_ENTER)
#define ACCENT LT(_ACCENTS, KC_ESC)

// ┌───────────────────────────────────────────────────────────┐
// │ l a y o u t  a n d  k e y m a p                           │
// └───────────────────────────────────────────────────────────┘

// Import the layout that you use from the layouts folder
#include "layout.cfg"

// Import the keymap that you use from the layouts folder
#include "keymap.h"

// Remember to change the layout name to the one you are using
// e.g. LAYOUT_konrad to LAYOUT_polydactyl
#define LAYOUT LAYOUT_konrad

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   s o u n d s                                 │
// └───────────────────────────────────────────────────────────┘

#ifdef AUDIO_ENABLE
#    define WINXP_SOUND W__NOTE(_DS6), Q__NOTE(_DS5), H__NOTE(_AS5), H__NOTE(_GS5), H__NOTE(_DS5), H__NOTE(_DS6), H__NOTE(_AS5)
#    define MAC_SOUND S__NOTE(_CS5), B__NOTE(_C5)

float winxp_song[][2] = SONG(WINXP_SOUND);
float mac_song[][2]   = SONG(MAC_SOUND);
#endif // AUDIO_ENABLE

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ H A P T I C   F E E D B A C K                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

void keyboard_post_init_user(void) {
// Call the post init code.
#if HAPTIC_ENABLE
    haptic_disable(); // disables per key haptic feedback by default
#endif                // HAPTIC ENABLE
}

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ O L E D                                                                                                                                    │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

#ifdef OLED_ENABLE

// ┌───────────────────────────────────────────────────────────┐
// │ d y n a m i c   m a c r o                                 │
// └───────────────────────────────────────────────────────────┘

char layer_state_str[24];
char o_text[24] = "";
int  dmacro_num = 0;

#    ifdef DYNAMIC_MACRO_ENABLE
char               dmacro_text[4][24] = {"", "RECORDING", "STOP RECORDING", "PLAY RECORDING"};
static uint16_t    dmacro_timer;
const char PROGMEM rec_ico[]  = {0xD1, 0xE1, 0};
const char PROGMEM stop_ico[] = {0xD3, 0xE1, 0};
const char PROGMEM play_ico[] = {0xD2, 0xE1, 0};

// DYNMACRO RECORD ├─────────────────────────────────────────────────────────────┐
void dynamic_macro_record_start_user(void) {
    dmacro_num = 1;
    return;
}

// DYNMACRO STOP RECORDING ├─────────────────────────────────────────────────────┐
void dynamic_macro_record_end_user(int8_t direction) {
    dmacro_num   = 2;
    dmacro_timer = timer_read();
    return;
}

// DYNMACRO PLAY RECORDING ├─────────────────────────────────────────────────────┐
void dynamic_macro_play_user(int8_t direction) {
    dmacro_num   = 3;
    dmacro_timer = timer_read();
    return;
}
#    endif // DYNAMIC_MACRO_ENABLE

void matrix_scan_user(void) {
#    ifdef DYNAMIC_MACRO_ENABLE
    // DynMacroTimer
    if (dmacro_num > 0) {
        if (timer_elapsed(dmacro_timer) < 3000) {
            strcpy(o_text, dmacro_text[dmacro_num]);
        } else {
            if (dmacro_num == 1) {
                strcpy(o_text, dmacro_text[1]);
            } else {
                strcpy(o_text, layer_state_str);
                dmacro_num = 0;
            }
        }
    }
#    endif // DYNAMIC_MACRO_ENABLE
}

// ┌───────────────────────────────────────────────────────────┐
// │ o l e d   g r a p h i c s                                 │
// └───────────────────────────────────────────────────────────┘

char modifiers[24]    = "init";
bool caps_word_status = false;
void caps_word_set_user(bool active) {
    if (active) {
        // Do something when Caps Word activates.
        caps_word_status = true;
    } else {
        // Do something when Caps Word deactivates.
        caps_word_status = false;
    }
}

void write_capsword_status(void) {
    if (caps_word_status) {
        oled_write_P(PSTR("TRUE"), false);
    } else {
        oled_write_P(PSTR("FALSE"), false);
    }
}

void render_os_lock_status(void) {
    static const char PROGMEM sep_v[]  = {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0};
    static const char PROGMEM sep_h1[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM sep_h2[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM face_1[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xE1, 0};
    static const char PROGMEM face_2[] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xE1, 0};
    static const char PROGMEM os_m_1[] = {0x95, 0x96, 0};
    static const char PROGMEM os_m_2[] = {0xB5, 0xB6, 0};
    static const char PROGMEM os_w_1[] = {0x97, 0x98, 0};
    static const char PROGMEM os_w_2[] = {0xB7, 0xB8, 0};
    static const char PROGMEM s_lock[] = {0x8F, 0x90, 0};
    static const char PROGMEM n_lock[] = {0x91, 0x92, 0};
    static const char PROGMEM c_lock[] = {0x93, 0x94, 0};
    static const char PROGMEM b_lock[] = {0xE1, 0xE1, 0};
#    ifdef AUDIO_ENABLE
    static const char PROGMEM aud_en[] = {0xAF, 0xB0, 0};
    static const char PROGMEM aud_di[] = {0xCF, 0xD0, 0};
#    endif
#    ifdef HAPTIC_ENABLE
    static const char PROGMEM hap_en[] = {0xB1, 0xB2, 0};
#    endif

    led_t led_usb_state = host_keyboard_led_state();

    if (led_usb_state.num_lock) {
        oled_write_P(n_lock, false); // ──── NUMLOCK
    } else {
        oled_write_P(b_lock, false);
    }
    if (caps_word_status) {
        oled_write_P(c_lock, false); // ─── CAPSLOCK
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.scroll_lock) { // ─ SCROLLLOCK
        oled_write_P(s_lock, false);
    } else {
        oled_write_P(b_lock, false);
    }

    // hardware feature status ──────────────────────────────┐

    oled_write_P(sep_h2, false);

#    ifndef AUDIO_ENABLE
    oled_write_P(b_lock, false);
#    endif
#    ifndef HAPTIC_ENABLE
    oled_write_P(b_lock, false);
#    endif

#    ifdef AUDIO_ENABLE // ────────────────── AUDIO
    if (is_audio_on()) {
        oled_write_P(aud_en, false);
    } else {
        oled_write_P(aud_di, false);
    }
#    endif // AUDIO ENABLE

#    ifdef HAPTIC_ENABLE // ─────────────── HAPTIC
    oled_write_P(hap_en, false);
#    endif // HAPTIC ENABLE
}

// layer status ──────────────────────────────────────────┐
void write_layer_status(void) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("BASE QWERTY"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("NUMBERS"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAV"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("SYMBOLS"), false);
            break;
        case _FUN:
            oled_write_P(PSTR("FUNCTION"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("MOUSE"), false);
            break;
        case _ACCENTS:
            oled_write_P(PSTR("ACCENTS"), false);
            break;
        default:
            oled_write_P(PSTR("UNDEFINED"), false);
    }
};

// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case SHT_T:
//             return TAPPING_TERM - 150;
//         case SHT_N:
//             return TAPPING_TERM - 150;
//         default:
//             return TAPPING_TERM;
//     }
// }

void oled_render_boot(bool bootloader) {
    oled_clear();
    for (int i = 0; i < 16; i++) {
        oled_set_cursor(0, i);
        if (bootloader) {
            oled_write_P(PSTR("Awaiting New Firmware "), false);
        } else {
            oled_write_P(PSTR("Rebooting "), false);
        }
    }

    oled_render_dirty(true);
}

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                                                │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
            // ┌───────────────────────────────────────────────────────────┐
            // │ q m k                                                     │
            // └───────────────────────────────────────────────────────────┘

        case MAKE_H:
            if (record->event.pressed) {
                SEND_STRING("qmk compile -kb klor/2040 -km bounce_miryoku");
                // tap_code(KC_ENTER);
            }
            break;

        case QK_BOOTLOADER:
            // oled_write_raw_P(PSTR("BOOTLOADER"), false);
            oled_render_boot(true);
            break;

            // ┌───────────────────────────────────────────────────────────┐
            // │ p r o d u c t i v i t y                                   │
            // └───────────────────────────────────────────────────────────┘

        case KC_MPLY:
            if (record->event.pressed) {
#    ifdef HAPTIC_ENABLE
                DRV_pulse(sharp_click);
#    endif // HAPTIC_ENABL
            }
            break;
    }
    return true;
}

void print_spaces(void) {
    oled_write("       ", false);
}

#    include "icons.h"
void display_layer_logo(bool master) {
    switch (get_highest_layer(layer_state)) {
        oled_clear();
        case _BASE:
            oled_write_raw_P(arch_logo, sizeof(arch_logo));
            break;
        case _NUM:
            if (master) {
                print_spaces();
                oled_write_ln_P(PSTR("[  7  8  9  ]"), false);
                oled_write_ln("", false);
                print_spaces();
                oled_write_ln_P(PSTR(";  4  5  6  ="), false);
                oled_write_ln("", false);
                print_spaces();
                oled_write_ln_P(PSTR("\"  1  2  3  \\"), false);
                oled_write_ln("", false);
                print_spaces();
                oled_write_ln_P(PSTR("      .  0  -"), false);
            } else {
                oled_write_ln("NUMBERS", false);
            }
            break;
        case _NAV:
            if (!master) {
                oled_write_ln_P(PSTR("CR CV CC CX CZ"), false);
                oled_write_ln("", false);
                oled_write_char(0X11, false);
                oled_write("  ", false);
                oled_write_char(0X1F, false);
                oled_write("  ", false);
                oled_write_char(0X1E, false);
                oled_write("  ", false);
                oled_write_char(0X10, false);
                oled_write_ln("", false);
                oled_write_ln("", false);
                oled_write_ln_P(PSTR("Insr Home PgD PgU End"), false);
                oled_write_ln("", false);
                // oled_write_ln_P(PSTR("      .  0  -"), false);
            } else {
                oled_write_ln("NAVIGUATION", false);
            }
            break;
        case _SYM:
            if (master) {
                print_spaces();
                oled_write_ln_P(PSTR("{  &  *  (  }"), false);
                oled_write_ln("", false);
                print_spaces();
                oled_write_ln_P(PSTR(":  $  %  ^  +"), false);
                oled_write_ln("", false);
                print_spaces();
                oled_write_ln_P(PSTR("~  !  @  #  |"), false);
                oled_write_ln("", false);
                print_spaces();
                oled_write_ln_P(PSTR("      (  )  _"), false);
            } else {
                oled_write_ln("SYMBOLS", false);
            }
            break;
        case _FUN:
            if (master) {
                oled_write_ln_P(PSTR("  F12 F7 F8 F9 PRSCR"), false);
                oled_write_ln("", false);
                oled_write_ln_P(PSTR("  F11 F4 F5 F6 SLOCK"), false);
                oled_write_ln("", false);
                oled_write_ln_P(PSTR("  F10 F1 F2 F3 BREAK"), false);
                oled_write_ln("", false);
                // oled_write_ln_P(PSTR("      (  )  _"), false);
            } else {
                oled_write_ln("FUNCTION", false);
            }
            break;
        case _MOUSE:
            if (!master) {
                oled_write_ln_P(PSTR("CR CV CC CX CZ"), false);
                oled_write_ln("", false);

                oled_write_char(0X11, false);
                oled_write("  ", false);
                oled_write_char(0X1F, false);
                oled_write("  ", false);
                oled_write_char(0X1E, false);
                oled_write("  ", false);
                oled_write_char(0X10, false);
                oled_write_ln("", false);
                oled_write_ln("", false);

                oled_write_char(0X1B, false);
                oled_write("  ", false);
                oled_write_char(0X19, false);
                oled_write("  ", false);
                oled_write_char(0X18, false);
                oled_write("  ", false);
                oled_write_char(0X1A, false);
                oled_write_ln("", false);
                oled_write_ln("", false);
                oled_write_ln_P(PSTR("RM LM MM"), false);
                // oled_write_ln_P(PSTR("      .  0  -"), false);
            } else {
                oled_write_ln("MOUSE", false);
            }
            break;
        case _ACCENTS:
            oled_write_ln("ACCENTS", false);
            break;
        default:
            oled_write_raw_P(arch_logo, sizeof(arch_logo));
    }
}

// ┌───────────────────────────────────────────────────────────┐
// │ w r i t e   t o   o l e d                                 │
// └───────────────────────────────────────────────────────────┘

void write_in_use_modifier(void) {
    uint8_t mods = get_mods();
    switch (mods) {
        case MOD_BIT(KC_RGUI):
        case MOD_BIT(KC_LGUI):
            oled_write_P(PSTR("GUI"), false);
            break;
        case (MOD_BIT(KC_LGUI) | MOD_BIT(KC_RSFT)):
        case (MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT)):
            oled_write_P(PSTR("GUI+SHIFT"), false);
            break;
        default:
            oled_write_P(PSTR("NONE"), false);
            break;
    };
};

bool oled_task_user(void) {
    if (is_keyboard_master()) { // ────────────────────────── PRIMARY SIDE

// layer status ──────────────────────────────────────────────────┐
#    ifdef DYNAMIC_MACRO_ENABLE
        if (dmacro_num == 1) {
            oled_write_P(rec_ico, false);
        }
        if (dmacro_num == 2) {
            oled_write_P(stop_ico, false);
        }
        if (dmacro_num == 3) {
            oled_write_P(play_ico, false);
        }
#    endif // DYNAMIC_MACRO_ENABLE

        if (get_highest_layer(layer_state) == _BASE) {
            oled_clear();
            oled_write_P(PSTR("layer: "), false);
            write_layer_status();
            oled_write_ln("", false);
            oled_write_P(PSTR("CapsWord: "), false);
            write_capsword_status();
            oled_write_ln("", false);
            oled_write_P(PSTR("Mods: "), false);
            write_in_use_modifier();
            oled_write_ln("", false);
            //  print_brightness_value();
            oled_write_ln("", false);
            //   oled_write_ln(o_text, false);
            render_os_lock_status();
            // render_animation();
        } else {
            display_layer_logo(true);
        }

    } else { // ─────────────────────────────────────────── SECONDARY SIDE
        display_layer_logo(false);
    }
    return false;
};

#endif // OLED_ENABLE

#ifdef COMBO_ENABLE
const uint16_t PROGMEM e_aigue[]    = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM e_grave[]    = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM e_circon[]   = {KC_W, KC_E, KC_R, COMBO_END};
combo_t                key_combos[] = {
    COMBO(e_aigue, UM(AIGUE)), COMBO(e_grave, UM(GRAVE)), COMBO(e_circon, UM(CIRCON)), // keycodes with modifiers are possible too!
};

#endif /* ifdef COMBO */

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ E N C O D E R                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

#ifdef ENCODER_ENABLE

// ┌───────────────────────────────────────────────────────────┐
// │ e n c o d e r  L                                          │
// └───────────────────────────────────────────────────────────┘

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (IS_LAYER_ON(_NUM)) {
            if (clockwise) {
                tap_code(KC_MPRV);
            } else {
                tap_code(KC_MNXT);
            }
        } else {
            if (clockwise) {
                tap_code(KC_PGUP);
            } else {
                tap_code(KC_PGDN);
            }
        }

        // ┌───────────────────────────────────────────────────────────┐
        // │ e n c o d e r  R                                          │
        // └───────────────────────────────────────────────────────────┘

    } else if (index == 1) {
        if (IS_LAYER_ON(_MOUSE)) {
        } else if (IS_LAYER_ON(_NAV)) {
            register_code(KC_LGUI);
            register_code(KC_LCTL);
            if (clockwise) {
                tap_code(KC_H);
            } else {
                tap_code(KC_L);
            }
            unregister_code(KC_LGUI);
            unregister_code(KC_LCTL);
        } else {
            if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
        }
    }
    return true;
}

#endif // ENCODER_ENABLE

/*

                                                       ▐█    ▟▛ ▐█     ▄▆▀▀▀▀▀▀▆▄  ▐█▀▀▀▀▀█▌
                                                       ▐█   ▟▛  ▐█    ▟▛        ▜▙ ▐█     █▌
                                                       ▐█  ▟▛   ▐█   ▐█          █▋▐█     █▌
                                                       ▐█ ▟█▙   ▐█   ▐█          █▋▐█▀▀▜█▀▀▘
                                                       ▐█▟▛ ▜▙  ▐█    ▜▙        ▟▛ ▐█   ▜▙
                                                       ▐█▛   ▜▙ ▐█▄▄▄▄ ▀▜▆▄▄▄▄▆▛▀  ▐█    ▜▙

                                                                 ▄██████████████▄
                                                                 ████████████████
                                                            ▄██████▀  ▀████▀  ▀██████▄
                                                            ███████▄  ▄████▄  ▄███████
                                                            ███████████▀▀▀▀███████████
                                                            ▀█████████▀ ▄▄ ▀█████████▀
                                                                 ████▀ ▄██▄ ▀████
                                                                 ████▄▄████▄▄████

*/
