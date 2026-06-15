#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "rpng.h"

#define TILE_SIZE 8
#define TILES_COLS 16  /* blocos por linha em tiles.png */

int main() {
    /* 1. carrega meu mapa com um retângulo vazado representando as paredes */
    Map *m = map_load("mapa.txt");
    map_print(m, stdout);

    /* 2. carrega os blocos */
    int tw, th, tc, tb;
    char *tiles = rpng_load_image("tiles.png", &tw, &th, &tc, &tb);
    if (!tiles) {
        fprintf(stderr, "falhou ao carregar tiles.png\n");
        map_free(m);
        return 1;
    }
    printf("carregado com w=%i h=%i c=%i b=%i \n", tw, th, tc, tb);

    /* 3. constroi a imagem RGB de saída, copiando um bloco por célula */
    int linhas = map_rows(m);
    int colunas = map_cols(m);
    int out_w = colunas * TILE_SIZE;
    int out_h = linhas * TILE_SIZE;
    char *out = calloc(out_w * out_h * 3 /* R G B */, sizeof(char)); // vetor zerado
    if (!out) {
        fprintf(stderr, "calloc falhou\n");
        free(tiles);
        map_free(m);
        return 1;
    }
    for (int r = 0; r < linhas; r++) {
        for (int c = 0; c < colunas; c++) {
            unsigned char ch = (unsigned char)map_get(m, r, c);
            int tile_col = ch % TILES_COLS;
            int tile_row = ch / TILES_COLS;
            for (int py = 0; py < TILE_SIZE; py++) {
                for (int px = 0; px < TILE_SIZE; px++) {
                    int sx = tile_col * TILE_SIZE + px;
                    int sy = tile_row * TILE_SIZE + py;
                    int dx = c * TILE_SIZE + px;
                    int dy = r * TILE_SIZE + py;
                    int si = (sy * tw + sx) * tc;
                    int di = (dy * out_w + dx) * 3;
                    out[di + 0] = tiles[si + 0];
                    out[di + 1] = tiles[si + 1];
                    out[di + 2] = tiles[si + 2];
                }
            }
        }
    }

    /* 4. Grava o resultado */
    if (rpng_save_image("drawing.png", out, out_w, out_h, 3, 8) != 0)
        fprintf(stderr, "falhou ao salvar imagem\n");
    else
        printf("imagem criada (%d x %d)\n", out_w, out_h);

    free(out);
    free(tiles);
    map_free(m);
    return 0;
}
