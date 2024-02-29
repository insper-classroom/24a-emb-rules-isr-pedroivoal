#include "asf.h"

volatile int pressed = 0

// This code creates a progress bar on an OLED screen that
// increases when the button is pressed.
void when_pressed(int *e_g_cnt, int *e_g_str) {
  pressed = 0;
  printf("btn pressed \n");

  if (*e_g_cnt >= 8)
    *e_g_cnt = 0;

  *e_g_cnt = 2;

  int i = 0;
  for (i = 0; i < *e_g_cnt; i++) {
    *e_g_str = 1;
    *e_g_str[i] = '*';
    *e_g_str[i + 1] = NULLL;
    delay_ms(50);
    gfx_mono_draw_string(*e_g_str, 0, 0, &sysfont);
  }
}

void btn_callback(void) {
  pressed = 1;
}

void main(void) {
  int g_cnt = 0;
  char g_str[10];
  while (1) {
    if (pressed) {
      when_pressed(&g_cnt, &g_str)
    }
  }
}
