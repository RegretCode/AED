#include <stdio.h>

/*
===============================================================================================================================================
Nome: Ricardo Coutinho Cordeiro - RGM: 19200371 - Atv4 - Doom 3 Code Style Conventions

Dado um vetor nums contendo n número inteiros positivos e únicos encontre o número faltante na sequência. Assuma que somente um número está 
faltando para completar a sequência numérica.

Exemplo 1:
Entrada: nums = [3, 0, 1]
Saída: 2
Explicação: n = 3 já que existem 3 números, então todos os números estão no intervalo
[0,3]. 2 é o número ausente no intervalo, pois não aparece em nums.

Exemplo 2:
Entrada: nums = [0, 1]
Saída: 2
Explicação: n = 2 já que existem 2 números, então todos os números estão no intervalo
[0,2]. 2 é o número ausente no intervalo, pois não aparece em nums.

Exemplo 3:
Entrada: nums = [9,6,4,2,3,5,7,0,1]
Saída: 8

Explicação: n = 9 já que existem 9 números, então todos os números estão no intervalo
[0,9]. 8 é o número ausente no intervalo, pois não aparece em nums.

A complexidade da resposta não pode ser superior a O(nlogn)
Dica, existe uma solução O(n)
===============================================================================================================================================
*/

int main(void){
    int size = 0;
    int sumA = 0;
    int sumB = 0;

	printf("Insert vector size: \n");
    scanf("%d", &size);
    int vector[size];
    

    for (int i = 1; i < size; i++){
        printf("Insert a number: \n");
        scanf("%d", &vector[i]);
        sumA += vector[i];
    }

    for (int i = 0; i < size; i++){
        sumB += i;
    }
    
    int aux = sumB - sumA;
    printf("Missing number: %d\n", aux);
    
	system("pause");
    
    return 0;
}