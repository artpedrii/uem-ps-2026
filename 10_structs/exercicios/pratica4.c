#include <stdio.h> 

typedef struct {
    int quantidade;
    float custo;
    char nome[20];
} Produto; 

void imprime_produto(Produto p){
    printf("%3i %0.2f %s\n", p.quantidade, p.custo, p.nome);
}

float valor_produto(Produto p){
    return p.quantidade * p.custo;
}

int main(){
    Produto vp[2] = {{120, 0.10, "porca"}, {80, 0.20, "parafuso"}};
    float valor_total = 0;
    for (int i = 0; i < 2; i++){
        imprime_produto(vp[i]);
        valor_total = valor_total + valor_produto(vp[i]);
    }
    printf("valor total: %0.2f\n", valor_total);
    return 0; 
}