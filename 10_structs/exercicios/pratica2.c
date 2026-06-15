#include <stdio.h> 

typedef struct {
    int quantidade;
    float custo;
    char nome[20];
} Produto; 

void imprime_produto(Produto p){
    printf("%3i %0.2f %s\n", p.quantidade, p.custo, p.nome);
}

int main(){
    Produto a = {120, 0.10, "porca"};
    Produto b = {80, 0.20, "parafuso"};
    imprime_produto(a);
    imprime_produto(b);
    return 0;
}
