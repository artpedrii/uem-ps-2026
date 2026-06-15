#include <stdio.h>

int main(){
    int v = 1;
    int produto = 1;
    while(v != 0){
        printf("Escreva um número inteiro:  ");
        scanf("%i", &v);
        if (v == 0){
            break;
        }
        else{
            produto = produto * v;
        }  
    }
    printf("%i", produto);
    return 0;
}