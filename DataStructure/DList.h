#pragma once

typedef int DataType;

typedef struct DListNode
{
	DataType data;
	DListNode *prev;
	DListNode *next;
} DListNode;

void DListInitial(DListNode **head);

int GetDListSize(DListNode *head);

int InsertDListData(DListNode *head, const int pos, DataType data);

int DeleteDListData(DListNode *head, const int pos, DataType *data);

int GetDListData(DListNode *head, const int pos, DataType *data);

void DestroyDList(DListNode **head);