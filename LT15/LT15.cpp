// LT15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

bool IsCompare(int a, int b)
{
	return a > b;
}
bool CompareVector(vector<int> a, vector<int> b)
{
	sort(a.begin(), a.end(), IsCompare);
//	qsort(a.begin(), a.size(), sizeof(a[0]), IsCompare);
	sort(b.begin(), b.end(), IsCompare);
	for (int i = 0; i < a.size();i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}
bool find(vector<int>& nums, int start, int& j, int& k,int sum)
{
	j = start;
	k = nums.size() - 1;
	while (j < k)
	{
		if (nums[j] + nums[k] == sum)
		{
			return true;
		}
		if (nums[j] + nums[k] < sum)
		{
			j++;
		}
		else
		{
			k--;
		}
	}
	return false;
}
vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size();i++)
	{
		if (i > 0 && nums[i] == nums[i- 1])
		{
			continue;
		}
		int j = i + 1,k = nums.size() - 1;
		while (j < k)
		{
			if (nums[j] + nums[k] < 0 - nums[i] || (j > i + 1 && nums[j] == nums[j - 1]))
			{
				j++;
				continue;
			}
			if (nums[j] + nums[k] > 0 - nums[i] || (k < nums.size() - 1 && nums[k] == nums[k + 1]))
			{
				k--;
				continue;
			}
			if (nums[j] + nums[k] == 0 - nums[i])
			{
				vector<int>temp;
				temp.push_back(nums[i]);
				temp.push_back(nums[j]);
				temp.push_back(nums[k]);
				res.push_back(temp);
				j++, k--;
				continue;
			}
		}
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//-1 0 1 2 -1 -4
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	threeSum(nums);
	return 0;
}

