#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Ricardo Coutinho Cordeiro - RGM: 19200371
Faça um programa que solicita do usuário uma série de números, cada número pode ser um
int, float ou double. Antes de solicitar o número pergunte qual tipo de dado o usuário vai entrar.
Todos os números entrados devem ser armazenados num buffer único. Esse buffer deve ter tamanho
dinâmico e não deve desperdiçar memória, por exemplo, alocar sempre espaço para um double
quando o usuário inserir um int ou float.
Você não deve solicitar para o usuário quantos números ele deseja entrar, na escolha do tipo
de dados coloque uma opção para parar a entrada da série de números. Após isso você deve imprimir
todos os números do buffer, primeiro toda a série em sequência depois novamente, mas primeiro os
ints seguido dos floats e doubles.*/

int main() {
	int tam=0,tipo,entrada=0,auxTamanho=0;
	void *pBuffer = malloc(sizeof(double));
	int *pOrdem = malloc (sizeof(int)); //ajudar na hora de listar
	int n;
	float f;
	double d;

	while ( 1 ) {
		printf("\nEscolha um tipo:\n");	
		printf("\n1 int: ");	
		printf("\n2 float: ");	
		printf("\n3 Double: \n");	
		scanf("%d",&tipo);
		getchar();

		switch ( tipo ) {
			case 1:
				printf("\nDigite int: ");
				scanf("%d",&n);	
				getchar();
				tam+=sizeof(int);
				pBuffer = realloc(pBuffer,tam);
				*(int *)(pBuffer+tam-sizeof(int))=n; //pega o pbuffer e cada vez q adc ele recebe o num adcionado
				break;

			case 2:
				printf("\nDigite float: ");	
				scanf("%f",&f);
				getchar();
				tam+=sizeof(float);
				pBuffer = realloc(pBuffer,tam);
				*(float *)(pBuffer+tam-sizeof(float))=f;
				break;

			case 3:
				printf("\nDigite double: ");
				scanf("%lf",&d);	
				getchar();
				tam+=sizeof(double);
				pBuffer = realloc(pBuffer,tam);
				*(double *)(pBuffer+tam-sizeof(double))=d;
				break;
                
			default:
				for (int i = 0; i < entrada; i++){
					if (*(pOrdem+i)==1){
						printf(" [ %d ] ",*(int*)(pBuffer+auxTamanho));
						auxTamanho+=sizeof(int);
					} else if (*(pOrdem+i)==2) {
						printf(" [ %f ] ",*(float*)(pBuffer+auxTamanho));
						auxTamanho+=sizeof(float);
					} else if (*(pOrdem+i)==3) {
						printf(" [ %lf ] ",*(double*)(pBuffer+auxTamanho));
						auxTamanho+=sizeof(double);
					}
				}

				auxTamanho=0;

				system("pause");
				system("cls");

				for (int i = 0; i < entrada; i++){
					if (*(pOrdem+i)==1){
						printf(" [ %d ] ",*(int*)(pBuffer+auxTamanho));
						auxTamanho+=sizeof(int);
					} else if (*(pOrdem+i)==2) {
						auxTamanho+=sizeof(float);
					} else auxTamanho+=sizeof(double);
				}
				auxTamanho=0;
			
				for (int i = 0; i < entrada; i++){
					if (*(pOrdem+i)==1){
						auxTamanho+=sizeof(int);
					} else if (*(pOrdem+i)==2) {
						printf(" [ %f ] ",*(float*)(pBuffer+auxTamanho));
						auxTamanho+=sizeof(float);
					} else auxTamanho+=sizeof(double);
				}
				auxTamanho=0;

				for (int i = 0; i < entrada; i++){
					if (*(pOrdem+i)==1){
						auxTamanho+=sizeof(int);
					} else if (*(pOrdem+i)==2) {
						auxTamanho+=sizeof(float);
					} else if (*(pOrdem+i)==3) {
						printf(" [ %lf ] ",*(double*)(pBuffer+auxTamanho));
						auxTamanho+=sizeof(double);
					}
				}
					
				system("pause");

				exit(0);
				break;
		}

		*(pOrdem+entrada)=tipo; //
		entrada++;

		pOrdem = (int*) realloc(pOrdem,sizeof(int)*(entrada+1));

	}
}