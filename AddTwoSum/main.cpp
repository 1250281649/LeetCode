#include <iostream>
#include <list>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p = l1, *q = l2;
		ListNode *result = NULL, *pt,*t;
		int carryin = 0;
		int sum = 0,a,b;

		pt = result;
		while ((p != NULL) || (q != NULL))
		{
			p == NULL ? a = 0 : a = p->val;
			q == NULL ? b = 0 : b = q->val;
			sum = carryin + a + b;
			t = (ListNode*)malloc(sizeof(ListNode));
			if (sum >= 10)
			{
				carryin = 1;
				t->val = sum % 10;
				t->next = NULL;
			}
			else
			{
				carryin = 0;
				t->val = sum;
				t->next = NULL;
			}
			if (result == NULL)
			{
				result = t;//第一个节点
				pt = result;
			}
			else
			{
				pt->next = t;
				pt = pt->next;
			}
			if(p != NULL)p = p->next;
			if(q != NULL)q = q->next;
		}
		if (carryin == 1)
		{
			carryin = 0;
			t = (ListNode*)malloc(sizeof(ListNode));
			t->val = 1;
			t->next = NULL;
			pt->next = t;
		}
		return result;
	}
};

int main()
{
	ListNode *l1, *l2, *result;
	ListNode l11(2), l12(4);
	ListNode l21(5), l22(6), l23(6);
	l1 = &l11;
	l11.next = &l12;
	//l12.next = &l13;
	l2 = &l21;
	l21.next = &l22;
	l22.next = &l23;

	cout << "(" << l11.val << " -> " << l12.val << " -> "  << ")" << " + ";
	cout << "(" << l21.val << " -> " << l22.val << " -> " << l23.val << ")" << endl;

	Solution s;

	result = s.addTwoNumbers(l1, l2);
	ListNode *p;
	p = result;
	if (p != NULL)
	{
		cout << p->val;
		p = p->next;
	}
 	while (p != NULL)
	{
		cout << " -> " << p->val;
		p = p->next;
	}
	cout << endl;
	system("pause");
}
