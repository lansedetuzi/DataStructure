#pragma once

#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef int DataType;

typedef struct Node
{
	DataType data;
	Node *leftChild;
	Node *rightChild;
}BiTreeNode;

/*
@return 0表示找到， -1表示未找到
*/
int Search(BiTreeNode *root, DataType data)
{
	BiTreeNode *p = root;
	while (p != nullptr)
	{
		if (data == p->data)
			return 0;
		else if (data < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	return -1;
}

int Insert(BiTreeNode **root, DataType x)
{
	BiTreeNode *cur = *root, *parent = nullptr, *p = nullptr;

	while (cur != nullptr)
	{
		if (x == cur->data)
			return -1;

		parent = cur;

		if (x < cur->data)
			cur = cur->leftChild;
		else
			cur = cur->rightChild;
	}

	p = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	if (nullptr == p)
		return -1;

	p->data = x;
	p->leftChild = p->rightChild = nullptr;

	if (parent = nullptr)
		*root = p;
	else if (x < parent->data)
		parent->leftChild = p;
	else
		parent->rightChild = p;

	return 0;
}

int Delete(BiTreeNode *root, DataType x)
{
	// 如果没找到该节点，返回
	// 存在该节点，分四种情况
	// 1) 要删除结点没有孩子，直接删除;
	// 2) 要删除结点只有左孩子，将要删除的节点的父节点指向该节点的左孩子，删除该节点;
	// 3) 要删除结点只有右孩子，将要删除的节点的父节点指向该节点的右孩子，删除该节点;
	// 4) 要删除结点有左右孩子，寻找该节点的右子树的最左结点，让该结点的父节点指向它，删除该节点和该最左结点
}

void InTraverse(BiTreeNode *root)
{
	if (nullptr == root)
		return;

	if (nullptr != root->leftChild)
		InTraverse(root->leftChild);

	printf("%d	", root->data);

	if (nullptr != root->rightChild)
		InTraverse(root->rightChild);
}