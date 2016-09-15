#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct bnode {
	int data;
	struct bnode *left;
	struct bnode *right;
}TREE;

bool is_binary_search_tree(TREE *node, int min, int max){
	
	if(node == NULL){
		return true;
	}

	if(node->data < min || node->data > max){
		return false;
	}

	int left = is_binary_search_tree(node->left, min, node->data);
	int right = is_binary_search_tree(node->right, node->data, max);

	return (left && right);
}

TREE* newBNode(int data){
	TREE* node = (TREE*)calloc(sizeof(TREE), 1);
	node->data = data;

	return node;
}

int main(){
	TREE *head = newBNode(25);

	head->left = newBNode(12);
	head->right = newBNode(37);

	head->left->left = newBNode(6);
	head->left->left = newBNode(18);

	head->right->left = newBNode(32);
	head->right->right = newBNode(45);

	printf("\nResult:%d\n", is_binary_search_tree(head, INT_MIN, INT_MAX));

	return 0;
}