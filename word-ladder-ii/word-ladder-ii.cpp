// word-ladder-ii.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;


int ladderLength(string start, string end, unordered_set<string> dict)
{
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	if (start.size() != end.size()) return 0;
	if (start.empty() || end.empty())return 0;
	dict.insert(end);
	queue<string> path;
	path.push(start);
	int level = 1;
	int count = 1;
	dict.erase(start);
	while (dict.size() > 0 && !path.empty())
	{
		string curword = path.front();
		path.pop();
		count--;
		for (int i = 0; i < curword.size(); i++)
		{
			string tmp = curword;
			for (char j = 'a'; j <= 'z'; j++)
			{
				if (tmp[i] == j)
					continue;
				tmp[i] = j;
				if (tmp == end)
					return level + 1;
				if (dict.find(tmp) != dict.end())
					path.push(tmp);
				dict.erase(tmp);
			}
		}
		if (count == 0)
		{
			count = path.size();
			level++;
		}
	}
	return 0;
}
void dfsFindLadders(string start, string end, unordered_set<string> dict, int level, vector<vector<string>>& res, vector<string> temp,const int& len)
{
	if (level == len)
	{
		if (start == end)
		{
			res.push_back(temp);
		}
		return;
	}
	if (level > len)
	{
		return;
	}
	for (int i = 0; i < start.length();i++)
	{
		string tempstr = start;
		for (char j = 'a'; j <= 'z';j++)
		{
			if (start[i] == j)
			{
				continue;
			}
			tempstr[i] = j;
			if (dict.find(tempstr) != dict.end())
			{
				dict.erase(tempstr);
				temp.push_back(tempstr);
				dfsFindLadders(tempstr, end, dict, level+1, res, temp,len);
				dict.insert(tempstr);
				temp.pop_back();
			}
		}
	}
}

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
{
	// write your code here
	//first: BFS to find the shortest path n
	//second: use n for DFS to find the collect of it
	vector<vector<string>> res;
	vector<string> temp;
	temp.push_back(start);
	int level = 1;
	unordered_set<string> tempdict = dict;
	dict.insert(end);
	int len = ladderLength(start, end, dict);
	dfsFindLadders(start, end, dict, level, res, temp, len);
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string start = "hit",end = "cog";
	unordered_set<string> dict;
	//["hot","dot","dog","lot","log"]
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	auto res = findLadders(start, end, dict);
	return 0;
}

