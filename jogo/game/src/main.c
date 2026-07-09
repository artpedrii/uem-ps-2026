#include "wasm4.h"
#include <stdint.h>

int bola_x; // Eixo horizontal bola
int bola_y; // Eixo vertical bola

int raquete_esq; // Eixo vertical raquete esquerda
int raquete_dir; // Eixo vertical raquete direita

int bola_dx; // Velocidade horizontal da bola
int bola_dy; // Velocidade vertical da bola

void cores_jogo () {
  PALETTE[0] = 0x0a0a0a; // Cor 1 (cor do fundo)
  PALETTE[1] = 0x7550e8; // Cor 2
  PALETTE[2] = 0x608fcf; // Cor 3
  PALETTE[3] = 0x622e4c;; // Cor 4
}

void inicia_bola () {
  bola_x = bola_y = 80;
  bola_dx = 2;
  bola_dy= 2;
}

void inicia_raquetes () {
  raquete_esq = 120;
  raquete_dir = 80;
}

void start () {
  cores_jogo();
  inicia_bola();
  inicia_raquetes();
}

void desenha_bola () {
  *DRAW_COLORS = 3;
  rect(bola_x, bola_y, 3, 3);
}

void desenha_raquetes () {
  *DRAW_COLORS = 2;
  rect(0, raquete_esq, 4, 20);
  rect(156, raquete_dir, 4, 20);
}

void move_bola () {
  bola_x = bola_x + bola_dx;
  bola_y = bola_y + bola_dy;
}

void move_raquete (int *raquete, uint8_t gamepad) {
  if (gamepad & BUTTON_UP){
    *raquete = *raquete - 3;
    if (*raquete < 0){
      *raquete = 0;
    }
  }
  if (gamepad & BUTTON_DOWN){
    *raquete = *raquete + 3;
    if (*raquete > 140){
      *raquete = 140;
    }
  }
}

void colisoes () {
  if (bola_x > 160 || bola_x < 0) {
      bola_x = bola_y = 80;
  }
  if (bola_y > 160 || bola_y < 0) {
      bola_dy = -1 * bola_dy; 
  }

  if (bola_x <= 4 && bola_y >= raquete_esq && bola_y <= raquete_esq + 20){
    bola_dx = -1 * bola_dx;
    bola_x = 5; 
  }

  if (bola_x >= 156 && bola_y >= raquete_dir && bola_y <= raquete_dir + 20){
    bola_dx = -1 * bola_dx;
    bola_x = 155;
  }
}

void update () {
  move_raquete(&raquete_esq, *GAMEPAD2);
  move_raquete(&raquete_dir, *GAMEPAD1);
  move_bola();
  
  colisoes();

  desenha_raquetes();
  desenha_bola();
}