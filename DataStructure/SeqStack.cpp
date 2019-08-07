#include "stdafx.h"
#include "SeqStack.h"
#include <iostream>
using namespace std;

void SeqStackInit(SeqStack *seqStack)
{
	seqStack->data[MAXSIZE] = { 0 };
	seqStack->top = 0;
}

bool SeqStackEmpty(SeqStack seqStack)
{
	return (seqStack.top <= 0);
}

int SeqStackPush(SeqStack *seqStack, DataType data)
{
	if (seqStack->top >= MAXSIZE)
	{
		cout << "stack is full, can not push" << endl;
		return -1;
	}

	seqStack->data[seqStack->top++] = data;
	return 0;
}

int SeqStackPop(SeqStack *seqStack, DataType *data)
{
	if (seqStack->top <= 0)
	{
		cout << "stack is empty, can not pop" << endl;
		return -1;
	}

	seqStack->top--;
	*data = seqStack->data[seqStack->top];
	seqStack->data[seqStack->top] = 0;
	return 0;
}

int SeqStackTop(SeqStack seqStack, DataType *data)
{
	if (seqStack.top <= 0)
	{
		cout << "stack is empty, can not get top elem" << endl;
		return -1;
	}

	*data = seqStack.data[seqStack.top - 1];
	return 0;
}
