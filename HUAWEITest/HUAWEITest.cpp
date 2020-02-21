// HUAWEITest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int cMaxLen = 1000000;

void printMaxLenSubstr(const vector<string> &vec)
{
	// 寻找最长的连续子串
	if (vec.size())
	{
		int nMax = vec[0].length();
		int nIndex = 0;
		for (size_t i = 1; i < vec.size(); i++)
		{
			if (vec[i].length() >= nMax)
			{
				nMax = vec[i].length();
				nIndex = i;
			}
		}
		cout << vec[nIndex] << endl;
	}
	else
	{
		cout << "" << endl;
	}
}

int main()
{
	char ch[cMaxLen];
	while (cin.getline(ch, cMaxLen))
	{
		vector<string> vec;
		string strTmp = "";
		int nLen = strlen(ch);
		for (int i = 0; i < nLen; i++)
		{
			// 结束，存放最后一个子串
			if (ch[i] == '\0')
			{
				if (!strTmp.empty())
				{
					vec.push_back(strTmp);
					strTmp.clear();
				}
				break;
			}

			if ('+' == ch[i] || '-' == ch[i])
			{
				// 先验证合法性
				if (i + 1 < nLen)
				{
					// +、-后为数字，合法
					if (ch[i + 1] >= '0' && ch[i + 1] <= '9')
					{
						if (!strTmp.empty()) // 说明本段结束，进入下一子串
						{
							vec.push_back(strTmp);
							strTmp.clear();
						}
						else
						{
							strTmp.push_back(ch[i]);
						}
					}
					else
					{
						strTmp.clear();
						continue;
					}
				}
				else
				{
					strTmp.clear();
					break;
				}
			}
			else if ('.' == ch[i])
			{
				// 判断合法性
				if (i + 1 < nLen && ch[i + 1] != '\0')
				{
					// 前后是否是数字
					if (ch[i - 1] >= '0' && ch[i - 1] <='9'
						&& ch[i + 1] >= '0' && ch[i + 1] <= '9')
					{
						size_t pos = strTmp.find('.'); // 查找前面是否已有.
						if (pos != string::npos)
						{
							// 前面的符合规则的子串入容器
							vec.push_back(strTmp);
							// 后面的子串计算开始位置
							strTmp = strTmp.substr(pos + 1, i - pos);
						}
						else
						{
							strTmp.push_back(ch[i]);
						}
					}
					else
					{
						strTmp.clear();
						continue;
					}
				}
				else
				{
					strTmp.clear();
					break;
				}
			}
			else
			{
				strTmp.push_back(ch[i]);
			}
		}

		printMaxLenSubstr(vec);

		vec.clear();
		strTmp.clear();
	}
    return 0;
}
