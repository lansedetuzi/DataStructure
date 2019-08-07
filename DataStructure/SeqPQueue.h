#pragma once

typedef int DataType;

#define MAXSIZE 1024

struct ElemType
{
	DataType elem;
	int priority;
};

struct SeqPQueue
{
	ElemType data[MAXSIZE];
	int size;
};

void PQueueInit(SeqPQueue *queue);
bool PQueueEmpty(SeqPQueue queue);
int PQueueAppend(SeqPQueue *queue, ElemType data);
int PQueueDelete(SeqPQueue *queue, ElemType *data);
int PQueueGet(SeqPQueue queue, ElemType *data);