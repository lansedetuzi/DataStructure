#pragma once

void CreateHeap(int a[], int n, int h)
{
	int i = h;
	int j = 2 * i + 1;
	int nFlag = 0;
	int nTemp = a[i];
	while (j < n && 0 == nFlag)
	{
		if (j < n - 1 && a[j] < a[j + 1])
			j++;

		if (nTemp > a[j])
		{
			nFlag = 1;
		}
		else
		{
			a[i] = a[j];
			i = j;
			j = 2 * i + 1;
		}
	}
	a[i] = nTemp;
}

void InitHeap(int a[], int n)
{
	for (int i = (n - 1) / 2; i >=0; i--)
	{
		CreateHeap(a, n, i);
	}
}

void HeapSort(int a[], int n)
{
	InitHeap(a, n);

	for (int i = n - 1; i > 0; i--)
	{
		int  nTemp = a[0];
		a[0] = a[i];
		a[i] = nTemp;

		CreateHeap(a, i, 0);
	}
}