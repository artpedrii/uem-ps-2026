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

int bola_x; //eixo horizontal bola
int bola_y; //eixo vertical bola

int raquete1_y; //eixo vertical raquete 1
int raquete2_y; //eixo vertical raquete 2

int bola_dx; //velocidade horizontal da bola
int bola_dy; //velocidade vertical da bola

void start () {
   bola_x = bola_y = 80; // posição inicial da bola

   bola_dx = 2;//velocidade bola
   bola_dy= 2;

   raquete1_y = 80;
   raquete2_y = 80; 
}

void update () {
  bola_x = bola_x + bola_dx;
  bola_y = bola_y + bola_dy;
  *DRAW_COLORS = 3; 
  rect(bola_x, bola_y, 2, 2);
  if (bola_x > 160 || bola_x < 0) {
      bola_x = bola_y = 80; 
  }
  if (bola_y > 160 || bola_y < 0) {
      bola_dy = -1 * bola_dy; 
  }
  rect(0, raquete1_y, 4, 20);
  rect(156, raquete2_y, 4, 20);

  uint8_t gamepad = *GAMEPAD2;
  if (gamepad & BUTTON_UP){
    raquete1_y = raquete1_y - 3;
    if (raquete1_y < 0){
      raquete1_y = 0;
    }
  }
  if (gamepad & BUTTON_DOWN){
    raquete1_y = raquete1_y + 3;
    if (raquete1_y > 140){
      raquete1_y = 140;
    }
  }

  uint8_t gamepad2 = *GAMEPAD1;
  if (gamepad2 & BUTTON_UP){
    raquete2_y = raquete2_y - 3;
    if (raquete2_y < 0){
      raquete2_y = 0;
    }
  }
  if (gamepad2 & BUTTON_DOWN){
    raquete2_y = raquete2_y + 3;
    if (raquete2_y > 140){
      raquete2_y = 140;
    }
  }

  if (bola_x <= 4 && bola_y >= raquete1_y && bola_y <= raquete1_y + 20){
    bola_dx = -1 * bola_dx;
  }

  if (bola_x >= 156 && bola_y >= raquete2_y && bola_y <= raquete2_y + 20){
    bola_dx = -1 * bola_dx;
  }
}

