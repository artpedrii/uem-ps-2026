#include "wasm4.h"
#include <stdint.h>

#define LARGURA_TELA 160
#define ALTURA_TELA 160

#define LARGURA_BOLA 3
#define ALTURA_BOLA 3

#define LARGURA_RAQUETE 4
#define ALTURA_RAQUETE 20

#define VELOCIDADE_RAQUETE 3
#define PONTOS_VITORIA 5

#define ESTADO_TITULO 0
#define ESTADO_INSTRUCOES 1
#define ESTADO_JOGO 2
#define ESTADO_VITORIA 3

int bola_x; // Eixo horizontal da bola
int bola_y; // Eixo vertical da bola
int bola_ant_x; // Posição horizontal anterior da bola
int bola_ant_y; // Posição vertical anterior da bola

int bola_dx; // Velocidade horizontal da bola
int bola_dy; // Velocidade vertical da bola

int raquete_esq; // Eixo vertical da raquete esquerda
int raquete_dir; // Eixo vertical da raquete direita
int raquete_esq_ant; // Posição anterior da raquete esquerda
int raquete_dir_ant; // Posição anterior da raquete direita

int pontos_raquete_esq; // Pontos da raquete esquerda
int pontos_raquete_dir; // Pontos da raquete direita

int estado_jogo;
int vencedor;
int rebatidas;
uint8_t botao_anterior;
uint32_t frames_inicio;
uint32_t seed;

void cores_jogo () {
  PALETTE[0] = 0x0a0a0a; // Cor 1: fundo
  PALETTE[1] = 0x7550e8; // Cor 2: raquetes
  PALETTE[2] = 0x608fcf; // Cor 3: bola
  PALETTE[3] = 0xb0b0b0; // Cor 4: texto, linha central e rastro
}

int sinal (int valor) {
  if (valor < 0) {
    return -1;
  }
  return 1;
}

int modulo (int valor) {
  if (valor < 0) {
    return -valor;
  }
  return valor;
}

uint32_t aleatorio () {
  seed = seed * 11035167 + 12345;
  return (seed >> 16) & 0x7fff;
}

uint8_t botao_menu () {
  uint8_t gamepad1 = *GAMEPAD1;
  uint8_t gamepad2 = *GAMEPAD2;
  return (gamepad1 | gamepad2) & (BUTTON_1 | BUTTON_2);
}

void inicia_bola_com_direcao (int direcao) {
  bola_x = 80;
  bola_y = 80;
  bola_ant_x = bola_x;
  bola_ant_y = bola_y;

  // A bola começa mais devagar e ganha velocidade ao longo do jogo.
  bola_dx = direcao;

  if (aleatorio() % 2 == 0) {
    bola_dy = 1;
  } else {
    bola_dy = -1;
  }
}

void inicia_bola () {
  inicia_bola_com_direcao(1);
}

void inicia_raquetes () {
  raquete_esq = 120;
  raquete_dir = 80;
  raquete_esq_ant = raquete_esq;
  raquete_dir_ant = raquete_dir;
}

void inicia_partida () {
  pontos_raquete_esq = 0;
  pontos_raquete_dir = 0;
  rebatidas = 0;
  vencedor = 1;
  inicia_raquetes();
  inicia_bola_com_direcao(1);
}

void start () {
  cores_jogo();

  estado_jogo = ESTADO_VITORIA;
  botao_anterior = 0;
  frames_inicio = 0;
  seed = 1;

  inicia_partida();
}

void desenha_tela_titulo () {
  *DRAW_COLORS = 4;
  text("PONG WASM-4", 38, 48);

  *DRAW_COLORS = 3;
  text("TUTU E SHIMAS", 30, 75);

  *DRAW_COLORS = 2;
  text("APERTE Z OU X", 30, 104);
}

void desenha_tela_instrucoes () {
  *DRAW_COLORS = 4;
  text("COMO JOGAR", 40, 16);

  *DRAW_COLORS = 2;
  text("ESQ: P2 E/D", 36, 44);
  text("DIR: P1 SETAS", 28, 60);

  *DRAW_COLORS = 3;
  text("REBATA A BOLINHA", 18, 88);
  text("VAI A 5 PONTOS", 27, 104);

  *DRAW_COLORS = 4;
  text("APERTE Z OU X", 32, 136);
}

void desenha_placar () {
  char placar[] = "0 X 0";

  placar[0] = (char)('0' + (pontos_raquete_esq % 10));
  placar[4] = (char)('0' + (pontos_raquete_dir % 10));

  *DRAW_COLORS = 4;
  text(placar, 60, 6);
}

void desenha_campo () {
  *DRAW_COLORS = 4;
  vline(79, 0, 160);
}

void desenha_rastro () {
  *DRAW_COLORS = 4;
  rect(bola_ant_x, bola_ant_y, LARGURA_BOLA, ALTURA_BOLA);
  rect(0, raquete_esq_ant, LARGURA_RAQUETE, ALTURA_RAQUETE);
  rect(156, raquete_dir_ant, LARGURA_RAQUETE, ALTURA_RAQUETE);
}

void desenha_bola () {
  *DRAW_COLORS = 3;
  rect(bola_x, bola_y, LARGURA_BOLA, ALTURA_BOLA);
}

void desenha_raquetes () {
  *DRAW_COLORS = 2;
  rect(0, raquete_esq, LARGURA_RAQUETE, ALTURA_RAQUETE);
  rect(156, raquete_dir, LARGURA_RAQUETE, ALTURA_RAQUETE);
}

void move_bola () {
  bola_ant_x = bola_x;
  bola_ant_y = bola_y;

  bola_x = bola_x + bola_dx;
  bola_y = bola_y + bola_dy;
}

void move_raquete (int *raquete, uint8_t gamepad) {
  if (gamepad & BUTTON_UP) {
    *raquete = *raquete - VELOCIDADE_RAQUETE;
    if (*raquete < 0) {
      *raquete = 0;
    }
  }

  if (gamepad & BUTTON_DOWN) {
    *raquete = *raquete + VELOCIDADE_RAQUETE;
    if (*raquete > ALTURA_TELA - ALTURA_RAQUETE) {
      *raquete = ALTURA_TELA - ALTURA_RAQUETE;
    }
  }
}

void aumenta_velocidade_bola () {
  if (modulo(bola_dx) < 4) {
    bola_dx = bola_dx + sinal(bola_dx);
  }

  if (modulo(bola_dy) < 3) {
    bola_dy = bola_dy + sinal(bola_dy);
  }
}

void colisao_pontos () {
  if (bola_x > LARGURA_TELA) {
    pontos_raquete_esq += 1;

    if (pontos_raquete_esq >= PONTOS_VITORIA) {
      vencedor = 1;
      estado_jogo = ESTADO_VITORIA;
    } else {
      inicia_bola_com_direcao(-1);
    }
  }

  if (bola_x < -LARGURA_BOLA) {
    pontos_raquete_dir += 1;

    if (pontos_raquete_dir >= PONTOS_VITORIA) {
      vencedor = 2;
      estado_jogo = ESTADO_VITORIA;
    } else {
      inicia_bola_com_direcao(1);
    }
  }
}

void colisao_teto_chao () {
  if (bola_y <= 0) {
    bola_y = 0;
    bola_dy = -1 * bola_dy;
  }

  if (bola_y >= ALTURA_TELA - ALTURA_BOLA) {
    bola_y = ALTURA_TELA - ALTURA_BOLA;
    bola_dy = -1 * bola_dy;
  }
}

void colisao_raquetes () {
  int bola_baixo = bola_y + ALTURA_BOLA;
  int raquete_esq_baixo = raquete_esq + ALTURA_RAQUETE;
  int raquete_dir_baixo = raquete_dir + ALTURA_RAQUETE;

  if (bola_x <= LARGURA_RAQUETE && bola_baixo >= raquete_esq && bola_y <= raquete_esq_baixo) {
    bola_dx = modulo(bola_dx);
    bola_x = LARGURA_RAQUETE;
    rebatidas += 1;

    if (rebatidas % 4 == 0) {
      aumenta_velocidade_bola();
    }
  }

  if (bola_x + LARGURA_BOLA >= LARGURA_TELA - LARGURA_RAQUETE && bola_baixo >= raquete_dir && bola_y <= raquete_dir_baixo) {
    bola_dx = -modulo(bola_dx);
    bola_x = LARGURA_TELA - LARGURA_RAQUETE - LARGURA_BOLA;
    rebatidas += 1;

    if (rebatidas % 4 == 0) {
      aumenta_velocidade_bola();
    }
  }
}

void colisoes () {
  colisao_pontos();
  colisao_teto_chao();
  colisao_raquetes();
}

void desenha_jogo () {
  desenha_campo();
  desenha_rastro();
  desenha_raquetes();
  desenha_bola();
  desenha_placar();
}

void desenha_vitoria () {
  *DRAW_COLORS = 4;
  text("FIM DE JOGO", 36, 40);

  *DRAW_COLORS = 3;
  if (vencedor == 1) {
    text("ESQUERDA VENCEU", 22, 76);
  } else {
    text("DIREITA VENCEU", 26, 76);
  }

  *DRAW_COLORS = 2;
  text("APERTE Z OU X", 30, 112);
}

void atualiza_titulo (int apertou_botao) {
  frames_inicio += 1;
  desenha_tela_titulo();

  if (apertou_botao) {
    estado_jogo = ESTADO_INSTRUCOES;
  }
}

void atualiza_instrucoes (int apertou_botao) {
  frames_inicio += 1;
  desenha_tela_instrucoes();

  if (apertou_botao) {
    seed = frames_inicio;
    if (seed == 0) {
      seed = 1;
    }

    inicia_partida();
    estado_jogo = ESTADO_JOGO;
  }
}

void atualiza_jogo () {
  raquete_esq_ant = raquete_esq;
  raquete_dir_ant = raquete_dir;

  move_raquete(&raquete_esq, *GAMEPAD2);
  move_raquete(&raquete_dir, *GAMEPAD1);
  move_bola();

  colisoes();
  desenha_jogo();
}

void atualiza_vitoria (int apertou_botao) {
  desenha_vitoria();

  if (apertou_botao) {
    seed = seed + frames_inicio + 1;
    inicia_partida();
    estado_jogo = ESTADO_JOGO;
  }
}

void update () {
  uint8_t botao_atual = botao_menu();
  int apertou_botao = botao_atual && !botao_anterior;

  if (estado_jogo == ESTADO_TITULO) {
    atualiza_titulo(apertou_botao);
  } else if (estado_jogo == ESTADO_INSTRUCOES) {
    atualiza_instrucoes(apertou_botao);
  } else if (estado_jogo == ESTADO_JOGO) {
    atualiza_jogo();
  } else if (estado_jogo == ESTADO_VITORIA) {
    atualiza_vitoria(apertou_botao);
  }

  botao_anterior = botao_atual;
}
