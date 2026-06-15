#include <stdio.h>

void expande_fatorial(int n){
    int resultado = 1;
    printf("%i! = ", n);
    while (n >= 1){
        resultado = resultado * n;
        printf("%i", n);
        if (n > 1){
            printf(" x ");
        }
        n--;
    }
    printf(" = %i\n", resultado);
}

void fatoriais(int n){
    int c = 1;
    while(c <= n){
        expande_fatorial(c);
        c++;
    }
}

int main(){
    fatoriais(5);
    return 0;
}