// DataStructure.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SeqList.h"
#include "SList.h"
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


int main()
{
	//testSeqList();

	testSList();

	system("pause");

    return 0;
}

