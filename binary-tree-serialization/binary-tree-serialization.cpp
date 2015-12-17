// binary-tree-serialization.cpp : Defines the entry point for the console application.
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

void gerneratepreorder(TreeNode *root, ostringstream& res)
{
	if (root != NULL)
	{
		res << root->val << ",";
		gerneratepreorder(root->left, res);
		gerneratepreorder(root->right, res);
	}
}
void gernerateinorder(TreeNode *root, ostringstream& res)
{
	if (root != NULL)
	{
		gernerateinorder(root->left, res);
		res << root->val << ",";
		gernerateinorder(root->right, res);
	}
}
string serialize(TreeNode *root)
{
	// write your code here
	if (root == NULL)
		return "";
	string res;
	ostringstream os,oos;
	string temp;
	gerneratepreorder(root,os);
	temp = os.str();
	temp = temp.substr(0, temp.length() - 1);
	res = temp + "#";
	gernerateinorder(root, oos);
	temp = oos.str();
	temp = temp.substr(0, temp.length() - 1);
	res += temp;
	return res;
}
vector<int> split_string(string data)
{
	std::vector<int> str_list; // 存放分割后的字符串
	int comma_n = 0;
	do
	{
		std::string tmp_s = "";
		comma_n = data.find(",");
		if (-1 == comma_n)
		{
			tmp_s = data.substr(0, data.length());
			str_list.push_back(atoi(tmp_s.c_str()));
			break;
		}
		tmp_s = data.substr(0, comma_n);
		data.erase(0, comma_n + 1);
		str_list.push_back(atoi(tmp_s.c_str()));
	} while (true);
	return str_list;
}
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
TreeNode *deserialize(string data)
{
	// write your code here
	int pos = data.find("#");
	string prestr = data.substr(0, pos);
	string inorderstr = data.substr(pos + 1, pos);
	vector<int> preorder = split_string(prestr);
	vector<int> inorder = split_string(inorderstr);
	int cur = 0;
	return buildTree(preorder, inorder);
}
int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode C(3);
	TreeNode B(2);
	TreeNode A(1);
	A.right = &C;
	A.left = &B;
	string res = serialize(NULL);
	TreeNode* root = deserialize(res);
	return 0;
}

