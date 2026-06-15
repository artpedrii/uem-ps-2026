#include <stdio.h>

int main(){
    int p = 0;
    int q = 0;
    float total; 
    printf("Escreva o código do produto: ");
    scanf("%i", &p);
    printf("Escreva a quantidade do produto: ");
    scanf("%i", &q);
    if (p == 1){
        total = q * 1.10;
    }
    else{
        if(p == 2){
            total = q * 2.30;
        }
        else{
            total = q * 4.70;
        }
    }
    printf("%f", total);
}