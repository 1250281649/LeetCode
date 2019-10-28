#include <iostream>
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
	int singleNumber(vector<int>& nums) {
		for (int i = 1; i < nums.size(); i++)
			nums[0] ^= nums[i];
		return nums[0];
	}

	void printVector(vector<int> v)
	{
		cout << "[";
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ", ";
		cout << "]" << endl;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> result;
	DWORD start = GetTickCount();

	//int a1[] = {-10, -3, 0, 5, 9};
	int a1[] = { 0, 1, 1, 3, 0, 4, 4 };
	int a2[] = { 4, 5, 6, 7, 6, 5, 4 };
	vector<int> v1(begin(a1), end(a1));
	vector<int> v2(begin(a2), end(a2));
	cout << "find the single number:" << endl;
	s.printVector(v1);
	cout << "Single:" << s.singleNumber(v1) << endl << endl;

	s.printVector(v2);
	cout << "Single:" << s.singleNumber(v2) << endl << endl;


	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
