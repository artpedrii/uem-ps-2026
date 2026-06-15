#include <stdio.h>
#include <math.h>

int digitos(int a){
    int quantidade_digitos = 0;
    if (a == 0){
        quantidade_digitos = 1;
    }
    else{
        while (a > 0){
            a = (a - (a % 10))/10;
            quantidade_digitos++;
        }
    }
    return quantidade_digitos;
}

int encontra_ultimo_digito(int n){
    int ultimo_digito = n % 10;
    return ultimo_digito; 
}

int potenciacao(int n, int m){
    int result_fim = 1;
    while (m > 0){
        result_fim = result_fim * n;
        m--;
    }
    return result_fim;
}

int narcisista(int b){
    int i = 0;
    int expoente = digitos(b);
    int temp = b;
    int soma = 0;
    for (i = 0; i < expoente; i++){
        int digito_separado = encontra_ultimo_digito(temp);
        temp = temp / 10; 
        soma = soma + potenciacao(digito_separado, expoente);
    }
    if (soma == b){
        return 1;
    }
    else{
        return 0;
    }
}    

int main(){
    int i = 0;
    for (i = 100; i < 10000; i++){
        if (narcisista(i) == 1){
            printf("%i ", i);
        }
    }

    return 0;
}