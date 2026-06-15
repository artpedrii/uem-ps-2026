#include <stdio.h>

void troca_par_sucessor(){
    int v[6] = {5, 4, 6, 3, 2, 1};
    int len_v = 6;
    int i = 0;
    for (i = 0; i < len_v; i++){
        if (v[i] % 2 == 0){
            v[i] = v[i] + 1;
        }
    }
    for (i = 0; i < len_v; i++){
        printf("%i ", v[i]);
    }
}

void main(){
    troca_par_sucessor();
}