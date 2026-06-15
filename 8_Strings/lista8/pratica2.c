#include <stdio.h> 
#include <string.h>

void primeira_ultima(char s[]){
    int tamanho_s =  strlen(s);
   printf("%c %c\n", s[0], s[tamanho_s - 1]);
}

int main(){
    char s[100];
    printf("Escreva uma palavra: ");
    scanf("%s", s);
    primeira_ultima(s);
    return 0;
}