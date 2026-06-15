#include <stdio.h>

int vetor_quadrados(int n){
    int i = 0;
    int tamanho_vetor = 0;
    for (i = 0; i <= n; i++){
        tamanho_vetor++;
    }
    int v[tamanho_vetor];
    for (i = 0; i <= (tamanho_vetor - 1); i++){
        int quadrado = i * i;
        v[i] = quadrado; 
    }
    for (i = 1; i < tamanho_vetor; i++){
        printf("%i ", v[i]);      
    }  
    return 0;
}

int main(){
    int n = 0;
    printf("Escreva um número inteiro n: ");
    scanf("%i", &n);
    vetor_quadrados(n);
    return 0;
}