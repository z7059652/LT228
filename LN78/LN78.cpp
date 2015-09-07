// LN78.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <windows.h>
#include <windef.h>
using namespace std;
class Solution {
public:
	/**
	* @param strs: A list of strings
	* @return: The longest common prefix
	*/
	struct MyStruct
	{
		char a;
		int count;
	};
	string longestCommonPrefix(vector<string> &strs)
	{
		// write your code here
		MyStruct Label[100];
		int m = INT_MAX;
		memset(Label, 0, 100 * sizeof(MyStruct));
		for (int i = 0; i < strs.size();i++)
		{
			int loop = min(m, strs[i].length());
			m = 0;
			for (int j = 0; j < loop;j++)
			{
				if (Label[j].a == 0 && Label[j].a != strs[i][j])
				{
					Label[j].a = strs[i][j];
					Label[j].count = 1;
					m += 1;
					continue;
				}
				if (Label[j].a == strs[i][j])
				{
					Label[j].count++;
					m++;
					continue;
				}
				else
				{
					break;
				}
			}
		}
		string s;
		for (int i = 0; i < 100;i++)
		{
			if (Label[i].count == strs.size())
			{
				s += Label[i].a;
				continue;
			}
			break;
		}
		return s;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> str;
	str.push_back(string("ABCDEFG"));
	str.push_back(string("ABCDEFG"));
	str.push_back(string("ABCDEFA"));
	Solution a;
	string s = a.longestCommonPrefix(str);
	return 0;
}

