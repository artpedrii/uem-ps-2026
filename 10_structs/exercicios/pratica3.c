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
    Produto a = {120, 0.10, "porca"};
    Produto b = {80, 0.20, "parafuso"};
    float valor_a = valor_produto(a);
    float valor_b = valor_produto(b);
    float valor_total = valor_a + valor_b; 
    imprime_produto(a);
    imprime_produto(b);
    printf("valor total: %0.2f", valor_total);
    return 0; 
}