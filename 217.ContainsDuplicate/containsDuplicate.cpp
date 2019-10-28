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
#include <queue>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		map<int, int>m;
		for (int i = 0; i < nums.size(); i++)
		{
			if (m.count(nums[i])) return true;
			else m[nums[i]] = 0;
		}
		return false;
	}

	void printVector(vector<int> v)
	{
		cout << "[";
		for (int j = 0; j < v.size(); j++)
			cout << v[j] << "  ";
		cout << "]" << endl;
	}
};

int main()
{
	Solution s;
	DWORD start = GetTickCount();

	cout << "Contains Duplicate:" << endl;
	int a1[] = { 7, 1, 5, 3, 6, 4};
	int a2[] = { 7,7 };
	int a3[] = { 3, 2, 6, 5, 0, 3 };
	int a4[] = { 1, 2, 11, 4, 7,1 };

	vector<int> v1(begin(a1), end(a1));
	vector<int> v2(begin(a2), end(a2));
	vector<int> v3(begin(a3), end(a3));
	vector<int> v4(begin(a4), end(a4));
	s.printVector(v1);
	cout << "Dilicate:" << s.containsDuplicate(v1) << endl << endl;

	s.printVector(v2);
	cout << "Dilicate:" << s.containsDuplicate(v2) << endl << endl;

	s.printVector(v3);
	cout << "Dilicate:" << s.containsDuplicate(v3) << endl << endl;

	s.printVector(v4);
	cout << "Dilicate:" << s.containsDuplicate(v4) << endl << endl;

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
