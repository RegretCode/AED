#include <stdio.h>

/* 4. Faca um programa que leia 2 valores inteiros e chame uma funcao que receba estas
2 variaveis e troque o seu conteudo, ou seja, esta funcao e chamada passando duas
variaveis A e B por exemplo e, apos a execucao da funcao, A contera o valor de B e B 
tera o valor de A.*/

void trocaConteudo(int *a, int *b){
    int ac;
    if(*a != *b){
        ac = *a;
        *a = *b;
        *b = ac;
    } else {
        printf("Ambas possuem o msm valor \n");
    }
}

int main(){
    int v1 = 6, v2 = 7;

    trocaConteudo(&v1, &v2);

    printf("v1 = %d, v2 = %d", v1, v2);


}