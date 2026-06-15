#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ler_palavra(int n){
    char temp[100]  = "";
    while (strlen(temp) < n){
        scanf("%s", temp);
    }
    char *palavra_final = malloc((strlen(temp) + 1) * sizeof(char));
    strcpy(palavra_final, temp);
    
    return palavra_final;
}

int main(){
    char *p_p = ler_palavra(5);
    printf("%s", p_p);
    free(p_p);
    p_p = NULL;
    return 0;
}