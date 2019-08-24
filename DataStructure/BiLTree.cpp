#include "stdafx.h"
#include "BiLTree.h"

#include <stdlib.h>
#include <iostream>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

void Initial(BiLTreeNode **root)
{
    *root = (BiLTreeNode*)malloc(sizeof(BiLTreeNode));
    (*root)->data = -1;
    (*root)->leftChild = NULL;
    (*root)->rightChild = NULL;
}

BiLTreeNode* InsertLeftChild(BiLTreeNode *curr, DataType x)
{
    if (NULL == curr)
        return NULL;

    BiLTreeNode *orginLeftChild = NULL, *newLeftChild = NULL;

    if (NULL == (newLeftChild = (BiLTreeNode *)malloc(sizeof(BiLTreeNode))))
    {
        cout << "malloc error..." << endl;
        return NULL;
    }

    orginLeftChild = curr->leftChild;
    newLeftChild->data = x;
    newLeftChild->leftChild = orginLeftChild;
    newLeftChild->rightChild = NULL;

    curr->leftChild = newLeftChild;

    return newLeftChild;
}

BiLTreeNode* InsertRightChild(BiLTreeNode *curr, DataType x)
{
    if (NULL == curr)
        return NULL;

    BiLTreeNode *originRightChild = NULL, *newRightChild = NULL;
    if (NULL == (newRightChild = (BiLTreeNode*)malloc(sizeof(BiLTreeNode))))
    {
        cout << "malloc error..." << endl;
        return NULL;
    }

    originRightChild = curr->rightChild;
    newRightChild->data = x;
    newRightChild->leftChild = NULL;
    newRightChild->rightChild = originRightChild;

    curr->rightChild = newRightChild;
    return newRightChild;
}

BiLTreeNode* DeleteLeftChild(BiLTreeNode *curr)
{
    if (NULL == curr || NULL == curr->leftChild)
        return NULL;

    Destroy(&curr->leftChild);
    curr->leftChild = NULL;

    return curr;
}

BiLTreeNode* DeleteRightChild(BiLTreeNode *curr)
{
    if (NULL == curr || NULL == curr->rightChild)
        return NULL;

    Destroy(&curr->rightChild);
    curr->rightChild = NULL;

    return curr;
}

void PreOrder(BiLTreeNode *curr, void Visit(DataType item))
{
    if (NULL == curr)
        return;

    Visit(curr->data);

    PreOrder(curr->leftChild, Visit);

    PreOrder(curr->rightChild, Visit);
}

void PreOrderNonRecur(BiLTreeNode *curr, void Visit(DataType item))
{
	if (!curr)
		return;

	BiLTreeNode *pCur = curr;
	stack<BiLTreeNode*> stack;
	while (pCur ||!stack.empty())
	{
		while (pCur)
		{
			Visit(pCur->data);
			stack.push(pCur);
			pCur = pCur->leftChild;
		}

		BiLTreeNode *pTop = stack.top();
		stack.pop();
		pCur = pTop->rightChild;
	}
}

void InOrder(BiLTreeNode *curr, void Visit(DataType item))
{
    if (NULL == curr)
        return;

    InOrder(curr->leftChild, Visit);

    Visit(curr->data);

    InOrder(curr->rightChild, Visit);
}

void InOrderNonRecur(BiLTreeNode *curr, void Visit(DataType item))
{
	if (!curr)
		return;

	BiLTreeNode *pCur = curr;
	stack<BiLTreeNode*> stack;
	while (pCur || !stack.empty())
	{
		while (pCur)
		{
			stack.push(pCur);
			pCur = pCur->leftChild;
		}

		BiLTreeNode *pTop = stack.top();
		stack.pop();
		Visit(pTop->data);
		pCur = pTop->rightChild;
	}
}

void PostOrder(BiLTreeNode *curr, void Visit(DataType item))
{
    if (NULL == curr)
        return;

    PostOrder(curr->leftChild, Visit);

    PostOrder(curr->rightChild, Visit);

    Visit(curr->data);
}

void PostOrderNonRecur(BiLTreeNode *curr, void Visit(DataType item))
{
	if (!curr)
		return;

	BiLTreeNode *pCur = curr;
	BiLTreeNode *pPrev = nullptr;
	stack<BiLTreeNode*> stack;
	while (pCur || !stack.empty())
	{
		while (pCur)
		{
			stack.push(pCur);
			pCur = pCur->leftChild;
		}

		BiLTreeNode *pTop = stack.top();
		if (nullptr == pTop->rightChild || pTop->rightChild == pPrev)
		{
			Visit(pTop->data);
			stack.pop();
			pPrev = pTop;
		}
		else
			pCur = pTop->rightChild;
	}
}

void LevelOrder(BiLTreeNode *curr, void Visit(DataType item))
{
	std::queue<BiLTreeNode*> q;
	if (!curr)
		return;
	else
		q.push(curr);

	while (!q.empty())
	{
		BiLTreeNode *pNode = q.front();
		q.pop();
		Visit(pNode->data);
		if (pNode->leftChild)
			q.push(pNode->leftChild);
		if (pNode->rightChild)
			q.push(pNode->rightChild);
	}
}

int Height(BiLTreeNode *curr)
{
	if (!curr)
		return 0;
	int nLeftHeight = Height(curr->leftChild);
	int nRightHeight = Height(curr->rightChild);
	return nLeftHeight > nRightHeight ? nLeftHeight + 1 : nRightHeight + 1;
}

int TotalLeafNode(BiLTreeNode *curr)
{
	if (!curr)
		return 0;

	if (!curr->leftChild && !curr->rightChild)
		return 1;

	return TotalLeafNode(curr->leftChild) + TotalLeafNode(curr->rightChild);
}

int KLevelNodeCount(BiLTreeNode *curr, int k)
{
	if (!curr)
		return 0;
	if (1 == k)
		return 1;
	return KLevelNodeCount(curr->leftChild, k - 1) + KLevelNodeCount(curr->rightChild, k - 1);
}

BiLTreeNode* FindNearestCommonAncestor(BiLTreeNode *curr, DataType x1, DataType x2)
{
	// 1. x1 x2有一个为根节点, 结果为根节点
	// 2. x1在左子树，x2在右子树，结果为根节点
	// 3. x1、x2均在左或右子树，转化为子问题

	if (!curr)
		return NULL;

	if ((curr->data == x1) || (curr->data == x2))
	{
		return curr;
	}

	bool bX1Left = false, bX2Left = false;
	BiLTreeNode *p1 = Search(curr->leftChild, x1);
	BiLTreeNode *p2 = Search(curr->leftChild, x2);
	if (p1)
		bX1Left = true;
	else
		bX1Left = false;
	if (p2)
		bX2Left = true;
	else
		bX2Left = false;

	if ((bX1Left && !bX2Left) || (!bX1Left && bX2Left))
		return curr;
	else if (bX1Left && bX1Left)
		return FindNearestCommonAncestor(curr->leftChild, x1, x2);
	else
		return FindNearestCommonAncestor(curr->rightChild, x1, x2);
}

bool IsBalance(BiLTreeNode *curr, int &depth)
{
	if (!curr)
		return false;
	int nLeftDepth = 0, nRightDepth = 0;
	if (IsBalance(curr->leftChild, nLeftDepth) && IsBalance(curr->rightChild, nRightDepth))
	{
		if (abs(nLeftDepth - nRightDepth) > 1)
			return false;
		else
		{
			depth = (nLeftDepth > nRightDepth ? nLeftDepth + 1 : nRightDepth + 1);
			return true;
		}	
	}
	else
		return false;
};

bool IsBalance(BiLTreeNode *curr)
{
	int nDepth = 0;
	return IsBalance(curr, nDepth);
}

BiLTreeNode* Search(BiLTreeNode *curr, DataType x)
{
    BiLTreeNode *p = NULL;
    if (NULL == curr)
        return NULL;

    if (x == curr->data)
        return curr;

    if (NULL != curr->leftChild)
    {
        p = Search(curr->leftChild, x);
        if (NULL != p)
            return p;
    }

    if (NULL != curr->rightChild)
    {
        p = Search(curr->rightChild, x);
        if (NULL != p)
            return p;
    }

    return NULL;
}

void Destroy(BiLTreeNode **root)
{
    if (NULL != (*root) && NULL != (*root)->leftChild)
        Destroy(&(*root)->leftChild);
    if (NULL != (*root) && NULL != (*root)->rightChild)
        Destroy(&(*root)->rightChild);
    free(*root);
    (*root) = NULL;
}
