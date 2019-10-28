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
	void deleteNode(ListNode* node) {
		//node->val = node->next->val;
		//node->next = node->next->next;
		*node = *(node->next);
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
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;

	cout << "Delete Node in a Linked List:" << endl;
	s.printList(head);
	cout << "delete node:" << l4.val << endl;
	s.deleteNode(&l4);
	s.printList(head);

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
