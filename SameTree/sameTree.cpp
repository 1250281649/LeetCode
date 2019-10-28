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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)
			return true;
		else if ((p == NULL) || (q == NULL) || (p->val != q->val))
			return false;
		else return isSameTree(p->left, q->left) & isSameTree(p->right,q->right);
	}
};

int main()
{
	Solution s;
	//clock_t start, stop;
	DWORD start = GetTickCount();
	/*TreeNode n1(1), n2(2), n3(1);
	n1.left = &n2;
	n1.right = &n3;

	TreeNode m1(1), m2(2), m3(1);
	m1.left = &m2;
	m1.right = &m3;*/
	TreeNode n1(1), n2(2);
	n1.left = &n2;

	TreeNode m1(1), m2(2);
	m1.right = &m2;

	cout << "Same tree:" << endl;
	cout << s.isSameTree(&n1, &m1) << endl;

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
