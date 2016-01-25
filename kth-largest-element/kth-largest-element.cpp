// kth-largest-element.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using namespace std;

int findmid(int low, int high, vector<int>& nums)
{
	int temp = nums[low];
	while (low < high)
	{
		while (low < high && temp < nums[high])
			high--;
		nums[low] = nums[high];
		while (low < high && nums[low] <= temp)
			low++;
		nums[high] = nums[low];
	}
	nums[low] = temp;
	return low;
}
void qsort(int low, int high, vector<int>& nums)
{
	if (low < high)
	{
		int mid = findmid(low, high, nums);
		qsort(mid + 1, high, nums);
		qsort(low, mid - 1, nums);
	}
}
int qsort(int k, int low, int high, vector<int>& nums)
{
	if (low < high)
	{
		int mid = findmid(low, high, nums);
		if (mid == k)
			return nums[mid];
		else if (mid < k)
			return qsort(k, mid + 1, high, nums);
		else
			return qsort(k, low, mid - 1, nums);
	}
}
int kthLargestElement(int k, vector<int> nums)
{
	// write your code here
	int low = 0, high = nums.size() - 1;
	int mid = qsort(nums.size() - k, low, high, nums);
	return mid;
}
vector<int> initalVector(int num)
{
	vector<int> res;
	for (int i = 0; i < num;i++)
	{
		res.push_back(i);
	}
	return res;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> res = initalVector(1000);
	int k = kthLargestElement(888, res);
	return 0;
}

