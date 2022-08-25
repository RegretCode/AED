#include <stdio.h>
#include <stdlib.h>

/* 2. Faca um programa que leia do usuario o tamanho de um vetor a ser lido e faca a alocacao˜
dinamica de memoria. Em seguida, leia do usuario seus valores e imprima o vetor lido*/

int main()
{
	int *vetor, tamanho, i;

	printf("Digite o tamanho do vetor que deseja ler: \n");
	scanf("%d", &tamanho);

	vetor = (int *)malloc(tamanho * (sizeof(int)));

	for ( i = 0; i < tamanho; i++)
	{
		printf("Insira vetor[%d]\n", i+1 );
		scanf("%d", &vetor[i]);
	}

	for ( i = 0; i < tamanho; i++)
	{
		printf("\n%d\n", vetor[i]);
	}
	
	system("pause");
	free(vetor);

	
}