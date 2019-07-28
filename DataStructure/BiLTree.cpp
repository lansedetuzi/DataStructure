#include "stdafx.h"
#include "BiLTree.h"

#include <stdlib.h>
#include <iostream>
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

void InOrder(BiLTreeNode *curr, void Visit(DataType item))
{
    if (NULL == curr)
        return;

    InOrder(curr->leftChild, Visit);

    Visit(curr->data);

    InOrder(curr->rightChild, Visit);
}

void PostOrder(BiLTreeNode *curr, void Visit(DataType item))
{
    if (NULL == curr)
        return;

    PostOrder(curr->leftChild, Visit);

    PostOrder(curr->rightChild, Visit);

    Visit(curr->data);
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
