#include <stdio.h>
#include <math.h>

float calcula_distancia_euclidiana(float x1, float y1, float x2, float y2){
    float distancia = sqrt(((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1))); 
    return distancia;
}

int main(){
    float distancia_final;
    distancia_final = calcula_distancia_euclidiana(4.0, 6.0, 7.0, 2.0);
    printf("%.1f", distancia_final);
}