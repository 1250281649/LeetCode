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
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<TreeNode*> temp;
		vector<vector<TreeNode*>> result;
		vector<string> str;

		findPath(root, result, temp);

		for (int i = 0; i < result.size(); i++)
		{
			string s1;
			s1 += std::to_string(result[i][0]->val);
			if (result[i].size() > 1)
			{
				for (int j = 1; j < result[i].size(); j++)
				{
					s1 = s1 + "->" + std::to_string(result[i][j]->val);
				}
			}
			str.push_back(s1);
		}

		return str;
	}

	int findPath(TreeNode* root, vector<vector<TreeNode*>>&v, vector<TreeNode*> &s1)
	{
		if (!root) return -1;
		s1.push_back(root);

		//左右子节点都是空
		if (!root->left && !root->right)
		{
			v.push_back(s1);
		}
		if (root->right)
		{
			findPath(root->right, v, s1);
			//return 0;
		}
		if (root->left)
		{
			findPath(root->left, v, s1);
			//return 0;
		}
		s1.pop_back();
		return 0;
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
	/*
	TreeNode n1(6), n2(2), n3(8), n4(0), n5(4), n6(7), n7(9), n8(3), n9(5);
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.left = &n6;
	n3.right = &n7;
	n5.left = &n8;
	n5.right = &n9;*/
	TreeNode n1(1), n2(2), n3(3), n4(5);
	n1.left = &n2;
	n1.right = &n3;
	n2.right = &n4;

	cout << "Binary Tree Paths:" << endl;
	s.printVector(s.levelOrderBottom(&n1));
	vector<string> result;
	result = s.binaryTreePaths(&n1);

	cout << "root-to-leaf paths:" << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i].c_str() << endl;
	}

	s.printVector(s.levelOrderBottom(NULL));
	result = s.binaryTreePaths(NULL);

	cout << "root-to-leaf paths:" << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i].c_str() << endl;
	}


	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
