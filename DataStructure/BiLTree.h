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
void PreOrderNonRecur(BiLTreeNode *curr, void Visit(DataType item));
void InOrder(BiLTreeNode *curr, void Visit(DataType item));
void InOrderNonRecur(BiLTreeNode *curr, void Visit(DataType item));
void PostOrder(BiLTreeNode *curr, void Visit(DataType item));
void PostOrderNonRecur(BiLTreeNode *curr, void Visit(DataType item));

void LevelOrder(BiLTreeNode *curr, void Visit(DataType item));

int Height(BiLTreeNode *curr);
int TotalLeafNode(BiLTreeNode *curr);
int KLevelNodeCount(BiLTreeNode *curr, int k);

BiLTreeNode* FindNearestCommonAncestor(BiLTreeNode *curr, DataType x1, DataType x2);
bool IsBalance(BiLTreeNode *curr);

BiLTreeNode* Search(BiLTreeNode *curr, DataType x);

void Destroy(BiLTreeNode **root);