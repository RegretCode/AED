#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
===============================================================================================================================================

Nome: Ricardo Coutinho Cordeiro - RGM: 19200371 - AGENDA/Semana 5 - Doom 3 Code Style Conventions

1-Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar, 
porém, toda a informação incluída na agenda deve ficar num único lugar chamado: “void *pBuffer”.

2-Não pergunte para o usuário quantas pessoas ele vai incluir. Não pode alocar espaço para mais pessoas do que o necessário.

3-Cada pessoa tem nome[10], idade e telefone. 

4-Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.
Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.

5-Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro).

6-Não pode usar struct em todo o programa.

7-Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.

8-Implementar a base de dados da agenda usando lista duplamente ligada

9-Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.

===============================================================================================================================================
Person:
Name (sizeof(char) * 10) // Age(sizeof(int)) // Phone(sizeof(int))
*/

//=====================================FUNCTIONS=====================================
void menu(void *pBuffer);
void search(void *pSentinel, void *pStart, void *pBuffer);
void *insertContact(void *pBuffer, void *pNodo, void *pSentinel);
void *delete(void *pSentinel, void *pStart);
void list(void *pSentinel, void *pStart);
void *empty(void *pSentinel, void *pStart);

//=======================================CONSTS======================================
#define NAME (sizeof(char)*10)
#define AGE (sizeof(int))
#define PHONE (sizeof(int))
#define PREVIOUS (sizeof(void **))
#define NEXT (sizeof(void **))

#define SELECTOR (sizeof(int))
#define COUNTER (sizeof(int))
#define AUX (sizeof(char)*10)

#define LAST (sizeof(void **))
#define FIRST (sizeof(void **))


int main(){
	void *pStart = NULL;
	void *pNodo = NULL;

	void *pSentinel = malloc (FIRST + LAST);
	void *pBuffer = malloc (SELECTOR + COUNTER + AUX);

	if (!pBuffer || !pSentinel)
	{
		printf("Memory error. Could not allocate required memory!\n");
        exit(0);
	}
	
	*(int *)(pBuffer + SELECTOR) = 0; //Inicialazing the counter as 0

	do
	{
		menu(pBuffer); //Displaying the menu for the user
		switch (*(char *)(pBuffer))
		{
		case '1': //Search - option
		if (*(int *)(pBuffer + SELECTOR) == 0) //Checking the number of contacts in the phonebook
		{
			printf("There are no contacts!\n");
			break;
			
		} else
		{
			search(pSentinel, pStart, pBuffer);
			break;
		}
		
		case '2': //Insert Contact - option
			*(int *)(pBuffer + SELECTOR) = *(int *)(pBuffer + SELECTOR) + 1; //Adding 1 in counter
			pSentinel = insertContact(pBuffer, pNodo, pSentinel);
			break;

		case '3': //Delete the first contact - option
			if (*(int *)(pBuffer + SELECTOR) == 0) //Checking the number of contacts in the phonebook
			{
				printf("There are no contacts!\n");
				break;
				
			} else
			{
				pSentinel = delete(pSentinel, pStart);
				*(int *)(pBuffer + SELECTOR) = *(int *)(pBuffer + SELECTOR) - 1;
				break;

			}
			
			
		case '4': //List contacts - option
			if (*(int *)(pBuffer + SELECTOR) == 0) //Checking the number of contacts in the phonebook
			{
				printf("There are no contacts!\n");
				break;
				
			} else
			{
				list(pSentinel, pStart);
 				break;

			}

		case '5': //Clear pointer - option
			if (*(int *)(pBuffer + SELECTOR) == 0) //Checking the number of contacts in the phonebook
			{
				free(pSentinel);
				free(pBuffer);
				
			} else
			{
				pSentinel = (void*)empty(pSentinel, pStart);
				free(pSentinel);
				free(pBuffer);
				
			}
			exit(0);
 				break;
			
		default:
			printf("Not an option!\n");
			break;
		}

	} while (*(int *)pBuffer > 0 || *(int *)pBuffer < 6); //While selector is greater than 0 and less than 6
	
}

void menu(void *pBuffer){
	printf("\n========================\n");
	printf("=======CONTACTS=======\n");
	printf("1-) Search contact: \n");
	printf("2-) Add contact: \n");
	printf("3-) Delete contact: \n");
	printf("4-) List contacts: \n");
	printf("5-) Exit. \n");
	printf("========================\n");
	printf("========================\n");
	scanf("%s", ((char *)(pBuffer)));
	getchar();
}

void search(void *pSentinel, void *pStart, void *pBuffer){
	
	printf("\nType a name to search: ");
	scanf("%s", (char *)(pBuffer + SELECTOR + COUNTER)); //Store in the AUX position for future comparison
	pStart = *(void **)pSentinel; //It sets the pointer pStart to the address of the first byte of the pSentinel
	printf("Searching..........\n");


	while (pStart != NULL)
	{
		if (strcmp(pStart, (char*)(pBuffer + SELECTOR + COUNTER)) == 0) //It compares the string in the buffer with the string in the buffer AUX
		{
			printf("\n============================\n");
			printf("========CONTACT==FOUND========\n");
			printf("Name: %s\n", (char *) pStart); //
			printf("Age: %d\n", *(int *)(pStart + NAME));
			printf("Phone: %d\n", *(int *)(pStart + NAME + AGE));
			printf("============================\n");
			printf("============================\n");

			return;

		}
		pStart = *(void **)(pStart + NAME + AGE + PHONE + LAST); //It moves the pointer to the next element
		
	}
	printf("========CONTACT=NOT=FOUND========\n");

	return;
	
}

void *insertContact(void *pBuffer, void *pNodo, void *pSentinel){

	pNodo = malloc (NAME + AGE + PHONE + PREVIOUS + NEXT);

	if (!pNodo)
	{
		printf("Memory error. Could not allocate required memory!\n");
        exit(1);
	}

	void *pTracer;
	void *aux;
	
	printf("==================================\n");
	printf("===========REGISTRATION===========\n");
	printf("\nInsert Name: ");
	scanf("%s",(char*)(pNodo));
	printf("\nInsert Age: ");
	scanf("%d",(int*)(pNodo + NAME));
	printf("\nInsert Phone: ");
	scanf("%d",(int*)(pNodo + NAME + AGE));
	printf("\n===============END===============\n");
	printf("==================================\n");

	*(void **)(pNodo + NAME + AGE + PHONE) = NULL; //The PREVIOUS  position in the node will receive NULL
	*(void **)(pNodo + NAME + AGE + PHONE + PREVIOUS) = NULL; //The NEXT  position in the node will receive NULL

	if (*(int*)(pBuffer + SELECTOR) == 1) //If the number of contacts is equal to 1
	{
		*(void **) pSentinel = pNodo; 
		*(void **)(pSentinel + FIRST) = pNodo; 
	} else if (*(int *)(pBuffer + SELECTOR) != 1) // If COUNTER != 1
		{
			*(int *)(pBuffer) = 1;
			pTracer = *(void **)pSentinel; 

			while (pTracer != NULL)
			{
				if (strcmp((char *)pNodo, (char *)pTracer) < 0) //Compares the char from pNodo with the char from pTracer
				{
					if (*(int *)(pBuffer) == 1)
					{
						*(void **)(pNodo + NAME + AGE + PHONE + PREVIOUS) = pTracer;
						*(void **)(pTracer + NAME + AGE + PHONE) = pNodo;
						*(void **)(pNodo + NAME + AGE + PHONE) = NULL;
						*(void **) pSentinel = pNodo;
						*(int *)(pBuffer) = 1;

						return pSentinel;

					} else {
						aux = *(void **)(pTracer + NAME + AGE + PHONE);
						*(void **)(aux + NAME + AGE + PHONE + PREVIOUS) = pNodo;
						*(void **)(pNodo + NAME + AGE + PHONE) = aux;
						*(void **)(pNodo + NAME + AGE + PHONE + PREVIOUS) = pTracer;
						*(void **)(pTracer + NAME + AGE + PHONE) = pNodo;
						*(int *)(pBuffer) = 1;

						return pSentinel;

					}
					
				}
				
				*(int *)(pBuffer) = *(int *)(pBuffer) + 1;
				pTracer = *(void **)(pTracer + NAME + AGE + PHONE + PREVIOUS);

			}
			
			if (*(int *)(pBuffer) >= *(int *)(pBuffer + SELECTOR)) //Checks if the int on pBuffer is greater than or equal to the COUNTER
			{
				pTracer = *(void **)(pSentinel + FIRST); 
				*(void **)(pTracer + (NAME + AGE + PHONE + PREVIOUS)) = pNodo;
				*(void **)(pNodo + NAME + AGE + PHONE) = pTracer;
				*(void **)(pSentinel + FIRST) = pNodo;
				*(int *)(pBuffer) = 1;

				return pSentinel;

			}			
		
		}

		return pSentinel;	

}

void *delete(void *pSentinel, void*pStart){

	pStart = *(void**)pSentinel;
	*(void **) pSentinel = *(void **)(pStart + NAME + AGE + PHONE + PREVIOUS);
	free(pStart);
	*(void **)(pSentinel + NAME + AGE + PHONE) = NULL; 
	printf("DONE!\n");
	
	return pSentinel;
}

void list(void *pSentinel, void *pStart){

	pStart = *(void **)pSentinel;

	while (pStart != NULL)
	{
		printf("\n===============================\n");
		printf("=============LISTING============\n");
		printf("Name: %s\n", (char *) pStart);
		printf("Age: %d\n", *(int *)(pStart + NAME));
		printf("Phone: %d\n", *(int *)(pStart + NAME + AGE));
		printf("================================\n");
		printf("================================\n");
		pStart = *(void **)(pStart + NAME + AGE + PHONE + PREVIOUS);
		
	}
	
	return;
}

void *empty(void *pSentinel, void *pStart){

	pStart = *(void **)pSentinel;

	do
	{
		*(void **) pSentinel = *(void **) (pStart + NAME + AGE + PHONE + PREVIOUS);
		free(pStart);
		pStart = *(void **) pSentinel;
	} while (pStart != NULL);

	
	free(pStart);
	return pStart;
}