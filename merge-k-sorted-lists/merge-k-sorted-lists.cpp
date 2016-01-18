// merge-k-sorted-lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <vector>
using namespace std;


class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
	this->val = val;
	this->next = NULL;
		}
};
ListNode *mergeKLists(vector<ListNode *> &lists)
{
	// write your code here
	if (lists.size() == 0 || (lists.size() == 1 && lists[0] == NULL)) return NULL;
	map<int, ListNode*> flag;
	for (int i = 0; i < lists.size(); i++)
	{
		ListNode* head = lists[i];
		while (head != NULL)
		{
			flag.insert(make_pair(head->val, head));
			head = head->next;
		}
	}
	if (flag.size() == 0) return NULL;
	ListNode* phead = (flag.begin())->second;
	ListNode* pcur = phead;
	map<int, ListNode*>::iterator iter = flag.begin();
	iter++;
	while (iter != flag.end())
	{
		pcur->next = (iter)->second;
		pcur = pcur->next;
		iter++;
	}
	pcur->next = NULL;
	return phead;
}
//[2->null,null,-1->null]
int _tmain(int argc, _TCHAR* argv[])
{
	vector<ListNode*> list;
	list.push_back(new ListNode(2));
	list.push_back(NULL);
	list.push_back(new ListNode(-1));
	ListNode* head = mergeKLists(list);
	return 0;
}

