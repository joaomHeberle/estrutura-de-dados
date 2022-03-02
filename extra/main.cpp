#include <stdio.h>
#include <stdlib.h>

int soma(int valor){
 
 if(valor==0){
 
	return (0);
}	
	return soma(valor-1)+valor;
	
}



int main(int argc, char *argv[]) {
	int resultado = 0;
	int valor=0;
	printf("digite o valor para a soma recursiva:");
	scanf("%d",&valor);
	resultado = soma(valor);
	printf(" a soma e igual : %d", resultado);
	
	return 0;
}
