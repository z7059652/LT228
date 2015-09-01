// LN158.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

bool _stdcall anagram(string s, string t)
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
typedef struct MyStruct
{
	int a : 4;
	int b : 4;
}TEST;
enum MyEnum
{

};
#define PR(...) printf(__VA_ARGS__)
int _tmain(int argc, _TCHAR* argv[])
{
	string s = "abcd",t = "dcba";
	TEST a;
	a.a = 8;
	a.b = 9;
	bool flag = anagram(s, t);
	cout << __cplusplus << endl;
	return 0;
}

