// LN158.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

bool anagram(string s, string t)
{
	if (s.length() != t.length())
	{
		return false;
	}
	int* flag = new int[26];
	memset(flag, 0, 26*sizeof(int));
	for (int i = 0; i < s.length();i++)
	{
		flag[s[i] - 'a']++;
	}
	for (int i = 0; i < t.length(); i++)
	{
		flag[t[i] - 'a']--;
	}
	for (int i = 0; i < 26;i++)
	{
		if (flag[i] != 0)
		{
			return false;
		}
	}
	return true;
}
int _tmain(int argc, _TCHAR* argv[])
{
	string s = "abcd",t = "dcba";
	bool flag = anagram(s, t);
	return 0;
}

