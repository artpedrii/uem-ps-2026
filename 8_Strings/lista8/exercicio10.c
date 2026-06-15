#include <stdio.h>
#include <string.h>

int potenciacao(int base, int expoente){
    int result = 1; 
    for (int i = 0; i < expoente; i++){
        result = result * base;
    }
    return result;
}

void converte_binario(char b[]){
    int tamanho_b = strlen(b);
    int acumulador = 0;
    for (int i = tamanho_b - 1; i >= 0; i--){
        if (b[i] == '1'){
            acumulador = acumulador + (1 * potenciacao(2, ((tamanho_b - 1) - i)));
        }
        else {
            acumulador = acumulador + 0;
        }
    }
    printf("%i\n", acumulador);
}

int main(){
    char b[100];
    printf("Digite um número binário: ");
    scanf("%s", b);
    converte_binario(b);
    return 0;
}