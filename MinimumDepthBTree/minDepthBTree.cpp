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

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		if (!root->left) return 1 + minDepth(root->right);
		if (!root->right) return 1 + minDepth(root->left);
		return 1 + min(minDepth(root->left), minDepth(root->right));
	}

	vector<vector<int>> levelOrderBottom(TreeNode* r) {
		vector<int> t;
		vector<vector<int>> result;
		if (!r) return result;
		queue<TreeNode *>q;
		TreeNode* p;
		int levelN = 1;
		int temp = 0;
		p = r;
		q.push(p);

		while (!q.empty())
		{
			for (int i = 0; i < levelN; i++)
			{
				p = q.front();
				if (p->left)
				{
					q.push(p->left);
					temp++;
				}
				if (p->right)
				{
					q.push(p->right);
					temp++;
				}
				t.push_back(p->val);
				q.pop();
			}
			result.push_back(t);
			t.clear();
			levelN = temp;
			temp = 0;
		}
		return result;
	}

	void printVector2(vector<vector<int>> v)
	{
		cout << "[" << endl;
		for (int i = 0; i < v.size(); i++)
		{
			cout << "  [";
			for (int j = 0; j < v[i].size(); j++)
				cout << v[i][j] << "  ";
			cout << "]," << endl;
		}
		cout << "]" << endl;
	}
};

int main()
{
	Solution s;
	DWORD start = GetTickCount();
	vector<vector<int>> result;

	TreeNode n1(1), n2(2), n3(2), n4(3), n5(3);
	n1.left = &n2;
	n1.right = &n3;
	n2.right = &n4;
	n3.right = &n5;

	TreeNode m1(1), m2(2), m3(2), m4(3), m5(4), m6(4), m7(3);
	m1.left = &m2;
	m1.right = &m3;
	m2.left = &m4;
	m2.right = &m5;
	m4.left = &m6;
	m4.right = &m7;

	TreeNode l1(1), l2(2), l3(3);
	l1.left = &l2;
	l2.left = &l3;

	cout << "Minimum Depth of Binary Tree:" << endl;
	cout << "tree 1:" << "expected:3" << endl;
	result = s.levelOrderBottom(&n1);
	s.printVector2(result);
	cout << "min depth:" << s.minDepth(&n1) << endl << endl;

	cout << "tree 2:" << "expected:2" << endl;
	result = s.levelOrderBottom(&m1);
	s.printVector2(result);
	cout << "min depth:" << s.minDepth(&m1) << endl << endl;

	cout << "tree 3:" << "expected:3" << endl;
	result = s.levelOrderBottom(&l1);
	s.printVector2(result);
	cout << "min depth:" << s.minDepth(&l1) << endl << endl;

	cout << "Null tree:" << "expected:0" << endl;
	result = s.levelOrderBottom(NULL);
	s.printVector2(result);
	cout << "min depth::" << s.minDepth(NULL) << endl << endl;

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
