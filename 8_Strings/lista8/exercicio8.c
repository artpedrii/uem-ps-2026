#include <stdio.h>
#include <string.h>

void ocorrencia_palavra(char s[], char t[]){
    int tamanho_s = strlen(s);
    int tamanho_t = strlen(t);
    for (int i = 0; i < tamanho_s; i++){
        if (s[i] == t[0]){
            int letras_certas = 0;
            for (int j = 0; j < tamanho_t; j++){
                if (s[i + j] == t[j]){
                    letras_certas++;
                }
            }
            if (letras_certas == tamanho_t){
            printf("'%s' encontrado à partir do índice %i\n", t, i);
            }
        }
    }
}

int main(){
    char s[100];
    char t[100];
    printf("Digite uma palavra: ");
    fgets(s, 100, stdin);
    int tamanho_s = strlen(s);
    printf("Digite outra palavra: ");
    fgets(t, 100, stdin);
    int tamanho_t = strlen(t);
    if (s[tamanho_s - 1] == '\n'){
        s[tamanho_s - 1] = '\0';
    }
    if (t[tamanho_t - 1] == '\n'){
        t[tamanho_t - 1] = '\0';
    }
    ocorrencia_palavra(s, t);
    return 0;
}