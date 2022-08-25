#include <stdio.h>
#include <stdlib.h>

struct Pessoa
{
	char nome [20];
	int idade;
	int altura;
};

struct Pessoa pessoas[10];

void adiciona(void *pBuffer){
	int *contador = (int *)(pBuffer + (sizeof(int)));
	
	if (*contador == 10)
	{
		printf("Ja atingiu o maximo que pode armazenar!\n");
	} else {
		printf("Digite o nome: \n");
		scanf("%s", (char*)&pessoas[*contador].nome);
		printf("Digite a idade: \n");
		scanf("%d", &pessoas[*contador].idade);
		printf("Digite a altura: \n");
		scanf("%d", &pessoas[*contador].altura);
		*contador+=1;
	}
	
}

void listar(void *pBuffer){
	int *i = (int *)(pBuffer+sizeof(int)* 2);
	int *tamanho = (int *)(pBuffer+sizeof(int));

	*i = 0;

	while (*i < *tamanho)
	{
		printf("Nome: %s\n", pessoas[*i].nome);
		printf("Idade: %d\n", pessoas[*i].idade);
		printf("Altura: %d\n", pessoas[*i].altura);
		*i+=1;
	}
	
		
}

int main()
{
	void *pBuffer = malloc(sizeof(int)*3);

	//teste
	if (!pBuffer){
		printf("Erro ao alocar\n");
		exit(1);
	}

	*(int *)pBuffer = 0;
	pBuffer = pBuffer + sizeof(int);//menu
	*(int *)pBuffer = 0;
	pBuffer = pBuffer + sizeof(int);//contador
	pBuffer = pBuffer - sizeof(int);
	pBuffer = pBuffer - sizeof(int);

	while (1)
	{
		printf("1-) Adicionar \n");
		printf("2-) Listar \n");
		scanf("%d",(int *)pBuffer);

		if (*(int *)pBuffer == 1)
		{
			adiciona(pBuffer);
		} else {
			listar(pBuffer);
		}
		

	}
	
	
}