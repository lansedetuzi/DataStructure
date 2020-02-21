#pragma once

void SelectSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int nSmallestIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[nSmallestIndex])
			{
				nSmallestIndex = j;
			}
		}

		if (nSmallestIndex != i)
		{
			int nTmp = a[nSmallestIndex];
			a[nSmallestIndex] = a[i];
			a[i] = nTmp;
		}
	}
}