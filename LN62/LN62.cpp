// LN62.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;


int search(vector<int> &A, int left, int right, int target)
{
	if (left > right)
		return -1;
	int mid = (left + right) / 2;
	if (A[mid] == target)
		return mid;
	if (A[mid] < target)
		return search(A, mid + 1, right, target);
	return search(A, left, mid-1, target);
}
int findMax(vector<int> &A, int low, int high)
{
	int mid = (low + high) / 2;
	if (mid == low)
		return A[low] > A[high] ? low : high;
	if (A[mid] > A[mid+1] && A[mid] > A[mid-1])
	{
		return mid;
	}
	if (A[mid] <= A[low])
		return findMax(A, low, mid);
	return findMax(A, mid + 1, high);
}
int search(vector<int> &A, int target)
{
	// write your code here
	if (A.size() == 0)
		return -1;
	int pos = findMax(A, 0, A.size() - 1);
	if (A[pos] == target)
		return pos;
	if (A[pos] < target || (A[0] > target && pos == A.size() - 1))
		return -1;
	if (A[pos] > target && A[0] <= target)
		return search(A, 0, pos, target);
	return search(A, pos + 1, A.size() - 1, target);
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> A;
	//A.push_back(4);
	//A.push_back(5);
	//A.push_back(6);
	//A.push_back(2);
	//A.push_back(3);
	for (int i = 0; i <= 3000; i++)
	{
		A.push_back(i + 133);
	}
	for (int i = 129; i > 10; i--)
	{
		A.push_back(i);
	}
	int res = search(A, 131);
	return 0;
}

