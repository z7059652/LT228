// 135combination-sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

void combinationSum(vector<int> &candidates, int target, int &sum, vector<int>temp, vector<vector<int>>&res,int floor)
{
	if (sum > target)
	{
		return;
	}
	if (sum == target)
	{
		sort(temp.begin(), temp.end());
		res.push_back(temp);
	}
	for (int i = floor; i < candidates.size();i++)
	{
		sum += candidates[i];
		temp.push_back(candidates[i]);
		combinationSum(candidates, target, sum, temp, res,i);
		sum -= candidates[i];
		temp.pop_back();
	}
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
	// write your code here
	int sum = 0;
	vector<vector<int>> res;
	vector<int> temp;
	combinationSum(candidates, target, sum, temp, res,0);
	return res;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> candidates;
	candidates.push_back(2);
	candidates.push_back(3);
	candidates.push_back(6);
	candidates.push_back(7);
	vector<vector<int>> res = combinationSum(candidates, 7);
	return 0;
}

