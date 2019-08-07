#pragma once

typedef int DataType;

#define  MAXSIZE 1024

struct SeqStack
{
	DataType data[MAXSIZE];
	int top;
};

void SeqStackInit(SeqStack *seqStack);
bool SeqStackEmpty(SeqStack seqStack);
int	SeqStackPush(SeqStack *seqStack, DataType data);
int SeqStackPop(SeqStack *seqStack, DataType *data);
int SeqStackTop(SeqStack seqStack, DataType *data);