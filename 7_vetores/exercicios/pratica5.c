#include <stdio.h>

void imprime_ordem_reversa(){
    int v[5] = {1, 2, 3, 4, 5};
    int len_v = 5;
    int i = 0;
    for (i = (len_v - 1); i >= 0; i--){
        printf("%i\n", v[i]);
    }
}

void main(){
    imprime_ordem_reversa();
}