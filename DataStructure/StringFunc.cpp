#include "stdafx.h"
#include "StringFunc.h"
#include "String.h"

#include <iostream>
#include <string>
#include <sstream>

#include <vector>
#include <algorithm>
#include <math.h>
#include <thread>
#include <mutex>
#include <condition_variable>

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

vector<string> Split(string strSource, char cSplit)
{
	stringstream ss(strSource);
	string strTmp;
	vector<string> vec;
	while (getline(ss, strTmp, cSplit))
	{
		vec.push_back(strTmp);
	}
	return vec;

/*	vector<string> vecRet;
	int nLastStart = 0;

	int i = 0;
	for (int i = 0; i < strSource.length(); i++)
	{
		if (cSplit != strSource[i])
			continue;
		else
		{
			string strTmp = strSource.substr(nLastStart, i - nLastStart);
			vecRet.push_back(strTmp);
			nLastStart = i + 1;
		}
	}

	vecRet.push_back(strSource.substr(nLastStart, strSource.length()));
	return vecRet;*/
}

bool IpValid(const vector<string> &vecIp)
{
	if (4 != vecIp.size())
		return false;

	for (int i = 0; i < 4; i++)
	{
		if (0 == vecIp[i].length())
			return false;
	}
	return true;
}

bool MaskValid(const vector<string> &vecMask)
{
	if (4 != vecMask.size())
		return false;

	bool bZero = false;
	for (int i = 0; i < 4; i++)
	{
		if (!bZero)
		{
			if (atoi(vecMask[i].c_str()) != 255)
			{
				if (atoi(vecMask[i].c_str()) != 0
					&& atoi(vecMask[i].c_str()) != 128
					&& atoi(vecMask[i].c_str()) != 192
					&& atoi(vecMask[i].c_str()) != 224
					&& atoi(vecMask[i].c_str()) != 240
					&& atoi(vecMask[i].c_str()) != 248
					&& atoi(vecMask[i].c_str()) != 252
					&& atoi(vecMask[i].c_str()) != 254)
				{
					return false;
				}
				else
				{
					bZero = true;
				}
			}
		}
		else
		{
			if (atoi(vecMask[i].c_str()) != 0)
				return false;
		}
	}

	if (atoi(vecMask[3].c_str()) == 255)
		return false;

	return true;
}

void IPAddrClassify()
{
	// 请解析IP地址和对应的掩码，进行分类识别。要求按照A / B / C / D / E类地址归类，不合法的地址和掩码单独归类。
	// 所有的IP地址划分为 A, B, C, D, E五类
	// A类地址1.0.0.0~126.255.255.255;
	// B类地址128.0.0.0~191.255.255.255;
	// C类地址192.0.0.0~223.255.255.255;
	// D类地址224.0.0.0~239.255.255.255；
	// E类地址240.0.0.0~255.255.255.255

	// 私网IP范围是：
	// 10.0.0.0～10.255.255.255
	// 172.16.0.0～172.31.255.255
	// 192.168.0.0～192.168.255.255

	// 子网掩码为二进制下前面是连续的1，然后全是0。（例如：255.255.255.32就是一个非法的掩码）
	
	string strInput;
	int a = 0,  b = 0, c = 0, d = 0, e = 0, err = 0, pri = 0;
	while (cin >> strInput)
	{
		vector<string> vecSplit = Split(strInput, '~');
		vector<string> vecIp = Split(vecSplit[0], '.');
		vector<string> vecMask = Split(vecSplit[1], '.');
		bool bIpValid = IpValid(vecIp);
		bool bMaskValid = MaskValid(vecMask);

		if (bIpValid && bMaskValid)
		{
			// a类
			int first = atoi(vecIp[0].c_str());
			if (first >= 1 && first <= 126)
			{
				a++;
				if (first == 10)
					pri++;
			}
			else if (first >= 128 && first <= 191) // b类
			{
				b++;
				if (first == 172
					&& (atoi(vecIp[1].c_str()) >= 16 && atoi(vecIp[1].c_str()) <= 32))
					pri++;
			}
			else if (first >= 192 && first <= 223)	// c类
			{
				c++;
				if (first == 192
					&& atoi(vecIp[1].c_str())== 168)
					pri++;
			}
			else if (first >= 224 && first <= 239) // d类
			{
				d++;
			}
			else if (first >= 240 && first <= 255) //e类
			{
				e++;
			}

		}
		else
		{
			err++;
		}
	}

	cout << a << " " << b << " " << c << " " << d << " " << e << " " << err << " " << pri;
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

std::mutex mtx;
condition_variable a, b, c, d;
bool bFinished = false;
string res = "";
void funA(int num)
{
	while (num--)
	{
		unique_lock<std::mutex> lock(mtx);
		a.wait(lock);
		res += "A";
		b.notify_one();
	}
	bFinished = true;
}

void funB()
{
	while (!bFinished)
	{
		unique_lock<mutex> lock(mtx);
		b.wait(lock);
		res += "B";
		c.notify_one();
	}
}

void funC()
{
	while (!bFinished)
	{
		unique_lock<mutex> lock(mtx);
		c.wait(lock);
		res += "C";
		d.notify_one();
	}
}

void funD()
{
	while (!bFinished)
	{
		unique_lock<mutex> lock(mtx);
		d.wait(lock);
		res += "D";
		a.notify_one();
	}
}

void ThreadSync()
{
	int num;
	while (cin >> num)
	{
		res = "";
		thread t1(funA, num);
		thread t2(funB);
		thread t3(funC);
		thread t4(funD);
		a.notify_one();
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		cout << res << endl;
		bFinished = false;
	}
}
