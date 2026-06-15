#include <stdio.h>
#include <math.h>

float fatorial(int n){
    float resultado = 1.0;
    while(n >= 1){
        resultado = resultado * n;
        n--;
    }
    return resultado;
}

float serie(int m){
    int c = 1; 
    float acumulador = 0.0;
    float resultado = 0.0;
    while(c <= m){
        acumulador = fatorial(c)/c; 
        resultado = resultado + acumulador;
        c++;
    }
    return resultado;
}

int main(){
    float result_serie = 0.0;
    result_serie = serie(5);
    printf("%.1f", result_serie);
}