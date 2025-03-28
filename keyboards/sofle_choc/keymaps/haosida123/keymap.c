/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Reduce file size
#ifndef MAGIC_ENABLE
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}
uint8_t mod_config(uint8_t mod) {
    return mod;
}
#endif

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
    MO(3),   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,   KC_MPLY,KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      MO(2), KC_LALT, KC_LCTL, TL_LOWR, KC_ENT,    KC_SPC, TL_UPPR,  KC_RCTL,  KC_RALT, KC_RGUI
),
[_LOWER] = LAYOUT(
    KC_GRV, KC_0, KC_9, KC_8, KC_7,  KC_6,                         _______, _______,   _______, _______,   _______,  _______,
    KC_BSPC, KC_P, KC_O, KC_I, KC_U, KC_Y,                         S(KC_6), S(KC_7),  S(KC_8),   S(KC_9),  S(KC_0), KC_GRV,
    KC_QUOT, KC_SCLN, KC_L, KC_K, KC_J, KC_H,                         KC_BSPC, KC_MINS,   KC_EQL, KC_LBRC,   KC_RBRC,   KC_BSLS,
    KC_RSFT, KC_SLSH, KC_DOT, KC_COMM, KC_M, KC_N, _______,       _______, S(KC_1), S(KC_2),  S(KC_3), S(KC_4),   S(KC_5),  S(KC_GRV),
                      KC_RGUI, KC_RALT, KC_RCTL,  _______, KC_SPC,       _______, _______,  _______,   _______, _______
),
[_RAISE] = LAYOUT(
    _______, G(KC_1), G(KC_2),   G(KC_3),  G(KC_4),   _______,                            KC_NO,   KC_NUM_LOCK,   KC_NO,   KC_NO,   KC_PSLS,  TO(0),
    KC_WWW_BACK, KC_INS, KC_APPLICATION, KC_HOME, KC_PAUS, KC_PGUP,                       S(KC_BSLS),    KC_P7,    KC_P8,    KC_P9,    KC_PAST,    KC_BSPC,
    KC_WWW_FORWARD, KC_DEL, KC_PSCR, KC_END, KC_UP, KC_PGDN,                         KC_BSPC, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_NO,
    _______, C(KC_SLSH), KC_F5, KC_LEFT, KC_DOWN, KC_RGHT, _______,       _______, KC_NO, KC_P1, KC_P2, KC_P3, KC_PPLS, _______,
                     _______, _______, _______, _______,  KC_ESC,       _______, _______, KC_P0, KC_PDOT, KC_PENT
),
[_ADJUST] = LAYOUT(
    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, A(KC_F4),                       KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, TO(0),
    KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,                       XXXXXXX, XXXXXXX, KC_MS_UP, XXXXXXX, XXXXXXX, KC_TRNS,
    KC_CAPS, KC_F11, KC_F12, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2,                       XXXXXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_BTN1, KC_MS_BTN2,
    KC_TRNS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, _______,     _______, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, KC_MS_BTN3, KC_TRNS,
                      KC_MS_BTN3, _______, _______, _______, _______,     _______, _______, _______, _______, _______
)
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case KC_PRVWD:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     register_mods(mod_config(MOD_LALT));
//                     register_code(KC_LEFT);
//                 } else {
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_LEFT);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LALT));
//                     unregister_code(KC_LEFT);
//                 } else {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_LEFT);
//                 }
//             }
//             return false;
//         case KC_NXTWD:
//              if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     register_mods(mod_config(MOD_LALT));
//                     register_code(KC_RIGHT);
//                 } else {
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_RIGHT);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LALT));
//                     unregister_code(KC_RIGHT);
//                 } else {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_RIGHT);
//                 }
//             }
//             return false;
//         case KC_LSTRT:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                      // CMD-arrow on Mac, but we have CTL and GUI swapped
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_LEFT);
//                 } else {
//                     register_code(KC_HOME);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_LEFT);
//                 } else {
//                     unregister_code(KC_HOME);
//                 }
//             }
//             return false;
//         case KC_LEND:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     // CMD-arrow on Mac, but we have CTL and GUI swapped
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_RIGHT);
//                 } else {
//                     register_code(KC_END);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_RIGHT);
//                 } else {
//                     unregister_code(KC_END);
//                 }
//             }
//             return false;
//         case KC_DLINE:
//             if (record->event.pressed) {
//                 register_mods(mod_config(MOD_LCTL));
//                 register_code(KC_BSPC);
//             } else {
//                 unregister_mods(mod_config(MOD_LCTL));
//                 unregister_code(KC_BSPC);
//             }
//             return false;
//         case KC_COPY:
//             if (record->event.pressed) {
//                 // CMD-c on Mac, but we have CTL and GUI swapped
//                 register_mods(mod_config(MOD_LCTL));
//                 register_code(KC_C);
//             } else {
//                 unregister_mods(mod_config(MOD_LCTL));
//                 unregister_code(KC_C);
//             }
//             return false;
//         case KC_PASTE:
//             if (record->event.pressed) {
//                 // CMD-v on Mac, but we have CTL and GUI swapped
//                 register_mods(mod_config(MOD_LCTL));
//                 register_code(KC_V);
//             } else {
//                 unregister_mods(mod_config(MOD_LCTL));
//                 unregister_code(KC_V);
//             }
//             return false;
//         case KC_CUT:
//             if (record->event.pressed) {
//                 // CMD-x on Mac, but we have CTL and GUI swapped
//                 register_mods(mod_config(MOD_LCTL));
//                 register_code(KC_X);
//             } else {
//                 unregister_mods(mod_config(MOD_LCTL));
//                 unregister_code(KC_X);
//             }
//             return false;
//             return false;
//         case KC_UNDO:
//             if (record->event.pressed) {
//                 // CMD-z on Mac, but we have CTL and GUI swapped
//                 register_mods(mod_config(MOD_LCTL));
//                 register_code(KC_Z);
//             } else {
//                 unregister_mods(mod_config(MOD_LCTL));
//                 unregister_code(KC_Z);
//             }
//             return false;
//         default:
//             return true;
//     }
// }

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN),   ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_LOWER] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),   ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),   ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

void write_int_ln(const char* prefix, uint8_t value) {
    oled_write_P(prefix, false);
    oled_write(get_u8_str(value, ' '), false);
}

static void print_status_narrow(void) {
    oled_write_ln_P(PSTR("SofleChoc _____"), false);

    // if (get_highest_layer(layer_state) == _ADJUST) {
    //     uint8_t mode  = rgb_matrix_get_mode();
    //     HSV     hsv   = rgb_matrix_get_hsv();
    //     uint8_t speed = rgb_matrix_get_speed();

    //     if (keymap_config.swap_lctl_lgui) {
    //         oled_write_ln_P(PSTR("MAC\n"), false);
    //     } else {
    //         oled_write_ln_P(PSTR("WIN\n"), false);
    //     }

    //     oled_write_ln("RGB", false);
    //     write_int_ln(PSTR("Mo"), mode);
    //     write_int_ln(PSTR("H "), hsv.h);
    //     write_int_ln(PSTR("S "), hsv.s);
    //     write_int_ln(PSTR("V "), hsv.v);
    //     write_int_ln(PSTR("Sp"), speed);
    //     oled_write_P(PSTR("\n\n\n"), false);
    // } else {
        oled_write_P(PSTR("\n\n\n\n\n\n\n\n\n"), false);
        led_t led_usb_state = host_keyboard_led_state();
        if (led_usb_state.caps_lock) {
            oled_write_ln_P(PSTR(" CAP "), true);
        } else {
            oled_write_ln_P(PSTR("     "), false);
        }
    // }

    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Alpha"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Nav  "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Sym  "), false);
            break;
        // case _ADJUST:
        //     oled_write_P(PSTR("Adj  "), false);
        //     break;
        default:
            oled_write_P(PSTR("???  "), false);
    }
}

// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     if (is_keyboard_master()) {
//         return OLED_ROTATION_270;
//     }
//     return rotation;
// }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }

    return false;
}

#endif
