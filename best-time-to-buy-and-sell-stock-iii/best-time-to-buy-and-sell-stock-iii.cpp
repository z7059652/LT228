// best-time-to-buy-and-sell-stock-iii.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution 
{
public:
	/**
	* @param prices: Given an integer array
	* @return: Maximum profit
	*/
	void InitialSeq(vector<int>& seq,vector<int> &prices)
	{
		int curMin = prices[0];
		for (int j = 1; j < prices.size();j++)
		{
			curMin = min(curMin, prices[j]);
			seq[j] = max(seq[j - 1], prices[j] - curMin);
		}
	}
	void ReInitialSeq(vector<int>& seq, vector<int> &prices)
	{
		vector<bool> flag(prices.size(), 0);
		int curMax = prices[prices.size() - 1];
		for (int j = prices.size()-2; j >= 0;j--)
		{
			curMax = max(curMax, prices[j]);
			seq[j] = max(seq[j + 1], curMax - prices[j]);
		}

	}
	int maxProfit(vector<int> &prices) 
	{
		// write your code here
		vector<int> seq(prices.size(),0);
		vector<int> rseq(prices.size(), 0);
		InitialSeq(seq, prices);
		ReInitialSeq(rseq, prices);
		int sum = 0;
		int tempsum = 0;
		for (int i = 0; i < prices.size();i++)
		{
			tempsum = seq[i] + rseq[i];
			sum = max(sum, tempsum);
		}
		return sum;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> prices;//3,3,5,0,0,3,1,4
	prices.push_back(3);
	prices.push_back(3);
	prices.push_back(5);
	prices.push_back(0);
	prices.push_back(0);
	prices.push_back(3);
	prices.push_back(1);
	prices.push_back(4);
	Solution s;
	int res = s.maxProfit(prices);
	return 0;
}

