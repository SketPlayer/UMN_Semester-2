#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node {
	char data;
	struct Node *left, *right;
}Node;

Node *newNode(char item) {
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *node, char data) {
	if (node == NULL) {
		return newNode(data);
	}
	
	Node *temp = newNode(data);
	
	if (data == '-'|| data == '+' || data == '*' || data == '/') {
		if (temp->left != NULL) {
			temp->left = node;
        	return temp;
		}
		else {
			temp->right = node;
			return temp;
		}
	}
	else if (data >= 'a' && data <= 'z') {
		if (node->left == NULL) {
			node->left = insert(node->left, data);
		} else if (node->left != NULL) {
			node->right = insert(node->right, data);
		}
	}
	return node;
}

void printInorder(Node *root){
	if(root != NULL) {
		printInorder(root->left);
		printf("%c ", root->data);
		printInorder(root->right);
	}
}

int main(){
	char math[20];
	int i = 0;
	Node *root = NULL;
	
	printf("Insert Mathematic Expression : ");
	scanf("%s", math);
	
	while (math[i] != '\0') {
      root = insert(root, math[i]);
      i++;
   	}
	
	printf("\n");
	printInorder(root);
	
	return 0;
}
