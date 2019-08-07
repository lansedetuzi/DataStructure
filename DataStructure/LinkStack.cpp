#include "stdafx.h"
#include "LinkStack.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

void LinkStackInit(LSNode **head)
{
	if (NULL == (*head = (LSNode *)malloc(sizeof(LSNode))))
	{
		cout << "malloc error..." << endl;
		return;
	}
	(*head)->next = NULL;
}

bool LinkStackEmpty(LSNode *head)
{
	return (head == NULL) || (head->next == NULL);
}

int LinkStackPush(LSNode *head, DataType data)
{
	LSNode *p = NULL;
	if (NULL == (p = (LSNode *)malloc(sizeof(LSNode))))
	{
		cout << "malloc error..." << endl;
		return -1;
	}

	p->data = data;
	p->next = head->next;
	head->next = p;
	return 0;
}

int LinkStackPop(LSNode *head, DataType &data)
{
	LSNode *p = head;
	if (NULL == p->next)
	{
		cout << "stack empty" << endl;
		return -1;
	}
	LSNode *q = head->next;
	data =q->data;
	p->next = p->next->next;
	free(q);
	q = NULL;
	return 0;
}

int LinkStackTop(LSNode *head, DataType &data)
{
	LSNode *p = head;
	if (NULL == p->next)
	{
		cout << "stack empty" << endl;
		return -1;
	}

	data = p->next->data;
	return 0;
}

void LinkStackDestoy(LSNode **head)
{
	LSNode *p = *head;
	LSNode *q = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
		q = NULL;
	}

	*head = NULL;
}
