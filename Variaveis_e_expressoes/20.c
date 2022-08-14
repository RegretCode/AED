#include <stdio.h>

/*20. Leia um valor de massa em quilogramas e apresente-o convertido em libras. A formula
de conversao e: L = K /0,45 , sendo K a massa em quilogramas e L a massa em libras.*/

int main(){
    float k, l;
    printf("Digite o valor da  massa em quilogramas que deseja converter em libras: \n");
    scanf("%f", &k);
    l = k/0.45;
    printf("Convertido em libras: %.3f", l);
}