// LN159.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> num, int start, int end)
{
	int mid = (start + end + 1) / 2;
	if (mid == end)
	{
		if (num[start] < num[end])
		{
			return num[start];
		}
		return num[end];
	}
	if (num[start] < num[end])
		return num[start];
	if (num[mid] > num[start])
		return findMin(num, mid + 1, end);
	return findMin(num, start, mid);
}
int findMin(vector<int> &num)
{
	// write your code here
	return findMin(num, 0, num.size() - 1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	//4,5,6,7,0,1,2
	vector<int> res;
	//res.push_back(4);
	//res.push_back(5);
	//res.push_back(6);
	res.push_back(7);
	res.push_back(0);
	res.push_back(1);
	res.push_back(2);
// 	res.push_back(2);
	//res.push_back(3);
	//res.push_back(4);
	//res.push_back(5);
	int flag = findMin(res);
	return 0;
}

