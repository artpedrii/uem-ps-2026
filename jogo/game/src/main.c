#include "wasm4.h"
#include <stdint.h>

int bola_x; //eixo horizontal bola
int bola_y; //eixo vertical bola

int raquete1_y; //eixo vertical raquete 1
int raquete2_y; //eixo vertical raquete 2

int bola_dx; //velocidade horizontal da bola
int bola_dy; //velocidade vertical da bola

void cores_jogo () {
  PALETTE[0] = 00000000; // Cor 1 (Geralmente a cor de fundo da tela)
  PALETTE[1] = 0xFFFFFF; // Cor 2
  PALETTE[2] = 0xFFFFFF; // Cor 3
  PALETTE[3] = 0xFFFFFF; // Cor 4
}

void inicia_bola () {
  bola_x = bola_y = 80; // Posição inicial da bola
  bola_dx = 2; // Velociade da bola no eixo X
  bola_dy= 2; // Velocidade da bola no eixo Y
}

void inicia_raquetes () {
  raquete1_y = 120; // Posição da raquete da esquerda no eixo Y
  raquete2_y = 80; // Posição da raquete da direita no eixo Y
}

void start () {
  cores_jogo();
  inicia_bola();
  inicia_raquetes();
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
    bola_x = 5; 
  }

  if (bola_x >= 156 && bola_y >= raquete2_y && bola_y <= raquete2_y + 20){
    bola_dx = -1 * bola_dx;
    bola_x = 155;
  }
}

