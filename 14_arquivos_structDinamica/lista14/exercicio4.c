#include <stdio.h>

int main(){
    int codigo[4] = {23, 45, 67, 89};
    int quantidade[4] = {12, 3, 65, 25};
    double valor[4] = {1.29, 2.39, 1.19, 3.09};
    char *descricao[4] = {"porca", "parafuso", "arruela", "braçadeira"};

    FILE *arq = fopen("arquivo.csv", "w");
    fprintf(arq, "codigo, quantidade, valor, descricao\n");
    for (int i = 0; i <= 3; i++){
        fprintf(arq, "%i, %i, %f, %s\n", codigo[i], quantidade[i], valor[i], descricao[i]);
    }
    fclose(arq);
    arq = NULL;
    return 0;
}