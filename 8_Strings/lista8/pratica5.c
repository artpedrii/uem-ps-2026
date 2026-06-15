#include <stdio.h>
#include <string.h>

void escreve_reverso(char s[]){
    int j = 0;
    int tamanho_s = strlen(s);
    char string_reversa[tamanho_s + 1];
    for (int i = tamanho_s - 1; i >= 0; i--){
        string_reversa[j] = s[i];
        j++;
    }
    string_reversa[j] = '\0';
    printf("%s\n", string_reversa);
}

int main(){
    char s[100];
    printf("Escreva uma frase: ");
    fgets(s, 100, stdin);
    escreve_reverso(s);
    return 0;
}