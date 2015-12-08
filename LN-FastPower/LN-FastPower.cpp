// LN-FastPower.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

long long fastPower(int a, int b, int n)
{
	// write your code here
	if (n == 0 || a == 1)
		return 1 % b;
	if (n == 1)
		return a%b;
	int c = 1;
	if (n % 2 == 1)
	{
		c = (a%b)*c;
		n = n - 1;
	}
	long long m = fastPower(a, b, n / 2);
	long long res = (((c*(m%b)) % b)*(m%b)) % b;

	return res;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int res = fastPower(109, 10000007, 1000001); 

	return 0;
}

