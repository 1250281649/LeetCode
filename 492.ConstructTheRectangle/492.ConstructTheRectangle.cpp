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
	vector<int> constructRectangle(int area) {
		vector<int> result;
		int q = 0;
		q = sqrt(area);
		for (int i = q; i >= 1; i--)
		{
			if (area%i == 0)
			{
				result.push_back(area/i);
				result.push_back(i);
				break;
			}
		}
		return result;
	}

	void printVector(vector<int> v)
	{
		cout << "[";
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << ",";
		}
		cout << "]" << endl;
	}
};

int main()
{
	Solution s;

	cout << "492. Construct the Rectangle:" << endl;
	int a1[] = { 4, 5, 12, 100 };
	
	for (int i = 0; i < sizeof(a1) / sizeof(int); i++)
	{
		vector<int>t = s.constructRectangle(a1[i]);
		cout << a1[i] << " -> " << t[0] << " * " << t[1] << endl;
	}

	system("pause");
}
