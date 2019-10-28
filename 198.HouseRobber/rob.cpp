#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		vector<int> temp;
		if (nums.size()<=0) return 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i == 0)
				temp.push_back(nums[0]);
			else if (i == 1)
				temp.push_back(max(nums[0], nums[1]));
			else temp.push_back(max(nums[i]+temp[i-2], temp[i-1]));
		}
		return temp[nums.size()-1];
	}

	/*
	int rob(vector<int>& nums) {
		return maxSum(nums, nums.size()-1); 
	}

	int maxSum(vector<int>& nums, int length)
	{
		if (length == 0)
			return nums[0];
		else if (length == 1)
			return max(nums[0], nums[1]);
		else if (length == 2)
			return max(nums[0]+nums[2], nums[1]);
		else
		{
			return max(maxSum(nums, length - 2) + nums[length],
				maxSum(nums, length - 1));
		}
	}
	*/
	void printVector(vector<int> nums)
	{
		cout << "[";
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << "  ";
		}
		cout << "]" << endl;
	}
};

int main()
{
	Solution s;

	cout << "House Robber:" << endl;

	unsigned int a1[] = { 6, 4, 1, 10, 8};
	unsigned int a2[] = { 6, 8, 1 };
	unsigned int a3[] = { 10, 1, 1, 1, 12};
	unsigned int a4[] = { 226, 174, 214, 16, 218, 48, 153, 131, 128, 17, 157, 142, 88, 43, 37, 157, 43, 221, 191, 68, 206, 23, 225, 82, 54, 118, 111, 46, 80, 49, 245, 63, 25, 194, 72, 80, 143, 55, 209, 18, 55, 122, 65, 66, 177, 101, 63, 201, 172, 130, 103, 225, 142, 46, 86, 185, 62, 138, 212, 192, 125, 77, 223, 188, 99, 228, 90, 25, 193, 211, 84, 239, 119, 234, 85, 83, 123, 120, 131, 203, 219, 10, 82, 35, 120, 180, 249, 106, 37, 169, 225, 54, 103, 55, 166, 124};
	vector<int> v1(begin(a1), end(a1));
	vector<int> v2;// (begin(a2), end(a2));
	vector<int> v3(begin(a3), end(a3));
	vector<int> v4(begin(a4), end(a4));

	s.printVector(v1);
	cout << "Rob:" << s.rob(v1) << endl << endl;

	s.printVector(v2);
	cout << "Rob:" << s.rob(v2) << endl << endl;

	s.printVector(v3);
	cout << "Rob:" << s.rob(v3) << endl << endl;

	s.printVector(v4);
	cout << "Rob:" << s.rob(v4) << endl << endl;

	system("pause");
}
