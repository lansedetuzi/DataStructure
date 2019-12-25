#pragma once

struct LinkNode
{
    char data;
    LinkNode *next;
};

/*
@brief: �����ӡ������
*/
void LinkListReversePrint(LinkNode *head);

/*
@brief: ������������pos֮ǰ����һ��Ԫ��
*/
void LinkListInsertBefore(LinkNode *head, LinkNode *pos, char value);

/*
@brief: Լɪ�򻷵�ʵ��
*/
LinkNode* JosephCircle(LinkNode *head, int m);

/*
@brief: ����������
*/
void LinkListReverse(LinkNode **head);

/*
@brief: �������ð������
*/
void LinkListBubbleSort(LinkNode *head);

/*
@brief: ������������ϲ���һ����������
*/
LinkNode* LinkListMerge(LinkNode *head1, LinkNode *head2);

/*
@brief: �����м���
*/
LinkNode* LinkListFindMidNode(LinkNode *head);

/*
@brief: �ҵ�����k�����
*/
LinkNode* LinkListFindLastKNode(LinkNode *head);

/*
@brief: ɾ��������k�����
*/
void LinkListEraseKthNode(LinkNode** head, size_t K);

/*
@brief: �ж��������Ƿ����
*/
LinkNode* LinkListHasCycle(LinkNode *head);

/*
@brief: ���������������󻷵����
*/
LinkNode* LinkListCycleEntry(LinkNode *head);

/*
@brief: �ж����������Ƿ��ཻ���󽻵�
*/
LinkNode* LinkListHasCross(LinkNode* head1, LinkNode* head2);
