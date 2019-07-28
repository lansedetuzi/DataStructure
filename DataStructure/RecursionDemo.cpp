#include "stdafx.h"
#include "RecursionDemo.h"

#include <iostream>
#include <stdio.h>
using namespace std;

int factorial(const int n)
{
    if (n < 0)
    {
        cout << "invalid param ";
        return -1;
    }
    else if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int BSearch(int a[], int x, int low, int high)
{   
    if (low > high)
        return -1;
    int nMid = (low + high) / 2;

    if (a[nMid] == x)
    {
        return nMid;
    }
    else if (a[nMid] < x)
    {
        return BSearch(a, x, nMid + 1, high);
    }
    else
    {
        return BSearch(a, x, low, nMid - 1);
    }
}

void HanoTower(int n, char from, char by, char to, int &step)
{
    if (n == 1)
    {
        step++;
        printf("move disk1 from %c to %c\n", from, to);
        return;
    }

    HanoTower(n - 1, from, to, by, step);

    printf("move disk%d from %c to %c\n", n, from, to, step++);

    HanoTower(n - 1, by, from, to, step);
}
