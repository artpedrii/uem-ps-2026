#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float altura;
    float largura;
} Retangulo;

Retangulo *cria_retangulo(){
    Retangulo *p_r = malloc(sizeof(Retangulo));
    p_r->altura = 1;
    p_r->largura = 4;
    return p_r;
}

float calcula_area(Retangulo *r){
    return (r->altura * r->largura);
}

void transforma_quadrado(Retangulo *r){
    float area_retangulo = calcula_area(r);
    r->altura = sqrt(area_retangulo);
    r->largura = sqrt(area_retangulo);
}

int main(){
    //exer1
    FILE *arq = fopen("planilha.csv", "w");
    for (int i = 0; i <= 10; i++){
        fprintf(arq, "%i, %f, %f\n", i, sqrt(i), sin(i));
    }
    fclose(arq);
    arq = NULL;

    //exer2
    Retangulo *p_ret = cria_retangulo();
    float area = calcula_area(p_ret);
    printf("Área: %f\n", area);
    transforma_quadrado(p_ret);
    printf("Altura nova: %f\nLargura nova: %f", p_ret->altura, p_ret->largura);
}