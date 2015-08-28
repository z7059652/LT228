// LT228.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
using namespace std;

void stringformat(string& str,int a,int b)
{
	char buf[10];
	memset(buf, 0, 10);
	if (a==b)
	{
		sprintf(buf, "%d", a);
	}
	else
		sprintf(buf, "%d->%d", a, b);
	str = buf;
}
vector<string> summaryRanges(vector<int>& nums)
{
	vector<string> res;
	if (nums.size() == 0)
	{
		return res;
	}
	int startpos = 0, endpos = 0;
	int ifirst, ilast;
	for (int i = 0; i < nums.size() - 1; i++)
	{
// 		ifirst = ilast = nums[i];
		startpos = endpos = i;
		while (i < nums.size() - 1)
		{
			if (nums[i + 1] - nums[i] == 1)
			{
				i++;
				endpos = i;
			}
			else
			{
				string temp;
				stringformat(temp, nums[startpos], nums[endpos]);
				res.push_back(temp);
				break;
			}
		}
	}
	string temp;
	if (endpos == nums.size() - 1)
		stringformat(temp, nums[startpos], nums[endpos]);
	else
		stringformat(temp, nums[endpos + 1], nums[endpos + 1]);
	res.push_back(temp);
	return res;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(11);
	nums.push_back(12);
	nums.push_back(13);
	nums.push_back(18);
	vector<string> res = summaryRanges(nums);
	return 0;
}
