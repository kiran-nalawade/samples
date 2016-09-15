#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
	int data;
	struct tnode *left;
	struct tnode *right;
}TREE;

typedef struct list{
	int data;
	struct list *next;
}LIST;

TREE* newTNode(int data){
	TREE* node = (TREE*)calloc(sizeof(TREE), 1);
	node->data = data;
	
	return node;
}

LIST* newLNode(int data){
	LIST* node = (LIST*)calloc(sizeof(LIST), 1);
	node->data = data;
	
	return node;
}

void diagonalSum(TREE *tnode, LIST *lnode){
	
	lnode->data += tnode->data;
	
	if(tnode->left){
		LIST *leftnode = lnode->next;
		
		if(leftnode == NULL) 
			leftnode = newLNode(0);
			
		lnode->next = leftnode;
		diagonalSum(tnode->left, leftnode);
	}
	
	if(tnode->right){
		diagonalSum(tnode->right, lnode);
	}
}

int main(){

	TREE *thead = newTNode(10);
	
	thead->left = newTNode(-2);
	thead->right = newTNode(8);
	
	thead->left->left = newTNode(6);
	thead->left->right = newTNode(-4);
	
	thead->right->left = newTNode(9);
	thead->right->right = newTNode(10);

	LIST *lhead = newLNode(0);
	
	diagonalSum(thead, lhead);
	
	while(lhead){
		printf("%d ", lhead->data);
		lhead = lhead->next;
	}
	
	return 0;
}
