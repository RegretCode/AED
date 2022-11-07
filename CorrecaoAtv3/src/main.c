#include <stdio.h>
#include <stdlib.h>

/*===============================================================================================================================================
Nome: Ricardo Coutinho Cordeiro - RGM: 19200371 - Atv3 - Doom 3 Code Style Conventions

Criar uma árvore binária de busca, após o usuario inserir os dados reconhecer se a mesma é avl ou não

===============================================================================================================================================*/

typedef struct node {
    int data;
    struct node *left, *right;
}Node;

//---------functions------------------
Node* newNode(int value);
Node* insert(Node* root, int value);
void isAVL(Node* root);
int altura(Node* root);
void clear(Node* root);

int main(void){

    int selector, valor;
    Node* root = NULL;

    do
    {
        printf("\n0- Sair.\n1- Inserir valor na arvore: \n2- Verificar se é AVL.\n");
        scanf("%d", &selector);
        switch (selector)
        {
        case 0:
			clear(root);
            printf("Saindo...");
            system("exit");
            break;
        case 1:
            printf("Digite o valor que deseja inserir: \n");
            scanf("%d", &valor);
            root = insert(root, valor); //faltava o ponteiro raiz receber o novo valor a ser inserido
            break;
        case 2:
            isAVL(root);
            break;
        default:
            printf("Não é uma opção!");
            break;
        }
    } while (selector);
    
    return 0;
}

Node* newNode(int value){

    Node* new = (Node*)malloc(sizeof(Node));
    if (new){

        new->data = value;
        new->left = NULL;
        new->right = NULL;
    }

    else {
        printf("Error alocating newNode!\n");
    }
    return new;
}

Node* insert(Node* node, int value){
    
    if (node == NULL){
        return newNode(value);
    }

    else if (value < node->data){
        node->left = insert(node->left, value);
    }

    else if (value > node->data){
        node->right = insert(node->right, value);
    }

    else {
        printf("Não foi possivel inserir\n");
    }

    return node;   
}


/*Para a arvore ser avl é necessario saber sua altura e se ela é balanceada*/
void isAVL(Node* root){//mudanca

	int left, right;

    if (root == NULL){
		printf("É AVL!\n");
	}

	else {
		left = altura(root->left);
		right = altura(root->right);


		if ((left - right) > 1 || (left - right) < -1){
			printf("Não é AVL!\n");
		}

		else {
			printf("É AVL!\n");

		}
		
	}
}

int altura(Node *root){//mudanca
	int left, right;

	if (root == NULL){
		return 0;
	}

	else {
		left = altura(root->left);
		right = altura(root->right);

		if (left > right){
			return left + 1;
		}

		else {
			return right + 1;
		}
		
	}
	
}

void clear(Node* root){ //mudanca
	if (!root){
		return;
	}
	clear(root->left);
	clear(root->right);
	free(root);
	
}