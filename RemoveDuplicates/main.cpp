#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int p = 0, q = 1;
		if (nums.size() <= 1) 
			return nums.size();

		for (p = 0, q = 1; q<nums.size(); q++)
		{
			if (nums[q] != nums[p])
			{
				nums[++p] = nums[q];
			}
		}
		return p+1;
	}

	void printVector(vector<int>& nums)
	{
		int i = 0;
		for (i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << "  ";
		}
		cout << endl;
	}
};

int main()
{
	Solution s;
	vector<int> nums;
	//nums.push_back(1);
	//nums.push_back(1);
	//nums.push_back(2);
	
	cout << "input array:";
	s.printVector(nums);
	cout << "output array:";
	
	cout << "Length:" << s.removeDuplicates(nums) << endl;
	s.printVector(nums);

	system("pause");
}
