#include <stdio.h>
#include <string.h>

/* 2. Implemente um programa que leia o nome, a idade e o enderec¸o de uma pessoa e
armazene os dados em uma estrutura.*/

struct pessoa{
	char nome[10];
	int idade;
	char endereco[100];
};

int main(){

	struct pessoa p1;
	

	printf("Digite o nome da pessoa: \n");
	scanf("%s", p1.nome);
	printf("Digite a idade: \n");
	scanf("%d", &p1.idade);
	printf("Digite o endereco: \n");
	getchar();
	gets(p1.endereco);
	

	printf("%s", p1.endereco);
}