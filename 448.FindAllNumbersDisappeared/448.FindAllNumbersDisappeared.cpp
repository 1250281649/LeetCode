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
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> result;
		int i = 0;
		int j = 0;
		int length = 0;
		for (i = 0; i <= nums.size(); i++)
			result.push_back(i);
		for (i = 0; i < nums.size(); i++)
		{
			if (result[nums[i]] > 0)
				result[nums[i]] = 0;
			else result[nums[i]]--;
		}
		for (i = 0; i < result.size(); i++)
		{
			if (result[i] > 0)
			{
				result[j++] = result[i];
			}
		}
		length = result.size() - j;
		for (i = 0; i < length; i++)
			result.pop_back();
		return result;
	}
	
	void printVector(vector<int> v)
	{
		cout << "[";
		for (int i = 0; i < v.size(); i++)
		{
			cout<< v[i] << ",";
		}
		cout << "]" << endl;
	}
};

int main()
{
	Solution s;

	cout << "Find All Numbers Disappeared in an Array:" << endl;
	int a1[] = { 4,3,2,7,8,2,3,1 };
	vector<int> v1(begin(a1), end(a1));
	s.printVector(v1);
	s.printVector(s.findDisappearedNumbers(v1));
	cout << endl;
	

	system("pause");
}
