#include <stdio.h>

void soma_media_vetor(int n){
    float soma = 0;
    int i = 0;
    float elemento = 0;
    float v[n];
    for (i = 0; i < n; i++){
        printf("Digite um número real: ");
        scanf("%f", &elemento);
        v[i] = elemento;
    }
    for (i = 0; i < n; i++){
        soma = soma + v[i];
    }
    float media = soma / n; 
    printf("%f\n", soma);
    printf("%f\n", media);
}

int main(){
    int n = 0;
    printf("Digite um número natural: ");
    scanf("%i", &n);
    soma_media_vetor(n);
    return 0;
}