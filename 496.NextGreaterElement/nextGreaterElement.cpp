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
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int> result;
		int i, j;
		int temp1;
		for (i = 0; i < findNums.size(); i++)
		{
			for (j = 0; j < nums.size(); j++)
			{
				if (findNums[i] == nums[j])
					break;
			}
			temp1 = INT_MAX;
			for (; j < nums.size(); j++)
			{
				if (nums[j] > findNums[i])
				{
					temp1 = nums[j];
					break;
				}
			}
			if (temp1 != INT_MAX)
				result.push_back(temp1);
			else result.push_back(-1);
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

	cout << "下一个更大元素:" << endl;
	int a1[] = { 4, 1, 2 };
	int a2[] = { 1, 3, 4, 2};
	vector<int> v1(begin(a1), end(a1));
	vector<int> v2(begin(a2), end(a2));
	s.printVector(v1);
	s.printVector(v2);
	cout << "next greater:";
	s.printVector(s.nextGreaterElement(v1, v2));

	int a12[] = { 2, 4};
	int a22[] = { 1, 2, 3, 4 };
	vector<int> v12(begin(a12), end(a12));
	vector<int> v22(begin(a22), end(a22));
	s.printVector(v12);
	s.printVector(v22);
	cout << "next greater:";
	s.printVector(s.nextGreaterElement(v12, v22));


	system("pause");
}
