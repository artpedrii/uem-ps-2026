#include <stdio.h>

int main(){
    int a = 0;
    int b = 0;
    int numero_atual = 0;
    printf("Escreva um número inteiro a: ");
    scanf("%i", &a);
    printf("Escreva um número inteiro b: ");
    scanf("%i", &b);
    if (a <= b){
        while(a <= b){
            numero_atual = a;
            printf("%i\n", numero_atual);
            a++; 
        }
    }
    else{
        if(a > b){
            while(a >= b){
                numero_atual = a;
                printf("%i\n", numero_atual);
                a--; 
            }
        }
    }
    return 0;
}