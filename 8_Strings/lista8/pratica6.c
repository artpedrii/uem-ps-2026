#include <stdio.h>
#include <string.h>

void escreve_reverso(char s[], char reversa[]){
    int j = 0;
    int tamanho_s = strlen(s);
    for (int i = tamanho_s - 1; i >= 0; i--){
        reversa[j] = s[i];
        j++;
    }
    reversa[j] = '\0';
    //printf("%s\n", reversa);

}

void eh_palindromo(char s[]){
    char palavra_invertida[100];
    escreve_reverso(s, palavra_invertida);
    //int tamanho_s = strlen(s);
    int comparacao = strcmp(s, palavra_invertida);
    if (comparacao == 0){
        printf("sim");
    }
    else {
        printf("não");
    }
}

int main(){
    char s[100];
    printf("escreva uma palavra: ");
    fgets(s, 100, stdin);
    int tamanho_s = strlen(s);
    if (s[tamanho_s - 1] == '\n'){
        s[tamanho_s - 1] = '\0';
    }
    eh_palindromo(s);
    return 0;
}