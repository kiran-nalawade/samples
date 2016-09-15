#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}NODE;

NODE* nodeh;

int bsumtree(NODE *n){
	
	if(n == NULL) return 0;
	
	int left = bsumtree(n->left);
	int right = bsumtree(n->right);
	
	int nodeval = n->data;
	
	n->data = left + right + ((n->left != NULL) ? n->left->data : 0) + ((n->right != NULL) ? n->right->data : 0);
	
	return nodeval;
}

void printInorder(NODE *n)
{
     if (n == NULL)
          return;
     printInorder(n->left);
     printf("%d ", n->data);
     printInorder(n->right);
}
 
/* Utility function to create a new Binary Tree node */
NODE* newNode(int data)
{
  NODE* temp = (NODE*)calloc(sizeof(struct node), 1);
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
 
  return temp;
}

int tmain(int argc, char** argv) {
  int x;
 
  /* Constructing tree given in the above figure */
  nodeh = newNode(10);
  nodeh->left = newNode(-2);
  nodeh->right = newNode(6);
  nodeh->left->left = newNode(8);
  nodeh->left->right = newNode(-4);
  nodeh->right->left = newNode(7);
  nodeh->right->right = newNode(5);
 
   // Print inorder traversal of the converted tree to test result of toSumTree()
  printf("Inorder Traversal of the resultant tree is: \n");
  printInorder(nodeh);
  
  bsumtree(nodeh);
 
  // Print inorder traversal of the converted tree to test result of toSumTree()
  printf("\n\nInorder Traversal of the resultant tree is: \n");
  printInorder(nodeh);
  return 0;
}
