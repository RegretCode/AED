#include <stdio.h>

/*21. Leia um valor de massa em libras e apresente-o convertido em quilogramas. A formula
de conversao e: K = L∗ 0, 45, sendo K a massa em quilogramas e L a massa em libras.*/

int main(){
    float k, l;
    printf("Digite o valor da  massa em libras que deseja converter em quilogramas: \n");
    scanf("%f", &l);
    k = l*0.45;
    printf("Convertido em libras: %.3f", k);
}