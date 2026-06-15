#include <stdio.h>

void verifica_valor_5(){
    int valor_presente = 0;
    int i = 0;
    int v[4] = {4, 2, 7, 5};
    int len_v = 4;
    for (i = 0; i < len_v; i++){
        if (v[i] == 5){
            valor_presente = 1; 
        }
    }
    if (valor_presente == 1){
        printf("o valor 5 está presente\n");
    }
    else {
        printf("O valor 5 não está presente\n");
    }
}

void main(){
    verifica_valor_5();
}