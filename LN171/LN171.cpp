// LN171.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int compare(const void *arg1, const void *arg2)
{
	/* Compare all of both strings: */
	return (*(char**)arg1-*(char**)arg2);
}
vector<string> anagrams(vector<string> &strs)
{
	map<string, int> m1;
	map<string, int>::iterator iter;
	vector<string> res;
	for (int i = 0; i < strs.size();i++)
	{
		string s = strs[i];
		if (s == "")
		{
			continue;
		}
		sort(s.begin(), s.end());
		if (m1.find(s) == m1.end())
		{
			m1.insert(pair<string, int>(s,1));
		}
		else
		{
			m1[s]++;
		}
	}
	for (int i = 0; i < strs.size(); i++)
	{
		string s = strs[i];
		if (s == "")
		{
			res.push_back(s);
			continue;
		}
		sort(s.begin(), s.end());
		iter = m1.find(s);
		if (iter->second > 1)
			res.push_back(strs[i]);
	}
	return res;
}
int _tmain(int argc, _TCHAR* argv[])
{
	//["tea","tea","ate","eat","den"]
	vector<string> strs;
	strs.push_back("tea");
	strs.push_back("and");
	strs.push_back("ate");
	strs.push_back("eat");
	strs.push_back("den");
	anagrams(strs);
	return 0;
}

