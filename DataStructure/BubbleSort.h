#pragma once

void BubbleSort(int a[], int n)
{
	int nFlag = 1;
	for (int i = 1; i < n && 1 == nFlag; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			nFlag = 0;
			if (a[j] > a[j + 1])
			{
				nFlag = 1;
				int nTemp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = nTemp;
			}
		}
	}
}