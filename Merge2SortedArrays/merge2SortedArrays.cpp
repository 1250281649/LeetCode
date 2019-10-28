#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <ctime>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int p = m-1, q = n-1;
		while (p >= 0 && q >= 0)
		{
			if (nums2[q] >= nums1[p])
			{
				nums1[p + q + 1] = nums2[q];
				q--;
			}
			else
			{
				nums1[p + q + 1] = nums1[p];
				p--;
			}
		}
		if (q >= 0)
			memcpy(&nums1[0], &nums2[0], (q+1)*sizeof(int));
		/*
		if (q >= 0)
		{
			while (q >= 0)
			{
				nums1[q] = nums2[q];
				q--;
			}
		}*/
	}

	void printArray(vector<int>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << "  ";
		}
		cout << endl;
	}
};

int main()
{
	Solution s;
	//clock_t start, stop;
	DWORD start = GetTickCount();

	int a[] = { 2, 3, 5, 6, 9 };
	int b[] = {0,1,4,7,8};
	//int b[] = { 1 };
	vector<int> nums1(begin(a), end(a));
	vector<int> nums2(begin(b), end(b));
	for (int i = 0; i < nums2.size(); i++)
		nums1.push_back(0);

	cout << "merger 2 sorted arrays:" << endl;
	cout << "input:" << endl;
	s.printArray(nums1);
	s.printArray(nums2);
	cout << "output:" << endl;
	s.merge(nums1,nums1.size()-nums2.size(), nums2, nums2.size());
	s.printArray(nums1);

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
