#include <stdio.h>
#include <string.h>

/* 3. Construa uma estrutura aluno com nome, numero de matrıcula e curso. Leia do usuario 
a informacao de 5 alunos, armazene em vetor dessa estrutura e imprima os dados na tela.
*/

struct aluno
{
	char nome[20], numM[20], curso[20];
};


int main()
{
	struct aluno a[5];

	int i; 

	for (i = 0; i < 5; i++)
	{
		strcpy(a[i].nome, "NULL");
		strcpy(a[i].numM, "NULL");
		strcpy(a[i].curso, "NULL");
	}
	
	for (i = 0; i < 5; i++)
	{
		printf("Digite o nome do aluno numero %d: \n", i+1);
		scanf("%s", a[i].nome);
		getchar();
		printf("Digite o numero de matricula do aluno numero %d: \n", i+1);
		scanf("%s", a[i].numM);
		getchar();
		printf("Digite o curso do aluno numero %d: \n", i+1);
		scanf("%s", a[i].curso);
		getchar();
	}
	
	for ( i = 0; i < 5; i++)
	{
		printf("\nNome: %s ", a[i].nome);
		printf("\nMatricula: %s ", a[i].numM);
		printf("\nCurso: %s ", a[i].curso);
	}
	
}