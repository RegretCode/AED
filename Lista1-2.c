#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu(void);
void listar(char *listarNomes, int qtdNomes);


int main(){

    int qtdNomes = 0, escolha, 
    char *listarNomes = NULL;

    while (1) {
    escolha = menu();
    switch (escolha) {
    case 1:
        listar(listarNomes, qtdNomes);
        break;
      
    case 2:
        break;

    case 3:
        break;
    
    case 4:
        if (qtdNomes > 0) {
            free(listarNomes);
        }
      exit(0);
    
   
  }

    void listar(char *listarNomes, int qtdNomes){
        if (qtdNomes == 0){
            printf("nao existem nomes na lista!\n");
        } else {
            printf("nomes: %s\n", ListaNomes);
        }
    }

    int menu(void){
        int escolhe = 0;

        do{
            printf("-------Menu-------\n");
            printf("1. Listar nome: \n");
            printf("2. Adcionar nome: \n");
            printf("3. Remover nome: \n");
            printf("4. Sair. \n");
            scanf("%d", &escolha);
        }while(escolhe < 1 || escolhe > 4);
        getchar();
        return escolha;
        
    }
    
}


