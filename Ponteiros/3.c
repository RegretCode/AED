#include <stdio.h>

/* 3. Escreva um programa que contenha duas variaveis inteiras. Leia essas variaveis do 
teclado. Em seguida, compare seus enderecos e exiba o conteudo do maior endereco.*/

int main(){
    int a, b;

    printf("Digite um valor para a: \n");
    scanf("%d", &a);
    printf("Digite um valor para b: \n");
    scanf("%d", &b);

    printf("%p\n", &a);
    printf("%p\n", &b);

    if (&a > &b){
        printf("%p", &a);
    } else {
        printf("%p", &b);
    }
}