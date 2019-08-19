#pragma once
#include "SeqList.h"

int SeqListSearch(SeqList seqList, DataType x)
{
	for (int i = 0; i < seqList.size; i++)
	{
		if (x == seqList.data[i])
			return i;
	}
	return -1;
}