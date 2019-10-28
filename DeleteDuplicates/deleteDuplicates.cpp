#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <ctime>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *p, *q;
		p = head;
		q = head;
		if (q == NULL)
			return p;
		q = p->next;
		while (q != NULL)
		{
			if (q->val == p->val)
			{
				q = q->next;
			}
			else
			{
				p->next = q;
				q = q->next;
				p = p->next;
			}
		}
		p->next = q;
		return head;
	}

	void printList(ListNode* head)
	{
		ListNode* p;
		p = head;
		while (p != NULL)
		{
			cout << p->val << "->";
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

	ListNode n1(1) , n2(1), n3(2), n4(3), n5(3);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	
	cout << "deleteDuplicates:" << endl;

	cout << "input:" << endl;
	s.printList(&n1);
	s.deleteDuplicates(&n1);
	cout << "output:" << endl;
	s.printList(&n1);

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
