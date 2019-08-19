#pragma once

#include "SeqList.h"

/*
@brief: SeqList should sort in order£¬ or you will only use OrderSearch
*/
int BinarySearch(SeqList list, DataType x)
{
	int low = 0, high = list.size - 1;
	int mid = (low + high) / 2;

	while (low <= high)
	{
		if (x == list.data[mid])
			return mid;
		else if (x < list.data[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return -1;
}