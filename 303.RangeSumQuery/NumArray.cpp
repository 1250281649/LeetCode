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

class NumArray {
public:
	vector<int> sum;
	NumArray(vector<int> nums) {
		sum.push_back(0);
		if (nums.size() > 0)
			sum.push_back(nums[0]);
		if (nums.size()>1)
			for (int i = 1; i < nums.size(); i++)
			{
				sum.push_back(nums[i] + sum[i]);
			}
	}

	int sumRange(int i, int j) {
		return sum[j+1] - sum[i];
	}
};
int main()
{
	

	cout << "Range Sum Query - Immutable:" << endl;

	DWORD start = GetTickCount();

	int a[] = { -2, 0, 3, -5, 2, -1 };
	NumArray s(vector<int>(begin(a),end(a)));

	cout << "0,2" << " -> " << s.sumRange(0, 2) << endl;
	cout << "2,5" << " -> " << s.sumRange(2, 5) << endl;
	cout << "0,5" << " -> " << s.sumRange(0, 5) << endl;

	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;
	system("pause");
	return 0;
}