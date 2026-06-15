#include <stdio.h>
#include <string.h>

void contem_decimal(char d[]){
    int tamanho_d = strlen(d); 
    int quantidade_numeros_0a9 = 0;
    for (int i = 0; i < tamanho_d; i++){
        if (d[i] >= '0' && d[i] <= '9'){
            quantidade_numeros_0a9++;
        }
    }
    if (quantidade_numeros_0a9 == tamanho_d){
        printf("sim\n");
    }
    else {
        printf("não\n"); 
    } 
}

int main(){
    char d[100];
    printf("escreva uma palavra: ");
    scanf("%s", d);
    contem_decimal(d);
    return 0;
}