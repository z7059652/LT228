// LN179.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <bitset>
using namespace std;
int updateBits(int n, int m, int i, int j) 
{
	unsigned int c(0xffffffff);















	c = c << (32 - (j-i+1));
	c = c >> (32 - j - i + 1);
	c = ~c;
	n = n & c;
	m = m << i;
	n = n ^ m;
	return n;
}
int _tmain(int argc, _TCHAR* argv[])
{
	updateBits(1024, 21, 2, 6);
	return 0;
}

