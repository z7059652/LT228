// 18subsets-ii.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
using namespace std;
set<string> flag;
void dfsSub(vector<int>& s, vector<int> temp,vector<vector<int>>& res, int cur, int n,string os)
{
	if (n == 0)
	{
		if (flag.find(os) == flag.end())
		{
			res.push_back(temp);
			flag.insert(os);
		}
		return;
	}
	if (cur == s.size())
	{
		return;
	}
	dfsSub(s, temp, res, cur + 1, n,os);
	temp.push_back(s[cur]);
	ostringstream ss;
	ss << s[cur];
	os += ss.str();
	dfsSub(s, temp, res, cur + 1, n-1,os);
}
void BuildSub(vector<int>& s, vector<vector<int>>& res,int n)
{
	vector<int> temp;
	string os;
	dfsSub(s, temp, res, 0,n,os);
}
vector<vector<int>> subsetsWithDup(const vector<int> &S)
{
	// write your code here
	vector<vector<int>> res;
	res.push_back(vector<int>());
	int num = S.size();
	vector<int> temp = S;
	sort(temp.begin(), temp.end());
	if (num == 0)
	{
		goto Exit;
	}
	for (int i = 1; i < num;i++)
	{
		BuildSub(temp, res, i);
	}
	res.push_back(S);

Exit:
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> S;
	S.push_back(1);
	S.push_back(2);
	S.push_back(2);
	subsetsWithDup(S);
	return 0;
}

