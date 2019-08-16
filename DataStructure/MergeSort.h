#pragma once
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void Merge(int a[], int n, int b[], int k)
{
	int l1 = 0, r1, l2, r2, m = 0, i, j;

	while (l1 + k <= n - 1)
	{
		l2 = l1 + k;
		r1 = l2 - 1;
		r2 = (l2 + k - 1 <= n - 1 ? l2 + k - 1 : n -1);

		for (i = l1, j = l2; i <= r1 && j <= r2; m++)
		{
			if (a[i] <= a[j])
				b[m] = a[i++];
			else
				b[m] = a[j++];
		}

		while (i <= r1)
		{
			b[m++] = a[i++];
		}

		while (j <= r2)
		{
			b[m++] = a[j++];
		}

		l1 = r2 + 1;
	}

	for (i = l1; i < n;)
		b[m++] = a[i++];
}

void MergeSort(int a[], int n)
{
	int *p = (int *)malloc(10 * sizeof(int));

	int k = 1;
	while (k < n)
	{
		Merge(a, n, p, k);
		for (int i = 0; i < n; i++)
			a[i] = p[i];
		k *= 2;
	}
	
	free(p);
}