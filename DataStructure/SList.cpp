#include "stdafx.h"
#include "SList.h"

#include <stdlib.h>
#include <iostream>
using namespace std;

void SListInitial(SListNode **head)
{
	if (NULL == (*head = (SListNode *)malloc(sizeof(SListNode))))
	{
		cout << "malloc space error..." << endl;
		exit(-1);
	}
	(*head)->next = NULL;
}

int GetSListSize(SListNode *head)
{
	int size = 0;
	SListNode *pTemp = head;
	while (NULL != pTemp->next)
	{
		pTemp = pTemp->next;
		++size;
	}
		
	return size;
}

int InsertSListData(SListNode *head, const int pos, DataType data)
{
	SListNode *p = head;
	int i = -1; // Í·½áµã
	while (NULL != p->next && i < pos - 1)
	{
		p = p->next;
		++i;
	}

	if (i != pos - 1)
	{
		cout << "insert pos error..." << endl;
		return -1;
	}

 	SListNode *q = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == q)
	{
		cout << "malloc space error..." << endl;
		exit(-1);
	}

	q->data = data;
	q->next = p->next;
	p->next = q;
	return 0;
}

int DeleteSListData(SListNode *head, const int pos, DataType *data)
{
	SListNode *p = head;
	int i = -1;
	while (NULL != p->next && NULL != p->next->next && i < pos - 1)
	{
		p = p->next;
		++i;
	}

	if (i != pos - 1)
	{
		cout << "delete pos error..." << endl;
		return -1;
	}

	SListNode *q = p->next;
	*data = q->data;
	p->next = p->next->next;
	free(q);
	q = NULL;
	return 0;
}

int GetSListData(SListNode *head, const int pos, DataType *data)
{
	SListNode *p = head;
	int i = -1;
	while (NULL != p->next && i < pos)
	{
		p = p->next;
		++i;
	}

	if (i != pos)
	{
		cout << "pos error..." << endl;
		return -1;
	}

	*data = p->data;
	return 0;
}

void DestroySList(SListNode **head)
{
	SListNode *p = *head;
	SListNode *q = NULL;
	while (NULL != p)
	{
		q = p;
		p = p->next;
		free(q);
		q = NULL;
	}
	*head = NULL;
}
