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
	vector<int> getRow(int rowIndex) {
		vector<int> result;
		int i = 0, j = 0;
		int temp1 = 0, temp2;
		if (rowIndex < 0)return result;
		for (i = 0; i < rowIndex+1; i++)
		{
			result.push_back(1);
			j = 1;
			temp1 = 1;
			while (j < i)
			{
				
				temp2 = result[j] + temp1;
				j++;
				temp1 = result[j-1];
				result[j - 1] = temp2;
			}
		}
		return result;
	}

	void printVector2(vector<int> v)
	{
		for (int j = 0; j < v.size(); j++)
			cout << v[j] << "  ";
		cout << endl;
	}
};

int main()
{
	Solution s;
	DWORD start = GetTickCount();

	cout << "Pascal's Trangle II" << endl;
	
	for (int i = 0; i < 6; i++)
	{
		s.printVector2(s.getRow(i));
	}

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
