#ifndef KLOR_KEYCODE_H
#define KLOR_KEYCODE_H

#include "keymap_miryoku.h"
#include QMK_KEYBOARD_H

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                             │
// └───────────────────────────────────────────────────────────┘

typedef enum {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    LOWER,
    RAISE,
    ADJUST,
    OS_SWAP,
    MAKE_H,
} custom_keycodes;

enum unicode_names {
    AIGUE,
    GRAVE,
    CEDIL,
    CIRCON,
};

const uint32_t PROGMEM unicode_map[] = {
    [AIGUE]  = 0x00E9,
    [GRAVE]  = 0x00E8,
    [CEDIL]  = 0x00E7,
    [CIRCON] = 0x00EA,
};
#endif
