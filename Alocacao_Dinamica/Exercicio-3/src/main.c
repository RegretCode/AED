#include <stdio.h>
#include <stdlib.h>

/* 3. Faca um programa que leia do usuario o tamanho de um vetor a ser lido e fac¸a a alocac¸ ´ ao˜
dinamica de memoria. Em seguida, leia do usuario seus valores e mostre quantos dos ´
numeros sao pares e quantos sao ımpares.*/

int main()
{
	int *vetor, tamanho, i, par = 0, impar = 0;

	printf("Digite o tamanho do vetor que deseja ler: \n");
	scanf("%d", &tamanho);

	vetor = (int *)malloc(tamanho * (sizeof(int)));

	/*teste
	if (!vetor)
    {
        printf("Memória não alocada.");
        return 1;
    }
	*/
	for ( i = 0; i < tamanho; i++)
	{
		printf("Insira vetor[%d]\n", i+1 );
		scanf("%d", &vetor[i]);
	}

	for ( i = 0; i < tamanho; i++)
	{
		printf("\n%d\n", vetor[i]);

		if (vetor[i] % 2 == 0)
		{
			par++;
		} else {
			impar++;
		}
	}

	printf("Quantidade de par: %d | Quantidade de impar: %d\n", par, impar);
	
	system("pause");
	free(vetor);

}