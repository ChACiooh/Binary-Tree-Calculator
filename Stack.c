#include "Stack.h"

int isEmpty_stack(Stack *stack)
{
	if(!stack) {
		puts("the stack doesn't exist.");
		return TRUE;
	}
	return stack->topNode == NULL;
}

StackNode* make_stack_node()
{
	StackNode *tmp = (StackNode*)calloc(sizeof(StackNode), 1);
	if(!tmp){
		puts("memory is full-using.");
		exit(1);
	}
	return tmp;
}

Stack* make_stack()
{
	Stack *tmp = (Stack*)calloc(sizeof(Stack), 1);
	if(!tmp) {
		puts("memory is full-using.");
		exit(1);
	}
	return tmp;
}

void print_stack_node(StackNode *tNode)
{
	if(!tNode)	return;
	if(tNode->isChar){
		printf("%c", tNode->data.opr);
	}
	else{
		printf("%g", tNode->data.num);
	}
}

void push(Stack *stack, Data datum, int isChar)
{
	StackNode *tmp = make_stack_node();
	if(!tmp) {
		puts("memory is full-using.");
		exit(1);
	}
	tmp->data = datum;
	tmp->isChar = isChar;
	tmp->pNode = stack->topNode;
	stack->topNode = tmp;
}

StackNode pop(Stack *stack)
{
	StackNode res;
	res.data = dummy_data;
	res.isChar = FALSE;
	if(!stack || isEmpty_stack(stack))	return res;
	res = *(stack->topNode);
	StackNode *tmp = stack->topNode;
	stack->topNode = tmp->pNode;
	free(tmp);
	return res;
}

void remove_stack(Stack *stack)
{
	StackNode sn;
	while(!isEmpty_stack(stack)) {
		sn = pop(stack);
		print_stack_node(&sn);
	}
}
