#include <stdio.h>

void imprimne_vetor_reverso(){
    int v[6] = {11, 22, 33, 44, 55, 66};
    int len_v = 6;
    int i = 0;
    int j = 0;
    int r[len_v]; 
    for (i = (len_v - 1); i >= 0; i--){
        r[j] = v[i];
        j++;
    }
    for (j = 0; j < len_v; j++){
        printf("%i ", r[j]);
    }
}

void main(){
   imprimne_vetor_reverso(); 
}