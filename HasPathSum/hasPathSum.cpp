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
#include <map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) return false;
		if (!root->right && !root->left) return root->val == sum;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
	/*
	bool hasPathSum(TreeNode* root, int sum) {
		map<int, int>table;
		queue <TreeNode* > q;
		TreeNode *p;
		int nowNodes = 0, lastNodes = 0;
		if (!root) return false;

		p = root;
		lastNodes = 1;
		q.push(p);

		while (!q.empty())
		{
			for (int i = 0; i < lastNodes; i++)
			{
				p = q.front();
				if (p->left)
				{
					p->left->val += p->val;
					nowNodes++;
					q.push(p->left);
				}
				if (p->right)
				{
					p->right->val += p->val;
					nowNodes++;
					q.push(p->right);
				}
				if (!p->left && !p->right)
					table[p->val] = 1;
				q.pop();
			}
			lastNodes = nowNodes;
			nowNodes = 0;
		}

		return table[sum];
	}
	*/
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

	TreeNode m1(5), m2(4), m3(8), m4(11), m5(13), m6(4), m7(7), m8(2), m9(1);
	m1.left = &m2;
	m1.right = &m3;
	m2.left = &m4;
	m3.left = &m5;
	m3.right = &m6;
	m4.left = &m7;
	m4.right = &m8;
	m6.right = &m9;

	TreeNode l1(1), l2(2), l3(3);
	l1.left = &l2;
	l2.left = &l3;

	cout << "Path Sum:" << endl;
	cout << "tree 1:" << "expected:1" << endl;
	result = s.levelOrderBottom(&n1);
	s.printVector2(result);
	cout << "has path sum:" << s.hasPathSum(&n1,6) << endl << endl;

	cout << "tree 2:" << "expected:1" << endl;
	result = s.levelOrderBottom(&m1);
	s.printVector2(result);
	cout << "has path sum:" << s.hasPathSum(&m1, 22) << endl << endl;

	cout << "tree 3:" << "expected:0" << endl;
	result = s.levelOrderBottom(&l1);
	s.printVector2(result);
	cout << "has path sum:" << s.hasPathSum(&l1, 5) << endl << endl;

	cout << "Null tree:" << "expected:0" << endl;
	result = s.levelOrderBottom(NULL);
	s.printVector2(result);
	cout << "has path sum:" << s.hasPathSum(NULL, 1) << endl << endl;

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
