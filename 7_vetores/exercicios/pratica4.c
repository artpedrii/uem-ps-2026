#include <stdio.h>

void conta_par_impar(){
    int v[6] = {1, 4, 6, 5, 8, 2};
    int len_v = 6;
    int i = 0;
    int np = 0;
    int ni = 0;
    for (i = 0; i < len_v; i++){
        if (v[i] % 2 == 0){
            np++;
        }
        else {
            ni++;
        }
    }
    printf("%i %i\n", np, ni);
}

void main(){
    conta_par_impar();
}