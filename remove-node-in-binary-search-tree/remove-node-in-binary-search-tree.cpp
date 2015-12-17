// remove-node-in-binary-search-tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <sstream>
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


TreeNode* findNode(TreeNode* root, int value)
{
	if (root->val > value)
	{
		if (root->left == NULL)
			return NULL;
		return findNode(root->left, value);
	}
	if (root->val < value)
	{
		if (root->right == NULL)
			return NULL;
		return findNode(root->right, value);
	}

	if (root->left->val == value || root->right->val == value)
		return root;
}
void deleteNode(TreeNode* root, TreeNode* proot)
{
	bool flag = false;
	while (root->left != NULL || root->right != NULL)
	{
		if (root->left != NULL)
		{
			root->val = root->left->val;
			root = root->left;
			proot = proot->left;
			flag = false;
		}
		else
		{
			root->val = root->right->val;
			root = root->right;
			proot = proot->right;
			flag = true;
		}
	}
	delete root;
	if (flag == false)
		proot->left = NULL;
	else
		proot->right = NULL;
}
TreeNode* removeNode(TreeNode* root, int value)
{
	// write your code here
	if (root == NULL)
		return NULL;
	if (root->val == value)
	{
		if (root->left == NULL && root->right == NULL)
			return NULL;
		TreeNode* temp = new TreeNode(-1);
		temp->left = root;
		deleteNode(root, temp);
		return root;
	}
	TreeNode* predelete = findNode(root, value);
	if (predelete == NULL)
		return root;
	if (predelete->left->val == value)
		deleteNode(predelete->left, predelete);
	else
		deleteNode(predelete->right, predelete);
	return root;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

