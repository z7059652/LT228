// LN28.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target)
{
	// write your code here
	vector<vector<int>>::iterator iter = matrix.end() - 1;
	int imax = *(iter->end() - 1);
	if (target < matrix[0][0] || target > imax)
	{
		return false; 
	}
	int start = 0, end = matrix.size() - 1;
	int mid = (start + end) / 2;
	while (mid >= start && mid <= end)
	{
		if (mid < matrix.size() - 1 && matrix[mid][0] <= target && matrix[mid + 1][0] > target)
			break;
		if (mid == matrix.size() - 1 && matrix[mid][0] <= target)
			break;
		if (matrix[mid][0] < target)
		{
			start = mid + 1;
		}
		else if (matrix[mid][0] > target)
		{
			end = mid - 1;
		}
		else
			return true;
		mid = (start + end) / 2;
	}
	iter = matrix.begin() + mid;
	start = 0, end = iter->size() - 1;
	mid = (start + end) / 2;
	while (mid >= start && mid <= end)
	{
		if (*(iter->begin() + mid) == target)
		{
			return true;
		}
		if (*(iter->begin() + mid) < target)
		{
			start = mid + 1;
		}
		else
			end = mid - 1;
		mid = (start + end) / 2;
	}
	return false;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> re;
	vector<int> re1;
	vector<int> re2;
	vector<vector<int>> matrix;
	re.push_back(1);
	//re.push_back(3);
	//re.push_back(5);
	//re.push_back(7);
	//re1.push_back(10);
	//re1.push_back(11);
	//re1.push_back(16);
	//re1.push_back(20);
	re2.push_back(3);
	//re2.push_back(30);
	//re2.push_back(34);
	//re2.push_back(50);
	matrix.push_back(re);
	//matrix.push_back(re1);
	matrix.push_back(re2);
	auto res = searchMatrix(matrix, 3);
	return 0;
}

