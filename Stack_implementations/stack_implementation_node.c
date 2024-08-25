#include <stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int val;
	struct Node * next;
}node;

node * head = NULL;

node * create_node(int data)
{
	node * newnode = (node *)malloc(sizeof(node));
	newnode -> val = data;
       	newnode -> next = NULL;
	return newnode;       
}

void push(int data)
{
	node * newnode = create_node(data);
	if(head == NULL)
	{
		head = newnode;
		return;
	}
	newnode -> next = head;
	head = newnode;
	return;
}

int pop()
{
	if(head == NULL)
	{
		return 0;
	}
	int num = (head)->val;
	head = (head)->next;
	return num;
}

void printStack()
{
	node * temp = head;
	while(temp != NULL)
	{
		printf("%d ",(temp)->val);
		temp = temp->next;
	}
	printf("\n");
}
int main()
{
	push(10);
	push(20);
	printStack();
	printf("%d\n",pop());
	printf("%d\n",pop());
	printStack();
	return 0;
}
