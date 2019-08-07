#include "stdafx.h"
#include "SeqCQueue.h"

#include <iostream>
using namespace std;

void QueueInit(SeqCQueue *queue)
{
	queue->front = queue->rear = queue->count = 0;
}

bool QueueEmpty(SeqCQueue queue)
{
	return queue.count == 0;
}

int QueueAppend(SeqCQueue *queue, DataType data)
{
	if (queue->count > 0 && (queue->rear == queue->front))
	{
		cout << "queue full error..." << endl;
		return -1;
	}

	queue->data[queue->rear] = data;
	queue->rear = (queue->rear + 1) % MAXSIZE;
	++queue->count;
	return 0;
}

int QueueDelete(SeqCQueue *queue, DataType *data)
{
	if (queue->count == 0)
	{
		cout << "queue empty error..." << endl;
		return -1;
	}

	*data = queue->data[queue->front];
	queue->front = (queue->front + 1) % MAXSIZE;
	--queue->count;
	return 0;
}

int QueueGet(SeqCQueue queue, DataType *data)
{
	if (queue.count == 0)
	{
		cout << "queue empty error..." << endl;
		return -1;
	}

	*data = queue.data[queue.front];
	return 0;
}
