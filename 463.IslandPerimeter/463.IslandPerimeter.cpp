#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int i = 0, j = 0;
		int result = 0;
		for (i = 0; i < grid.size(); i++)
		{
			for (j = 0; j < grid[i].size(); j++)
				result += count(grid, i, j);
		}

		return result;

	}

	int count(vector<vector<int>>grid, int i, int j)
	{
		int num = 0;
		if (grid[i][j])
		{
			if (i == 0) num++;
			else if (grid[i - 1][j] == 0)num++;
			if (i == grid.size() - 1)num++;
			else if (grid[i + 1][j] == 0)num++;
			if (j == 0)num++;
			else if (grid[i][j - 1] == 0)num++;
			if (j == grid[i].size() - 1)num++;
			else if (grid[i][j + 1] == 0)num++;
		}

		return num;
	}

	void printVector2(vector<vector<int>>& grid)
	{
		cout << "[" << endl;
		for (int i = 0; i < grid.size(); i++)
		{
			cout << "[";
			for (int j = 0; j < grid[i].size(); j++)
			{
				cout << grid[i][j] << ", ";
			}
			cout << "]" << endl;
		}
		cout << "]" << endl;
	}
};

int main()
{
	Solution s;

	cout << "463. Island Perimeter:" << endl;
	int a[4][4] = { {0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0} };
	vector<vector<int>>v1;
	for (int i = 0; i < 4; i++)
	{
		vector<int>t(begin(a[i]), end(a[i]));
		v1.push_back(t);
	}
	s.printVector2(v1);
	cout << "Answer:" << s.islandPerimeter(v1) << endl << endl;

	system("pause");
}
