#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    if (dano < 0) {
        dano = 0;
    }
    return dano;
}

Personagem inimigo(){
    Personagem z = {"Zed", 0, 0, 0};
    z.poder = 20 + rand() % (30 - 20 + 1);
    z.defesa = 10 + rand() % (30 - 10 + 1);
    z.vida = 20 + rand() % (50 - 20 + 1);
    return z;
}

int main(){
    srand(time(NULL));
    Personagem a = {"Xil", 54, 12, 100};
    Personagem z = inimigo(); 
    printf("Batalha:\n");
    while (a.vida > 0 && z.vida > 0){
        int dano_causado_a = ataque(a, z);
        int dano_causado_z = ataque(z, a);
        a.vida = a.vida - dano_causado_z;
        z.vida = z.vida - dano_causado_a;
        status(a);
        status(z);
    }
    if (a.vida > 0 && z.vida < 1){
        printf("Xil venceu\n");
    }
    else if (a.vida < 1 && z.vida < 1){
        printf("Ambos morreram\n");
    } 
    else {
        printf("Inimigo venceu\n");
    }
    return 0;
}