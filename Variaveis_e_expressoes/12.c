#include <stdio.h>

/*12. Leia uma distancia em milhas e apresente-a convertida em quilometros. A formula de
conversao e: K = 1, 61 ∗ M, sendo K a distancia em quilometros e M em milhas.*/

int main(){
    float m, k;
    printf("Digite a distancia em milhas que deseja converter em quilometros: \n");
    scanf("%f", &m);
    k = m * 1.609;
    printf("Conversao para km: %.2f", k);
}