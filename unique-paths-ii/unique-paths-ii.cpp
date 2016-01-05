// unique-paths-ii.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
{
	// write your code here
	if (obstacleGrid[0][0] == 1)
		return 0;
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	if (m == 1 || n == 1) return 1;
	vector<int> temp(n, 0);
	vector<vector<int>> flag(m, temp);
	flag[0][0] = 1;
	for (int i = 1; i < m; i++)
	{
		if (obstacleGrid[i][0] == 1)
			flag[i][0] = 0;
		else
			flag[i][0] = flag[i - 1][0];
	}
	for (int i = 1; i < n; i++)
	{
		if (obstacleGrid[0][i] == 1)
			flag[0][i] = 0;
		else
			flag[0][i] = flag[0][i - 1];
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (obstacleGrid[i][j] == 1)
				flag[i][j] = 0;
			else
				flag[i][j] = flag[i - 1][j] + flag[i][j - 1];
		}
	}
	return flag[m - 1][n - 1];
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> temp(6, 0);
	vector<vector<int>> flag(7, temp);
	flag[0][2] = 1;
	int res = uniquePathsWithObstacles(flag);
	return 0;
}

