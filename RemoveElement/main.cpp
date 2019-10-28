#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int p = 0, q = 0;
		while (q < nums.size())
		{
			if (nums[q] == val) q++;
			else
			{
				if (q>p)
					nums[p] = nums[q];
				p++;
				q++;
			}
		}
		return p;
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
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);

	cout << "input array:";
	s.printVector(nums);
	cout << "output array:";

	cout << "Length:" << s.removeElement(nums,3) << endl;
	s.printVector(nums);

	system("pause");
}
