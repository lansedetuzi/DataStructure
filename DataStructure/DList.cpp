#include "stdafx.h"
#include "DList.h"

#include <stdlib.h>
#include <iostream>
using namespace std;

void DListInitial(DListNode **head)
{
	if (NULL == (*head = (DListNode *)malloc(sizeof(DListNode))))
		exit(-1);

	(*head)->prev = *head;
	(*head)->next = *head;
}

int GetDListSize(DListNode *head)
{
	int nSize = 0;
	DListNode *p = head;
	while (p->next != head)
	{
		++nSize;
		p = p->next;
	}
	return nSize;
}

int InsertDListData(DListNode *head, const int pos, DataType data)
{
	DListNode *p = head->next;
	int i = 0;
	while (p != head && i < pos)
	{
		p = p->next;
		i++;
	}

	if (i != pos)
	{
		cout << "insert pos error..." << endl;
		return -1;
	}

	DListNode *q = nullptr;
	if (NULL == (q = (DListNode*)malloc(sizeof(DListNode))))
	{
		cout << "malloc space error..." << endl;
		exit(-1);
	}

	q->data = data;
	p->prev->next = q;
	q->prev = p->prev;
	q->next = p;
	p->prev = q;

	return 0;
}

int DeleteDListData(DListNode *head, const int pos, DataType *data)
{
	DListNode *p = head->next;
	int i = 0;
	while (p->next != head && i < pos)
	{
		p = p->next;
		i++;
	}

	if (i != pos)
	{
		cout << "delete pos error..." << endl;
		return -1;
	}

	*data = p->data;
	p->prev->next = p->next;
	p->next->prev = p->prev;

	free(p);
	p = nullptr;

	return 0;
}

int GetDListData(DListNode *head, const int pos, DataType *data)
{
	DListNode *p = head->next;
	int i = 0;
	while (p->next != head && i < pos)
	{
		p = p->next;
		i++;
	}

	if (i != pos)
	{
		cout << "delete pos error..." << endl;
		return -1;
	}

	*data = p->data;
	return 0;
}

void DestroyDList(DListNode **head)
{
	DListNode *p = *head;
	DListNode *q = nullptr;
	while (p != *head)
	{
		q = p;
		p = p->next;
		free(q);
		q = nullptr;
	}
	*head = nullptr;
}
