#include <stdio.h>
#include <string.h>

//EXERCÍCIO 1)
typedef struct {
    char nome[100]; 
    int idade;
} Pessoa;

void compara_nome(Pessoa p1, Pessoa p2){
    int comparacao = strcmp(p1.nome, p2.nome); 
    if (comparacao < 0){
        printf("%s vem antes de %s\n", p1.nome, p2.nome);
    }
    else if (comparacao == 0){
        printf("Mesmo nome.\n");
    }
    else {
         printf("%s vem antes de %s\n", p2.nome, p1.nome);
    }
}

void compara_idade(Pessoa p1, Pessoa p2){
    if (p1.idade < p2.idade){
        printf("%s é mais novo.\n", p1.nome);
    }
    else if (p1.idade == p2.idade){
        printf("Mesma idade.\n");
    }
    else {
        printf("%s é mais novo.\n", p2.nome);
    }
}

//EXERCÍCIO 2)
void zera_vetor(int v[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        if (v[i] < 0){
            v[i] = 0;
        }
    }
    
}

//EXERCÍCIO 3)
void converte_maiuscula(char c[]){
    int tamanho_c = strlen(c);
    for (int i = 0; i < tamanho_c; i++){
        if (c[i] < 65 || c[i] > 90){
            c[i] = c[i] - 32;
        }
        
    }
}

int main(){
    //ex1
    Pessoa p1;
    Pessoa p2;
    printf("Escreva o nome da pessoa: ");
    scanf("%s", p1.nome); 
    printf("Escreva a idade da pessoa: ");
    scanf("%i", &p1.idade);
    printf("Escreva o nome da outra pessoa: ");
    scanf("%s", p2.nome); 
    printf("Escreva a idade da outra pessoa: ");
    scanf("%i", &p2.idade);
    compara_nome(p1, p2); 
    compara_idade(p1, p2);

    //ex2
    int v[10] = {2, 3, -7, 8, 8, -60, 5, 5, 5, 5};
    zera_vetor(v, 10);
    for (int i = 0; i < 10; i++){
        printf("%i ", v[i]);
    }

    //ex3
    char c[100]; 
    printf("Escreva uma palavra. ");
    scanf("%s", c);
    converte_maiuscula(c);
    for (int i = 0; i < 100; i++){
        printf("%c", c[i]);
    }
    return 0;
}