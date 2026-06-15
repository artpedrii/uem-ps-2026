#include <stdio.h>

double codigo_preco(int codigo_digitado){
    int codigo[3] = {12, 34, 56};
    double preco[3] = {1.34, 2.49, 3.89};
    int i = 0;
    int tam_vetores = 3;
    int indice_codigo_digitado = -1;
    for (i = 0; i < tam_vetores; i++){
        if (codigo_digitado == codigo[i]){
            indice_codigo_digitado = i;
        }
    }
    if (indice_codigo_digitado == -1){
        printf("Escolha um código válido.\n");
        return 0.0;
    }
    else {
        return preco[indice_codigo_digitado];
    }
}

int main(){
    int cod = 0;
    double preco = 0;
    printf("Digite o código do produto: ");    
    scanf("%i", &cod);
    preco = codigo_preco(cod);
    printf("%0.2f", preco);
    return 0;
}