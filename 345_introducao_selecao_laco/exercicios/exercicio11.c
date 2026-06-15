#include <stdio.h>

int main(){
    double valor_real = 999999999999999.9;
    double menor = 999999999999999.9;
    while (valor_real != 0){
        printf("Insira um valor real: ");
        scanf("%lf", &valor_real);
        if (valor_real == 0){
            break;
        }
        else{
            if (valor_real <= menor){
                menor = valor_real;
            }
        }
    }
    printf("%lf", menor);
    return 0;
}