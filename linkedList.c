#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node * next;
};

void list_print(struct node * head)
{
	while(head != NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

void list_free(struct node * head)
{
	if(head == NULL)
	{
		return;
	}
	else
	{
		list_free(head->next);
		free(head);
	}
}

struct node * reverse(struct node * previousNode, struct node * currentNode)
{
	if(currentNode->next == NULL)
	{
		currentNode->next = previousNode;
		return currentNode;
	}
	else
	{
		struct node * nextNode = currentNode->next;
		currentNode->next = previousNode;
		return reverse(currentNode, nextNode);
	}
}

int main()
{
	int i;
	struct node * currentNode;
	struct node * previousNode = malloc(sizeof(struct node));
	struct node * head = previousNode;
	previousNode->data = 0;
	for(i = 0; i < 10; i++)
	{
		struct node * currentNode = malloc(sizeof(struct node));
		currentNode->next = NULL;
		currentNode->data = i+1;
		previousNode->next = currentNode;
		previousNode->data = i;
		previousNode = currentNode;
	}
	head = reverse(NULL, head);
	list_print(head);
	return 0;
}