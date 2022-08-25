#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char nome[30];
	int idade;
	int altura;
}Pessoa;

int contador = 0;

void *adiciona(Pessoa *pBuffer){

	if(contador>9)
		realloc(pBuffer,(sizeof(Pessoa)*contador)+1);

	Pessoa p;
	printf("Digite o Nome: \n");
	scanf("%s",p.nome);
	printf("Digite a idade: \n");
	scanf("%d",&p.idade);
	printf("Digite a altura: \n");
	scanf("%d",&p.altura);
	pBuffer+=(contador*sizeof(Pessoa));
	*pBuffer = p;
	contador++;
	return(NULL);
}

void listar(Pessoa *pBuffer){

	for (int i = 0; i < contador; i++)
	{
		printf("Nome: %s\n", (char *)pBuffer);
		printf("Idade: %d\n", pBuffer->idade);
		printf("Altura: %d\n", pBuffer->altura);
		pBuffer+=sizeof(Pessoa);
	}
	
}

int main(){

	//Pessoa entrada;
	Pessoa *pBuffer = malloc(sizeof(Pessoa) * 10);

	int selector;

	//teste
	if(!pBuffer){
        printf("Erro de memória!");
        exit(1);
    }
    
	while ( 1 ){
        printf("Digite 1 para adicionar ou 0 para listar e sair: \n");
        scanf("%d", &selector);

        if (selector==1){
			adiciona(pBuffer);		
        }
        else {
            listar(pBuffer);
			free(pBuffer);
            system("pause");
            break;
        }
    }
	
}