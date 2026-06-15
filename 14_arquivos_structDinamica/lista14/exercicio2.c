#include <stdio.h>

int main(){
    FILE *arq = fopen("random.txt", "r");
    char linha[100 + 1];
    int linha_qt = 0;
    while (1){
       fscanf(arq, "%100[^\n]%*c", linha);
       if (feof(arq)) { 
            break; 
        }
        linha_qt++;
    }
    fclose(arq);
    arq = NULL;
    printf("%i\n", linha_qt);
    return 0;
}