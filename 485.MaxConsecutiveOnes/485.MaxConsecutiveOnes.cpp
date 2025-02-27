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
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int max = 0, temp = 0;
		int i = 0;
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				if (temp > max) max = temp;
				temp = 0;
			}
			else temp++;
		}
		if (temp > max) max = temp;
		return max;
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

	cout << "485. Max Consecutive Ones:" << endl;
	int a1[] = {1,1,0,1,1,1};
	vector<int> v1(begin(a1), end(a1));
	s.printVector(v1);
	cout << "output:" << s.findMaxConsecutiveOnes(v1) << endl;
	
	system("pause");
}
