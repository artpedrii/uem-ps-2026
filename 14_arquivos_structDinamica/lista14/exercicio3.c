#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arq = fopen("random.txt", "r");
    char linha[100 + 1];
    int soma = 0;
    while (1){
       fscanf(arq, "%100[^\n]%*c", linha);
       if (feof(arq)) { 
            break; 
        }
        soma += atoi(linha);
    }
    fclose(arq);
    arq = NULL;
    printf("%i\n", soma);
    return 0;
}