#include <stdio.h>

void imprime_pares_vetor(){
    int v[8] = {9, 6, 2, 4, 8, 5, 1, 3};
    int len_v = 8; 
    int i = 0;
    int quantidade_elementos = 0;
    for (i = 0; i < len_v; i++){
        quantidade_elementos++;
    }
    if (quantidade_elementos % 2 == 0){
        for (i = 0; i < len_v; i=i+2){
            printf("%i %i\n", v[i], v[i + 1]);
        }
    }
}

int main(){
    imprime_pares_vetor();
    return 0;
}