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
	bool hasCycle(ListNode *head)
	{
		ListNode *p, *q;
		p = head;
		if (!p || !p->next) return false;
		q = p->next;
		while (q->next)
		{
			if (p == q)
				return true;
			p = p->next;
			q = q->next;
			if (q->next)
				q = q->next;
			else return false;
		}
		return false;
	}
	/*
	bool hasCycle(ListNode *head) {
		unordered_map<ListNode *, ListNode *>address;
		ListNode *p = head;
		while (p)
		{
			if (address.find(p) != address.end())
				return true;
			else
			{
				address[p] = p;
				p = p->next;
			}
		}
		return false;
	}
	*/
};

int main()
{
	Solution s;
	//clock_t start, stop;
	DWORD start = GetTickCount();

	ListNode *head;
	ListNode l1(1), l2(2), l3(3), l4(4);
	head = &l1;
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l2;

	ListNode l5(1), l6(2);

	cout << "Linked List Cycle:" << endl;
	cout << "Has Cycle:" << s.hasCycle(head) << endl << endl;
	head = &l5;
	l5.next = &l6;
	cout << "Has Cycle:" << s.hasCycle(head) << endl << endl;

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
