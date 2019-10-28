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
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>>result;
		vector<int>t;
		int i = 0, j = 0;
		if (numRows <= 0) return result;
		t.push_back(1);
		result.push_back(t);
		t.clear();
		i = 1;
		while (i<numRows)
		{
			t.push_back(1);
			j = 1;
			while (j < i)
			{
				t.push_back(result[i-1][j] + result[i-1][j-1]);
				j++;
			}
			t.push_back(1);
			result.push_back(t);
			t.clear();
			i++;
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

	cout << "Pascal's Trangle" << endl;
	s.printVector2(s.generate(1));
	s.printVector2(s.generate(2));
	s.printVector2(s.generate(5));

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
