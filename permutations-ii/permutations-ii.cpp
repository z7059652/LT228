// permutations-ii.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <set>
#include <sstream>
using namespace std;
set<string> flag;
void Swap(vector<int> &nums, int x, int y)
{
	int temp = nums[x];
	nums[x] = nums[y];
	nums[y] = temp;
}
void permuteUnique(vector<int> nums, int cur, int n, vector<vector<int>>& res)
{
	if (cur == n)
	{
		ostringstream os;
		for (int i = 0; i < nums.size();i++)
		{
			os << nums[i];
		}
		if (flag.find(os.str()) == flag.end())
		{
			res.push_back(nums);
		}
	}
	for (int i = cur; i < n;i++)
	{
		Swap(nums, i, cur);
		permuteUnique(nums, cur + 1, n, res);
		Swap(nums, cur,i);
	}
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
	// write your code here
	vector<vector<int>> res;
	permuteUnique(nums, 0, nums.size(), res);
	return res;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	vector<vector<int>> res;

	res = permuteUnique(test);
	return 0;
}

