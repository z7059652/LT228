// largest-rectangle-in-histogram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int largestRectangleArea(vector<int> &height)
{
	// write your code here
	int m = height.size();
	if (m == 0) return 0;
	vector<int> dp(m, 0);
	dp[0] = height[0];
	int maxhgt = dp[0];
	for (int i = 1; i < m; i++)
	{
		int hgt = height[i];
		int j = i - 1;
		for (; j >= 0; j--)
		{
			if (height[j] < hgt)
				break;
		}
		if (j >= 0)
			dp[i] = max(height[i] * (i - j+1), dp[j] + height[j] * (i - j));
		else
			dp[i] = height[i] * (i - j);
		maxhgt = max(dp[i], maxhgt);
	}
	return maxhgt;
}
void convert2Matrix(string data, vector<int>& matrix)
{
	int npos = -1;
	while ((npos = data.find(",")) != string::npos)
	{
		string temp = data.substr(0, npos);
		int inter = atoi(temp.c_str());
		matrix.push_back(inter);
		data = data.substr(npos + 1, data.length() - npos - 1);
	}
	matrix.push_back(atoi(data.c_str()));
}

int _tmain(int argc, _TCHAR* argv[])
{
	string data = "3,5,5,2,5,5,6,6,4,4,1,1,2,5,5,6,6,4,1,3";
	vector<int> matrix;
	convert2Matrix(data, matrix);
	int res = largestRectangleArea(matrix);
	memcpy()
	return 0;
}

