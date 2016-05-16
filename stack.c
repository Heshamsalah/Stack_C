/*

 * Author: Hesham Salah
 * Email: heshamsalahuldeen@gmail.com
 * Linkedin: https://eg.linkedin.com/in/heshamsalahuldeen
 * Github: https://github.com/Heshamsalah

 * Implementation of a stack using Arrays
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct stack
{
	int top;
	unsigned capacity;
	int *array;
}stack;

stack *createStack(unsigned capacity); /* Create a new stack of size "capacity" */
bool isFull(stack *stack); /* Checks the stack is full or not */
bool isEmpty(stack *stack); /* Checks the stack is empty or not */
void push(stack *stack, int newItem); /* Adds new item to the Stack */
int pop(stack *stack); /* Removes the last added item to the stack */
int peak(stack *stack); /* Get the most top item of the stack */

int main()
{
	stack *newStack = createStack(100); /* Create a stack with a size of 100 items*/
	int i;
	for (i = 0; i < 20; i++)
	{
		/* push(newStack, i); */
	}
	
	printf("%d %s\n", pop(newStack), "is removed!");
	printf("%d %s\n", peak(newStack), "is the most top value!");
	return 0;
}

stack *createStack(unsigned capacity){
	stack *newStack = (stack*) malloc(sizeof(stack)); /* Create a new stack and allocate memory for it */
	newStack->capacity = capacity; /* Set the capacity of the stack with the given capacity */
	newStack->top = -1; /* The stack is empty */
	newStack->array = (int*) malloc(newStack->capacity * sizeof(int)); /* allocate some memory for the array of 
																	the stack where malloc() takes the size of memory in bytes*/
	return newStack;
}

bool isFull(stack *stack){
	return stack->top == (stack->capacity - 1);  /* The top of a stack is equal to the stack capacity */
}

bool isEmpty(stack *stack){
	return stack->top == -1; /* The top of the stack is equal to -1 when empty */
}

void push(stack *stack, int newItem){
	if(isFull(stack)) return; /* checks first to see if the stack is full */
	stack->array[++stack->top] = newItem; /* Increment the top of the stack by 1 the add the new item to the array of that top */
	printf("%d %s\n", stack->array[stack->top],"New Item Added");
}

int pop(stack *stack){
	if(isEmpty(stack)) return INT_MIN; /* If the stack is empty then nothing to remove */
	return stack->array[stack->top--]; /* The main idea is to decease the top by 1 */
}

int peak(stack *stack){
	if(isEmpty(stack)) return INT_MIN;
	return stack->array[stack->top];
}