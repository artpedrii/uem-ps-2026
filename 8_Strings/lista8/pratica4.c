#include <stdio.h>
#include <string.h>

void conta_vogal(char s[]){
    int tamanho_s = strlen(s);
    int a = 0;
    int e = 0;
    int i = 0;
    int o = 0;
    int u = 0;
    for (int j = 0; j < (tamanho_s); j++){
        if ((s[j] == 'A') || (s[j] == 'a')){
            a++;
        }
        else if ((s[j] == 'E') || (s[j] == 'e')){
            e++;
        }
        else if ((s[j] == 'I') || (s[j] == 'i')){
            i++;
        }
        else if ((s[j] == 'O') || (s[j] == 'o')){
            o++;
        }
        else if ((s[j] == 'U') || (s[j] == 'u')){
            u++;
        }
    }
    printf("%i %i %i %i %i\n", a, e, i, o, u);
}

int main(){
    char s[100];
    printf("Escreva uma frase: ");
    fgets(s, 100, stdin);
    conta_vogal(s);
    return 0;
}