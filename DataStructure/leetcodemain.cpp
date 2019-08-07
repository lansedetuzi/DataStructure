#include "stdafx.h"

#include "3Sum.h"
#include "3SumClosest.h"
#include "AccountsMerge.h"

#include <windows.h>
#include <iostream>
using namespace std;

void test3Sum()
{
    int a[] = { -1, 1, 1, 1, -1, -1, 0,0,0 };
    vector<int> n(a, a + sizeof(a) / sizeof(int));
    vector< vector<int> > result = threeSum(n);
    printMatrix(result);
}

void test3SumClosest()
{
    int a[] = { -1, 2, 1, -4 };
    vector<int> n(a, a + sizeof(a) / sizeof(int));
    int target = 1;
    cout << threeSumClosest(n, target) << endl;
}

void testAccountsMerge()
{
    vector<vector<string>> vecAccounts = { {"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"},
    {"John", "johnsmith@mail.com", "john_newyork@mail.com"},{"Mary", "mary@mail.com" } };

    Solution soulution;
    vector<vector<string>> rel = soulution.accountsMerge(vecAccounts);
    int nSize = rel.size();
}

int main()
{
    //test3Sum();

    //test3SumClosest();

    testAccountsMerge();

    system("pause");

    return 0;
}