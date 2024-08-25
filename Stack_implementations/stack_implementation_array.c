#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int* arr;
	int capacity;
	int top;
};

struct stack create(int capacity)
{
	struct stack stk;
	stk.capacity = capacity;
	stk.top = -1;
	stk.arr = (int* )malloc(stk.capacity * sizeof(int));
	return stk;
}

int isFull(struct stack *stk)
{
	if(stk->top == stk->capacity-1)
	{
		return 1;
	}
	return 0;
}

int isEmpty(struct stack *stk)
{
	if(stk->top == -1)
	{
		return 1;
	}
	return 0;
}

void push(struct stack *stk,int value)
{
	if(isFull(stk))
	{
		return;
	}
	stk->arr[++stk->top]=value;
}

int pop(struct stack *stk)
{
	if(isEmpty(stk))
	{
		printf("\nStack is Empty");
		return 0;
	}
	return stk->arr[stk->top--];
}
int main()
{
	struct stack stk = create(5);
	printf("Stack created successfully..");

	push(&stk,1);
	push(&stk,2);
	push(&stk,3);
	push(&stk,4);
	printf("%d",pop(&stk));
	printf("%d",pop(&stk));
	printf("%d",pop(&stk));
	printf("%d",pop(&stk));
	printf("%d",pop(&stk));
	return 0;
}
