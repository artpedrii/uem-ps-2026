#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

float *vetor_aleatorio(int n){
   float *p_v = malloc(n * sizeof(float));
   for (int i = 0;  i < n; i++){
        p_v[i] = (float)rand()/RAND_MAX;
   }
   return p_v;
}

int main(){
    srand(time(NULL));
    int n = 10;
    int m = 100;
    int o = 1000;

    float *p_va1 = vetor_aleatorio(n);
    float *p_va2 = vetor_aleatorio(m);
    float *p_va3 = vetor_aleatorio(o);

    float soma1 = 0;
    for (int i = 0; i < n; i++){
        soma1 = soma1 + p_va1[i];
    }

    float soma2 = 0;
    for (int j = 0; j < m; j++){
        soma2 = soma2 + p_va2[j];
    }

    float soma3 = 0;
    for (int k = 0; k < o; k++){
        soma3 = soma3 + p_va3[k];
    }

    printf("%f\n", (float)soma1 / n);
    printf("%f\n", (float)soma2 / m);
    printf("%f\n", (float)soma3 / o);

    free(p_va1);
    free(p_va2);
    free(p_va3);
    p_va1 = NULL;
    p_va2 = NULL;
    p_va3 = NULL;
    
    return 0;
}