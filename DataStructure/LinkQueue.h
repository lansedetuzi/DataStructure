#pragma once

typedef int DataType;

struct LQNode
{
	DataType data;
	LQNode *next;
};

struct LQueue
{
	LQNode *front;
	LQNode *rear;
};

void QueueInit(LQueue *queue);
bool QueueEmpty(LQueue queue);
int QueueAppend(LQueue *queue, DataType data);
int QueueDelete(LQueue *queue, DataType *data);
int QueueGet(LQueue queue, DataType *data);
void QueueDestoy(LQueue *queue);
