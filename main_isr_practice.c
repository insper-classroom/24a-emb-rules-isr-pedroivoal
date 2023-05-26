#include "asf.h"

#define LED_PIO PIOC
#define LED_PIO_ID ID_PIOC
#define LED_IDX 8
#define LED_IDX_MASK (1 << LED_IDX)

#define BUT_PIO PIOA
#define BUT_PIO_ID ID_PIOA
#define BUT_IDX 11
#define BUT_IDX_MASK (1 << BUT_IDX)

void io_init(void);
void pisca_led(int n, int t);
void btn_callback(void);

// ERRO: cppcheck unitvar
// ERRO: addon IsrVarVolatile
int btn_flag;

// ERRO: addon IsrFuncName
void btn_callback(void) {

  // ERRO: addon IsrPrintf
  printf("btn pressed \n");

  // ERRO: addon IsrNoLoop
  while (!pio_get(BUT_PIO, BUT_IDX_MASK)) {
    // ERRO: addon IsrNoDelay
    delay_ms(1);
  }

  // ERRO: addon IsrPrintf
  printf("btn released \n");

  // ERRO: addon IsrNoDelay
  delay_ms(1);

  btn_flag = 1;
}

void io_init(void) {
  pmc_enable_periph_clk(LED_PIO_ID);
  pio_configure(LED_PIO, PIO_OUTPUT_0, LED_IDX_MASK, PIO_DEFAULT);
  pmc_enable_periph_clk(BUT_PIO_ID);
  pio_configure(BUT_PIO, PIO_INPUT, BUT_IDX_MASK, PIO_PULLUP);
  pio_handler_set(BUT_PIO, BUT_PIO_ID, BUT_IDX_MASK, PIO_IT_FALL_EDGE,
                  btn_callback);
  pio_enable_interrupt(BUT_PIO, BUT_IDX_MASK);
  pio_get_interrupt_status(BUT_PIO);
  NVIC_EnableIRQ(BUT_PIO_ID);
  NVIC_SetPriority(BUT_PIO_ID, 4);
}

void main(void) {
  sysclk_init();
  WDT->WDT_MR = WDT_MR_WDDIS;
  io_init();
  volatile int capture_flag = 0;
  int a;

  while (1) {
    if (btn_flag) {
      capture_flag = 1;
      btn_flag = 0;
    }

    if (capture_flag) {
    }
  }
}
