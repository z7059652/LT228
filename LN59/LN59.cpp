// LN59.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int threeSumClosest(vector<int> nums, int target)
{
	// write your code here
	if (nums.size() < 3)
		return 0;
	sort(nums.begin(), nums.end());
	int sum = nums[0] + nums[1] + nums[2];
	int min = abs(sum - target);
	for (int i = 0; i <= nums.size() - 3; i++)
	{
		int temp = target - nums[i];
		int j = i + 1, k = nums.size() - 1;
		int mintemp = nums[j] + nums[k];
		while (j < k)
		{
			if (nums[j] + nums[k] > temp)
			{
				if (abs(temp - mintemp) > abs(nums[j] + nums[k] - temp))
					mintemp = nums[j] + nums[k];
				k--;
				continue;
			}
			if (nums[j] + nums[k] < temp)
			{
				if (abs(temp - mintemp) > abs(nums[j] + nums[k] - temp))
					mintemp = nums[j] + nums[k];
				j++;
				continue;
			}
			mintemp = temp;
			break;
		}
		if (min > abs(temp - mintemp))
		{
			min = abs(temp - mintemp);
			sum = nums[i] + mintemp;
		}
	}
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums;
	//2,7,11,15
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);
	threeSumClosest(nums,3);
	return 0;
}

