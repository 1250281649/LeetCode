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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *t,*p,*q,*result = NULL;
		p = l1;
		q = l2;
		if (l1 == NULL) return l2;
		else if (l2 == NULL) return l1;

		if (p->val > q->val)
		{
			t = q;
			q = q->next;
		}
		else
		{
			t = p;
			p = p->next;
		}
		result = t;
		while ((p != NULL) && (q != NULL))
		{
			if (p->val > q->val)
			{
				t->next = q;
				q = q->next;
			}
			else
			{
				t->next = p;
				p = p->next;
			}
			t = t->next;
		}
		if (p == NULL) t->next = q;
		else if (q == NULL) t->next = p;
		return result;
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
	ListNode L11(3), L12(5), L13(6), L14(9);
	ListNode L21(4), L22(6), L23(8), L24(10);
	L11.next = &L12;
	L12.next = &L13;
	L13.next = &L14;
	L21.next = &L22;
	L22.next = &L23;
	L23.next = &L24;

	cout << "orign list:" << endl;
	s.printfList(&L11);
	s.printfList(&L21);
	cout << "merged list:" << endl;
	s.printfList(s.mergeTwoLists(&L11, &L21));

	system("pause");
}
