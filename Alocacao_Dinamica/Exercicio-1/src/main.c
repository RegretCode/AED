#include <stdio.h>
#include <stdlib.h>

/*  1. Crie um programa que:
(a) Aloque dinamicamente um array de 5 numeros inteiros,
(b) Pec¸a para o usuario digitar os 5 numeros no espaco alocado,
(c) Mostre na tela os 5 numeros, 
(d) Libere a memoria alocada.*/

int main()
{
	int *ptr, i;

	ptr = (int *)malloc( 5 * sizeof(int));

	for ( i = 0; i < 5; i++)
	{
		printf("Insira v[%d]: \n", i+1);
		scanf("%d", &ptr[i]);
	}

	for ( i = 0; i < 5; i++)
	{
		printf("\n%d\n", ptr[i]);
	}

    system("pause");
	free(ptr);	
	
}