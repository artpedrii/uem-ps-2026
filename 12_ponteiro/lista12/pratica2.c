#include <stdio.h>
#include <string.h>

void imprime_maior_string(char *v[], int tamanho_v){
    int maior_tamanho =  strlen(v[0]);
    int indice_maior_tam = 0;
    for (int i = 0; i < tamanho_v; i++){
        if (strlen(v[i]) >= maior_tamanho){
            maior_tamanho = strlen(v[i]);
            indice_maior_tam = i;
        }
    }
    printf("%s\n", v[indice_maior_tam]);
    
}

int main(){
    char *palavras[] = {"jfd", "kj", "usjkfhcs", "nbxh", "yt", "muoi", "x", "rhd"};
    imprime_maior_string(palavras, 8);
    return 0;
}