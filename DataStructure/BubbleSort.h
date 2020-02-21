#pragma once

void BubbleSort(int a[], int n)
{
	int nFlag = 1;
	for (int i = 1; i < n && nFlag == 1; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			nFlag = 0;
			if (a[j] > a[j + 1])
			{
				nFlag = 1;
				int nTmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = nTmp;
			}
		}
	}
}
