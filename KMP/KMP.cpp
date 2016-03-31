// KMP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
void MyPrint(int a[],int len)
{
	for (int i = 0; i < len;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void getNextValue(string s, int a[])
{
	a[0] = -1;
	int i = 1,k = -1;
	while( i < s.length())
	{
		if (k == -1 || s[i] == s[k])
		{
			a[i] = k + 1;
			i++;
			k++;
		}
		else
		{
			k = a[k];
		}
	}
	a[0] = 0;
	//move //
	for (int i = s.length() - 1; i > 0;i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = -1;
	//优化//
	for (int i = 1; i < s.length();i++)
	{
		int k = a[i];
		if (s[k] == s[i])
		{
			a[i] = a[k];
		}
	}
}
int KMPSearch(string s,string p,int a[])
{
	int slen = s.length();
	int plen = p.length();
	int i = 0, j = 0;
	while (i < slen && j < plen)
	{
		if (j == -1 || s[i] == p[j])
		{
			i++, j++;
		}
		else
		{
			j = a[j];
		}
	}
	if (j == plen)
	{
		return i - j;
	}
	return -1;
}
int _tmain(int argc, _TCHAR* argv[])
{
	string s = "abab",p = "abadabacabab";
	int* a = new int[s.length()];
	memset(a, 0, sizeof(int)*s.length());
	getNextValue(s, a);
	MyPrint(a,s.length());
	int pos = KMPSearch(p,s, a);
	free(a);
	a = NULL;
	return 0;
}

