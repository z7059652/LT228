// LT165.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
string removezero(string str)
{
	string temp;
	int pos = 0;
	for (int i = 0; i < str.length();i++)
	{
		if (str[i] != '0')
		{
			pos = i;
			break;
		}
	}
	temp = str.substr(pos,str.length());
	return temp;
}
void splitbysym(string str,string& first,string& last)
{
	int pos = 0;
	while (pos < str.length())
	{
		if (str[pos] != '.')
		{
			pos++;
			continue;
		}
		break;
	}
	first = str.substr(0,pos);
	if (pos == str.length())
	{
		return;
	}
	last = str.substr(pos + 1, str.length() - pos);
}
int compareVersion(string aa, string bb)
{
	string aafirst = "0", aalast = "0";
	splitbysym(aa, aafirst, aalast);
	aafirst = removezero(aafirst);
	aalast = removezero(aalast);
	string bbfirst = "0", bblast = "0";
	splitbysym(bb, bbfirst, bblast);
	bbfirst = removezero(bbfirst);
	bblast = removezero(bblast);
	int af = atoi(aafirst.c_str());
	int al = atoi(aalast.c_str());
	int bf = atoi(bbfirst.c_str());
	int bl = atoi(bblast.c_str());
	if (af > bf)
	{
		return 1;
	}
	if (af < bf)
	{
		return -1;
	}
	if (al > bl)
	{
		return 1;
	}
	if (al < bl)
	{
		return -1;
	}
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	string a = "1.2";
	string b = "1.10";
	int i = compareVersion(a, b);
	return 0;
}

