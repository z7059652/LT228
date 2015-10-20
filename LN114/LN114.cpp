// LN114.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
long long cal_factorial(long a, long start = 1)
{
	long long res = 1;
	int c = start;
	while (start >= 1)
	{
		res *= a;
		if (res < 0)
		{
			break;
		}
		while (c > 1 && res%c == 0)
		{
			res = res / c;
			c--;
		}
		a--, start--;
	}
	return res;
}
int uniquePaths(int m, int n)
{
	int max_mn = (m <= n ? m : n) - 1; //尽可能使得乘积较小，防止溢出
	if (max_mn == 0)
		return 1;
	long long a = cal_factorial(m + n - 2, max_mn);
	//long long b = cal_factorial(max_mn, max_mn);
	//long long result = a / b;
	return a;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int res = uniquePaths(17, 18);
	return 0;
}

