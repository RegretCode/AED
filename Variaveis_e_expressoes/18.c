#include <stdio.h>

/*18. Leia um valor de volume em metros cubicos m^3 e apresente-o convertido em litros. A
formula de conversao e: L = 1000 ∗ M, sendo L o volume em litros e M o volume em
metros cubicos.*/

int main (){
    float l, m;
    printf("Digite o valor em metros cubicos que deseja converter em litros: \n");
    scanf("%f", &m);
    l = 1000*m;
    printf("Convertido em litros: %.2f", l);
}