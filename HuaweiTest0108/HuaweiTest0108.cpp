// HuaweiTest0108.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int cBit = 7;

int UnitConvert(const string &str)
{
	int nlen = str.length();
	if (str[nlen - 1] == 's'
		|| str[nlen - 1] == 'S')
	{
		return cBit * atoi(str.substr(0, nlen - 1).c_str());
	}
	else if (str[nlen - 1] == 'y'
		|| str[nlen - 1] == 'Y')
	{
		return atoi(str.substr(0, nlen - 1).c_str());
	}
	else
	{
		//cout << "error";
		return 0;
	}
}

vector<int> SplitData(const string &str)
{
	vector<int> vec;
	int nlen = str.length();
	int nStart = 0;
	string strTmp = "";
	for (int i = 0; i < nlen; i++)
	{
		strTmp.clear();
		if (str[i] == ' ')
		{
			strTmp = str.substr(nStart, i - nStart);
			vec.push_back(UnitConvert(strTmp));
			nStart = i + 1;
		}
	}

	if (nStart != nlen)
	{
		strTmp.clear();
		strTmp = str.substr(nStart);
		vec.push_back(UnitConvert(strTmp));
	}
	return vec;
}

int main()
{
	string strInput;
	while (getline(cin, strInput))
	{
		vector<int> vecData = SplitData(strInput);
		vector<int> vecBuyIndex;
		vector<int> vecSoldIndex;

		int nSize = vecData.size();
		for (int i = 0; i < nSize - 2; ++i)
		{
			// 四种情况（）
			if (vecData[i] <= vecData[i + 1] && vecData[i + 1] <= vecData[i + 2])
			{
				continue;
			}
			else if (vecData[i] <= vecData[i + 1] && vecData[i + 1] >= vecData[i + 2])
			{
				vecSoldIndex.push_back(i + 1);
			}
			else if (vecData[i] >= vecData[i + 1] && vecData[i + 1] >= vecData[i + 2])
			{
				continue;
			}
			else
			{
				vecBuyIndex.push_back(i + 1);
			}
		}

		// 漏掉的两端
		if (vecBuyIndex.size() == 0
			&& vecSoldIndex.size() == 0)
		{
			if (vecData[0] < vecData[nSize - 1])
			{
				vecBuyIndex.push_back(vecData[0]);
				vecSoldIndex.push_back(vecData[nSize - 1]);
			}
		}
		else
		{
			if (vecData[0] < vecData[1] && vecSoldIndex[0] < vecBuyIndex[0])
				vecBuyIndex.push_back(0);

			sort(vecBuyIndex.begin(), vecBuyIndex.end());

			if (vecData[nSize - 2] < vecData[nSize - 1]
				/*&& vecBuyIndex[vecBuyIndex.size() - 1] > vecSoldIndex[vecSoldIndex.size() - 1]*/)
				vecSoldIndex.push_back(nSize - 1);
		}

		int nTotal = 0;
		for (int i = 0; i < vecBuyIndex.size(); i++)
			nTotal -= vecData[i];

		for (int i = 0; i < vecSoldIndex.size(); i++)
			nTotal += vecData[i];

		cout << nTotal << endl;
	}
    return 0;
}

