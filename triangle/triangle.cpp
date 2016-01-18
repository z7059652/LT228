// triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;


int minimumTotal(vector<vector<int> > &triangle)
{
	// write your code here
	int n = triangle.size();
	if (n == 1)
	{
		return triangle[0][0];
	}
	vector<int> flag(n, 0);
	flag[0] = triangle[0][0];
	for (int i = 1; i < n;i++)
	{
		int m = triangle[i].size();
		vector<int> tempflag = flag;
		for (int j = 0; j < m;j++)
		{
			if (j > 0 && j < m - 1)
			{
				flag[j] = min(tempflag[j - 1], tempflag[j]) + triangle[i][j];
			}
			else if (j == 0)
			{
				flag[j] = tempflag[j] + triangle[i][j];
			}
			else
				flag[j] = tempflag[j-1] + triangle[i][j];

		}
	}
	int res = flag[0];
	for (int i = 0; i < n;i++)
	{
		if (res > flag[i])
			res = flag[i];
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//[[-1],[2,3],[1,-1,-3]]
	vector<int> v1,v2,v3;
	v1.push_back(-1);
	v2.push_back(2);
	v2.push_back(3);
	v3.push_back(1);
	v3.push_back(-1);
	v3.push_back(-3);
	vector<vector<int>> res;
	res.push_back(v1);
	res.push_back(v2);
	res.push_back(v3);
	int flag = minimumTotal(res);
	return 0;
}


