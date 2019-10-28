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
	vector<int> findMode(TreeNode* root) {
		vector<int> result;


		return result;
	}



	void printVector(vector<int> v)
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << "  ";
		}
		cout << endl;
	}
};

int main()
{
	Solution s;
	
	cout << "501. 二叉搜索树中的众数" << endl;
	TreeNode *root = NULL;
	//test case1
	TreeNode n11(1), n12(2), n13(2);
	root = &n11;
	n11.right = &n12;
	n12.left = &n13;
	cout << "case 1:";
	s.printVector(s.findMode(root));
	
	cout<< endl << endl;

	system("pause");

}
