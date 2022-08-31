#include <stdio.h>
#include <stdlib.h>

/* 9. Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
Imprima o endereco de cada posicao dessa matriz. */

int main()
{
	float matriz[3][3] = {{15.6, 17.700, 18.5}, {14.9, 1.2, 3.75}, {5.5, 6.6, 7.8}};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("Endereco: %p \n", &matriz[i][j]);
		}
	}

	system("pause");

}