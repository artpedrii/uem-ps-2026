#include <stdio.h>
#include <math.h>

void impares(int n){
	int c = 0;
	while(c  <= (2*n)){  
           if (c % 2 != 0){ 
	      printf("%i ", c); 	
           }	
	   c++;
         }
}

int main(){
  impares(10);
  return 0; 
}
