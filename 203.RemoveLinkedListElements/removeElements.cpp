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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode *p = head;
		ListNode *q = head;
		ListNode *h = head;

		if (!head) return NULL;
		while (p)
		{
			if (p->val == val)
				p = p->next;
			else
			{
				h = p;
				break;
			}
		}

		if (!p) return p;
		else q = p->next;

		while (q)
		{
			if (q->val == val)
			{
				q = q->next;
				p->next = q;
			}
			else
			{
				p = p->next;
				q = q->next;
			}
		}

		return h;
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
	//clock_t start, stop;
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

	cout << "Remove Linked List Elements:" << endl;
	s.printList(head);
	cout << "return remove 6:";
	s.printList(s.removeElements(head, 6));

	head = &l7;
	s.printList(head);
	cout << "return remove 6:";
	s.printList(s.removeElements(head, 6));

	head = &l3;
	s.printList(head);
	cout << "return remove 6:";
	s.printList(s.removeElements(head, 6));

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;
	


	system("pause");
}
