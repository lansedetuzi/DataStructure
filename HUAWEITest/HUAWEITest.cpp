// HUAWEITest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int cMaxLen = 1000000;

void printMaxLenSubstr(const vector<string> &vec)
{
	// Ѱ����������Ӵ�
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
			// ������������һ���Ӵ�
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
				// ����֤�Ϸ���
				if (i + 1 < nLen)
				{
					// +��-��Ϊ���֣��Ϸ�
					if (ch[i + 1] >= '0' && ch[i + 1] <= '9')
					{
						if (!strTmp.empty()) // ˵�����ν�����������һ�Ӵ�
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
				// �жϺϷ���
				if (i + 1 < nLen && ch[i + 1] != '\0')
				{
					// ǰ���Ƿ�������
					if (ch[i - 1] >= '0' && ch[i - 1] <='9'
						&& ch[i + 1] >= '0' && ch[i + 1] <= '9')
					{
						size_t pos = strTmp.find('.'); // ����ǰ���Ƿ�����.
						if (pos != string::npos)
						{
							// ǰ��ķ��Ϲ�����Ӵ�������
							vec.push_back(strTmp);
							// ������Ӵ����㿪ʼλ��
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
