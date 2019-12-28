#include "stdafx.h"
#include "StringFunc.h"
#include "String.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int LastWordLenOfString(const char *str)
{
    if (str == NULL)
        return 0;

    const char *tmp = str + StringLen(str) - 1;
    int nLastWordLen = 0;
    bool bStart = false;
    while (*tmp != ' ')
    {
        if (tmp == str)
        {
            nLastWordLen++;
            break;
        }
        if (!bStart)
        {
            if ((*tmp >= 'a' && *tmp <= 'z')
                || (*tmp >= 'A' && *tmp <= 'Z'))
            {
                bStart = true;
                nLastWordLen++;
            }
            tmp--;
            continue;
        }
        else
        {
            tmp--;
            nLastWordLen++;
        }
    }
    return nLastWordLen;
}

int LetterCountOfString(const char *str, const char c)
{
    int nCount = 0;
    const char *tmp = str;
    while (*tmp != '\0')
    {
        if (*tmp == c)
            nCount++;
        else
        {
            if (c >= 'a' && c <= 'z')
            {
                if (*tmp == c - 32)
                    nCount++;
            }
            else if (c >= 'A' && c <= 'Z')
            {
                if (*tmp == c + 32)
                    nCount++;
            }
        }
        tmp++;
    }
    return nCount;
}

bool JudgeBrother(string strFind, string v)
{
    sort(strFind.begin(), strFind.end());
    sort(v.begin(), v.end());
    if (0 == strFind.compare(v))
        return true;
    else
        return false;
};

void StringBrother()
{
    int num;
    vector<string> vecDic;
    vector<string> vecBro;
    while (cin >> num)
    {
        vecDic.clear();
        vecBro.clear();
        string strTmp;
        for (int i = 0; i < num; i++)
        {
            cin >> strTmp;
            vecDic.push_back(strTmp);
        }

        int index;
        string strFindWord;
        cin >> strFindWord;
        cin >> index;

        for (int i = 0; i < num; i++)
        {
            if (0 != strFindWord.compare(vecDic[i]) && JudgeBrother(strFindWord, vecDic[i]))
                vecBro.push_back(vecDic[i]);
        }
        sort(vecBro.begin(), vecBro.end());
        cout << vecBro.size() << endl;
        if (index <= vecBro.size())
            cout << vecBro[index - 1] << endl;
    }
}

vector<int> G[105];
int pre[105];
bool used[105];

bool dfs(int k)
{
    for (int i = 0; i < G[k].size(); i++)
    {
        if (used[G[k][i]] == 0)
        {
            used[G[k][i]] = 1;
            if (pre[G[k][i]] == 0 || dfs(pre[G[k][i]]))
            {
                pre[G[k][i]] = k;
                return true;
            }
        }
        else
        {
            continue;
        }
    }
    return false;
}

bool IsPrime(int n)
{
    int k = (int)sqrt((double)n);
    for (int i = 2; i <= k; i++)
    {
        if (n % i == 0)
            return true;
    }
    return false;
}

void PrimePartner()
{
    int N;
    int nums[105] = {0};
    while (cin >> N)
    {
        int tmp;
        for (int i = 0; i < N; i++)
        {
            cin >> tmp;
            nums[i] = tmp;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (IsPrime(nums[i] + nums[j]))
                    (nums[i] & 1) ? G[i].push_back(j) : G[j].push_back(i);
            }
        }
        memset(pre, 0, sizeof(pre));
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            memset(used, 0, sizeof(used));
            if (dfs(i))
                count++;
        }
        cout << count << endl;
        for (int i = 0; i < N; i++)
            G[i].clear();
    }
}

void SnakeMatrix(int n)
{
    int num = 1;
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        num += i;
        tmp = num;
        for (int j = 0; j < n - i; j++)
        {
            cout << tmp;
            if (j != n - i - 1)
                cout << " ";
            else
                cout << endl;
            tmp += i + 2 + j;
        }
    }
}

int RabbitCount(int month)
{
    int first = 1, second = 0, third = 0;
    while (--month)
    {
        third += second;
        second = first;
        first = third;
    }
    int nRet = first + second + third;
    cout << nRet << endl;
    return nRet;
}

void FamaWeight()
{
    int n;//砝码数
    int m[10] = { 0 };//每个砝码的质量
    int c[10] = { 0 };//每个砝码的数量
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> m[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];
        vector<int> weight;//存所有已经称出的砝码的质量
        /*先将第一个砝码称出的质量入队。*/
        weight.push_back(0);//初始化weights数组
        for (int i = 1; i <= c[0]; i++)
            weight.push_back(i * m[0]);//将第一个砝码能称出的质量入队
        for (int i = 1; i < n; i++)//前多少个砝码
        {
            int len = weight.size();//记录已经称出砝码质量便于下面for循环
            for (int j = 1; j <= c[i]; j++)//遍历该质量的砝码数
            {
                for (int k = 0; k < len; k++)
                {
                    int w = weight[k] + j * m[i];

                    if (std::find(weight.begin(), weight.end(), w) == weight.end())
                        weight.push_back(w);
                }
            }
        }
        cout << weight.size() << endl;
    }
}
