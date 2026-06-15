#include <stdio.h>
#include <string.h>

//EXERCÍCIO 1
void primeira_ocorrencia_a(char s[]){
    int ocorrencia = 0;
    int tamanho_s = strlen(s);
    for (int i = 0; i < (tamanho_s + 1); i++){
        if ((s[i] == 'A') || (s[i] == 'a')){
            ocorrencia = i;
            break; 
        }
    }
    printf("Primeiro ocorrência da letra a: %i\n", ocorrencia);
}

//EXERCÍCIO 2
void conta_palavra(char s[]){
    int i = 0;
    int quantidade_palavras = 1;
    int tamanho_s = strlen(s);
    while (i < tamanho_s + 1){
        if (s[i] == ' '){
            quantidade_palavras++;
        }
        i++;
    }
    printf("Quantidade de palavras: %i\n", quantidade_palavras); 
}

//EXERCÍCIO 3
void maior_palavra(char s[], char t[]){
    int comparacao = strcmp(s, t);
    if (comparacao < 0) {
        printf("%s vem antes de %s", s, t);
    }
    else if (comparacao == 0){
        printf("Mesma ordem.");
    }
    else {
        printf("%s vem antes de %s", t, s);
    }
}

int main(){
    //ex1
    char s[999]; 
    printf("Digite um texto: ");
    fgets(s, 999, stdin); 
    primeira_ocorrencia_a(s);

    //ex2
    char t[999];
    printf("Digite um texto: ");
    fgets(t, 999, stdin);
    conta_palavra(t);

    //ex3
    char h1[999];
    char h2[999];
    printf("Digite uma palavra: ");
    scanf("%s", h1);
    printf("Digite outra palavra: ");
    scanf("%s", h2);
    maior_palavra(h1, h2);
    return 0;
}
