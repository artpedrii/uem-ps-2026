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

Personagem batalha(Personagem p1, Personagem p2){
    printf("Batalha:\n");
    while (p1.vida > 0 && p2.vida > 0){
        int dano_causado_p1 = ataque(p1, p2);
        int dano_causado_p2 = ataque(p2, p1);
        p1.vida = p1.vida - dano_causado_p2;
        p2.vida = p2.vida - dano_causado_p1;
        status(p1);
        status(p2);
    }
    if (p1.vida > 0 && p2.vida < 1){
        printf("Xil venceu\n");
    }
    else if (p1.vida < 1 && p2.vida < 1){
        printf("Ambos morreram\n");
    } 
    else {
        printf("Inimigo venceu\n");
    }
    return p1;
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
    Personagem inimigos[5];
    for (int i = 0; i < 5; i++){
        inimigos[i] = inimigo();
    }
    for (int i = 0; i < 5; i++){
        if (a.vida > 0) {
            a = batalha(a, inimigos[i]);
        }    
    }
    return 0;
}