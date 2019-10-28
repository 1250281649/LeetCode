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
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root) return 0;
		return root->left ? 
			(!root->left->left && !root->left->right) ? root->left->val +sumOfLeftLeaves(root->right) :
			sumOfLeftLeaves(root->right) + sumOfLeftLeaves(root->left)
			
			:sumOfLeftLeaves(root->right);
	}
};

int main()
{
	Solution s;
	//clock_t start, stop;
	DWORD start = GetTickCount();
	TreeNode n1(3), n2(9), n3(20), n4(15), n5(7);
	n1.left = &n2;
	n1.right = &n3;
	n3.left = &n4;
	n3.right = &n5;

	TreeNode m1(1), m2(2), m3(2), m4(3), m5(4), m6(4), m7(3);
	m1.left = &m2;
	m1.right = &m3;

	m2.left = &m4;
	m2.right = &m5;
	m3.left = &m6;
	m3.right = &m7;

	cout << "Sum of Left Leaves:" << endl;
	cout << "Tree 1:" << s.sumOfLeftLeaves(&n1) << endl;
	cout << "Tree 2:" << s.sumOfLeftLeaves(&m1) << endl;

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
