#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
	int data;
	struct tnode *left;
	struct tnode *right;
}TNODE;

typedef struct levelnodes{
	int data;
	struct levelnodes* next;
}ListNode;

typedef struct levelListNode{
	int level;
	int nodecount;
	struct levelListNode *next;
	struct levelnodes *nodes;
}LevelListNode;

TNODE *thead;

TNODE* newtnode(int data){
	TNODE *newnode = (TNODE*)calloc(sizeof(TNODE), 1);
	newnode->data = data;
	return newnode;
}

LevelListNode* newLevelListNode(int level){
	LevelListNode *newnode = (LevelListNode*)calloc(sizeof(LevelListNode), 1);
	newnode->level = level;
	return newnode;
}

ListNode* newListNode(int data){
	ListNode *newnode = (ListNode*)calloc(sizeof(ListNode), 1);
	newnode->data = data;
	return newnode;
}

LevelListNode *maxNodesList, *head; int maxNodes;

void findMaxNodes(TNODE *tn, int level, LevelListNode *n){
	LevelListNode *current;
	ListNode *newnode;
	
	if(tn == NULL) return;
	
	if(n == NULL){
		head = newLevelListNode(level);
		current = head;
	}else if(n->next == NULL){
		n->next = newLevelListNode(level);
		current = n->next;
	}else{
		current = n->next;
	}
	
	newnode = newListNode(tn->data);
	newnode->next = current->nodes;
	current->nodes = newnode;
	current->nodecount++;
	if(current->nodecount > maxNodes){
		maxNodesList = current;
		maxNodes = current->nodecount;
	}
	
	findMaxNodes(tn->left, level+1, current);
	findMaxNodes(tn->right, level+1, current);	
}

int main(int argc, char** argv) {
	
	thead = newtnode(10);
	thead->left = newtnode(-2);
	thead->right = newtnode(6);
	thead->left->left = newtnode(8);
	thead->left->right = newtnode(-4);
	thead->right->left = newtnode(7);
	thead->right->right = newtnode(-5);
	
	findMaxNodes(thead, 0, NULL);
	
	LevelListNode *next, *curr;
	curr = head;
	while(curr){
		next = curr->next;
		if(curr != maxNodesList)
			free(curr);
		curr = next;
	}
	
	printf("\n Level %d has max nodes(%d).\n", maxNodesList->level, maxNodesList->nodecount);
	ListNode *list = maxNodesList->nodes, *nextListnode;
	while(list){
		printf("%d ", list->data);
	 	nextListnode = list->next;
	 	free(list);
	 	list = nextListnode;
	}
	
	free(maxNodesList);

	return 0;
}
