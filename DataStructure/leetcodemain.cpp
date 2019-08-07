#include "stdafx.h"

#include "3Sum.h"
#include "3SumClosest.h"
#include "AccountsMerge.h"
#include "addBinary.h"
#include "addDigits.h"
#include "AdditiveNumber.h"
#include "AddStrings.h"
#include "ArithmeticSlices.h"
#include "BackspaceStringCmp.h"

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

void testAddBinary()
{
    string a = "11";
    string b = "1";
    cout << a << "+" << b << "=" << addBinary(a, b) << endl;
}

void testAddDigits()
{
    AddDigits addDigits;
    cout << addDigits.addDigits(38, 1);
}

void testAdditiveNumber()
{
    AdditiveNumberSolution solution;
    cout << solution.isAdditiveNumber("199100199");
}

void testAddStrings()
{
    AddStringsSolution solution;
    cout << solution.addStrings("245", "857") << endl;
}

void testArithmeticSlices()
{
    vector<int> vec = { 1, 3, 5, 7, 9, 11, 13 };
    ArithmeticSlicesSolution solution;
    cout << solution.numberOfArithmeticSlices(vec) << endl;
}

void testBackspaceStringCmpSolution()
{
    BackspaceStringCmpSolution so;
    cout << so.backspaceCmp("a##b", "cd##a#b") << endl;
}

int main()
{
    //test3Sum();

    //test3SumClosest();

    //testAccountsMerge();

    //testAddBinary();

    //testAddDigits();

    //testAdditiveNumber();

    //testAddStrings();

    //testArithmeticSlices();

    //testBackspaceStringCmpSolution();

    system("pause");

    return 0;
}