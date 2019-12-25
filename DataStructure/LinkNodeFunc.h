#pragma once

struct LinkNode
{
    char data;
    LinkNode *next;
};

/*
@brief: 逆序打印单链表
*/
void LinkListReversePrint(LinkNode *head);

/*
@brief: 不遍历链表在pos之前插入一个元素
*/
void LinkListInsertBefore(LinkNode *head, LinkNode *pos, char value);

/*
@brief: 约瑟夫环的实现
*/
LinkNode* JosephCircle(LinkNode *head, int m);

/*
@brief: 单链表逆置
*/
void LinkListReverse(LinkNode **head);

/*
@brief: 单链表的冒泡排序
*/
void LinkListBubbleSort(LinkNode *head);

/*
@brief: 两个有序链表合并成一个有序链表
*/
LinkNode* LinkListMerge(LinkNode *head1, LinkNode *head2);

/*
@brief: 查找中间结点
*/
LinkNode* LinkListFindMidNode(LinkNode *head);

/*
@brief: 找倒数第k个结点
*/
LinkNode* LinkListFindLastKNode(LinkNode *head);

/*
@brief: 删除倒数第k个结点
*/
void LinkListEraseKthNode(LinkNode** head, size_t K);

/*
@brief: 判定单链表是否带环
*/
LinkNode* LinkListHasCycle(LinkNode *head);

/*
@brief: 如果单链表带环，求环的入口
*/
LinkNode* LinkListCycleEntry(LinkNode *head);

/*
@brief: 判定两个链表是否相交，求交点
*/
LinkNode* LinkListHasCross(LinkNode* head1, LinkNode* head2);
