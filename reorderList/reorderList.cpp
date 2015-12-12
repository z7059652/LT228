// reorderList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
class ListNode{
public:
	int val;
	ListNode *next;
	ListNode(int val) 
	{
		this->val = val;
		this->next = NULL;		
	}
	ListNode(int val,ListNode* next)
	{
		this->val = val;
		this->next = next;
	}

};
void reverse(ListNode* &head)
{
	ListNode* phead = head->next;
	ListNode* temp = NULL;
	head->next = NULL;
	while (phead != NULL)
	{
		temp = phead->next;
		phead->next = head;
		head = phead;
		phead = temp;
	}
}
void merge(ListNode* &phead, ListNode* qhead)
{
	ListNode* p = phead;
	ListNode* temp = NULL;
	while (qhead != NULL)
	{
		temp = qhead->next;
		qhead->next = p->next;
		p->next = qhead;
		qhead = temp;
		p = p->next->next;
	}
}
void reorderList(ListNode *head)
{
	// write your code here
	ListNode* phead = head;
	int ncount = 0;
	while (phead != NULL)
	{
		ncount++;
		phead = phead->next;
	}
	ncount = (ncount + 1) / 2;
	phead = head;
	while (ncount > 1)
	{
		phead = phead->next;
		ncount--;
	}
	if (phead == NULL)
		return;
	ListNode* qhead = phead->next;
	phead->next = NULL;
	reverse(qhead);
	merge(head, qhead);
}

int _tmain(int argc, _TCHAR* argv[])
{
	//ListNode E(5);
	//ListNode D(4, &E);
	ListNode A(0);
	ListNode B(-1, &A);
	ListNode C(2, &B);
	reorderList(&C);
	return 0;
}

