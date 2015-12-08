// LNLargest-number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <set>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

string largestNumber(vector<int> &num)
{
	// write your code here
	vector<string> res;
	bool cur = false;
	for (int i = 0; i < num.size(); i++)
	{
		char temp[10];
		if (0 == num[i])
		{
			continue;
			cur = true;
		}
		sprintf((char*)temp, "%d\0", num[i]);
		res.push_back(temp);
	}
	if (cur)
		res.push_back("0");
	sort(res.begin(), res.end());
	string ans;
	for (int i = res.size() - 1; i >= 0;i--)
	{
		ans += res[i];
	}
	return ans;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> num;
	num.push_back(0);
	//num.push_back(20);
	//num.push_back(23);
	//num.push_back(4);
	//num.push_back(8);
	string res = largestNumber(num);
//	cout << res << endl;
	return 0;
}

