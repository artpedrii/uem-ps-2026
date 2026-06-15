#include <stdio.h>

int main(){
	
	float comprimento = 0.0;
	float largura = 0.0;
	printf("Escreva o comprimento: ");
	scanf("%f", &comprimento);
	printf("Escreva a largura: ");
	scanf("%f", &largura);
	
	if (comprimento == largura){
		printf("Quadrado.\n");
	}

	else{
		printf("Retângulo.\n");
	}

}
