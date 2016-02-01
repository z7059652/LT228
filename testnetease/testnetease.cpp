// testnetease.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <algorithm>
int main()
{
	int R = 0, x1 = 0, y1 = 0, x2 = 0, x3 = 0, y2 = 0, y3 = 0, x0 = 0, y0 = 0;
	scanf("%d %d %d %d %d %d %d %d %d", &R, &x1, &y1, &x2, &y2, &x3, &y3, &x0, &y0);
	int sum = 0;
	int temp = 0;
	temp = sqrt((x1 - x0)*(x1 - x0) + (y1 - y0)*(y1 - y0));
	if (temp <= R)
		sum++;
	temp = sqrt((x2 - x0)*(x2 - x0) + (y2 - y0)*(y2 - y0));
	if (temp <= R)
		sum++;
	temp = sqrt((x3 - x0)*(x3 - x0) + (y3 - y0)*(y3 - y0));
	if (temp <= R)
		sum++;
	printf("%dx\n", sum);
	return 0;
}
