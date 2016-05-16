#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct stackNode
{
	int data;
	struct stackNode *next;
}stackNode;

stackNode *createStack(int data);
bool isEmpty(stackNode *root); /* Check if the root = NULL or not */
void push(stackNode **rootRef, int data);
int pop(stackNode **root);
int peak(stackNode **root);

int main()
{
	stackNode *root = NULL;
	int i;
	for (i = 0; i < 10; i++)
	{
		push(&root, i);
	}
	printf("%d %s\n",pop(&root), "is removed!");
	return 0;
}

stackNode *createStackNode(int data){
	stackNode * newNode = (stackNode*) malloc(sizeof(stackNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

bool isEmpty(stackNode *root){
	return !root; /* If root is NULL then empty then true else false */
}

void push(stackNode **rootRef, int data){
	stackNode *newNode = createStackNode(data);
	newNode->next = *rootRef; /* rootRef is the last node (which happen to be NULL at the beginning */
	*rootRef = newNode; /* make the root of the list = the new added node in which the root is always in top of the stack */
	printf("%d %s\n", newNode->data, "is added!");
}

int pop(stackNode **rootRef){
	if (isEmpty(*rootRef)) return -1;
	stackNode *tempNode = *rootRef;
	*rootRef = (*rootRef)->next; /* make the root point to the next node to it. */
	int dataRemoved = tempNode->data;
	free(tempNode);
	return dataRemoved;
}

int peak(stackNode *root){
	if (isEmpty(*rootRef)) return -1;
	return root->data; /* Because the root is always at the top of the stack*/
}