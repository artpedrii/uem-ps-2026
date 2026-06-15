#include <stdio.h>
#include "map.h"

int eh_igual(Map *m1, Map *m2){
        int boolean = 1;
        for(int i = 0; i < map_rows(m1); i++){
            for (int j = 0; j < map_cols(m1); j++){
                if (map_get(m1, i, j) != map_get(m2, i, j)){
                    printf("Diferenca em [%d][%d]: original='%c' vs carregado='%c'\n", i, j, map_get(m1, i, j), map_get(m2, i, j));
                    boolean = 0;
                }
            }
        }
        return boolean;
    }

int main(){
    Map *m = map_create(16, 16);
    int c = map_cols(m);
    int l = map_rows(m);
    printf("Linhas: %i\n", l);
    printf("Colunas: %i\n", c);
    for (int i = 0; i < map_rows(m); i++) {
        for (int j = 0; j < map_cols(m); j++) {
            if (i == 0 || i == map_rows(m) - 1 || j == 0 || j == map_cols(m) - 1) {
                map_set(m, i, j, WALL);
            } else {
                map_set(m, i, j, OPEN);
            }
        }   
    }
    map_set(m, 10, 11, 'a');
    map_set(m, 8, 12, '-');
    map_set(m, 5, 5, '$');
    map_set(m, 12, 12, '$');
    map_set(m, 15, 11, 'b');
    map_set(m, 10, 12, '$');
    map_set(m, 7, 11, 'a');
    FILE *arq = fopen("mapa.txt", "w");
    map_print(m, arq);
    fclose(arq);

    Map *m2 = map_load("mapa.txt");

    if (eh_igual(m, m2) == 1){
        printf("testes funcionaram");
    }
    else {
        printf("testes falharam");
    }
    
    map_free(m);
    map_free(m2);
    arq = NULL;
    return 0;
}