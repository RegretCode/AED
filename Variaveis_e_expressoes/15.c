#include <stdio.h>

/*15. Leia um angulo em radianos e apresente-o convertido em graus. A formula de conversao
e: G = R ∗ 180/π, sendo G o angulo em graus e R em radianos e π = 3.14*/

int main(){
float g, r;
    printf("Digite o angulo em radianos que deseja converter em graus: \n");
    scanf("%f", &r);
    g = r * (180/3.14);
    printf("Conversao para graus: %.2f", g);
}