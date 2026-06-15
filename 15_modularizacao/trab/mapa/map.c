#include "map.h"
#include <stdio.h>
#include <stdlib.h>

/* Cria um mapa vazio (todas células com OPEN) com o tamanho fornecido. */
Map *map_create(int rows, int cols){
    Map *m = malloc(sizeof(Map));
    m->linhas = rows;
    m->colunas = cols;
    m->mapa = malloc(rows * cols * sizeof(char));

    for (int i = 0; i < (rows * cols); i++){
        m->mapa[i] = OPEN;
    }
    return m; 
}

/* Obtém dimensões. */
int map_rows(const Map *m){
    return m->linhas;
}
int map_cols(const Map *m){
    return m->colunas;
}

/* Consulta/modifica uma célula (qualquer caractere é válido). */
char map_get(const Map *m, int r, int c){
    int i = r * m->colunas + c;
    return m->mapa[i];
}
void map_set(Map *m, int r, int c, char ch){
    int i = r * m->colunas + c;
    m->mapa[i] = ch; 
}

/* Imprime o mapa em `out` (por exemplo, `stdout`). */
void map_print(const Map *m, FILE *out){
    fprintf(out, "%i %i\n", m->linhas, m->colunas);
    for (int i = 0; i < m->linhas; i++){
        for (int j = 0; j < m->colunas; j++){
            fprintf(out, "%c", map_get(m, i, j));
        }
        fprintf(out, "\n");
    }
}

/* Libera todos os recursos. */
void map_free(Map *m){
    free(m->mapa);
    m->mapa = NULL;
    free(m);
    m = NULL;
}

/* Carrega um mapa de um arquivo de texto. Formato:
* Linha 1: <l> <c>
* Para as próximas `l` linhas: `c` caracteres copiados para a grade.
* Retorna NULL em caso de falha. */
Map *map_load(const char *filename){
    FILE *arq = fopen(filename, "r");
    int l = 0;
    int c = 0;
    Map *mapa = NULL;
    if (arq == NULL ){
        printf("A abertura do arquivo falhou!\n");
        return NULL;
    }
    else {
        fscanf(arq, "%d %d", &l, &c);
        mapa = map_create(l, c);
        char caractere;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                fscanf(arq, " %c", &caractere); 
                map_set(mapa, i, j, caractere);
            }
        }
    }
    fclose(arq);
    return mapa;
}
