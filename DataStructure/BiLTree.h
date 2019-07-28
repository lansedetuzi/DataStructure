#pragma once

/**
@brief: 二叉链存储结构的二叉树
*/
typedef int DataType;

struct BiLTreeNode
{
    DataType data;
    BiLTreeNode *leftChild;
    BiLTreeNode *rightChild;
};

void Initial(BiLTreeNode **root);

BiLTreeNode* InsertLeftChild(BiLTreeNode *curr, DataType x);
BiLTreeNode* InsertRightChild(BiLTreeNode *curr, DataType x);

BiLTreeNode* DeleteLeftChild(BiLTreeNode *curr);
BiLTreeNode* DeleteRightChild(BiLTreeNode *curr);

void PreOrder(BiLTreeNode *curr, void Visit(DataType item));
void InOrder(BiLTreeNode *curr, void Visit(DataType item));
void PostOrder(BiLTreeNode *curr, void Visit(DataType item));

BiLTreeNode* Search(BiLTreeNode *curr, DataType x);

void Destroy(BiLTreeNode **root);