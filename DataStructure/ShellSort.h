#pragma once

void ShellSort(int array[], int n, int d[], int numd)
{
	for (int i = 0; i < numd; i++)
	{
		int span = d[i];
		for (int j = 0; j < span; j++)
		{
			for (int m = j; m < n - span; m += span)
			{
				int nTemp = array[m + span];
				int n = m;
				while (n >= 0 && nTemp < array[m])
				{
					array[m + span] = array[m];
					m -= span;
				}
				array[m + span] = nTemp;
			}
		}
	}
}