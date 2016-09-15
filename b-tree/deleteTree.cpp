#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
	int data;
	struct tnode *left;
	struct tnode *right;
}TREE;

void delete_tree(TREE *node){

	if(node == NULL) return;
	
	delete_tree(node->left);
	delete_tree(node->right);
	
	printf("\n node %d deleted.", node->data);
	
	free(node);
}

void _count_leaf_nodes(TREE *node, int *count){
	
	if(node->left == NULL && node->right == NULL) (*count)++;
	else{
		if(node->left)
			_count_leaf_nodes(node->left, count);
		if(node->right)
			_count_leaf_nodes(node->right, count);	
	}
}

int count_leaf_nodes(TREE *head){
	int count = 0;
	_count_leaf_nodes(head, &count);
	return count;	
}

TREE* newNode(int data){
	TREE* node = (TREE*)calloc(sizeof(TREE), 1);
	node->data = data;
	return node;
}

int main(){
	
	TREE *head = newNode(4);
	int count;
	
	head->left = newNode(5);
	head->right = newNode(3);
	
	head->left->left = newNode(7);
	head->left->right = newNode(2);
	
	head->right->left = newNode(1);
	head->right->right = newNode(0);
	
	/*delete_tree(head);
	printf("\Tree deleted completely\n");*/

	count = count_leaf_nodes(head);
	printf("There are %d leaf nodes.", count);
	return 0;
}


