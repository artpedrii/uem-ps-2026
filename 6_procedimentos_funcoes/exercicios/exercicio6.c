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

int main(){
    float result_final = 0.0;
    result_final = fatorial(5);
    printf("%.1f", result_final);

}