// LN-binaryrepresentation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string Int2Binary(int n)
{
	if (n == 0)
	{
		return "0";
	}
	if (n == 1)
	{
		return "1";
	}
	int temp = n % 2;
	if (temp == 0)
	{
		return Int2Binary(n / 2) + "0";
	}
	return Int2Binary(n / 2) + "1";
}
int stringMutil2(string& num)
{
	int pos = num.find(".");
	if (pos == num.length() - 1)
		pos == -1;
	if (pos == -1)
	{
		return -1;
	}
	int c = 0;
	for (int i = num.length() - 1; i > pos;i--)
	{
		int a = num[i] - '0';
		num[i] = (2 * a) % 10 + '0' + c;
		c = (2 * a + c) / 10;
	}
	for (int i = num.length() - 1; i >= 0;i--)
	{
		if (num[i] == '0')
		{
			continue;
		}
		pos = i;
		break;
	}
	num = num.substr(0, 1 + pos);
	return c + '0';
}
string Point2Int(string num)
{
	int index = -2;
	//int m = 0;
	//while (true)
	//{
	//	m = pow(2, index);

	//}
	int count = 0;
	string res = ".";
	while (true)
	{
		index = num.find(".");
		if (index == num.length() - 1)
		{
			break;
		}
		if (count == 32)
		{
			return "error";
		}
		res += stringMutil2(num);
		count++;
	}	
	return res;
}
string binaryRepresentation(string n)
{
	// wirte your code here
	int pos = n.find_first_of(".");
	if (pos == -1)
	{
		int res = atoi(n.c_str());
		return Int2Binary(res);
	}
	string a = n.substr(0, pos);
	string b = n.substr(pos + 1, n.length() - pos - 1);
	string btemp = Point2Int("0."+b);
	if (!btemp.compare("error"))
	{
		return "error";
	}
	pos = btemp.find_first_of(".");
	bool flag = false;
	for (int i = pos + 1; i < btemp.length();i++)
	{
		if (btemp[i] != '0')
		{
			flag = !flag;
			break;
		}
	}
	if (!flag)
	{
		return Int2Binary(atoi(a.c_str()));
	}
	return Int2Binary(atoi(a.c_str())) + btemp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string res = binaryRepresentation("3.125");
	return 0;
}

