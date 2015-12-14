// construct-binary-tree-from-preorder-and-inorder-traversal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using namespace std;
class TreeNode 
{
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) 
	{
		this->val = val;
		this->left = this->right = NULL;
	}
};

TreeNode* generate(vector<int> &preorder, vector<int> &inorder, int& icur, int left, int right)
{
	if (left > right)
		return NULL;
	TreeNode* root = new TreeNode(preorder[icur]);
	if (left == right)
		return root;
	int pos = 0;
	for (int i = 0; i < inorder.size(); i++)
	{
		if (preorder[icur] == inorder[i])
			pos = i;
	}
	root->left = generate(preorder, inorder, ++icur, left, pos - 1);
	if (root->left == NULL)
		icur--;
	root->right = generate(preorder, inorder, ++icur, pos + 1, right);
	if (root->right == NULL)
		icur--;

	return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
	// write your code here
	if (preorder.size() <= 0)
		return NULL;
	int icur = 0;
	return generate(preorder, inorder, icur, 0, preorder.size() - 1);
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> preorder;
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(4);
	preorder.push_back(5);
	preorder.push_back(3);
	preorder.push_back(6);
	preorder.push_back(7);
	vector<int> inorder;
	inorder.push_back(4);
	inorder.push_back(2);
	inorder.push_back(5);
	inorder.push_back(1);
	inorder.push_back(6);
	inorder.push_back(3);
	inorder.push_back(7);
	TreeNode *root = buildTree(preorder, inorder);
	return 0;
}

