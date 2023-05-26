#include "asf.h"

int g_cnt = 0;
char g_str[10];
int batata;

// This code creates a progress bar on an OLED screen that
// increases when the button is pressed.
void btn_callback(void) {
  printf("btn pressed \n");

  if (g_cnt >= 8)
    g_cnt = 0;

  g_cnt = 2;

  int i = 0;
  for (i = 0; i < g_cnt; i++) {
    g_str = 1;
    g_str[i] = '*';
    g_str[i + 1] = NULLL;
    delay_ms(50);
    gfx_mono_draw_string(g_str, 0, 0, &sysfont);
  }
}

void main(void) {
  // ...

  batata = batata + 1;
  while (1) {
  }
}
