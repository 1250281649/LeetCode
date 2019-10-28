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
			//result.insert(result.begin(),t);
			result.push_back(t);
			t.clear();
			levelN = temp;
			temp = 0;
		}
		for (int i = 0; i < result.size() / 2; i++)
		{
			t = result[i];
			result[i] = result[result.size() - 1 - i];
			result[result.size() - 1 - i] = t;
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

	vector<vector<int>>result;
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
	m3.left = &m6;
	m3.right = &m7;

	cout << "Level Order Bottom tree:" << endl;
	cout << "Tree 1:" << endl;
	result = s.levelOrderBottom(&n1);
	s.printVector(result);

	cout << "Tree 2:" << endl;
	result = s.levelOrderBottom(&m1);
	s.printVector(result);

	cout << "Tree one node:" << endl;
	result = s.levelOrderBottom(&n5);
	s.printVector(result);

	cout << "Tree NULL:" << endl;
	result = s.levelOrderBottom(NULL);
	s.printVector(result);

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
