#include <stdio.h>
#include <stdlib.h>

/* 10. Faca um programa que pergunte ao usuario quantos valores ele deseja armazenar em
um vetor de double, depois use a funcao MALLOC para reservar (alocar) o espaco de
memoria de acordo com o especificado pelo usuario. Esse vetor deve ter um tamanho
maior ou igual a 10 elementos. Use este vetor dinamico como um vetor comum, atribuindo aos 10 primeiros
elementos do vetor valores aleatorios (usando a funcao rand)
entre 0 e 100. Exiba na tela os valores armazenados nos 10 primeiros elementos do
vetor.*/

int main()
{
	double *vetor;
	int tamanho, i;

	printf("Digite o tamanho de um vetor, que seja >= 10: \n");
	scanf("%d", &tamanho);

	vetor = (double *)malloc(tamanho * (sizeof(double)));

		if (!vetor)
    {
        printf("Memória não alocada.");
        return 1;
    }

	for ( i = 0; i < tamanho; i++)
	{
		vetor[i] = rand() % 100;

		printf("v[%0.lf]\n", vetor[i]);
	}

	system("pause");
	free(vetor);

}