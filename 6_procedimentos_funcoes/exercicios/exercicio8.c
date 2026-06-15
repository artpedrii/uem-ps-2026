#include <stdio.h>

int digitos(int n){
    int quantidade_digitos = 0;
    int temp = n;
    if (n == 0) {
        quantidade_digitos == 1;
    }
    else{
        while(temp > 0){
            temp = (temp - (temp % 10))/10;
            quantidade_digitos++;
        }
    }
    return quantidade_digitos;
}

int main(){
    int quant_digitos = digitos(8);
    printf("%i\n", quant_digitos);
    int quant_digitos = digitos(27);
    printf("%i\n", quant_digitos);
    int quant_digitos = digitos(456);
    printf("%i\n", quant_digitos);
}