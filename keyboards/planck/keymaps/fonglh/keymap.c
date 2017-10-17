#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _DVORAK,
  _LOWER,
  _RAISE,
  _NAV,
  _NAVMAC,
  _NUM,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  LOWER,
  RAISE,
  NAV,
  NAVMAC,
  NUM
};

enum {
  TD_QUOTE_ENTER = 0,
  TD_LOWER_NAV,
  TD_COPY_CUT,
  TD_PASTE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   -  |
 * |-------+------+------+------+------+-------------+------+------+------+------+------|
 * |Esc/Ctl|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |"/Ent |
 * |-------+------+------+------+------+------|------+------+------+------+------+------|
 * | (/Lsft|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |)/Rsft|
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |Esc/Ctl| Num  | Alt  | GUI  |Low/Nav|Space| Bksp | Raise|  Up  |CpyCut| Paste|Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS},
  {CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, TD(TD_QUOTE_ENTER)},
  {KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC},
  {CTL_T(KC_ESC), TT(_NUM), KC_LALT, KC_LGUI, TD(TD_LOWER_NAV),   KC_SPC,  KC_BSPC,  RAISE,   KC_UP, TD(TD_COPY_CUT), TD(TD_PASTE),   KC_ENT}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab   |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |-------+------+------+------+------+-------------+------+------+------+------+------|
 * |Esc/Ctl|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |-------+------+------+------+------+------|------+------+------+------+------+------|
 * | (/Lsft|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |)/Rsft|
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |Esc/Ctl| Num  | Alt  | GUI  |Low/Nav|Space| Bksp |Raise |  Up  |CpyCut| Paste|Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {CTL_T(KC_ESC),  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
  {KC_LSPO, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_RSPC},
  {CTL_T(KC_ESC), TT(_NUM), KC_LALT, KC_LGUI, TD(TD_LOWER_NAV),   KC_SPC,  KC_BSPC,  RAISE,   KC_UP, TD(TD_COPY_CUT), TD(TD_PASTE),   KC_ENT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   [  |   ]  |  =   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Del  |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LBRC, KC_RBRC, KC_EQL},
  {_______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______},
  {_______, _______, _______, _______, _______, _______, KC_DEL, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  +   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PLUS},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Nav -- For Ctrl-<number> tab navigation, consistent with tab switching for macs.
 * ,-----------------------------------------------------------------------------------.
 * |      |Ctl-1 |Ctl-2 |Ctl-3 |Ctl-4 |Ctl-5 | Ctl-6 |Ctl-7 |Ctl-8 | Ctl-9|      |      |
 * |------+------+------+------+------+--------------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |      |      |      |      |      |
 * |------+------+------+------+------+------|-------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |      |      |      |      |      |
 * |------+------+------+------+------+------+-------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *
 * 
 */
[_NAV] = {
  {_______, LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5), LCTL(KC_6), LCTL(KC_7), LCTL(KC_8), LCTL(KC_9), _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* NavMac -- Nav layer for Macs to navigate between tabs, enter by double tapping LOWER.
 * ,-----------------------------------------------------------------------------------.
 * |CmdGrv|Cmd-1 |Cmd-2 |Cmd-3 |Cmd-4 |Cmd-5 | Cmd-6 |Cmd-7 |Cmd-8 | Cmd-9|      |      |
 * |------+------+------+------+------+--------------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |      |      |      |      |      |
 * |------+------+------+------+------+------|-------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |      |      |      |      |      |
 * |------+------+------+------+------+------+-------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *
 */
[_NAVMAC] = {
  {LGUI(KC_GRV), LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Num
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |       |  7   |  8   |  9   | Home | PgUp |
 * |------+------+------+------+------+--------------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |  4   |  5   |  6   | End  | PgDn |
 * |------+------+------+------+------+------|-------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |  1   |  2   |  3   | Up   |      |
 * |------+------+------+------+------+------+-------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |  0   |  .   | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 *
 */
[_NUM] = {
  {_______, _______, _______, _______, _______, _______, _______,    KC_7,    KC_8,    KC_9, KC_HOME, KC_PGUP},
  {_______, _______, _______, _______, _______, _______, _______,    KC_4,    KC_5,    KC_6,  KC_END, KC_PGDN},
  {_______, _______, _______, _______, _______, _______, _______,    KC_1,    KC_2,    KC_3,   KC_UP, _______},
  {_______, _______, _______, _______, _______, _______, _______,    KC_0,  KC_DOT, KC_LEFT, KC_DOWN, KC_RIGHT}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, DVORAK,  _______,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      // https://www.reddit.com/r/olkb/comments/4x3dei/hack_too_ugly_to_live/
      // link here is for reference, currently not used.
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void dance_nav_on(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    layer_on(_LOWER);
  } else {
    // Windows GUI/ALT layout, assume Windows nav shortcuts.
    if(keymap_config.swap_lalt_lgui == 1 && keymap_config.swap_ralt_rgui == 1) {
      layer_on(_NAV);
    } else {
      layer_on(_NAVMAC);
    }
  }
}

void dance_nav_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    layer_off(_LOWER);
  } else {
    layer_off(_NAV);
    layer_off(_NAVMAC);
  }
}

// Copy on single tap, Cut otherwise.
// Sends Cmd or Ctrl depending on whether Mac or Win GUI/Alt option is enabled.
void dance_copy_cut(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    // Copy
    // Windows GUI/ALT layout, assume Windows copy shortcut.
    if(keymap_config.swap_lalt_lgui == 1 && keymap_config.swap_ralt_rgui == 1) {
      register_code(KC_LCTL);
      register_code(KC_C);
      unregister_code(KC_C);
      unregister_code(KC_LCTL);
    }
    else {
      register_code(KC_LGUI);
      register_code(KC_C);
      unregister_code(KC_C);
      unregister_code(KC_LGUI);
    }
  } else {
    // Cut
    // Windows GUI/ALT layout, assume Windows cut shortcut.
    if(keymap_config.swap_lalt_lgui == 1 && keymap_config.swap_ralt_rgui == 1) {
      register_code(KC_LCTL);
      register_code(KC_X);
      unregister_code(KC_X);
      unregister_code(KC_LCTL);
    }
    else {
      register_code(KC_LGUI);
      register_code(KC_X);
      unregister_code(KC_X);
      unregister_code(KC_LGUI);
    }
  }
}

// Normal paste on single tap, terminal paste shortcut if in Windows mode (For Linux VMs)
void dance_paste(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    // Normal paste
    // Windows GUI/ALT layout, assume Windows paste shortcut.
    if(keymap_config.swap_lalt_lgui == 1 && keymap_config.swap_ralt_rgui == 1) {
      register_code(KC_LCTL);
      register_code(KC_V);
      unregister_code(KC_V);
      unregister_code(KC_LCTL);
    }
    else {
      register_code(KC_LGUI);
      register_code(KC_V);
      unregister_code(KC_V);
      unregister_code(KC_LGUI);
    }
  }
  else {
    // Windows GUI/ALT layout, double tapped, use terminal emulator paste shortcut
    // Ctrl+Shift+V
    if(keymap_config.swap_lalt_lgui == 1 && keymap_config.swap_ralt_rgui == 1) {
      register_code(KC_LCTL);
      register_code(KC_LSFT);
      register_code(KC_V);
      unregister_code(KC_V);
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);
    }
  }
}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for quote, twice for Enter
  [TD_QUOTE_ENTER] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_ENT),
  [TD_LOWER_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_nav_on, dance_nav_reset),
  [TD_COPY_CUT] = ACTION_TAP_DANCE_FN(dance_copy_cut),
  [TD_PASTE] = ACTION_TAP_DANCE_FN(dance_paste)
};

// Supposed to use this with ACTION_FUNCTION(n) in a keymap but it didn't work.
// If this works, can get rid of the NAV case in `process_record_user`.
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  bool use_navmac = true;

  // Compare to MAGIC_SWAP_ALT_GUI and MAGIC_UNSWAP_ALT_GUI configs,
  // set in:quantum/quantum.c
  if(keymap_config.swap_lalt_lgui == 1 && keymap_config.swap_ralt_rgui == 1) {
    use_navmac = false;
  }

  switch(id) {
    case 0:
      if (record->event.pressed) {
        if (use_navmac) {
          layer_on(_NAVMAC);
        }
        else {
          layer_on(_NAV);
        }
      } else {
        layer_off(_NAV);
        layer_off(_NAVMAC);
      }
      break;
  }
}
