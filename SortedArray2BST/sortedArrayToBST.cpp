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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return createBST(nums,0,nums.size()-1);
	}

	TreeNode *createBST(vector<int>& nums, int begin, int end)
	{
		if (end - begin >= 0)
		{
			TreeNode *p = new TreeNode(nums[(end + begin) / 2]);
			p->left = createBST(nums, begin, (end + begin) / 2 - 1);
			p->right = createBST(nums, (end + begin) / 2 + 1, end);
			return p;
		}
		else return NULL;

	}
	/*
	TreeNode *createBST(vector<int>& nums,int begin, int end)
	{
		if (end - begin > 0)
		{
			TreeNode *p = new TreeNode(nums[(end+begin)/2]);
			p->left = createBST(nums, begin, (end + begin) / 2-1);
			p->right = createBST(nums, (end + begin) / 2 + 1, end);
			return p;
		}
		else if (end - begin == 0)
		{
			return new TreeNode(nums[(end + begin) / 2]);
		}
		else return NULL;
	}
	*/
	void printVector(vector<int> v)
	{
		cout << "[";
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ", ";
		cout << "]" << endl;
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
	vector<vector<int>> result;
	DWORD start = GetTickCount();

	//int a1[] = {-10, -3, 0, 5, 9};
	int a1[] = { 0, 1, 2, 3, 4,5 };
	//int a1[] = { -10};
	vector<int> v1(begin(a1), end(a1));
	TreeNode *temp;
	cout << "sortedArrayToBST:" << endl;
	s.printVector(v1);
	temp = s.sortedArrayToBST(v1);
	result = s.levelOrderBottom(temp);
	s.printVector2(result);


	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
