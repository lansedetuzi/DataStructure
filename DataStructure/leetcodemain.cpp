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
#include "BasicCalculator1.h"
#include "BTLevelOrderTraval.h"
#include "BuddyString.h"
#include "BurstBalloons.h"
#include "Candy.h"
#include "CoinChange.h"
#include "Combination.h"
#include "constructBinaryTreeFromInorderAndPostorderTraversal.h"
#include "CountAndSay.h"
#include "DecodeWays.h"
#include "DistinctSubsequence.h"
#include "DirectInsertSort.h"
#include "ShellSort.h"
#include "SelectSort.h"
#include "HeapSort.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "RadixSort.h"

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

void testCalculator()
{
	string s = " 15-(1+3)+(2+1) ";

	cout << s << " = " << calculate(s) << endl;
	cout << "---------------" << endl;
	s = "(2+4)-(6+(1+5))";
	cout << s << " = " << calculate(s) << endl;
}

void testLevelOrderTraval()
{
	TreeNode *p;
	vector< vector<int> > vv;

	int a[] = { 1,2,3,4,5,0,0 };
	p = createTree(a, sizeof(a) / sizeof(int));
	printTree_level_order(p);
	vv = levelOrder1(p);
	printMatrix(vv);
	cout << endl;

	int b[] = { 1,0,2 };
	p = createTree(b, sizeof(b) / sizeof(int));
	printTree_level_order(p);
	vv = levelOrder2(p);
	printMatrix(vv);
	cout << endl;

	int c[] = { 1,2,0,3,0,4,0,5 };
	p = createTree(c, sizeof(c) / sizeof(int));
	printTree_level_order(p);
	vv = levelOrder1(p);
	printMatrix(vv);
	cout << endl;

	int d[] = { 1,2,3,4,0,0,5 };
	p = createTree(d, sizeof(d) / sizeof(int));
	printTree_level_order(p);
	vv = levelOrder1(p);
	printMatrix(vv);
	cout << endl;
}

void testBuddyString()
{
	string strA = "aaaaaaabc", strB = "aaaaaaacb";
	BuddyStringSolution so;
	cout << so.buddyStrings(strA, strB) << endl;
}

void testBurstBalloons()
{
	std::vector<int> vecNumbers = { 3, 1, 5, 8 };
	BurstBalloonsSolution so;
	cout << so.maxCoins(vecNumbers) << endl;
}

void testCandy()
{
	int n = 10;
	vector<int> ratings;
	generateRatings(ratings, n);
	print(ratings);

	cout << candy(ratings) << endl;

	cout << "--------------------" << endl;
	int r[] = { 5, 6, 7, 4, 1, 2, 3, 2, 1, 7 };
	vector<int> ra(r, r + sizeof(r) / sizeof(r[0]));
	print(ra);
	cout << candy(ra) << endl;
}
 
void testCoinChange()
{
	vector<int> cointype = { 1, 2, 5 };
	CoinChangeSolution1 s1;
	cout << s1.coinChange(cointype, 11) << endl; 

	CoinChangeSolution2 s2;
	cout << s2.coinChange(cointype, 11) << endl;
}

void testCombination()
{
	//vector<vector<int>> vecCombination1 = combine1(5, 2);
	vector<vector<int>> vecCombination2 = combine2(5, 2);
}

void testConstructBTFromInOrderAndPostOrder()
{
	int   in_order[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
	int post_order[] = { 'A', 'C', 'E', 'D', 'B', 'H', 'I', 'G', 'F' };
	vector<int>   inorder(in_order, in_order + 9);
	vector<int> postorder(post_order, post_order + 9);

	TreeNode* tree = buildTree(inorder, postorder);

	printTree_level_order(tree);
	printTree_pre_order(tree);
	printf("\n");
	printTree_in_order(tree);
	printf("\n");
}

void testCountAndSay()
{
	int n = 5;
	cout << countAndSay(n) << endl;
}

void testDistinctSubsequence()
{
	string s = "rabbbit";
	string t = "rabbit";
	cout << "S=\"" << s << "\"  T=\"" << t << "\"" << endl;
	cout << "numDistinct = " << numDistinct1(s, t) << endl;
}

void testDecodeWays()
{
	string s = "1234";
	cout << "\"" << s << "\" : " << numDecodings(s) << endl;
}

void printArray(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void testSort()
{
	int array[10] = {12, 10, 3, 8, 33, 5, 91, 23, 8, 7};
	printArray(array, 10);

	//DirectInsertSort(array, 10); 
	//printArray(array, 10);
	
	//int d[3] = {5, 2, 1};
	//ShellSort(array, 10, d, 3);
	//printArray(array, 10);

	//SelectSort(array, 10);
	//printArray(array, 10);

	//HeapSort(array, 10);
	//printArray(array, 10);

	//BubbleSort(array, 10);
	//printArray(array, 10);

	//QuickSort(array, 0, 9);
	//printArray(array, 10);

	//MergeSort(array, 10);
	//printArray(array, 10);

	RadixSort(array, 10, 2, 10);
	printArray(array, 10);
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

	//testCalculator();

	//testLevelOrderTraval();

	//testBuddyString();

	//testBurstBalloons();

	//testCandy();

	//testCoinChange();

	//testCombination();

	//testConstructBTFromInOrderAndPostOrder();

	//testCountAndSay();

	//testDecodeWays();

	//testDistinctSubsequence();

	testSort();

    system("pause");

    return 0;
}