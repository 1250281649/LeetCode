#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution {
public:
	int pathSum(TreeNode* root, int sum)
	{
		if (!root)return 0;
		return find(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}

	int find(TreeNode* root, int num)
	{
		if (!root) return 0;
		return (root->val==num?1:0) + 
		find(root->left, num - root->val) + find(root->right, num - root->val);
	}

	/*
	int pathSum(TreeNode* root, int sum) {
		unordered_map<int, int>table;
		stack<unordered_map<int, int>>t;
		stack<TreeNode*>s;
		TreeNode *p;
		int result = 0;
		if (!root)
			return 0;
		s.push(root);
		while (!s.empty())
		{
			p = s.top();
			table[p->val]++;
			s.pop();

			if (!p->left && !p->right)
			{
				t.push(table);
				table.erase(p->val);
			}

			if (p->right)
			{
				p->right->val += p->val;
				s.push(p->right);
			}
			if (p->left)
			{
				p->left->val += p->val;
				s.push(p->left);
			}
			
		}
		unordered_map<int, int> temp;
		while (!t.empty())
		{
			temp = t.top();
			t.pop();
			unordered_map<int, int>::iterator it;
			for (it = temp.begin(); it != temp.end(); it++)
			{
				if (sum != 0)
				{
					if (temp.count(it->first - sum) > 0)
						result++;
				}
				if (it->first == sum)
					result ++;
			}
		}
		return result;
	}

	*/
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
	
	/*
	TreeNode n1(10), n2(5), n3(-3), n4(3), n5(2), n6(11), n7(3), n8(-2), n9(1);
	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;
	n2.right = &n5;

	n3.right = &n6;

	n4.left = &n7;
	n4.right = &n8;
	n5.right = &n9;
	*/
	
	TreeNode n1(1), n2(-2), n3(-3);
	n1.left = &n2;
	n1.right = &n3;
	
	/*
	TreeNode n1(1), n2(2), n3(3),n4(4),n5(5);
	n1.right = &n2;
	n2.right = &n3;
	n3.right = &n4;
	n4.right = &n5;
	*/
	cout << "Path Sum III:" << endl;

	s.printVector(s.levelOrderBottom(&n1));
	//cout << "8-> " << "paths:" << s.pathSum(&n1, 8) << endl;
	//cout << "1-> " << "paths:" << s.pathSum(&n1, 1) << endl;
	//cout << "3-> " << "paths:" << s.pathSum(&n1, 3) << endl;
	cout << "-1-> " << "paths:" << s.pathSum(&n1, -1) << endl;

	system("pause");
}
