// DataStructure.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SeqList.h"
#include "SList.h"
#include "DList.h"
#include "SeqStack.h"
#include "LinkStack.h"
#include "StackApplication.h"
#include "SeqCQueue.h"
#include "LinkQueue.h"
#include "SeqPQueue.h"

#include "SeqString.h"
#include "RecursionDemo.h"
#include "BiLTree.h"
#include "String.h"
#include "StringFunc.h"
#include "LinkNodeFunc.h"

#include <stdio.h>
#include <iostream>
using namespace std;

void testSeqList()
{
	SeqList seqList;
	SeqListInitial(&seqList);
	for (int i = 0; i < 10; i++)
	{
		InsertListData(&seqList, i, i * 10);
	}

	int size = GetListSize(seqList);
	for (int i = 0; i < size; i++)
	{
		DataType data = 0;
		GetListData(seqList, i, &data);
		cout << data << " ";
	}
	cout << endl;

	DataType data;
	DeleteListData(&seqList, 5, &data);
	cout << "after delete index = 5, data = " << data << endl;
	size = GetListSize(seqList);
	for (int i = 0; i < size; i++)
	{
		DataType data = 0;
		GetListData(seqList, i, &data);
		cout << data << " ";
	}
	cout << endl;
}

void testSList()
{
	SListNode *head = NULL;
	SListInitial(&head);
	for (int i = 0; i < 10; i++)
	{
		InsertSListData(head, i, i * 10);
	}

	int size = GetSListSize(head);
	for (int i = 0; i < size; i++)
	{
		DataType data = 0;
		GetSListData(head, i, &data);
		cout << data << " ";
	}
	cout << endl;

	DataType data;
	DeleteSListData(head, 5, &data);
	cout << "after delete index = 5, data = " << data << endl;
	size = GetSListSize(head);
	for (int i = 0; i < size; i++)
	{
		DataType data = 0;
		GetSListData(head, i, &data);
		cout << data << " ";
	}
	cout << endl;
	DestroySList(&head);
}

void testDList()
{
	DListNode *head = NULL;
	DListInitial(&head);
	for (int i = 0; i < 10; i++)
	{
		InsertDListData(head, i, i * 10);
	}

	int size = GetDListSize(head);
	for (int i = 0; i < size; i++)
	{
		DataType data = 0;
		GetDListData(head, i, &data);
		cout << data << " ";
	}
	cout << endl;

	DataType data;
	DeleteDListData(head, 5, &data);
	cout << "after delete index = 5, data = " << data << endl;
	size = GetDListSize(head);
	for (int i = 0; i < size; i++)
	{
		DataType data = 0;
		GetDListData(head, i, &data);
		cout << data << " ";
	}
	cout << endl;
 	DestroyDList(&head);
}

void testSeqStack()
{
	SeqStack seqStack;
	SeqStackInit(&seqStack);

	for (int i = 0; i < 10; i++)
	{
		SeqStackPush(&seqStack, i * i);
	}
	cout << "stack empty: " << SeqStackEmpty(seqStack) << endl;

	DataType topData;
	SeqStackTop(seqStack, &topData);
	cout << "top elem: " << topData << endl;

	for (int i = 0; i < 3; i++)
	{
		DataType tempData;
		SeqStackPop(&seqStack, &tempData);
		SeqStackTop(seqStack, &topData);
		cout << "after pop " << tempData << ", the top elem is: " << topData << endl;
	}
	cout << "stack empty: " << SeqStackEmpty(seqStack) << endl;
}

void testLinkStack()
{
	LSNode *head = NULL;
	LinkStackInit(&head);

	for (int i = 0; i < 10; i++)
	{
		LinkStackPush(head, i * i);
	}
	cout << "stack empty: " << LinkStackEmpty(head) << endl;

	DataType topData;
	LinkStackTop(head, topData);
	cout << "top elem: " << topData << endl;

	for (int i = 0; i < 3; i++)
	{
		DataType tempData;
		LinkStackPop(head, tempData);
		LinkStackTop(head, topData);
		cout << "after pop " << tempData << ", the top elem is: " << topData << endl;
	}
	cout << "stack empty: " << LinkStackEmpty(head) << endl;

	LinkStackDestoy(&head);
	cout << "stack empty: " << LinkStackEmpty(head) << endl;
}

void testBracketsMatched()
{
	const string strExp1 = "{x+y*[5-z*(a+b)]}";
	bool bRet = bracketsMatched(strExp1);
	cout << "strExp1 Matched: " << bRet << endl;

	const string strExp2 = "x+y*[5-z*(a+b)]}";
	bRet = bracketsMatched(strExp2);
	cout << "strExp1 Matched: " << bRet << endl;
}

void testMidExp2BackExp()
{
	string str = MidExp2BackExp("A+(B-C/D)*E#");
	cout << str << endl;

	cout << MidExp2BackExp("A*(B-D)+E/F#") << endl;
}

void testSeqCQueue()
{
	SeqCQueue queue;
	QueueInit(&queue);
	for (int i = 0; i < 10; i++)
	{
		QueueAppend(&queue, i * i);
	}

	cout << "queue empty: " << QueueEmpty(queue) << endl;

	for (int i = 0; i < 3; i++)
	{
		DataType top = 0, pop = 0;
		QueueDelete(&queue, &pop);
		QueueGet(queue, &top);
		cout << "after delete pop: " << pop << ", top: " << top << endl;
	}
	cout << "queue empty: " << QueueEmpty(queue) << endl;
}

void testLinkQueue()
{
	LQueue queue;
	QueueInit(&queue);
	for (int i = 0; i < 10; i++)
	{
		QueueAppend(&queue, i * i);
	}

	cout << "queue empty: " << QueueEmpty(queue) << endl;

	for (int i = 0; i < 3; i++)
	{
		DataType top = 0, pop = 0;
		QueueDelete(&queue, &pop);
		QueueGet(queue, &top);
		cout << "after delete pop: " << pop << ", top: " << top << endl;
	}
	cout << "queue empty: " << QueueEmpty(queue) << endl;

	QueueDestoy(&queue);
}

void testPQueue()
{
	SeqPQueue queue;
	PQueueInit(&queue);

	ElemType data1 = {1, 5};
	ElemType data2 = {2, 1};
	ElemType data3 = {3, 3};
	ElemType data4 = {4, 2};
	ElemType data5 = {5, 3};
	ElemType data6 = {6, 2};
	ElemType data7 = {7, 4};

	PQueueAppend(&queue, data1);
	PQueueAppend(&queue, data2);
	PQueueAppend(&queue, data3);
	PQueueAppend(&queue, data4);
	PQueueAppend(&queue, data5);
	PQueueAppend(&queue, data6);
	PQueueAppend(&queue, data7);

	ElemType data;
	for (int i = 0; i < 7; i++)
	{
		PQueueDelete(&queue, &data);
		cout << "delete seq: " << data.elem << ", priority: " << data.priority << endl;
	}
}

void testRecursionDemo()
{
    //cout << factorial(-1) << endl;
    //cout << factorial(0) << endl;
    //cout << factorial(3) << endl;
    //cout << factorial(10) << endl;

    //int a[] = {1, 5, 7, 9, 12, 16, 21, 45, 62};
    //cout << BSearch(a, 1, 0, sizeof(a)/ sizeof(a[0]) - 1) << endl;
    //cout << BSearch(a, 9, 0, sizeof(a) / sizeof(a[0]) - 1) << endl;
    //cout << BSearch(a, 21, 0, sizeof(a) / sizeof(a[0]) - 1) << endl;
    //cout << BSearch(a, 45, 0, sizeof(a) / sizeof(a[0]) - 1) << endl;
    int step = 0;
    HanoTower(15, 'A', 'B', 'C', step);
    cout << "total step: " << step << endl;
}

void Visit(DataType item)
{
    printf("%c ", item);
}

void testBiLTree()
{
    BiLTreeNode *root = NULL, *p = NULL, *pp = NULL;

    Initial(&root);

    //p = InsertLeftChild(root, 'A');
    //p = InsertLeftChild(p, 'B');
    //p = InsertLeftChild(p, 'D');
    //p = InsertRightChild(p, 'G');
    //p = InsertRightChild(root->leftChild, 'C');

    //pp = p;
    //InsertLeftChild(p, 'E');
    //InsertRightChild(pp, 'F');

	p = InsertLeftChild(root, 'A');
	InsertLeftChild(p, 'C');
	InsertRightChild(p, 'D');
	p = InsertRightChild(root, 'B');
	InsertLeftChild(p, 'E');
	InsertRightChild(p, 'F');

    cout << "PreOrder: " << endl;
    PreOrder(root, Visit);
    cout << endl;

	cout << "PreOrderNonRecur: " << endl;
	PreOrderNonRecur(root, Visit);
	cout << endl;

    cout << "InOrder: " << endl;
    InOrder(root, Visit);
    cout << endl;

	cout << "InOrderNonRecur: " << endl;
	InOrderNonRecur(root, Visit);
	cout << endl;

    cout << "PostOrder: " << endl;
    PostOrder(root, Visit);
    cout << endl;

	cout << "PostOrderNonRecur: " << endl;
	PostOrderNonRecur(root, Visit);
	cout << endl;

	cout << "LevelOrderNon: " << endl;
	LevelOrder(root, Visit);
	cout << endl;

	cout << "Height: " << Height(root) << endl;
	cout << "TotalLeafNode: " << TotalLeafNode(root) << endl;
	cout << "1 level node count: " << KLevelNodeCount(root, 1) << endl;
	cout << "2 level node count: " << KLevelNodeCount(root, 2) << endl;
	cout << "3 level node count: " << KLevelNodeCount(root, 3) << endl;

	cout << "is balance: " << IsBalance(root) << endl;
	
	p = Search(root, 'G');
	if (p)
		printf("%c\n", p->data);

    Destroy(&root);
}

void testString()
{
	SeqString s1, s2;
	StringInitial(&s1, "i am a programmer.");
	StringInitial(&s2, "programmer");

	// assign
	SeqString s3;
	StringInitial(&s3);
	StringAssign(&s3, s2);
	cout << s3.data << endl;

	// length
	cout << s1.length << endl;
	cout << s2.length << endl;
	cout << s3.length << endl;

	// compare
	SeqString s4;
	SeqString s5;
	SeqString s6;
	SeqString s7;
	StringInitial(&s4, "programmer");
	StringInitial(&s5, "programmer11");
	StringInitial(&s6, "program");
	StringInitial(&s7, "project");
	cout << StringCompare(s2, s4) << endl;
	cout << StringCompare(s2, s5) << endl;
	cout << StringCompare(s2, s6) << endl;
	cout << StringCompare(s2, s7) << endl;

	// insert 
	SeqString s8;
	StringInitial(&s8, " c plus plus");
	StringInsert(&s1, 6, s8);
	cout << s1.data << endl;

	// delete
	StringDelete(&s1, 0, 5);
	cout << s1.data << endl;

	// substring
	SeqString s9;
	StringInitial(&s9);
	SubString(s5, 10, 2, &s9);
	cout << s9.data << endl;

	cout << StringSearch(s1, 0, s2, SSA_KMP) << endl;
}

void testString1()
{
    const char source[] = "abcdefg";
    char dest[20] = {0};
    StringCopy(dest, source, strlen(source));
    cout << "dest: " << dest << endl;

    StringCat(dest, "sssss", 5);
    cout << dest << endl;

    char str1[] = "sfsdfq";
    char str2[] = "sfsdfq4";
    cout << StringCmp(str1, str2) << endl;
    cout << "str1 len: " << StringLen(str1) << ", str2 len: " << StringLen(str2) << endl;

    cout << StringChr(str1, 'd') << ", " << StringChr(str1, 's') << endl;
    cout << StringRChr(str2, 'f') << ", " << StringRChr(str2, 'q') << endl;

    char *str3 = StringDup(str1);
    cout << str3 << endl;

    cout << StringRev(str3) << endl;

    cout << StringStr("qwersdfasdf", "sdf") << endl;

    char str4[] = "QSfasEWSdsdfAEdf";
    char str5[32] = { 0 };
    StringToLower(str5, str4);
    cout << str5 << endl;

    char str6[] = "wersdf,sdgert,wer234,dsf2453,we";
    char p[10][20] = { 0 };
    int nCount = StringSplit(str6, 's', p);
    int nTotal = sizeof(p);
    int nEach = sizeof(p[0]);
    for (int i = 0; i < nCount; i++)
    {
        cout << p[i] << endl;
    }
}

int N, M;// 分别代表行和列
vector<vector<int>> maze; // 迷宫矩阵
vector<vector<int>> path_temp;// 存储当前路径，第一维标识位置
vector<vector<int>> path_best;// 存储最佳路径

void MazeTrack(int i, int j)
{
    maze[i][j] = 1;// 表示当前节点已走，不可再走
    path_temp.push_back({i, j}); // 当前节点加入到路径中

    if (i == N - 1 && j == M - 1)   // 判断是否到达终点
        if (path_best.empty() || path_temp.size() < path_best.size())
            path_best = path_temp;

    if (i - 1 >= 0 && maze[i - 1][j] == 0) // 探索向上走是否可行
        MazeTrack(i - 1, j);
    if (i + 1 < N && maze[i + 1][j] == 0) // 探索向下走是否可行
        MazeTrack(i + 1, j);
    if (j - 1 >= 0 && maze[i][j - 1] == 0) // 探索向左走是否可行
        MazeTrack(i, j - 1);
    if (j + 1 < M && maze[i][j + 1] == 0) // 探索向左走是否可行
        MazeTrack(i, j + 1);

    maze[i][j] = 0; // 恢复现场，设为未走

    path_temp.pop_back();
}

void testHuaWeiString()
{
    //const char str1[] = "ABSIB T";
    //cout << "last word's length of str1: " << LastWordLenOfString(str1) << endl;

    //const char str2[] = "nhrwlbcc8m7c5hih9mhalw98k0322wf2jjm47kk3ntm9snfrflzzundn7d608usy049asxalzjk7izj6amcqhr8uubc04g52mcjboj2fmge2l6iarizfu4yve5o4i3srf5zgqbg82ckcotdeqp760mc9gzei5dzk5gj9x9yj05o3hle0ii64krkkp5i7blh7nbu3gu5vgi2scyn4yqx3z4vcjbyzhnqkh887izotjkg2l0mit0k14vyn39";
    //cout << "l count of str1: " << LetterCountOfString(str2, 't') << endl;

    //FamaWeight();

    //while (cin >> N >> M)
    //{
    //    maze = vector<vector<int>>(N, vector<int>(M, 0));
    //    path_temp.clear();
    //    path_best.clear();
    //    for (auto &i : maze)
    //    {
    //        for (auto &j : i)
    //        {
    //            cin >> j;
    //        }
    //    }
    //    MazeTrack(0, 0);
    //    for (auto i : path_best)
    //        cout << '(' << i[0] << ',' << i[1] << ')' << endl;//输出通路
    //}

    //int n;
    //while (cin >> n)
    //{
    //    vector<int> vecScore;
    //    for (int i = 0; i < n; i++)
    //    {
    //        string strTmp;
    //        cin >> strTmp;
    //        vecScore.push_back(CalScore(strTmp));
    //    }

    //    for (int i = 0; i < n; i++)
    //    {
    //        cout << vecScore[i] << endl;
    //    }
    //}

    string str;
    int n;
    while (cin >> str >> n)
    {
        int i = 0;
        for (; i < str.length(); i++)
        {
            if (n <= 1 && (i + 1 < str.length()) && (str[i + 1] >= 0 && str[i + 1] <= 255))
            {
                break;
            }
            char c = str[i];
            if (c >= 0 && c <= 255)
            {
                n--;
            }
            else
            {
                n -= 2;
            }
        }
        cout << str.substr(0, i + 1) << endl;
    }
}

void testLinkNodeFunc()
{
    LinkNode *pHead = new LinkNode;
    pHead->data = -1;
    LinkNode *pLast = pHead;

    for (int i = 0; i < 8; i++)
    {
        LinkNode *pTmp = new LinkNode;
        pTmp->data =  i + 1;
        pTmp->next = nullptr;

        pLast->next = pTmp;
        pLast = pTmp;
    }
    pLast->next = pHead->next;

    //cout << "正向打印:" << endl;
    //LinkListPrint(pHead);

    //cout << "逆向向打印:" << endl;
    //LinkListReversePrint(pHead);

    cout << "约瑟夫环: " << endl;
    JosephCircle(pHead, 5);
}

int main()
{
    //testSeqList();

	//testSList();

	//testDList();

	//testSeqStack();

	//testLinkStack();

	//testBracketsMatched();

	//testMidExp2BackExp();

	//testSeqCQueue();

	//testLinkQueue();

	//testPQueue();

	//testBiLTree();

	//testString();

    //testString1();

    testHuaWeiString();

    //testLinkNodeFunc();

	system("pause");

	return 0;
}

