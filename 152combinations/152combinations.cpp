// 152combinations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void combine(int n, int k, vector<int> res, vector<vector<int>>& vctres)
{
	if (k < 1)
	{
		sort(res.begin(), res.end());
		vctres.push_back(res);
		return;
	}
	if (n == k)
	{
		for (int i = n; i > 0;i--)
		{
			res.push_back(i);
		}
		sort(res.begin(), res.end());
		vctres.push_back(res);
		return;
	}
	vector<int> temp = res;
	temp.push_back(n);
	combine(n - 1, k - 1,temp,vctres);
	combine(n - 1, k,res,vctres);
}

vector<vector<int> > combine(int n, int k)
{
	// write your code here
	vector<vector<int>> res;
	if (n < k)
	{
		return res;
	}
	vector<int> restemp;
	combine(n, k, restemp, res);
 	return res;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> res = combine(4, 2);
	return 0;
}

