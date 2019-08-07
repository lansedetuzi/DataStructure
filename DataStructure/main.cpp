// DataStructure.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SeqList.h"
#include "SList.h"
#include "DList.h"
#include "SeqStack.h"
#include "LinkStack.h"
#include "StackApplication.h"
#include "SeqCQueue.h"
#include "LinkQueue.h"
#include "SeqPQueue.h"

#include <iostream>
using namespace std;

void testSeqList()
{
	SeqList seqList;
	SeqListInitial(&seqList);
	for (int i = 0; i < 10; i++)
	{
		InsertListData(&seqList, i, i * 10);
	}

	int size = GetListSize(seqList);
	for (int i = 0; i < size; i++)
	{
		DataType data = 0;
		GetListData(seqList, i, &data);
		cout << data << " ";
	}
	cout << endl;

	DataType data;
	DeleteListData(&seqList, 5, &data);
	cout << "after delete index = 5, data = " << data << endl;
	size = GetListSize(seqList);
	for (int i = 0; i < size; i++)
	{
		DataType data = 0;
		GetListData(seqList, i, &data);
		cout << data << " ";
	}
	cout << endl;
}

void testSList()
{
	SListNode *head = NULL;
	SListInitial(&head);
	for (int i = 0; i < 10; i++)
	{
		InsertSListData(head, i, i * 10);
	}

	int size = GetSListSize(head);
	for (int i = 0; i < size; i++)
	{
		DataType data = 0;
		GetSListData(head, i, &data);
		cout << data << " ";
	}
	cout << endl;

	DataType data;
	DeleteSListData(head, 5, &data);
	cout << "after delete index = 5, data = " << data << endl;
	size = GetSListSize(head);
	for (int i = 0; i < size; i++)
	{
		DataType data = 0;
		GetSListData(head, i, &data);
		cout << data << " ";
	}
	cout << endl;
	DestroySList(&head);
}

void testDList()
{
	DListNode *head = NULL;
	DListInitial(&head);
	for (int i = 0; i < 10; i++)
	{
		InsertDListData(head, i, i * 10);
	}

	int size = GetDListSize(head);
	for (int i = 0; i < size; i++)
	{
		DataType data = 0;
		GetDListData(head, i, &data);
		cout << data << " ";
	}
	cout << endl;

	DataType data;
	DeleteDListData(head, 5, &data);
	cout << "after delete index = 5, data = " << data << endl;
	size = GetDListSize(head);
	for (int i = 0; i < size; i++)
	{
		DataType data = 0;
		GetDListData(head, i, &data);
		cout << data << " ";
	}
	cout << endl;
 	DestroyDList(&head);
}

void testSeqStack()
{
	SeqStack seqStack;
	SeqStackInit(&seqStack);

	for (int i = 0; i < 10; i++)
	{
		SeqStackPush(&seqStack, i * i);
	}
	cout << "stack empty: " << SeqStackEmpty(seqStack) << endl;

	DataType topData;
	SeqStackTop(seqStack, &topData);
	cout << "top elem: " << topData << endl;

	for (int i = 0; i < 3; i++)
	{
		DataType tempData;
		SeqStackPop(&seqStack, &tempData);
		SeqStackTop(seqStack, &topData);
		cout << "after pop " << tempData << ", the top elem is: " << topData << endl;
	}
	cout << "stack empty: " << SeqStackEmpty(seqStack) << endl;
}

void testLinkStack()
{
	LSNode *head = NULL;
	LinkStackInit(&head);

	for (int i = 0; i < 10; i++)
	{
		LinkStackPush(head, i * i);
	}
	cout << "stack empty: " << LinkStackEmpty(head) << endl;

	DataType topData;
	LinkStackTop(head, topData);
	cout << "top elem: " << topData << endl;

	for (int i = 0; i < 3; i++)
	{
		DataType tempData;
		LinkStackPop(head, tempData);
		LinkStackTop(head, topData);
		cout << "after pop " << tempData << ", the top elem is: " << topData << endl;
	}
	cout << "stack empty: " << LinkStackEmpty(head) << endl;

	LinkStackDestoy(&head);
	cout << "stack empty: " << LinkStackEmpty(head) << endl;
}

void testBracketsMatched()
{
	const string strExp1 = "{x+y*[5-z*(a+b)]}";
	bool bRet = bracketsMatched(strExp1);
	cout << "strExp1 Matched: " << bRet << endl;

	const string strExp2 = "x+y*[5-z*(a+b)]}";
	bRet = bracketsMatched(strExp2);
	cout << "strExp1 Matched: " << bRet << endl;
}

void testMidExp2BackExp()
{
	string str = MidExp2BackExp("A+(B-C/D)*E#");
	cout << str << endl;

	cout << MidExp2BackExp("A*(B-D)+E/F#") << endl;
}

void testSeqCQueue()
{
	SeqCQueue queue;
	QueueInit(&queue);
	for (int i = 0; i < 10; i++)
	{
		QueueAppend(&queue, i * i);
	}

	cout << "queue empty: " << QueueEmpty(queue) << endl;

	for (int i = 0; i < 3; i++)
	{
		DataType top = 0, pop = 0;
		QueueDelete(&queue, &pop);
		QueueGet(queue, &top);
		cout << "after delete pop: " << pop << ", top: " << top << endl;
	}
	cout << "queue empty: " << QueueEmpty(queue) << endl;
}

void testLinkQueue()
{
	LQueue queue;
	QueueInit(&queue);
	for (int i = 0; i < 10; i++)
	{
		QueueAppend(&queue, i * i);
	}

	cout << "queue empty: " << QueueEmpty(queue) << endl;

	for (int i = 0; i < 3; i++)
	{
		DataType top = 0, pop = 0;
		QueueDelete(&queue, &pop);
		QueueGet(queue, &top);
		cout << "after delete pop: " << pop << ", top: " << top << endl;
	}
	cout << "queue empty: " << QueueEmpty(queue) << endl;

	QueueDestoy(&queue);
}

void testPQueue()
{
	SeqPQueue queue;
	PQueueInit(&queue);

	ElemType data1 = {1, 5};
	ElemType data2 = {2, 1};
	ElemType data3 = {3, 3};
	ElemType data4 = {4, 2};
	ElemType data5 = {5, 3};
	ElemType data6 = {6, 2};
	ElemType data7 = {7, 4};

	PQueueAppend(&queue, data1);
	PQueueAppend(&queue, data2);
	PQueueAppend(&queue, data3);
	PQueueAppend(&queue, data4);
	PQueueAppend(&queue, data5);
	PQueueAppend(&queue, data6);
	PQueueAppend(&queue, data7);

	ElemType data;
	for (int i = 0; i < 7; i++)
	{
		PQueueDelete(&queue, &data);
		cout << "delete seq: " << data.elem << ", priority: " << data.priority << endl;
	}
}

int main()
{
	//testSeqList();

	//testSList();

	//testDList();

	//testSeqStack();

	//testLinkStack();

	//testBracketsMatched();

	//testMidExp2BackExp();

	//testSeqCQueue();

	//testLinkQueue();

	testPQueue();

	system("pause");

    return 0;
}

