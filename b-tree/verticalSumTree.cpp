#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
	int data;
	struct tnode *left;
	struct tnode *right;
}TREE;

typedef struct dlnode{
	int data;
	struct dlnode *next;
	struct dlnode *prev;
}DLIST;

TREE* newTNode(int data){
	TREE* node = (TREE*)calloc(sizeof(TREE), 1);
	node->data = data;
	return node;
}

DLIST* newDLNode(int data){
	DLIST* node = (DLIST*)calloc(sizeof(DLIST), 1);
	node->data = data;
	return node;
}

void verticalSumBTree(TREE *tnode, DLIST* lnode){
	
	lnode->data += tnode->data;
	
	if(tnode->left){
		DLIST *prev = lnode->prev;
		if(prev == NULL){
			prev = newDLNode(0);
		}
		prev->next = lnode;
		lnode->prev = prev;
		
		verticalSumBTree(tnode->left, prev);
	}
	
	if(tnode->right){
		DLIST* nxt = lnode->next;
		if(nxt == NULL){	
			nxt = newDLNode(0);
		}
		nxt->prev = lnode;
		lnode->next = nxt;
				
		verticalSumBTree(tnode->right, nxt);
	}

}

int main(){

	TREE *thead; DLIST* dlhead, *rightList, *leftList;
	
	thead = newTNode(10);
	thead->left = newTNode(-2);
	thead->right = newTNode(4);
	
	thead->left->left = newTNode(8);
	thead->left->right = newTNode(6);
	
	thead->right->left = newTNode(5);
	thead->right->right = newTNode(9);
	
	dlhead = newDLNode(0);
	
	verticalSumBTree(thead, dlhead);

	rightList = dlhead; leftList = dlhead->next;

	while(rightList){
		dlhead = rightList;
		rightList = rightList->prev;
	}

	while(dlhead){
		printf("%d ", dlhead->data); 
		dlhead = dlhead->next;
	}	
	
	return 0;
}
