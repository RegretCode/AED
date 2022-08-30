#include <stdio.h>
#include <stdlib.h>

/* 8. Crie um programa que contenha um array de float contendo 10 elementos. Imprima o
endereco de cada posicao desse array. */

int main()
{
	float vetorDez[10];
	float *p;
	p = vetorDez;

	for (int i = 0; i < 10; i++)
	{
		vetorDez[i] = rand();
		printf("v[%d] = %f \n", i, vetorDez[i]); //mostra a posicao e o valor armazenado
		printf("Endereco: v[%d] = %p\n", i, p); //mostra a posicao do vetor e o endereco baseado no float *p(ponteiro float) e dps incrementa o p, oq faz andar para a proxima posicao de memoria.
		p++;
		
	}

	system("pause");

	
}