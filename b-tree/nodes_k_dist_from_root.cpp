#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
	int data;
	struct tnode *left;
	struct tnode *right;
}TREE;

TREE* newNode(int data){
	TREE *node = (TREE*)calloc(sizeof(TREE), 1);
	node->data = data;
	return node;	
}

void nodes_at_k(TREE *node, int k){
	if(node == NULL) return;
		
	if(k == 0){
		printf("%d ", node->data);
		return;
	}
	
	nodes_at_k(node->left, k-1);
	nodes_at_k(node->right, k-1);
}

int main(){
	
	TREE *head = newNode(1);
	head->left = newNode(2);
	head->right = newNode(3);
	head->left->left = newNode(4);
	head->left->right = newNode(5);
	head->right->left = newNode(6);
	head->right->right = newNode(7);
	
	nodes_at_k(head, 3);	
		
	return 0;
}
