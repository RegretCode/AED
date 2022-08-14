#include <stdio.h>

/*13. Leia uma distancia em quilometros e apresente-a convertida em milhas. A formula de
conversao e: M = K /1,61 , sendo K a distancia em quil ˆ ometros e ˆ M em milhas.*/

int main(){
    float m, k;
    printf("Digite a distancia em quilometros que deseja converter em milhas: \n");
    scanf("%f", &k);
    m = k / 1.609;
    printf("Conversao para km: %.2f", m);
}