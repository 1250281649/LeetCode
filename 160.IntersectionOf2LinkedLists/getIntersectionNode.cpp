#include <iostream>
#include <list>
#include <vector>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode *headA, ListNode *headB) {
		ListNode *result = NULL;
		ListNode *p,*q;
		int a = 0, b = 0;

		p = headA;
		while (p)
		{
			a++;
			p = p->next;
		}
		p = headB;
		while (p)
		{
			b++;
			p = p->next;
		}
		if (a > b)
		{
			p = headA;
			q = headB;
		}
		else
		{
			p = headB;
			q = headA;
		}
		for (int i = 0; i < abs(a - b); i++)
			p = p->next;
		while (p && q)
		{
			if (p == q)
				return p;
			p = p->next;
			q = q->next;
		}
		return NULL;
	}

	void printfList(ListNode* l)
	{
		ListNode *t;
		t = l;
		while (t != NULL)
		{
			cout << t->val << "  ";
			t = t->next;
		}
		cout << endl;
	}
};

int main()
{
	Solution s;
	ListNode *r = NULL;
	ListNode L11(3), L12(5);
	ListNode L21(4), L22(6), L23(8);
	ListNode L31(1), L32(10), L33(8);

	L11.next = &L12;
	L21.next = &L22;
	L22.next = &L23;

	L31.next = &L32;
	L32.next = &L33;

	L12.next = &L31;
	L23.next = &L31;

	cout << "orign list:" << endl;
	s.printfList(&L11);
	s.printfList(&L21);
	cout << "result:" << endl;
	cout << s.mergeTwoLists(&L11, &L21)->val << endl;
	r = s.mergeTwoLists(NULL, NULL);
	if (r)
		cout << r->val << endl;
	else cout << "Null" << endl;

	ListNode ll(1);
	r = s.mergeTwoLists(&ll, &ll);
	if (r)
		cout << r->val << endl;
	else cout << "Null" << endl;

	system("pause");
}
