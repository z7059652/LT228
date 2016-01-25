// maximal-rectangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <hash_map>
#include <set>
using namespace std;
int maximalRectangle(vector<vector<char>>& matrix)
{
	if (matrix.size() == 0) return 0;
	int m = matrix.size();
	int n = matrix[0].size();
	if (m == 1)
	{
		int maxlen = 0;
		for (int i = 0; i < n;)
		{
			int count = 0;
			while (i < n && matrix[0][i++] == '1')
				count++;
			maxlen = max(maxlen, count);
		}
		return maxlen;
	}
	vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, 0)));
	for (int i = 0; i < m; i++)
	{
		if (matrix[i][0] == '0')
		{
			dp[i][0][0] = 0;
			dp[i][0][1] = 0;
		}
		else
		{
			if (i > 0)
			{
				dp[i][0][0] = dp[i - 1][0][0] + 1;
			}
			else
			{
				dp[i][0][0] = 1;
			}
			dp[i][0][1] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (matrix[0][i] == '0')
		{
			dp[0][i][0] = 0;
			dp[0][i][1] = 0;
		}
		else
		{
			dp[0][i][0] = 1;
			if (i > 0)
			{
				dp[0][i][1] = dp[1][i - 1][1] + 1;
			}
			else
				dp[0][i][1] = 1;
		}
	}
	int summax = 0;
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (matrix[i][j] == '0')
			{
				dp[i][j][0] = 0;
				dp[i][j][1] = 0;
			}
			else
			{
				if (matrix[i - 1][j] == '0')
				{
					dp[i][j][0] = 1;
					dp[i][j][1] = dp[i][j - 1][1] + 1;
				}
				else if (matrix[i][j - 1] == '0')
				{
					dp[i][j][0] = dp[i - 1][j][0] + 1;
					dp[i][j][1] = 1;
				}
				else
				{
					int aw = dp[i - 1][j][0] + 1;
					int ah = min(dp[i - 1][j][1], 1 + dp[i][j - 1][1]);
					int bw = min(dp[i - 1][j][0] + 1, dp[i][j - 1][0]);
					int bh = dp[i][j - 1][1] + 1;
					if (aw*ah > bh*bw)
					{
						dp[i][j][0] = aw;
						dp[i][j][1] = ah;
					}
					else
					{
						dp[i][j][0] = bw;
						dp[i][j][1] = bh;
					}
				}
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (summax < dp[i][j][0] * dp[i][j][1])
			{
				summax = dp[i][j][0] * dp[i][j][1];
			}
		}
	}
	return summax;
}
void store2matrix(string data, vector<vector<char>>& matrix)
{
	vector<char> s1;
	for (int i = 0; i < data.length();i++)
	{
		s1.push_back(data[i]);
	}
	matrix.push_back(s1);
}
void convert2Matrix(string data, vector<vector<char>>& matrix)
{
	int npos = -1;
	while ((npos = data.find(","))!= string::npos)
	{
		string temp = data.substr(0, npos);
		data = data.substr(npos + 1, data.length() - npos - 1);
		store2matrix(temp, matrix);
	}
	store2matrix(data, matrix);
}

int _tmain(int argc, _TCHAR* argv[])
{
	hash_map<int, int>  hm;
	multiset<int> mt;
	mt.insert(8);
	mt.insert(8);
	mt.erase(8);
	hm.insert(make_pair(4, 3));
	hm.insert(make_pair(2, 3));
	hm.insert(make_pair(8, 3));
	string data = "1011100010,0100000110,0101000011,1110000010,0111001010,1101101110";
	vector<vector<char>> matrix;
	convert2Matrix(data, matrix);
	int res = maximalRectangle(matrix);
	//hash_map<int, int>:
	return 0;
}