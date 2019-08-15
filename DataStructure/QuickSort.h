#pragma once

void QuickSort(int a[], int low, int high)
{
	int i = low, j = high;
	int nTemp = a[low];

	while (i < j)
	{
		while (i < j && nTemp < a[j])
			j--;
		if (i < j)
		{
			a[i] = a[j];
			i++;
		}

		while (i < j && a[i] < nTemp)
			i++;

		if (i < j)
		{
			a[j] = a[i];
			j--;
		}
	}

	a[i] = nTemp;
	if (low < i)
		QuickSort(a, low, i - 1);
	if (j < high)
		QuickSort(a, j + 1, high);
}