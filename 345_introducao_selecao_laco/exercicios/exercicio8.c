#include<stdio.h>

int main(){
    int soma = 0;
    int c = 3;
    while(c <= 99){
        soma = soma + c;
        c = c + 3;
    }
    printf("%i", soma);
    return 0;
}