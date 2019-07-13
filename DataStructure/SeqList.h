#pragma once

#define MAXSIZE 1024
typedef int DataType;

typedef struct
{
	DataType data[MAXSIZE];
	int size;
} SeqList;

void SeqListInitial(SeqList *seqList);

int GetListSize(SeqList seqList);

int InsertListData(SeqList *seqList, const int pos, DataType data);

int DeleteListData(SeqList *seqList, const int pos, DataType *data);

int GetListData(SeqList seqList, const int pos, DataType *data);

