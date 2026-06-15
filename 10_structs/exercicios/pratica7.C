#include <stdio.h>

typedef struct{
    char nome[10];
    int poder;
    int defesa;
    int vida;
} Personagem;

void status(Personagem p){
    printf("%9s poder=%03i defesa=%03i vida=%03i\n", p.nome, p.poder, p.defesa, p.vida);
}

int ataque(Personagem p1, Personagem p2){
    int dano = p1.poder - p2.defesa;
    return dano;
}

int main(){
    Personagem a = {"Xil", 54, 12, 100};
    Personagem b = {"Yen", 40, 20, 100}; 
    printf("Batalha:\n");
    while (a.vida > 0 && b.vida > 0){
        int dano_causado_a = ataque(a, b);
        int dano_causado_b = ataque(b, a);
        a.vida = a.vida - dano_causado_b;
        b.vida = b.vida - dano_causado_a;
        status(a);
        status(b);
    }
    if (a.vida > 0 && b.vida < 1){
        printf("Xil venceu\n");
    }
    else if (a.vida < 1 && b.vida < 1){
        printf("Ambos morreram\n");
    } 
    else {
        printf("Yen venceu\n");
    }
    return 0;
}