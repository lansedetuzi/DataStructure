#include "stdafx.h"
#include "LinkQueue.h"

#include <iostream>
using namespace std;

void QueueInit(LQueue *queue)
{
	queue->front = NULL;
	queue->rear = NULL;
}

bool QueueEmpty(LQueue queue)
{
	return queue.front == NULL;
}

int QueueAppend(LQueue *queue, DataType data)
{
	LQNode *p = NULL;
	if (NULL == (p = (LQNode *)malloc(sizeof(LQNode))))
	{
		cout << "malloc error..." << endl;
		return -1;
	}

	p->data = data;
	p->next = NULL;

	if (queue->rear != NULL)
		queue->rear->next = p;
	queue->rear = p;

	if (NULL == queue->front)
		queue->front = p;
	return 0;
}

int QueueDelete(LQueue *queue, DataType *data)
{
	if (NULL == queue->front)
	{
		cout << "queue empty" << endl;
		return -1;
	}

	LQNode *p = queue->front;
	*data = p->data;
	queue->front = queue->front->next;
	if (NULL == queue->front)
		queue->rear = NULL;
	free(p);
	p = NULL;
	return 0;
}

int QueueGet(LQueue queue, DataType *data)
{
	if (NULL == queue.front)
	{
		cout << "queue empty" << endl;
		return -1;
	}

	*data = queue.front->data;
	return 0;
}

void QueueDestoy(LQueue *queue)
{
	LQNode *p = queue->front;
	LQNode *q = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
		q = NULL;
	}
	queue->front = queue->rear = NULL;
}
