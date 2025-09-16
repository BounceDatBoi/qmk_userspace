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

// COLEMAK
// LEFT HAND HOME ROW MODS ├───────────────────────────────────┐

#define GUI_A MT(MOD_LGUI, KC_A)
#define ALT_R MT(MOD_LALT, KC_R)
#define CTL_S MT(MOD_LCTL, KC_S)
#define SHT_T MT(MOD_LSFT, KC_T)

// RIGHT HAND HOME ROW MODS ├───────────────────────────────────┐

#define SHT_N MT(MOD_RSFT, KC_N)
#define CTL_E MT(MOD_LCTL, KC_E)
#define ALT_I MT(MOD_LALT, KC_I)
#define GUI_O MT(MOD_LGUI, KC_O)

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
#define ACCENT LT(_ACCENTS, KC_ENTER)

// ┌───────────────────────────────────────────────────────────┐
// │ l a y o u t  a n d  k e y m a p                           │
// └───────────────────────────────────────────────────────────┘

// Import the layout that you use from the layouts folder
#include "layout.cfg"

// Import the keymap that you use from the layouts folder
#include "keymap_miryoku.h"

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

    // os mode status ────────────────────────────────────────┐

    // oled_write_ln_P(sep_v, false);

    // if (keymap_config.swap_lctl_lgui) {
    //     oled_write_P(os_m_1, false); // ──── MAC
    // } else {
    //     oled_write_P(os_w_1, false); // ──── WIN
    // }

    // oled_write_P(sep_h1, false);
    // oled_write_P(face_1, false);

    // if (keymap_config.swap_lctl_lgui) {
    //     oled_write_P(os_m_2, false); // ──── MAC
    // } else {
    //     oled_write_P(os_w_2, false); // ──── WIN
    // }

    // oled_write_P(sep_h1, false);
    // oled_write_P(face_2, false);
    // oled_write_ln_P(sep_v, false);

    // lock key layer status ─────────────────────────────────┐

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
        case _QWERTY:
            oled_write_P(PSTR("BASE QWERTY"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("BASE COLEMAK"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWER"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJUST"), false);
            break;
        case _ACCENTS:
            oled_write_P(PSTR("ACCENTS"), false);
            break;
        default:
            oled_write_P(PSTR("UNDEFINED"), false);
    }
};
int layerstate = 0;

layer_state_t layer_state_set_kb(layer_state_t state) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            strcpy(layer_state_str, "BASE QWERTY");
            break;
        case _COLEMAK:
            strcpy(layer_state_str, "BASE COLEMAK");
            break;
        case _LOWER:
            strcpy(layer_state_str, "LOWER");
            break;
        case _RAISE:
            strcpy(layer_state_str, "RAISE");
            break;
        case _ADJUST:
            strcpy(layer_state_str, "ADJUST");
            break;
        case _ACCENTS:
            strcpy(layer_state_str, "ACCENTS");
            break;
        default:
            strcpy(layer_state_str, "XXXXXX");
    }
    if (dmacro_num < 1) {
        strcpy(o_text, layer_state_str);
    }
    // return state;
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SHT_T:
            return TAPPING_TERM - 150;
        case SHT_N:
            return TAPPING_TERM - 150;
        default:
            return TAPPING_TERM;
    }
}

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
        case OS_SWAP:
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                    keymap_config.swap_lctl_lgui = true; // ─── MAC
#    ifdef AUDIO_ENABLE
                    PLAY_SONG(mac_song);
#    endif // AUDIO_ENABLE
                } else {
                    keymap_config.swap_lctl_lgui = false; // ─── WIN
#    ifdef AUDIO_ENABLE
                    PLAY_SONG(winxp_song);
#    endif // AUDIO_ENABLE
                }
#    ifdef HAPTIC_ENABLE
                DRV_pulse(pulsing_strong);
#    endif // HAPTIC_ENABLE
                eeconfig_update_keymap(keymap_config.raw);
                clear_keyboard(); // ──── clear to prevent stuck keys
                return false;
            }

            // ┌───────────────────────────────────────────────────────────┐
            // │ l a y e r                                                 │
            // └───────────────────────────────────────────────────────────┘

        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
#    ifdef HAPTIC_ENABLE
                DRV_pulse(transition_hum);
#    endif // HAPTIC_ENABLE
            }
            return false;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
#    ifdef HAPTIC_ENABLE
                DRV_pulse(transition_hum);
#    endif // HAPTIC_ENABLE
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;

            // ┌───────────────────────────────────────────────────────────┐
            // │ q m k                                                     │
            // └───────────────────────────────────────────────────────────┘

        case MAKE_H:
            if (record->event.pressed) {
                SEND_STRING("qmk compile -kb klor/2040 -km bounce");
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
        case KC_A:
            if (record->event.pressed) {
                strcpy(modifiers, "LGUI");
            } else {
                strcpy(modifiers, "NONE");
            }
            return false;
    }
    return true;
}

#    include "icons.h"
void display_layer_logo(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_raw_P(arch_logo, sizeof(arch_logo));
            break;
        case _COLEMAK:
            oled_write_raw_P(arch_logo, sizeof(arch_logo));
            break;
        case _LOWER:
            oled_write_raw_P(numbers, sizeof(numbers));
            break;
        case _RAISE:
            oled_write_raw_P(fn_key, sizeof(fn_key));
            break;
        case _ADJUST:
            oled_write_raw_P(cog, sizeof(cog));
            break;
        case _ACCENTS:
            break;
        default:
            oled_write_raw_P(arch_logo, sizeof(arch_logo));
    }
}

// ┌───────────────────────────────────────────────────────────┐
// │ w r i t e   t o   o l e d                                 │
// └───────────────────────────────────────────────────────────┘
#    include "../../lib/klorimation.h"

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

void print_brightness_value(void) {
    uint8_t brightness = oled_get_brightness();
    uint8_t max_chars  = oled_max_chars();
    uint8_t chars_left = max_chars - 12;

    chars_left = chars_left * (brightness / 255);

    oled_write_P(PSTR("Brightness: "), false);
    while (chars_left > 0) {
        oled_write_char('▮', false);
        chars_left--;
    }
}

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

    } else { // ─────────────────────────────────────────── SECONDARY SIDE

        display_layer_logo();
    }
    return false;
};

#endif // OLED_ENABLE

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
        if (IS_LAYER_ON(_RAISE)) {
            register_code(KC_LGUI);
            register_code(KC_LCTL);
            if (clockwise) {
                tap_code(KC_H);
            } else {
                tap_code(KC_L);
            }
            unregister_code(KC_LGUI);
            unregister_code(KC_LCTL);
        } else if (IS_LAYER_ON(_ADJUST)) {
            uint8_t brightness = oled_get_brightness();
            if (clockwise) {
                oled_set_brightness(brightness - 10);
            } else {
                oled_set_brightness(brightness + 10);
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
        if (IS_LAYER_ON(_LOWER)) {
            if (clockwise) {
                tap_code(KC_MPRV);
            } else {
                tap_code(KC_MNXT);
            }
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
