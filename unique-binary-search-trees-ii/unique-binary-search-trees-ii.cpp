// unique-binary-search-trees-ii.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
using namespace std;

/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode*> helper(int start, int end)
	{
		vector<TreeNode*> allTrees;
		if (start > end || end < start || start == end)
		{
			TreeNode* root = NULL;
			if (start == end)
				root = new TreeNode(start);
			allTrees.push_back(root);
			return allTrees;
		}

		for (int i = start; i <= end; i++){
			vector<TreeNode*> ltrees = helper(start, i - 1);
			vector<TreeNode*> rtrees = helper(i + 1, end);

			for (int l = 0; l < ltrees.size(); ++l){
				for (int r = 0; r < rtrees.size(); ++r){
					TreeNode* root = new TreeNode(i);
					root->left = ltrees[l];
					root->right = rtrees[r];
					allTrees.push_back(root);
				}
			}
		}

		return allTrees;
	}

	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> allTrees;
		int start = 1;
		int end = n;
		for (int i = 1; i <= n; i++){
			vector<TreeNode*> ltrees = helper(start, i - 1);
			vector<TreeNode*> rtrees = helper(i + 1, end);

			for (int l = 0; l < ltrees.size(); ++l){
				for (int r = 0; r < rtrees.size(); ++r){
					TreeNode* root = new TreeNode(i);
					root->left = ltrees[l];
					root->right = rtrees[r];
					allTrees.push_back(root);
				}
			}
		}
		return allTrees;
	}



protected:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		multiset<long long> pSum;
		int res = 0, i;
		long long left, right, sum = 0;
		for (i = 0, pSum.insert(0); i < nums.size(); ++i)
		{
			sum += nums[i];
			res += std::distance(pSum.lower_bound(sum - upper), pSum.upper_bound(sum - lower));
			pSum.insert(sum);
		}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	vector<TreeNode*> tempVec = s.generateTrees(3);
	cout << __func__;;
	return 0;
}

