
#include<stdio.h>

void printa_linha(int n){
	int i;
	for (i = 1; i <= n; i++){
		printf("%d", i);
}
}

void piramide(int n){
        int i;
        for (i = 1; i <= n; i++){
                printa_linha(i);
                printf("\n");
        }
}

int main(){
	piramide(5);
	return 0;
}
