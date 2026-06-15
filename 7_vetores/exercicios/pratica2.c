#include <stdio.h>

void indice_valor_a(){
    int a = 8;
    int v[4] = {6, 2, 8, 1};
    int len_v = 4;
    int i = 0;
    for (i = 0; i < len_v; i++){
        if (v[i] == a){
            printf("%i\n", i);
        }
    }
}

void main(){
    indice_valor_a();
}