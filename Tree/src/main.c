#include <stdio.h>
#include <stdlib.h>

//declaring a binary tree
typedef struct node{
	int data;
	struct node *left, *right;
}Node;

typedef struct{
	Node* root;
	int size;
}BinTree;

//functions
Node* new_node(int value);
Node* PUSH(Node* node, int value);
int size(Node* root);
Node* search(Node** bin_tree, int value);
Node* POP(Node* root, int value);
void printPreOrder(Node* bin_tree);
void printInOrder(Node* bin_tree);
void printPostOrder(Node* bin_tree);

int main(void){

	Node* root = NULL;
	Node* aux;
	root = PUSH(root, 10);
	PUSH(root, 30);
	PUSH(root, 25);
	PUSH(root, 36);
	PUSH(root, 56);
	PUSH(root, 78);

	printPreOrder(root);
	printf("\n");
	printInOrder(root);
	printf("\n");
	printPostOrder(root);
	printf("\n");

	aux = search(&root, 55); //change the value here

	if (aux){
		printf("Searched node: %d\n", aux->data);
	}
	else {
		printf("Data not found in tree.\n");
	}	

	system("pause");
}



Node* new_node(int value){
	Node* aux = (Node*)malloc(sizeof(Node));
	aux->data = value;
	aux->left = NULL;
	aux->right = NULL;

	return aux;
}

Node* PUSH(Node* node, int value){

	if (node == NULL){
		return new_node(value);
	}

	if (value < node->data){
		node->left = PUSH(node->left, value);
	}

	else if (value > node->data){
		node->right = PUSH(node->right, value);
	}
	
	return node;	
	
}

int size(Node* root){
	if (root == NULL){
		return 0;
	}

	else {
		return 1 + size(root->left) + size(root->right);
	}	
	
}

Node* search(Node** bin_tree, int value){
	if (!(*bin_tree)){
		return NULL;
	}

	else if (value == (*bin_tree)->data){
		return *bin_tree;
	}

	else if (value < (*bin_tree)->data){
		search(&((*bin_tree)->left), value);
	}

	else if (value > (*bin_tree)->data){
		search(&((*bin_tree)->right), value);
	}
	
	
}

Node* POP(Node* root, int value){
	if (root == NULL){
		printf("Value not found!\n");
		return NULL;
	}
	else {
		if (root->data == value){ //removes the external node

			if (root->left == NULL && root->right == NULL){
				free(root);
				return NULL;
			}

			else {

				if (root->left == NULL || root->right == NULL){ //removes a internal node with a least one child branch
					Node* aux;

					if (root->left != NULL){
						aux = root->left;
					}
					else {
						aux = root->right;
					}
					
					free(root);
					return aux;
					
				}

				else { 
					Node* aux = root->left;

					while (aux->right != NULL)
					{
						aux = aux->right;
					}
					root->data = aux->data;
					aux->data = value;
					root->left = POP(root->left, value);
					return root;

				}
				
			}
			
			
		} 
		else {
			if (value < root->data){
				root->left = POP(root->left, value);
			}

			else {
				root->right = POP(root->right, value);
			}

			return root;		
			
		}
		
		
	}
	
	
}

void printPreOrder(Node* bin_tree){
	if (bin_tree){
		printf("%d\n", bin_tree->data);
		printPreOrder(bin_tree->left);
		printPreOrder(bin_tree->right);
	}
	
}

void printInOrder(Node* bin_tree){
	if (bin_tree){
		printInOrder(bin_tree->left);
		printf("%d\n", bin_tree->data);
		printInOrder(bin_tree->right);
	}
	
}

void printPostOrder(Node* bin_tree){
	if (bin_tree){
		printPostOrder(bin_tree->left);
		printPostOrder(bin_tree->right);
		printf("%d\n", bin_tree->data);
	}
	
}

