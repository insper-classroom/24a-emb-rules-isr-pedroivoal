#include "asf.h"

int g_cnt = 0;
int f_btn = 0; // deveria ser volatile

// ISR
void btn_callback(void) {
  f_btn = 1; // variável alterada de uma interrupcão
}

void main(void) {

  volatile int cnt = 0; // não precisa ser volatile

  while (1) {
    if (f_btn) {
      cnt++;
      f_btn = 0;
    }
  }
}
