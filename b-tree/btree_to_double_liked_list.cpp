#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
	int data;
	struct tnode* left;
	struct tnode* right;
}TREE;

TREE *newNode(int data){
	TREE *node = (TREE*) calloc(sizeof(TREE), 1);
	node->data = data;
	return node;
}

void convert_tree_to_dll(TREE *root){

	if(root->left){

		TREE *tmp;
		while(tmp=root->left; tmp->right!= NULL; tmp = tmp->right);
		tmp->right = root;
		root->left = tmp;
	}
	
	if(root->right){

		TREE *tmp;
		while(tmp=root->right; tmp->left!= NULL; tmp = tmp->left);
		tmp->left = root;
		root->right = tmp;
	}
}

void print_dll(TREE *head){

	while(head){
		printf("%d ", head->data); head = head->right;
	}
}

int main(){

	TREE *head = newNode(34);
	head->left = newNode(23);
	head->right = newNode(4);

	head->left->left = newNode(39);
	head->left->right = newNode(8);

	head->right->left = newNode(87);
	head->right->right = newNode(72);

	convert_tree_to_dll(head);

	while(head->left){
		head = head->left;
	}

	print_dll(head);

	return 0;
}