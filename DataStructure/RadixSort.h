#pragma once

#include <stdlib.h>

#include "LinkQueue.h"

void RadixSort(int a[], int n, int m, int d)
{
	LQueue *tub;
	tub = (LQueue *)malloc(d * sizeof(LQueue));

	for (int i = 0; i < d; i++)
		QueueInit(&tub[i]);

	for (int i = 0; i < m; i++)
	{
		int power = 1;
		if (i == 0)
			power = 1;
		else
			power *= d;

		int k = 0;
		for (int j = 0; j < n; j++)
		{
			k = a[j] / power - (a[j] / (d * power)) * d;
			QueueAppend(&tub[k], a[j]);
		}

		k = 0;
		for (int j = 0; j < d; j++)
		{
			while (!QueueEmpty(tub[j]))
			{
				QueueDelete(&tub[j], &a[k++]);
			}
		}
	}

	free(tub);
}