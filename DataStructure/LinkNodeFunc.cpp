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
    // 应用递归思想，遍历链表,递归出口库为head==nullptr
    if (nullptr == head)
        return;
    else
        LinkListReversePrint(head->next);
    if (head->data != -1)
        cout << head->data << endl;
}

void LinkListInsertBefore(LinkNode *head, LinkNode *pos, char value)
{
    // 分析：这里利用调用之前的函数来实现，将pos位置的值往后移，在将value(要插入的值)，赋值给pos。
}

LinkNode* JosephCircle(LinkNode *head, int m)
{
    // 思想：给定一个数值即第几个是要被删掉的元素，然后循环删除，最后留下来的就是最后的赢家。
    // 例如：环中有元素a b c d e f,假设要被删掉的元素为第五个元素，则第一次被删掉的元素为e,然后继续往后走，遇到第五个在删除，
    // 依次往后，最后的赢家就是a,这里需要注意的是，要删的是第五个数，则只需要往后走4步。
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
    // 第一种方法：定义三个指针pre 、cur、next分别指向头结点，第二个结点和第三个结点，然后来修改cue的next在更新cur和pre依次往后移动，在循环这个过程，最后不要忘记修改头结点。

    // 方法二：定义两个指针cur一个指向头结点，to_delete一个指向第二个结点，然后修改cur的next为to_delete的next，再将to_delete插入到头部，循环这个过程。
}

void LinkListBubbleSort(LinkNode *head)
{
    // 分析：定义三个指针conut 用来表示冒泡的趟数，cur用来表示每趟的冒泡比较，tail用来记录末尾
}

LinkNode* LinkListMerge(LinkNode *head1, LinkNode *head2)
{
    // 分析：定义两个指针分别指向两个有序的单链表的头结点处，在定义一个新的链表即最后合成的有序链表，新链表有头指针和尾指针，
    // 然后比较两个单链表的结点值得大小，将小的插入到新链表的尾部，然后小的那个指针加加，在进行比较，知道两个链表有一个走到了最后，结束循环，
    // 将剩下的所有直接插入到新链表的尾部。

    return nullptr;
}

LinkNode* LinkListFindMidNode(LinkNode *head)
{
    // 分析：这个为快慢指针的思想，快指针每次走两步，慢指针每次走一步，当快指针指向最后一个元素的时候慢指针所指的位置就是中间位置，
    // 这里需要注意的是循环结束条件快指针不等于空，是因为若快指针指向了倒数第二个元素了然后在走两步快指针就会为空，
    // 也就是说当链表有偶数个元素时当快指针指向倒数第二个元素循环就结束了。
    return nullptr;
}

LinkNode* LinkListFindLastKNode(LinkNode *head)
{
    // 分析：思想与查找中间结点一样，快慢指针的思想，不同的是要查找倒数第K个值则先让快指针走K步，然后在循环快指针走一步慢指针走一步。
    return nullptr;
}

void LinkListEraseKthNode(LinkNode** head, size_t K)
{
    // 分析：要删除倒数第k个先得找到倒数第K+1个元素，然后在删掉倒数第K个元素，找倒数第K+1个元素调用查找倒数第K个元素的函数，就可以实现删除倒数第K个元素。
}

LinkNode* LinkListHasCycle(LinkNode *head)
{
    // 分析：还是快慢指针的思想，定义快慢两个指针，快指针每次走两步慢指针每次走一步，最后如果两个指针有相等的时候，则说明单链表带环。
    return nullptr;
}

LinkNode* LinkListCycleEntry(LinkNode *head)
{
    // 分析：此题的思想为从快慢指针的相遇位置到环的入口是链表的头指针的位置到环的入口点的N倍。
    return nullptr;
}

LinkNode* LinkListHasCross(LinkNode* head1, LinkNode* head2)
{
    // 分析：首先判断两个链表是否带环，若两个链表均不带环，则定义两个指针分别指向两个链表的头部，让两个指针都走到链表的尾部，
    // 若两个指针的值相等，则说明两个链表相交，交点的求法，求出两个链表的长度那个链表长那个先走长出来的部分，然后在两个指针一次走一步，最后重合的地方就为交点
    return nullptr;
}
