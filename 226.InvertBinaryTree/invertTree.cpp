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
	TreeNode* invertTree(TreeNode* root) {
		TreeNode *t;
		if (!root) return root;
		t = root->left;
		root->left = root->right;
		root->right = t;
		invertTree(root->left);
		invertTree(root->right);
		return root;
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
	TreeNode n1(4), n2(2), n3(7), n4(1), n5(3), n6(6), n7(9);
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.left = &n6;
	//n3.right = &n7;


	cout << "Invert Binary Tree:" << endl;
	s.printVector(s.levelOrderBottom(&n1));
	cout << "Invert:" << endl;
	s.printVector(s.levelOrderBottom(s.invertTree(&n1)));

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
