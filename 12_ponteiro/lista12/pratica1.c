#include <stdio.h>

 int main(){
    char a = 'x';
    float b = 1.23;
    int c = 4567;

    char *p_a = &a;
    float *p_b = &b;
    int *p_c = &c;

    printf("%c\n%0.2f\n%i\n", *p_a, *p_b, *p_c);

    return 0;
 }