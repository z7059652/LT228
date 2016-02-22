// max-points-on-a-line.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


struct Point {
int x;
int y;
Point() : x(0), y(0) {}
Point(int a, int b) : x(a), y(b) {}

};
int maxPoints(vector<Point>& points)
{
	// Write your code here
	if (points.size() < 3) return points.size();

	int maxcount = 0;
	for (int i = 0; i < points.size(); i++)
	{
		map<double, int> flag, limit;
		int dup = 0;
		for (int j = 0; j < points.size(); j++)
		{
			if (i == j) continue;
			double k = 0;
			if (points[j].x == points[i].x && points[j].y == points[i].y)
			{
				dup++;
				continue;
			}
			if (points[j].x == points[i].x)
			{
				k = INT_MAX;
			}
			else
				k = (points[j].y - points[i].y) / (1.0*(points[j].x - points[i].x));
			if (flag.find(k) != flag.end())
			{
				flag[k]++;
			}
			else
				flag.insert(make_pair(k, 1));
		}
		if (flag.size() == 0)
		{
			maxcount = max(maxcount, dup);
		}
		else
			for (map<double, int>::iterator iter = flag.begin(); iter != flag.end(); iter++)
			{
				maxcount = max(maxcount, iter->second + dup);
			}
		flag.clear();
	}
	return maxcount + 1;
}
int _tmain(int argc, _TCHAR* argv[])
{
	//[1,2],[3,6],[0,0],[1,3]
	Point a(1, 2), b(3,6), c(0,0), d(1,3);
	vector<Point> points;
	points.push_back(a);
	points.push_back(b);
	points.push_back(c);
	points.push_back(d);
	maxPoints(points);
	return 0;
}

