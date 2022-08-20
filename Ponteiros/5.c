#include <stdio.h>

/* 5. Faca um programa que leia dois valores inteiros e chame uma funcao que receba estes 
2 valores de entrada e retorne o maior valor na primeira variavel e o menor valor na 
segunda variavel. Escreva o conteudo das 2 variaveis na tela.*/

void maiorPrimeiro (int *a, int *b){
    int ac;
    if (*a < *b){
        ac = *a;
        *a = *b;
        *b = ac;
    } else {
        printf("O valor do primeiro ja eh maior.\n");
    }
}

int main (){
    int v1 = 10, v2 = 200;

    maiorPrimeiro(&v1, &v2);

    printf("v1 = %d, v2 = %d", v1, v2);
}