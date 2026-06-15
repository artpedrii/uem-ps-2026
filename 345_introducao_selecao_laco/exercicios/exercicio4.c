#include <stdio.h>
 int main(){

	int angulo_a = 0;
	int angulo_b = 0;
	printf("Insira o valor do ângulo a: ");
	scanf("%i", &angulo_a);
	printf("Insira o valor do ângulo b: ");
	scanf("%i", &angulo_b);
        
	if ((angulo_a + angulo_b >= 0) && (angulo_a + angulo_b < 360)){
		printf("%i\n", angulo_a + angulo_b);
	}   
	else{
		printf("%i\n", (angulo_a + angulo_b) % 360);
	}

}
