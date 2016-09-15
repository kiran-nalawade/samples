#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
	int data;
	struct tnode *left;
	struct tnode *right;
}TREE;

#define MAX(a,b) ((a>b)?a:b)

int heightOfTree(TREE *node){
	
	if(node == NULL) return 0;
	
	int left = heightOfTree(node->left);
	int right = heightOfTree(node->right);
	
	return (1 + MAX(left, right));
}

void spiralBtree(TREE *node, int level, int dir){
	
	if(node == NULL) return;
	if(level == 0) printf("%d ", node->data);
	
	if(dir == 0){
		spiralBtree(node->left, level-1, dir);
		spiralBtree(node->right, level-1, dir);
	}
	if(dir == 1){
		spiralBtree(node->right, level-1, dir);
		spiralBtree(node->left, level-1, dir);
	}
}

void SpiralTREE(TREE *node){
	
	int height = heightOfTree(node);
	int counter;
	int dir = 1;
	for(counter = 0; counter<height; counter++){
		spiralBtree(node, counter, dir);
		dir = (dir+1)%2;
	}
}

TREE* newTNode(int data){
	TREE* node = (TREE*)calloc(sizeof(TREE), 1);
	node->data = data;
	return node;
}

int main(){
	
	TREE *head = newTNode(1);
	head->left = newTNode(2);
	head->right = newTNode(3);
	head->left->left = newTNode(6);
	head->left->right = newTNode(7);
	head->right->left = newTNode(5);
	head->right->right = newTNode(4);
	
	SpiralTREE(head);
	
	return 0;
}
