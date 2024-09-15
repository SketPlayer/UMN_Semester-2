#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node{
	int key, height;
	struct Node *left, *right;
}Node;

int height(struct Node *N) {
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b) {
	return (a > b)? a : b;
}

Node *newNode(int item){
	Node *temp = (Node*) malloc(sizeof(Node));
	temp->key = item;
	temp->left = temp->right = NULL;
	temp->height = 1;
	return temp;
}

Node *leftRotate(Node *x) {
	Node *y = x->right;
	Node *T2 = y->left;
	
	y->left = x;
	x->right = T2;
	
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;
	
	return y;
}

Node *rightRotate(Node *y) {
	Node *x = y->left;
	Node *T2 = x->right;
	
	x->right = y;
	y->left = T2;
	
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
	
	return x;
}

int getBalance(Node *N) {
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

Node *insert(Node *node, int key){
	if (node == NULL)
		return newNode(key);
		
	if (key < node->key)
		node->left = insert(node->left, key);
	
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;
	
	node->height = 1 + max(height(node->left), height(node->right));
	
	int balance = getBalance(node);
	
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);
		
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);
		
	if (balance > 1 && key > node->left->key) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	
	if (balance < -1 && key < node->right->key) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	
	return node;
}

void printPreorder(Node *root){
	if(root != NULL) {
		printf("%d ", root->key);
		printPreorder(root->left);
		printPreorder(root->right);
	}
}

void printInorder(Node *root){
	if(root != NULL) {
		printInorder(root->left);
		printf("%d ", root->key);
		printInorder(root->right);
	}
}

void printPostorder(Node *root){
	if(root != NULL) {
		printPostorder(root->left);
		printPostorder(root->right);
		printf("%d ", root->key);
	}
}

Node* minValueNode(Node* root){
	Node* current = root;
	while (current && current->left != NULL)
		current = current->left;
		
	return current;
}

Node* deleteNode(Node* root, int key){
	if (root == NULL)
		return root;
		
	if (key < root->key)
		root->left = deleteNode(root->left, key);
		
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	
	else {
		if (root->left == NULL) {
			Node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			Node *temp = root->left;
			free(root);
			return temp;
		}
		
		Node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

int main(){
	Node *root = NULL;
	
	root = insert(root, 50);
	insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	
	printf("Base Tree\n");
	printf("Preorder	: "); printPreorder(root); printf("\n");
	printf("Inorder		: "); printInorder(root); printf("\n");
	printf("Postorder	: "); printPostorder(root); printf("\n\n");
	
	printf("Deleting node 20\n");
	deleteNode(root, 20);
	printf("Preorder	: "); printPreorder(root); printf("\n");
	printf("Inorder		: "); printInorder(root); printf("\n");
	printf("Postorder	: "); printPostorder(root); printf("\n\n");
	
	printf("Deleting node 30\n");
	deleteNode(root, 30);
	printf("Preorder	: "); printPreorder(root); printf("\n");
	printf("Inorder		: "); printInorder(root); printf("\n");
	printf("Postorder	: "); printPostorder(root); printf("\n\n");
	
	printf("Deleting node 70\n");
	deleteNode(root, 70);
	printf("Preorder	: "); printPreorder(root); printf("\n");
	printf("Inorder		: "); printInorder(root); printf("\n");
	printf("Postorder	: "); printPostorder(root); printf("\n\n");
	
	return 0;
}
