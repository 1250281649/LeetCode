#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include <ctime>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode*p = head;
		ListNode*q = p;
		ListNode*t;
		if (!p) return p;
		q = p->next;
		p->next = NULL;
		while (q)
		{
			t = q->next;
			q->next = p;
			p = q;
			q = t;
		}
		return p;
	}

	void printList(ListNode *head)
	{
		ListNode *p = head;
		if (!p)
		{
			cout << "NULL list" << endl;
			return;
		}
		while (p)
		{
			cout << p->val << " -> ";
			p = p->next;
		}
		cout << endl;
	}
};

int main()
{
	Solution s;
	DWORD start = GetTickCount();

	ListNode *head;
	ListNode l1(1), l2(2), l3(6), l4(3), l5(4), l6(5), l7(6);
	head = &l1;
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;

	cout << "Reverse Linked List:" << endl;
	s.printList(head);
	s.printList(s.reverseList(head));

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
