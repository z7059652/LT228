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
	if ((root->left != NULL && root->left->val == value) || (root->right != NULL && root->right->val == value))
		return root;
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
}
void deleteNode(TreeNode* root, TreeNode* proot)
{
	bool flag = false;
	if (proot->right != NULL && proot->right->val == root->val)
		flag = true;
	while (root->left != NULL || root->right != NULL)
	{
		if (root->left != NULL)
		{
			root->val = root->left->val;
			root = root->left;
			if (!flag)
			{
				proot = proot->left;
			}
			else
				proot = proot->right;
			flag = false;
		}
		else
		{
			root->val = root->right->val;
			root = root->right;
			if (!flag)
			{
				proot = proot->left;
			}
			else
				proot = proot->right;
			flag = true;
		}
	}
//	delete root;
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
	if (predelete->left != NULL && predelete->left->val == value)
		deleteNode(predelete->left, predelete);
	else
		deleteNode(predelete->right, predelete);
	return root;
}

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode A(1001);
	TreeNode B(92);
	TreeNode C(81);
	TreeNode D(75);
	TreeNode E(41);
	TreeNode F(65);
	A.left = &B;
	B.left = &C;
	C.left = &D;
	D.left = &E;
	E.right = &F;
	TreeNode* root = removeNode(&A, 92);
	return 0;
}

