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
	int minMoves(vector<int>& nums) {
		int result = 0;
		int min = INT_MAX;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			if (nums[i] < min)
				min = nums[i];
		}
		result = sum - nums.size()*min;
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

	cout << "Minimum Moves to Equal Array Elements:" << endl;
	int a1[] = { 1,2,3 };
	vector<int> v1(begin(a1), end(a1));
	s.printVector(v1);
	cout<<s.minMoves(v1) << endl << endl;

	int a2[] = { 5,6,8,8,5 };
	vector<int> v2(begin(a2), end(a2));
	s.printVector(v2);
	cout << s.minMoves(v2) << endl << endl;

	system("pause");
}
