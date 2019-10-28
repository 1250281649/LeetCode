#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>
#include <ctime>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int p = 0, q = 0;
		for (q = 0; q < nums.size(); q++)
		{
			if (nums[q])
				nums[p++] = nums[q];
		}
		for (p; p < nums.size(); p++)
			nums[p] = 0;
	}

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

	cout << "Move Zeroes:" << endl;

	int a[] = { 0, 1, 0, 3, 12 };

	DWORD start = GetTickCount();
	vector<int> v1(begin(a), end(a));

	s.printVector(v1);
	cout << "move:" << endl;
	s.moveZeroes(v1);
	s.printVector(v1);

	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;
	system("pause");
	return 0;
}