#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Fazer um programa que testa se uma sequencia de caracteres fornecida pelo usuario eh um 
palindromo, ou seja, eh uma palavra cuja a primeria metade eh simetrica a segunda metade. 
Veja os exemplos:

AABCCBAA - sim
ADDFDDA - sim
ABFFBB - nao

O usuario digita uma letra e tecla enter ate que o ele digite x e enter para terminar a sequencia.

Implemente a funcao POP e PUSH de pilha e resolva o problema com elas.  
NO video demonstre pelo menos 4 casos de sim e 4 casos de nao*/

typedef struct {
  int topo;
  char letras[10];
} Pilha;

Pilha* pilha;

void RESET() {
  pilha->topo = 0;
}

void PUSH(char letra) {
  pilha->letras[pilha->topo] = letra;
  pilha->topo++;
}

char POP() {
  pilha->topo--;
  return pilha->letras[pilha->topo];
}

void LIST() {
  for (int i = pilha->topo - 1; i >= 0; i--)
    printf("%i - %c\n", i, pilha->letras[i]);
}

void palindromo() {
  char entradaDoUsuario[10];
  printf("Digite uma palavra: ");
  scanf("%s", entradaDoUsuario);

  for (int i = 0; i < strlen(entradaDoUsuario); i++)
    PUSH(entradaDoUsuario[i]);

  printf("Palavra Digitada: %s\n", entradaDoUsuario);
  printf("Palavra na Pilha: \n");
  LIST();

  char *resultado = "É um Palíndromo";
  for (int i = 0; i < strlen(entradaDoUsuario); i++)
    if (entradaDoUsuario[i] != POP())
      resultado = "Não é um Palíndromo";

  printf("%s\n", resultado);
}

int main() {
  palindromo();
}