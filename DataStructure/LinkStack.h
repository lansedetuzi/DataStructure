#pragma once

typedef int DataType;

struct LSNode
{
	DataType data;
	LSNode *next;
};

void LinkStackInit(LSNode **head);
bool LinkStackEmpty(LSNode *head);
int LinkStackPush(LSNode *head, DataType data);
int LinkStackPop(LSNode *head, DataType &data);
int LinkStackTop(LSNode *head, DataType &data);
void LinkStackDestoy(LSNode **head);