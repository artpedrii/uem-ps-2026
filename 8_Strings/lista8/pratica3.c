#include <stdio.h> 
#include <string.h>

void decompoe_palavra(char s[]){
    int tamanho_s = strlen(s);
    for (int i = 0; i < (tamanho_s); i++){
        printf("'%c'\n", s[i]);
    }
}

int main(){
    char s[100];
    printf("Escreva uma frase: ");
    fgets(s, 100, stdin);
    decompoe_palavra(s);
    return 0;
}