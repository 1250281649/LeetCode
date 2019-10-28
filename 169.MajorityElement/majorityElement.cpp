#include <iostream>
#include <list>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int>table;
		for (int i = 0; i < nums.size(); i++)
		{
			if(table.find(nums[i]) != table.end())
				table[nums[i]] ++;
			else table[nums[i]] = 0;
		}
		int max = INT_MIN;
		int index = 0;
		map<int, int>::iterator it;
		for (it = table.begin(); it != table.end(); it++)
		{
			if (it->second > max)
			{
				max = it->second;
				index = it->first;
			}
		}
		return index;
	}

	void printVector(vector<int>& numbers)
	{
		cout << "[";
		for (int i = 0; i < numbers.size(); i++)
		{
			cout << numbers[i] << ", ";
		}
		cout << "]" << endl;
	}
};

int main()
{
	Solution s;

	int a[] = { 2, 7, 3, 3, 2, 3, 3, 5, 3 };
	int b[] = { 1, 2, 3, 1, 1, 1, 3, 1 };

	vector<int>v1(begin(a), end(a));
	vector<int>v2(begin(b), end(b));
	vector<int>result;

	cout << "Majority Element:" << endl;
	s.printVector(v1);
	cout << "Major Element:" << s.majorityElement(v1) << endl << endl;

	s.printVector(v2);
	cout << "Major Element:" << s.majorityElement(v2) << endl;

	system("pause");
}
