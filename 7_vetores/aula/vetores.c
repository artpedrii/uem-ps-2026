#include <stdio.h>

//EXERCÍCIO 1)

void vetor_maior_menor(){
    int i = 0;
    int v[5] = {4, 1, 5, 8, 6}; 
    int len_v = 5;
    int maior_valor = 0;
    int menor_valor = 999999999; 
    for (i = 0; i < len_v; i++){
        if (v[i] >= maior_valor){
            maior_valor = v[i]; 
        }
    }
    for (i = 0; i < len_v; i++){
        if (v[i] <= menor_valor){
            menor_valor = v[i];
        }
    }
    printf("Maior valor é: %i\n", maior_valor);
    printf("Menor valor é: %i\n", menor_valor);
}

//EXERCÍCIO 2)

void divisores(int n){
    int i = 1;
    int quantidade_divisores = 0;
    for (i = 1; i <= n; i++){
        if (n % i == 0){
            quantidade_divisores++;
        }
    }
        int len_v = quantidade_divisores;
        int v[quantidade_divisores];
        int posicao_divisor = 0;
        
    for (i = 1; i <= n; i++){
        if (n % i == 0){
            int divisor = i;
            v[posicao_divisor] = divisor;  
            posicao_divisor++;
        }
    }
    for (i = (len_v - 1); i >= 0; i--){
        printf("%i\n", v[i]);
    }
}

void main(){
    vetor_maior_menor();
    divisores(12);
}
