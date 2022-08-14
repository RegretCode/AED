#include <stdio.h>

/*19. Leia um valor de volume em litros e apresente-o convertido em metros cubicos m^3. A
formula de conversao e: M = L/1000 , sendo L o volume em litros e M o volume em metros
cubicos.*/

int main (){
    float l, m;
    printf("Digite o valor em litros que deseja converter em metros cubicos: \n");
    scanf("%f", &l);
    m = l/1000;
    printf("Convertido em metros cubicos: %.2f", m);
}