#include <stdio.h>

int main(){
    int a = 0;
    int b = 0;
    int c = 0;
    printf("Escreva o primeiro número: ");
    scanf("%i", &a);
    printf("Escreva o segundo número: ");
    scanf("%i", &b);
    printf("Escreva o terceiro número: ");
    scanf("%i", &c);

    if (a == b || a == c || b == c){
        printf("os números têm que ser distintos.");
    }
    else {
        if (a < b && b < c){
            printf("%i %i %i", a , b , c);
        }
        else {
            if (a < b && c < b){
                printf("%i %i %i", a , c , b);
            }
            else {
                if (b < a && a < c){
                    printf("%i %i %i", b , a , c);
                }
                else {
                    if (b < a && c < a){
                        printf("%i %i %i", b , c , a);
                    }
                    else {
                        if (c < a && a < b){
                            printf("%i %i %i", c , a , b);
                        }
                        else{
                            if (c < a && b < a){
                                printf("%i %i %i", c , b , a);
                            }
                        }
                    }
                }
            }
        }
    }
}