#include <stdio.h>
#include <stdlib.h>

//EXERCICIO 2)
char *somente_consoante(char t[]){
    int nova_palavra_tam = 0;
    int i = 0;
    while (t[i] != '\0'){
        if ((t[i] != 'A' || t[i] != 'a') && (t[i] != 'E' || t[i] != 'e') && (t[i] != 'I' || t[i] != 'i') && (t[i] != 'O' || t[i] != 'o') && (t[i] != 'U' || t[i] != 'u')){
            nova_palavra_tam++;
        }
        i++;
    }

    char *p_p = malloc((nova_palavra_tam  + 1) * (sizeof(char)));

    i = 0; 
    int j = 0;
    while (t[j] != '\0') {
       if ((t[j] != 'A' && t[j] != 'a') && (t[j] != 'E' && t[j] != 'e') && (t[j] != 'I' && t[j] != 'i') && (t[j] != 'O' && t[j] != 'o') && (t[j] != 'U' && t[j] != 'u')){
            p_p[i] = t[j];
            i++;
        } 
        j++;
    }
    p_p[i] = '\0';

    return p_p;
}

int main(){
    //exer1
    char p1[] = "copa"; 
    char p2[] = "cabana"; 
    char *p_a = malloc(11 * sizeof(char)); 
    for (int i = 0; i < 10; i++){
        if (i < 4) {
            p_a[i] = p1[i]; 
        }
        else {
            p_a[i] = p2[i - 4];
        }
        if (i == 11){
            p_a[i] = '\0';
        }
    }
    //exer2
    char p3[] = "xetelba";
    char p4[] = "gremio"; 
    char *pTemp1 = somente_consoante(p3);
    char *pTemp2 = somente_consoante(p4);
    
    //exer2
    int k = 0;
    while (pTemp1[k] != '\0'){
        printf("%c", pTemp1[k]);
        k++;
    }

    k = 0;
    while (pTemp2[k] != '\0'){
        printf("%c", pTemp2[k]);
        k++;
    }

    free(p_a);
    p_a = NULL;

    free(pTemp1);
    pTemp1 = NULL;

    free(pTemp2);
    pTemp2 = NULL;


    return 0;
}