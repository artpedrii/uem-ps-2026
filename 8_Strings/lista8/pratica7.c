#include <stdio.h>
#include <string.h>

void ocorrencia_caractere(char s[], char c){
    int tamanho_s = strlen(s);
    for (int i = 0; i <  tamanho_s; i++){
        if (s[i] == c){
            printf("'%c' encontrado no índice %i\n", c, i);
        }
    }
}

int main(){
    char s[100];
    char c;
    printf("Escreva uma palavra: ");
    fgets(s, 100, stdin);
    printf("Escreva uma letra: ");
    scanf("%c", &c);
    ocorrencia_caractere(s, c);
    return 0;
}

