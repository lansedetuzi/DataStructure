#pragma once

void DirectInsertSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int nTmp = a[i + 1];
		int j = i;
		while (j >= 0 && nTmp < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = nTmp;
	}
}
