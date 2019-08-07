#include "stdafx.h"
#include "SeqPQueue.h"

#include <iostream>
using namespace std;

void PQueueInit(SeqPQueue *queue)
{
	queue->size = 0;
}

bool PQueueEmpty(SeqPQueue queue)
{
	return queue.size <= 0;
}

int PQueueAppend(SeqPQueue *queue, ElemType data)
{
	if (queue->size >= MAXSIZE)
	{
		cout << "priority queue full" << endl;
		return -1;
	}

	queue->data[queue->size++] = data;
	return 0;
}

int PQueueDelete(SeqPQueue *queue, ElemType *data)
{
	if (queue->size <= 0)
	{
		cout << "priority queue empty" << endl;
		return -1;
	}

	// 先找优先级最高的(priority最小)
	ElemType min = queue->data[0];
	int minIndex = 0;
	for (int i = 0; i < queue->size; i++)
	{
		if (queue->data[i].priority < min.priority)
		{
			min = queue->data[i];
			minIndex = i;
		}
	}

	*data = min;
	for (int i = minIndex + 1; i < queue->size; i++)
	{
		queue->data[i - 1] = queue->data[i];
	}
	--queue->size;
	return 0;
}

int PQueueGet(SeqPQueue queue, ElemType *data)
{
	if (queue.size <= 0)
	{
		cout << "priority queue empty" << endl;
		return -1;
	}

	// 先找优先级最高的(priority最小)
	ElemType min = queue.data[0];
	int minIndex = 0;
	for (int i = 0; i < queue.size; i++)
	{
		if (queue.data[i].priority < min.priority)
		{
			min = queue.data[i];
			minIndex = i;
		}
	}

	*data = min;
	return 0;
}
