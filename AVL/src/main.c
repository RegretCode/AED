#include <stdio.h>
#include <stdlib.h>

//declaring a binary tree
typedef struct node{
	int data;
	struct node *left, *right;
	int height;
}Node;


//---------------Functions------------------
Node* new_node(int value);
short greater(short a, short b);
int height(Node* node);
short balanceFactor(Node* node);
Node* rotationLeft(Node* root);
Node* rotationRight(Node* root);
Node* rotationLeftRight(Node* root);
Node* rotationRightLeft(Node* root);
Node* balance(Node* root);
Node* PUSH(Node* node, int value);
int height(Node* root);
Node* search(Node** root, int value);
Node* POP(Node* root, int value);
void printTree(Node* root, int level);


int main(void){

	int selector,  value;
	Node* root = NULL;

	do
	{
		printf("\n\n0 - Exit.\n1 - Insert: \n2 - Remove: \n3 - Print: \n");
		scanf("%d", &selector);

		switch (selector)
		{
		case 0:
			printf("Leaving...");
			system("exit");
			break;
		case 1:
			printf("Insert a number: \n");
			scanf("%d", &value);
			root = PUSH(root, value);
			break;
		case 2:
			printf("Type a number to be removed: \n");
			scanf("%d", &value);
			root = POP(root, value);
			break;
		case 3:
			printTree(root, 1);
			break;	
		default:
			printf("Not an option!\n");
		}

	} while (selector != 0);

	return 0;

}



Node* new_node(int value){
	Node* new = (Node*)malloc(sizeof(Node));

	if (new){
		new->data = value;
		new->left = NULL;
		new->right = NULL;
		new->height = 0;
	}
	
	else {
		printf("Error allocating new_node!\n");
	}

	return new;
	
}

short greater(short a, short b){
	return (a > b)? a: b;
}

int height(Node* node){
	if (node == NULL){
		return -1;
	}

	else {
		return node->height;
	}	
	
}

short balanceFactor(Node* node){
	if (node){
		return (height(node->left) - height(node->right));
	}

	else {
		return 0;
	}
		
}

Node* rotationLeft(Node* root){
	Node *aux, *son;

	aux = root->right;
	son = aux->left;

	aux->left = root;
	root->right = son;

	root->height = greater(height(root->left), height(root->right)) + 1;
	aux->height = greater(height(aux->left), height(aux->right)) + 1;

	return aux;

}

Node* rotationRight(Node* root){
	Node *aux, *son;

	aux = root->left;
	son = root->right;

	aux->right = root;
	root->left = son;

	root->height = greater(height(root->left), height(root->right)) + 1;
	aux->height = greater(height(aux->left), height(aux->right)) + 1;

	return aux;

}

Node* rotationLeftRight(Node* root){
	root->left = rotationLeft(root->left);
	return rotationRight(root);
}

Node* rotationRightLeft(Node* root){
	root->right = rotationRight(root->right);
	return rotationRightLeft(root);
}

Node* balance(Node* root){
	short bf = balanceFactor(root);

	if (bf < -1 && balanceFactor(root->right) <= 0)
	{
		root = rotationLeft(root);
	}

	else if (bf > 1 && balanceFactor(root->left) >= 0)
	{
		root = rotationRight(root);
	}
	
	else if (bf > 1 && balanceFactor(root->right) < 0)
	{
		root = rotationLeftRight(root);
	}

	else if (bf < -1 && balanceFactor(root->right) > 0)
	{
		root = rotationRightLeft(root);
	}
	
	return root;
	
}

Node* PUSH(Node* node, int value){

	if (node == NULL){
		return new_node(value);
	}

	else if (value < node->data){
		node->left = PUSH(node->left, value);
	}

	else if (value > node->data){
		node->right = PUSH(node->right, value);
	}
	
	else {
		printf("Not possible, element %d does not exist!\n", value);
	}

	node->height = greater(height(node->left), height(node->right)) + 1; //calculate tree height and all nodes between new inserted nodes and root
	node = balance(node); //verify the need to rebalance

	return node;	
	
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

				else { //removes nodes with two childs
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
			
		}
		
		root->height = greater(height(root->left), height(root->right)) + 1;
		root = balance(root);

		return root;
		
	}
	
	
}

void printTree(Node* root, int level){
	int i;

	if (root){
		printTree(root->right, level + 1);
		printf("\n\n");

		for (i = 0; i < level; i++)
		{
			printf("\t");
		}
		
		printf("%d", root->data);
		printTree(root->left, level + 1);
	}
	
	
}


