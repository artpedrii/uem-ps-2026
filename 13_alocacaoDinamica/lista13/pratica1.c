#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char p1[] = "ela";
    char p2[] = "viu";
    char p3[] = "a";
    char p4[] = "uva";
    char *frase = malloc(strlen(p1) + strlen(p2) + strlen(p3) + strlen(p4) + 4);
    strcpy(frase, p1);
    strcat(frase, " ");
    strcat(frase, p2);
    strcat(frase, " ");
    strcat(frase, p3);
    strcat(frase, " ");
    strcat(frase, p4);

    printf("frase: %s\n", frase);
    printf("comprimento: %zu\n", strlen(frase));
    printf("tamanho: %zu\n", (strlen(frase) + 1));

    free(frase);
    frase = NULL;

    return 0;
}