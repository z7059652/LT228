// LN141.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int Mysqrt(int x)
{
	if (x == 0)
		return 0;
	double pre;
	double cur = 1;
	do
	{
		pre = cur;
		cur = x / (2 * pre) + pre / 2.0;
	} while (abs(cur - pre) > 0.00001);
	return int(cur);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int res = Mysqrt(2147483647);
	return 0;
}

