#include <stdio.h>

//EXERCÍCIO 1)
void troca_valor (int *a, int *b) {
    int aux_a = *a; 
    int aux_b = *b;
    *a = aux_b; 
    *b = aux_a;
}

//EXERCÍCIO 2)
void menor_maior(int v[], int tamanho_v, int *maior, int *menor){
     *menor = v[0];
     *maior = v[0];
    for (int i = 0; i < tamanho_v; i++){
        if (v[i]<= *menor){
            *menor = v[i];
        }
        if (v[i] >= *maior ){
            *maior = v[i];
        }
    }
}

int main(){
    //ex1
    int a = 7;
    int b = 6; 
    troca_valor(&a, &b);
    printf("%i %i\n", a, b);

    //ex2
    int vetor[5] = {1, 2, 3, 4, 5};
    int tamanho_vetor = 5;
    int maior;
    int menor;
    menor_maior(vetor, tamanho_vetor, &maior, &menor);
    printf("Maior valor: %i\nMenor valor: %i\n", maior, menor);

    return 0;
}