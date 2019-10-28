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
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		else return isMirror(root->left, root->right);
	}

	bool isMirror(TreeNode* left, TreeNode* right)
	{
		queue <TreeNode*> leftqueue, rightqueue;
		TreeNode * ln, *rn;
		if (left != NULL)leftqueue.push(left);
		if(right != NULL)rightqueue.push(right);

		while (!rightqueue.empty() && !leftqueue.empty())
		{
			ln = leftqueue.front();
			rn = rightqueue.front();
			if (ln->val != rn->val)
				return false;
			leftqueue.pop();
			rightqueue.pop();
			if (ln->left && (!rn->right))return false;
			else if (!ln->left && rn->right) return false;
			else if (ln->left && rn->right)
			{
				leftqueue.push(ln->left);
				rightqueue.push(rn->right);
			}

			if (ln->right && !rn->left)return false;
			else if (!ln->right && rn->left)return false;
			else if (ln->right && rn->left)
			{
				leftqueue.push(ln->right);
				rightqueue.push(rn->left);
			}
			
		}

		if (!rightqueue.empty() || !leftqueue.empty())
			return false;

		return true;
	}

	/*
	bool isMirror(TreeNode* left, TreeNode* right)
	{
		if (left==NULL && right == NULL) return true;
		else if (left == NULL || right == NULL) return false;
		else if (left->val != right->val) return false;
		else return isMirror(left->right, right->left) && isMirror(left->left, right->right);

		return false;
	}*/
};

int main()
{
	Solution s;
	//clock_t start, stop;
	DWORD start = GetTickCount();
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

	cout << "Symmetric tree:" << endl;
	cout << "tree 1:" << s.isSymmetric(&n1) << "  except:0" << endl;
	cout << "tree 2:" << s.isSymmetric(&m1) << "  except:1" << endl;
	cout << "one node:" << s.isSymmetric(&m7) << "  except:1" << endl;
	cout << "null:" << s.isSymmetric(NULL) << "  except:1" << endl;

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
