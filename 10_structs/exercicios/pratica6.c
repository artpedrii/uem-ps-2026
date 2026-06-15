#include <stdio.h>

typedef struct{
    char nome[10];
    int poder;
    int defesa;
    int vida;
} Personagem;

void status(Personagem p){
    printf("%10s poder=%03i defesa=%03i vida=%03i\n", p.nome, p.poder, p.defesa, p.vida);
}

int ataque(Personagem p1, Personagem p2){
    int dano = p1.poder - p2.defesa;
    return dano;
}

int main(){
    Personagem a = {"Xil", 54, 12, 100};
    Personagem b = {"Yen", 40, 20, 100}; 
    int dano_causado = 0;
    status(a);
    status(b);
    dano_causado = ataque(a, b);
    printf("ataque de Xil a Yen vai causar %i de dano\n", dano_causado);
    dano_causado = ataque(b, a);
    printf("ataque de Yen a Xil vai causar %i de dano\n", dano_causado);
    return 0;
}