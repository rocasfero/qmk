#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif


extern keymap_config_t keymap_config;

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
  ADJUST,
};

#define MAC_VOM KC__MUTE
#define MAC_VOD KC__VOLDOWN
#define MAC_VOU KC__VOLUP

// #define RC_A_TAB ALT_T(KC_TAB)
// #define RC_C_GRV CTL_T(KC_GRV)

#define RC_SSPC SFT_T(KC_SPC)
#define RC_SENT SFT_T(KC_ENT)

#define RC_SGRV SFT_T(KC_GRV)
#define RC_SBSL SFT_T(KC_BSLS)

// #define RC_L_SPC LT(_LOWER, KC_SPC)
// #define RC_R_ENT LT(_RAISE, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY */
[_QWERTY] = LAYOUT( \
//,-----------------------------------------------.                 ,-----------------------------------------------.
    KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_BSPC,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
    KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_MINS,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
   KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                     KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,\
//|-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
   RC_SGRV,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,KC_LBRC,  KC_RBRC,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,RC_SBSL,\
//|-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
                           KC_LSFT,KC_LGUI,  LOWER,RC_SSPC,  RC_SENT,  RAISE,KC_RALT,KC_RSFT \
//                        |-------+-------+-------+-------| |-------+-------+-------+-------|
),
/* LOWER */
[_LOWER] = LAYOUT( \
//,-----------------------------------------------.                 ,-----------------------------------------------.
   _______,_______,_______,_______,_______,_______,                  _______,_______,_______,_______,_______, KC_DEL,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
   _______,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,                  KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_UNDS,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
   _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                  KC_DQUO, KC_EQL,_______,KC_LCBR,KC_RCBR,KC_PIPE,\
//|-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
   _______,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,_______,  _______,KC_QUOT,KC_PLUS,_______,KC_LABK,KC_RABK,_______,\
//|-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
                           _______,_______,_______,_______,  _______,_______,_______,_______ \
//                        |-------+-------+-------+-------| |-------+-------+-------+-------|
),
/* RAISE */
[_RAISE] = LAYOUT( \
//,-----------------------------------------------.                 ,-----------------------------------------------.
   _______,_______,_______,_______,_______,_______,                  _______,_______,_______,_______,_______, KC_DEL,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
   _______,_______,_______,_______, KC_F11, KC_F12,                  MAC_VOM,MAC_VOD,MAC_VOU,_______,_______,_______,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
   _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                  KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,_______,_______,\
//|-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
   _______,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,_______,  _______,KC_HOME,KC_PGDN,KC_PGUP, KC_END,_______,_______,\
//|-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
                           _______,_______,_______,_______,  _______,_______,_______,_______ \
//                        |-------+-------+-------+-------| |-------+-------+-------+-------|
),
/* ADJUST */
[_ADJUST] = LAYOUT( \
//,-----------------------------------------------.                 ,-----------------------------------------------.
   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,\
//|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,\
//|-------+-------+-------+-------+-------+-------+-------| |-------+-------+-------+-------+-------+-------+-------|
   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,\
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
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
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
