#include "stdafx.h"
#include "SeqList.h"
#include <iostream>
using namespace std;

void SeqListInitial(SeqList *seqList)
{
	seqList->size = 0;
}

int GetListSize(SeqList seqList)
{
	return seqList.size;
}

int InsertListData(SeqList *seqList, const int pos, DataType data)
{
	if (seqList->size >= MAXSIZE)
	{
		cout << "Seq List is full" << endl;
		return -1;
	}
	else if (pos < 0 || pos > seqList->size)
	{
		cout << "insert pos error..." << endl;
		return -1;
	}
	else
	{
		int i = 0;
		for (i = seqList->size; i > pos; i--)
		{
			seqList->data[i] = seqList->data[i - 1];
		}

		seqList->data[i] = data;
		++seqList->size;
		return 0;
	}
}

int DeleteListData(SeqList *seqList, const int pos, DataType *data)
{
	if (seqList->size <= 0)
	{
		cout << "Seq List is empty" << endl;
		return -1;
	}
	else if (pos < 0 || pos >= seqList->size)
	{
		cout << "pos error" << endl;
		return -1;
	}
	else
	{
		int i = 0;
		*data = seqList->data[pos];
		for (i = pos; i < seqList->size - 1; i++)
		{
			seqList->data[i] = seqList->data[i + 1];
		}
		--seqList->size;
		return 0;
	}
}

int GetListData(SeqList seqList, const int pos, DataType *data)
{
	if (seqList.size <= 0)
	{
		cout << "Seq List is empty" << endl;
		return -1;
	}
	else if (pos < 0 || pos >= seqList.size)
	{
		cout << "pos error" << endl;
		return -1;
	}
	else
	{
		*data = seqList.data[pos];
		return 0;
	}
}
