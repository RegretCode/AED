#include <stdio.h>

/* 2. Escreva um programa que contenha duas variaveis inteiras. Compare seus enderecos e
exiba o maior endereco.*/

int main(){
    int i = 10, j = 20;

    printf("%p\n", &i);
    printf("%p\n", &j);

    if (&i > &j){
        printf("A variavel i tem o maior endereco \n");
    } else {
        printf("A variavel j tem o maior endereco \n");
    }
}