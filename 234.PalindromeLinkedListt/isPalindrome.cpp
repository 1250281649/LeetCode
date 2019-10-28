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
	bool isPalindrome(ListNode* head) {
		int length = 0;
		ListNode*p = head;
		ListNode*t;
		ListNode*q;
		if (!p) return true;
		while (p)
		{
			length++;
			p = p->next;
		}
		if (length == 1) return true;
		p = head;
		if (length == 2)
			return p->val == p->next->val;
		p = head;
		q = p->next;
		t = q->next;
		p->next = NULL;
		q->next = p;
		for (int i = 0; i < (length-1) / 2; i++)
		{
			p = q;
			q = t;
			t = t->next;
			q->next = p;
		}
		q->next = t;
		cout << p->val << "  ";
		cout << q->val << endl;
		if (length % 2)
			p = p->next;
		for (int i = 0; i < length / 2; i++)
		{
			if (p->val != q->val) return false;
			cout << p->val << "  " << q->next << endl;
			p = p->next;
			q = q->next;
		}
		return true;
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
	ListNode l1(1), l2(2), l3(2), l4(1), l5(3), l6(2), l7(1);
	head = &l1;
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	//l4.next = &l5;
	//l5.next = &l6;
	//l6.next = &l7;

	cout << "Palindrome Linked List:" << endl;
	s.printList(head);
	cout << "is Palindrome:" << s.isPalindrome(head) << endl;

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
