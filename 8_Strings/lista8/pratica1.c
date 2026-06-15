#include <stdio.h>
#include <string.h>

void primeira_ultima(){
   char s[19] = "Isso foi um teste!";
   int tamanho_s =  strlen(s);
   printf("%c %c\n", s[0], s[tamanho_s - 1]);
}

int main(){
    primeira_ultima();
    return 0;
}