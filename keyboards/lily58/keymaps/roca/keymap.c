#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

#define MAC_VOD KC__VOLDOWN
#define MAC_VOU KC__VOLUP
#define RC_CEQL LCTL_T(KC_EQL)
#define RC_CMIN RCTL_T(KC_MINS)

#define RC_CSPC LCTL_T(KC_SPC)
#define RC_SENT RSFT_T(KC_ENT)

#define RC_SESC LSFT_T(KC_ESC)
#define RC_SBSP RSFT_T(KC_BSPC)

#define RC_LANG LCTL(KC_SPC)

#define RC_GLBR LGUI_T(KC_LBRC)
#define RC_GRBR RGUI_T(KC_RBRC)

#define RC_GEQL LGUI_T(KC_EQL)
#define RC_GMIN RGUI_T(KC_MINS)

#define RC_CLBR LCTL_T(KC_LBRC)
#define RC_CRBR RCTL_T(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
[_QWERTY] = LAYOUT( \
//,-----------------------------------------------.                 ,-----------------------------------------------.
    KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_BSPC,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
    KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_MINS,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
  KC_LCTRL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                     KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,\
//|-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
   RC_SESC,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,RC_CLBR,  RC_CRBR,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,RC_SBSP,\
//|-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
                           KC_LALT,RC_CEQL,  LOWER,RC_CSPC,  RC_SENT,  RAISE,RC_CMIN,KC_RALT \
//                        |-------+-------+-------+-------| |-------+-------+-------+-------|
),*/
/* MAXOS */
[_QWERTY] = LAYOUT( \
//,-----------------------------------------------.                 ,-----------------------------------------------.
    KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_BSPC,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
    KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_MINS,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
  KC_LCTRL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                     KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,\
//|-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
   RC_SESC,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,RC_CLBR,  RC_CRBR,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,RC_SBSP,\
//|-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
                           KC_LALT,RC_GEQL,  LOWER,RC_CSPC,  RC_SENT,  RAISE,RC_GMIN,KC_RALT \
//                        |-------+-------+-------+-------| |-------+-------+-------+-------|
),
/* LOWER */
[_LOWER] = LAYOUT( \
//,-----------------------------------------------.                 ,-----------------------------------------------.
   _______,_______,_______,_______,_______,_______,                  _______,_______,_______,_______,_______,_______,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
   _______,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,                  KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_UNDS,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
   _______, KC_TAB,KC_BSLS,KC_PIPE,KC_TILD, KC_GRV,                   KC_EQL,KC_QUOT,KC_DQUO,KC_LCBR,KC_RCBR,KC_PIPE,\
//|-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
   _______,RC_LANG,_______,_______,_______,_______,_______,  _______,KC_PLUS,  KC_LT,  KC_GT,KC_LBRC,KC_RBRC,_______,\
//|-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
                           _______,_______,_______,_______,  _______,_______,_______,_______ \
//                        |-------+-------+-------+-------| |-------+-------+-------+-------|
),
/* RAISE */
[_RAISE] = LAYOUT( \
//,-----------------------------------------------.                 ,-----------------------------------------------.
   _______,_______,_______,_______,_______,_______,                  _______,_______,_______,_______,_______, KC_DEL,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
   _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,_______,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
   _______,_______,_______,_______,_______,_______,                  KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,MAC_VOU,_______,\
//|-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
   _______,_______,_______,_______,_______,_______,_______,  _______,KC_HOME,KC_PGDN,KC_PGUP, KC_END,MAC_VOD,_______,\
//|-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
                           _______,_______,_______,_______,  _______,_______,_______,_______ \
//                        |-------+-------+-------+-------| |-------+-------+-------+-------|
),
/* ADJUST */
[_ADJUST] = LAYOUT( \
//,-----------------------------------------------.                 ,-----------------------------------------------.
     KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,                    KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
   XXXXXXX,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                    KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,XXXXXXX,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
   XXXXXXX, KC_F11, KC_F12,KC_PSCR,  RESET, KC_INS,                  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,\
//|-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, KC_DEL,\
//|-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
                           _______,_______,_______,_______,  _______,_______,_______,_______ \
  //                      |-------+-------+-------+-------| |-------+-------+-------+-------|
)

};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
  }
  return true;
}
