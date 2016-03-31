// reverseKGroup.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode* start, ListNode* head, ListNode* end)
{
	ListNode* pcur = head->next;
	ListNode* temp = NULL;
	head->next = NULL;
	ListNode* phead = head;
	while (pcur != end)
	{
		temp = pcur->next;
		pcur->next = head;
		head = pcur;
		pcur = temp;
	}
	phead->next = end;
	start->next = head;
	return head;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
	// Write your code here 
	if (head == NULL || k == 1)
		return head;
	ListNode* phead = new ListNode(INT_MAX);
	ListNode* start = phead;
	phead->next = head;
	ListNode* p = head;
	while (p != NULL)
	{
		int count = 0;
		while (p != NULL && count < k)
		{
			count++;
			p = p->next;
		}
		if (count == k)
		{
			ListNode* temp = start->next;
			start->next = reverse(start, temp, p);
			while (count > 0)
			{
				start = start->next;
				count--;
			}
		}
	}
	return phead->next;
}
int _tmain(int argc, _TCHAR* argv[])
{
	ListNode A(1);
	ListNode B(2);
	ListNode C(3);
	ListNode D(4);
	ListNode E(5);
	A.next = &B;
	B.next = &C;
	C.next = &D;
	D.next = &E;
	return 0;
}

