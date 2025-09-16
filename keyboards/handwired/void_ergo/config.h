// Copyright 2022 Victor Lucachi (@victorlucachi)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
#define SPLIT_USB_DETECT
#define MASTER_LEFT
#define TAPPING_TERM 170
#define TAPPING_FORCE_HOLD

#define COMBO_COUNT 1

#define ENABLE_COMPILE_KEYCODE
#define UNICODE_KEY_LNX LCTL(LSFT(KC_U))
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

// #define SERIAL_USART_FULL_DUPLEX // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP0 // USART TX pin
// #define SERIAL_USART_RX_PIN GP1  // USART RX pin
