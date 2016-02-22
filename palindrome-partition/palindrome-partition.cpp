// palindrome-partition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution 
{
public:
	/**
	* @param s: A string
	* @return: A list of lists of string
	*/
	bool IsOk(string s)
	{
		int i = 0;
		int j = s.length() - 1;
		while (i < j)
		{
			if (s[i] == s[j])
			{
				i++;
				j--;
			}
			else
				return false;
		}
		return true;
	}
	void dfs(vector<vector<string>> &res, vector<string> tempres, int start, string s)
	{
		if (start == s.length())
		{
			res.push_back(tempres);
			return;
		}
		for (int i = start; i < s.length(); i++)
		{
			string str = s.substr(start, i - start + 1);
			if (IsOk(str))
			{
				tempres.push_back(str);
				dfs(res, tempres, i+1, s);
				tempres.pop_back();
			}
		}
	}
	vector<vector<string>> partition(string s)
	{
		// write your code here
		vector<vector<string>> res;
		vector<string> temp;
		dfs(res, temp, 0, s);
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	string str("ab");
	s.partition(str);
	return 0;
}

