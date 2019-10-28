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
	int missingNumber(vector<int>& nums) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += nums[i];
		return (nums.size()*(nums.size()+1)/2-sum);
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

	cout << " Missing Number:" << endl;

	int a[] = { 3, 0, 1 };
	int b[] = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };

	DWORD start = GetTickCount();
	vector<int> v1(begin(a), end(a));
	vector<int> v2(begin(b),end(b));

	cout << "number " << "missing" << endl;
	s.printVector(v1);
	cout << "missing:" << s.missingNumber(v1) << endl;
	s.printVector(v2);
	cout << "missing:" << s.missingNumber(v2) << endl;

	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;
	system("pause");
	return 0;
}