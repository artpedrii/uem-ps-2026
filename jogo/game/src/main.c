#include "wasm4.h"
#include <stdint.h>

// ---------------- FUNÇÕES ÚTEIS ----------------

// desenha pixel (x,y) com cor c
void pset(int x, int y, int c) {
  if (x < 0 || x > 159 || y < 0 || y > 159) { return; }
  if (c == 0) { return; /* transparent */ }
  int idx = (y*160 + x) >> 2;
  int shift = (x & 0b11) << 1;
  int mask = 0b11 << shift;
  FRAMEBUFFER[idx] = (uint8_t) ((c-1) << shift) | (FRAMEBUFFER[idx] & ~mask);
}

// retorna cor do pixel (x,y)
int pget(int x, int y) {
  if (x < 0 || x > 159 || y < 0 || y > 159) { return 0; }
  int idx = (y*160 + x) >> 2;
  int shift = (x & 0b11) << 1;
  int mask = 0b11 << shift;
  return ((FRAMEBUFFER[idx] & mask) >> shift) + 1;
}

uint8_t x, y; // posição do jogador

void start () {
   x = y = 50; // posição inicial
}

void update () {
  uint8_t dx = 0, dy = 0; // deslocamento, permite mais de uma tecla pressionada
  uint8_t gamepad = *GAMEPAD1;
  if (gamepad & BUTTON_LEFT)  { dx = dx - 2; }
  if (gamepad & BUTTON_RIGHT) { dx = dx + 2; }
  if (gamepad & BUTTON_UP)    { dy = dy - 2; }
  if (gamepad & BUTTON_DOWN)  { dy = dy + 2; }
  x += dx;
  y += dy;

  *DRAW_COLORS = 2; rect(20, 20, 10, 60); // desenha parede

  if (pget(x, y) == 2) { // se colidiu com parede então desfaz movimento
    x -= dx;
    y -= dy;
  }

  *DRAW_COLORS = 3; rect(x, y, 2, 2); // desenha jogador
}

