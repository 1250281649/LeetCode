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
	
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*>r1;
		vector<TreeNode*>r2;
		int i = 0;
		if (!p || !q || !root) return NULL;
		findPath(root, p,r1);
		findPath(root, q, r2);
		int length = min(r1.size(), r2.size());
		for (i = 0; i < length; i++)
		{
			if (r1[i] != r2[i])
				return r1[i - 1];
		}
		if (i==length)
			return r1[i - 1];
		return NULL;
	}

	int findPath(TreeNode* root, TreeNode* p, vector<TreeNode*> &s1)
	{
		int ret = 0;
		if (!root) return -1;
		if (p == root)
		{
			s1.push_back(root);
			return 0;
		}
		s1.push_back(root);
		if (root->left)
		{
			int ret1 = findPath(root->left, p,s1);
			if (ret1 == 0)
				return 0;
		}
		if (root->right)
		{
			int ret2 = findPath(root->right,p,s1);
			if (ret2 == 0)
				return 0;
		}
		s1.pop_back();
		return -1;
	}

	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<int> t;
		vector<vector<int>> result;
		if (!root) return result;
		queue<TreeNode *>q;
		TreeNode* p;
		int levelN = 1;
		int temp = 0;
		p = root;
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

	void printVector(vector<vector<int>> v)
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
	TreeNode n1(6), n2(2), n3(8), n4(0), n5(4), n6(7), n7(9), n8(3), n9(5);
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.left = &n6;
	n3.right = &n7;
	n5.left = &n8;
	n5.right = &n9;

	cout << "Lowest Common Ancestor of a Binary Search Tree:" << endl;
	s.printVector(s.levelOrderBottom(&n1));
	stack<TreeNode*> st;
	TreeNode*p;

	p = s.lowestCommonAncestor(&n1, &n2, &n5);
	cout << n2.val << "," << n5.val << ":";
	if (p)
		cout << "LCA:" << p->val << endl;
	else cout << "LCA:" << "NULL" << endl;

	p = s.lowestCommonAncestor(&n1, &n2, &n7);
	cout << n2.val << "," << n7.val << ":";
	if (p)
		cout << "LCA:" << p->val << endl;
	else cout << "LCA:" << "NULL" << endl;

	p = s.lowestCommonAncestor(&n1, &n2, &n1);
	cout << n2.val << "," << n1.val << ":";
	if (p)
		cout << "LCA:" << p->val << endl;
	else cout << "LCA:" << "NULL" << endl;

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
