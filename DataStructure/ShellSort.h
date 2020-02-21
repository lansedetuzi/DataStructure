#pragma once

void ShellInsertSort(int a[], const int n, int d)
{
	for (int i = 0; i < n - d; i++)
	{
		int nTmp = a[i + d];
		int j = i;
		while (j >= 0 && nTmp < a[j])
		{
			a[j + d] = a[j];
			j -= d;
		}
		a[j + d] = nTmp;
	}
}

void ShellSort(int a[], const int n)
{
	int d = n / 2;
	while (d >= 1)
	{
		ShellInsertSort(a, n, d);
		d /= 2;
	}
}
