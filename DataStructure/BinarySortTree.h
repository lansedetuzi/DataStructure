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
@return 0��ʾ�ҵ��� -1��ʾδ�ҵ�
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
	// ���û�ҵ��ýڵ㣬����
	// ���ڸýڵ㣬���������
	// 1) Ҫɾ�����û�к��ӣ�ֱ��ɾ��;
	// 2) Ҫɾ�����ֻ�����ӣ���Ҫɾ���Ľڵ�ĸ��ڵ�ָ��ýڵ�����ӣ�ɾ���ýڵ�;
	// 3) Ҫɾ�����ֻ���Һ��ӣ���Ҫɾ���Ľڵ�ĸ��ڵ�ָ��ýڵ���Һ��ӣ�ɾ���ýڵ�;
	// 4) Ҫɾ����������Һ��ӣ�Ѱ�Ҹýڵ���������������㣬�øý��ĸ��ڵ�ָ������ɾ���ýڵ�͸�������
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