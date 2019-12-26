#include "stdafx.h"
#include "LinkNodeFunc.h"

#include <iostream>
using namespace std;

// https://blog.csdn.net/liru_1996/article/details/79862062

// https://blog.csdn.net/weixin_41826018/article/details/90248372

// http://mini.eastday.com/mobile/180316183528356.html

void LinkListPrint(LinkNode *head)
{
    LinkNode *pTmp = head->next;
    while (nullptr != pTmp)
    {
        cout << pTmp->data << endl;
        pTmp = pTmp->next;
    }
}

void LinkListReversePrint(LinkNode *head)
{
    // Ӧ�õݹ�˼�룬��������,�ݹ���ڿ�Ϊhead==nullptr
    if (nullptr == head)
        return;
    else
        LinkListReversePrint(head->next);
    if (head->data != -1)
        cout << head->data << endl;
}

void LinkListInsertBefore(LinkNode *head, LinkNode *pos, char value)
{
    // �������������õ���֮ǰ�ĺ�����ʵ�֣���posλ�õ�ֵ�����ƣ��ڽ�value(Ҫ�����ֵ)����ֵ��pos��
}

LinkNode* JosephCircle(LinkNode *head, int m)
{
    // ˼�룺����һ����ֵ���ڼ�����Ҫ��ɾ����Ԫ�أ�Ȼ��ѭ��ɾ��������������ľ�������Ӯ�ҡ�
    // ���磺������Ԫ��a b c d e f,����Ҫ��ɾ����Ԫ��Ϊ�����Ԫ�أ����һ�α�ɾ����Ԫ��Ϊe,Ȼ����������ߣ������������ɾ����
    // ������������Ӯ�Ҿ���a,������Ҫע����ǣ�Ҫɾ���ǵ����������ֻ��Ҫ������4����
    LinkNode *pTmp = head->next;
    if (nullptr == pTmp)
        return nullptr;
    if (pTmp->next == pTmp)
        return pTmp;

    LinkNode *pCur = pTmp;
    while (pCur->next != pCur)
    {
        int i = 1;
        for (; i < m; i++)
        {
            pCur = pCur->next;
        }

        cout << pCur->data << " ";
        pCur->data = pCur->next->data;
        LinkNode *pDel = pCur->next;
        pCur->next = pDel->next;
        if (pDel)
        {
            delete pDel;
            pDel = nullptr;
        }
    }
    cout << pCur->data;

    return pCur;
}

void LinkListReverse(LinkNode **head)
{
    // ��һ�ַ�������������ָ��pre ��cur��next�ֱ�ָ��ͷ��㣬�ڶ������͵�������㣬Ȼ�����޸�cue��next�ڸ���cur��pre���������ƶ�����ѭ��������̣����Ҫ�����޸�ͷ��㡣

    // ����������������ָ��curһ��ָ��ͷ��㣬to_deleteһ��ָ��ڶ�����㣬Ȼ���޸�cur��nextΪto_delete��next���ٽ�to_delete���뵽ͷ����ѭ��������̡�
}

void LinkListBubbleSort(LinkNode *head)
{
    // ��������������ָ��conut ������ʾð�ݵ�������cur������ʾÿ�˵�ð�ݱȽϣ�tail������¼ĩβ
}

LinkNode* LinkListMerge(LinkNode *head1, LinkNode *head2)
{
    // ��������������ָ��ֱ�ָ����������ĵ������ͷ��㴦���ڶ���һ���µ��������ϳɵ�����������������ͷָ���βָ�룬
    // Ȼ��Ƚ�����������Ľ��ֵ�ô�С����С�Ĳ��뵽�������β����Ȼ��С���Ǹ�ָ��Ӽӣ��ڽ��бȽϣ�֪������������һ���ߵ�����󣬽���ѭ����
    // ��ʣ�µ�����ֱ�Ӳ��뵽�������β����

    return nullptr;
}

LinkNode* LinkListFindMidNode(LinkNode *head)
{
    // ���������Ϊ����ָ���˼�룬��ָ��ÿ������������ָ��ÿ����һ��������ָ��ָ�����һ��Ԫ�ص�ʱ����ָ����ָ��λ�þ����м�λ�ã�
    // ������Ҫע�����ѭ������������ָ�벻���ڿգ�����Ϊ����ָ��ָ���˵����ڶ���Ԫ����Ȼ������������ָ��ͻ�Ϊ�գ�
    // Ҳ����˵��������ż����Ԫ��ʱ����ָ��ָ�����ڶ���Ԫ��ѭ���ͽ����ˡ�
    return nullptr;
}

LinkNode* LinkListFindLastKNode(LinkNode *head)
{
    // ������˼��������м���һ��������ָ���˼�룬��ͬ����Ҫ���ҵ�����K��ֵ�����ÿ�ָ����K����Ȼ����ѭ����ָ����һ����ָ����һ����
    return nullptr;
}

void LinkListEraseKthNode(LinkNode** head, size_t K)
{
    // ������Ҫɾ��������k���ȵ��ҵ�������K+1��Ԫ�أ�Ȼ����ɾ��������K��Ԫ�أ��ҵ�����K+1��Ԫ�ص��ò��ҵ�����K��Ԫ�صĺ������Ϳ���ʵ��ɾ��������K��Ԫ�ء�
}

LinkNode* LinkListHasCycle(LinkNode *head)
{
    // ���������ǿ���ָ���˼�룬�����������ָ�룬��ָ��ÿ����������ָ��ÿ����һ��������������ָ������ȵ�ʱ����˵�������������
    return nullptr;
}

LinkNode* LinkListCycleEntry(LinkNode *head)
{
    // �����������˼��Ϊ�ӿ���ָ�������λ�õ���������������ͷָ���λ�õ�������ڵ��N����
    return nullptr;
}

LinkNode* LinkListHasCross(LinkNode* head1, LinkNode* head2)
{
    // �����������ж����������Ƿ���������������������������������ָ��ֱ�ָ�����������ͷ����������ָ�붼�ߵ������β����
    // ������ָ���ֵ��ȣ���˵�����������ཻ��������󷨣������������ĳ����Ǹ������Ǹ����߳������Ĳ��֣�Ȼ��������ָ��һ����һ��������غϵĵط���Ϊ����
    return nullptr;
}
