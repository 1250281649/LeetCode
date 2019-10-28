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
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		else return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
};

int main()
{
	Solution s;
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
	cout << "tree 1:" << s.maxDepth(&n1) << "  except:3" << endl;
	cout << "tree 2:" << s.maxDepth(&m1) << "  except:3" << endl;
	cout << "one node:" << s.maxDepth(&m7) << "  except:1" << endl;
	cout << "null:" << s.maxDepth(NULL) << "  except:0" << endl;

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
