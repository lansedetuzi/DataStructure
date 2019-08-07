#pragma once

typedef int DataType;

#define MAXSIZE 1024

struct SeqCQueue
{
	DataType data[MAXSIZE];
	int front;
	int rear;
	int count;
};

void QueueInit(SeqCQueue *queue);
bool QueueEmpty(SeqCQueue queue);
int QueueAppend(SeqCQueue *queue, DataType data);
int QueueDelete(SeqCQueue *queue, DataType *data);
int QueueGet(SeqCQueue queue, DataType *data);

