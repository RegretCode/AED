#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_ELEMENTS 10

typedef struct node{
	char color;
	int data;
	struct node *leftChild, *rightChild, *parent;
}Node;

void leftRotation(Node** root, Node* aux);
void rightRotation(Node** root, Node* auy);
void FixUp(Node** root, Node* auz);
void insert(Node** root, int data);
void inOrder(Node* root);

int main(void)
{
	srandom(time(NULL));

	Node* root = NULL;

	clock_t t0 = clock();
	for (int i = 0; i < NUMBER_ELEMENTS; i++)
	{
		insert(&root, random());
	}
	clock_t t1 = clock();
	printf("Inorder Traversal is: \n");
	inOrder(root);
	printf("\n");

	float time_taken = (float)(t1 - t0) / CLOCKS_PER_SEC * 1000;
	printf("Insertion took %fms -> %fus/elen\n", time_taken, time_taken / NUMBER_ELEMENTS * 1000);
	
	system("pause");

	return (0);
}

void leftRotation(Node** root, Node* aux){

	if (!aux || !aux->rightChild){
		return ;
	}

	Node* auy = aux->rightChild;
	aux->rightChild = auy->leftChild;

	if (aux->rightChild != NULL){
		aux->rightChild->parent = aux;
	}
	
	auy->parent = aux->parent;

	if (aux->parent == NULL){
		(*root) = auy;
	}
	
	else if (aux == aux->parent->leftChild){ // store auy at place of aux
		aux->parent->leftChild = auy;
	}
	
	else {
		aux->parent->rightChild = auy;
	}
	
	auy->leftChild = aux; // aux leftChild of auy
	aux->parent = auy; // update parent pointer of aux
	
}

void rightRotation(Node** root, Node* auy){

	if (!auy || !auy->leftChild)
	{
		return ;
	}
	
	Node* aux = auy->leftChild;
	auy->leftChild = aux->rightChild;

	if (aux->rightChild != NULL){
		aux->rightChild->parent = auy;
	}
	aux->parent = auy->parent;

	if (aux->parent == NULL){
		(*root) = aux;
	}
	
	else if (auy = auy->parent->leftChild){
		auy->parent->leftChild = aux;
	}

	else {
		auy->parent->rightChild = aux;
	}

	aux->rightChild = auy;
	auy->parent = aux;

}

void FixUp(Node** root, Node* auz){

	while (auz != *root && auz != (*root)->leftChild && auz != (*root)->rightChild && auz->parent->color == 'R')
	{
		Node* auy;

		if (auz->parent && auz->parent->parent && auz->parent == auz->parent->parent->leftChild){
			auy = auz->parent->parent->rightChild;
		}
		
		else {
			auy = auz->parent->parent->leftChild;
		}

		if (!auy){
			auz = auz->parent->parent;
		}

		else if (auy->color = 'R'){
			auy->color = 'B';
			auz->parent->color = 'B';
			auz->parent->parent->color = 'R';
			auz = auz->parent->parent;
		}
		
		else {
			if (auz->parent == auz->parent->parent->leftChild && auz == auz->parent->leftChild){
				char ch = auz->color;
				auz->parent->color = auz->parent->parent->color;
				auz->parent->parent->color = ch;
				rightRotation(root, auz->parent->parent);
			}
			
			if (auz->parent && auz->parent->parent && auz->parent == auz->parent->parent->leftChild && auz == auz->parent->rightChild){
				char ch = auz->color;
				auz->color = auz->parent->parent->color;
				auz->parent->parent->color = ch;
				leftRotation(root, auz->parent);
				rightRotation(root, auz->parent->parent);
			}
			
			if (auz->parent && auz->parent->parent && auz->parent == auz->parent->parent->rightChild && auz == auz->parent->rightChild){
				char ch = auz->parent->color;
				auz->parent->color = auz->parent->parent->color;
				auz->parent->parent->color = ch;
				leftRotation(root, auz->parent->parent);
			}
			
			if (auz->parent && auz->parent->parent && auz->parent == auz->parent->parent->rightChild && auz == auz->parent->leftChild){
				char ch = auz->color;
				auz->color = auz->parent->parent->color;
				auz->parent->parent->color = ch;
				rightRotation(root, auz->parent);
				leftRotation(root, auz->parent->parent);
			}
			
		}		
		
	}
	
	(*root)->color = 'B';

}

void insert(Node** root, int data){
	Node* auz = (Node*)malloc(sizeof(Node));
	auz->data = data;
	auz->leftChild = NULL;
	auz->rightChild = NULL;
	auz->parent = NULL;

	if (*root == NULL){
		auz->color = 'B';
		(*root) = auz;
	}

	else {
		Node *auy = NULL;
		Node *aux = (*root);

		while (aux != NULL){
			
			auy = aux;

			if (auz->data > aux->data)
			{
				aux = aux->leftChild;
			}

			else {
				aux = aux->rightChild;
			}
		
		}

		auz->parent = auy;
		if (auz->data > auy->data){
			auy->rightChild = auz;
		}
		
		else {
			auy->leftChild = auz;
		}
		
		auz->color = 'R';
		FixUp(root, auz);
	}
		
}

void inOrder(Node* root){
	int last = 0;

	if (root == NULL){
		return ;
	}

	inOrder(root->leftChild);
	printf("%d", root->data);

	if (root->data < last){
		printf("\nPUTE\n");
	}
	last = root->data;
	inOrder(root->rightChild);
	
}