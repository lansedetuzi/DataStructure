#pragma once

typedef int DataType;

typedef struct SListNode
{
	DataType data;
	SListNode *next;
} SListNode;

void SListInitial(SListNode **head);

int GetSListSize(SListNode *head);

int InsertSListData(SListNode *head, const int pos, DataType data);

int DeleteSListData(SListNode *head, const int pos, DataType *data);

int GetSListData(SListNode *head, const int pos, DataType *data);

void DestroySList(SListNode **head);