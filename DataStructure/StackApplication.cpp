#include "stdafx.h"
#include "StackApplication.h"
#include "SeqStack.h"

#include <iostream>
#include <vector>
using namespace std;

bool bracketsMatched(const string &exp)
{
	SeqStack stack = {0};
	SeqStackInit(&stack);

	for (size_t i = 0; i < exp.size(); i++)
	{
		DataType ch = {0};
		if ((exp.at(i) == '(') || (exp.at(i) == '[') || (exp.at(i) == '{'))
		{
			SeqStackPush(&stack, exp.at(i));
		}
		else if ((exp.at(i) == ')') && !SeqStackEmpty(stack) && (0 == SeqStackTop(stack, &ch)) && (ch == '('))
		{
			SeqStackPop(&stack, (DataType*)&ch);
		}
		else if ((exp.at(i) == ')') && !SeqStackEmpty(stack) && (0 == SeqStackTop(stack, &ch)) && (ch != '('))
		{
			cout << "() not match" << endl;
			return false;
		}
		else if ((exp.at(i) == ']') && !SeqStackEmpty(stack) && (0 == SeqStackTop(stack, &ch)) && (ch == '['))
		{
			SeqStackPop(&stack, (DataType*)&ch);
		}
		else if ((exp.at(i) == ']') && !SeqStackEmpty(stack) && (0 == SeqStackTop(stack, &ch)) && (ch != '['))
		{
			cout << "[] not match" << endl;
			return false;
		}
		else if ((exp.at(i) == '}') && !SeqStackEmpty(stack) && (0 == SeqStackTop(stack, &ch)) && (ch == '{'))
		{
			SeqStackPop(&stack, (DataType*)&ch);
		}
		else if ((exp.at(i) == '}') && !SeqStackEmpty(stack) && (0 == SeqStackTop(stack, &ch)) && (ch != '{'))
		{
			cout << "{} not match" << endl;
			return false;
		}
		else if (((exp.at(i) == ')') || (exp.at(i) == ']') || (exp.at(i) == '}')) && SeqStackEmpty(stack))
		{
			cout << "more right brackets" << endl;
			return false;
		}
	}

	if (!SeqStackEmpty(stack))
	{
		cout << "more left brackets" << endl;
		return false;
	}

	return true;
}

std::string MidExp2BackExp(const string &exp)
{
	string strMidExp = exp;
	string outputExp = "";
	vector<string> vecSymbol = {"+", "-", "*", "/", "(", ")", "#" };
	vector<string> vecLarge = {"++", "+-", "+)", "+#", "-+", "--",  "-)", "-#", "*+", "*-", "**", "*/", "*)", "*#",
	"/+", "/-", "/*", "//", "/)", "/#", ")+", ")-", ")*", ")/", "))", ")#"};

	vector<string> vecLittle = {"+*", "+/", "+(", "-*", "-/", "-(", "*(", "/(", "(+", "(-", "(*", "(/", "((",
			"#+", "#-", "#*", "#/", "#("};

	SeqStack stack = { 0 };
	SeqStackInit(&stack);
	SeqStackPush(&stack, '#');

	if (strMidExp.at(strMidExp.size() - 1) != '#')
		strMidExp.append("#");

	for (size_t i = 0; i < strMidExp.size(); i++)
	{
		DataType x1 = { 0 };
		char x2 = strMidExp.at(i);
		string strX2(1, x2);
		
		if (!SeqStackEmpty(stack) && (0 == SeqStackTop(stack, &x1)) && (x1 == '(') && (x2 == ')'))
		{
			SeqStackPop(&stack, &x1);
		}
		else if (!SeqStackEmpty(stack) && (0 == SeqStackTop(stack, &x1)) && (x1 == '#') && (x2 == '#'))
		{
			break;
		}
		else if (!SeqStackEmpty(stack) && (0 == SeqStackTop(stack, &x1)) && (x1 == ')') && (x2 == '('))
		{
			cout << "syntax error" << endl;
			outputExp.empty();
			break;
		}
		else if ((std::find(vecSymbol.begin(), vecSymbol.end(), strX2) != vecSymbol.end()) &&
			!SeqStackEmpty(stack) && (0 == SeqStackTop(stack, &x1)))
		{
			string strTemp = string(1, x1) + strX2;

			auto it = std::find(vecLarge.begin(), vecLarge.end(), strTemp);
			if (it != vecLarge.end())
			{
				SeqStackPop(&stack, &x1);
				outputExp += string(1, x1);
				if (!SeqStackEmpty(stack))
					i--;
				else
				{
					cout << "syntax error" << endl;
					outputExp.empty();
					break;
				}
			}
			else
			{
				SeqStackPush(&stack, x2);
			}
		}
		else
		{
			outputExp += string(1, x2);
		}
	}

	return outputExp;
}
