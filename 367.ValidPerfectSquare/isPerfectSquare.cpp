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
	bool isPerfectSquare(int num) {
		int x1 = 0, x2 = 0;
		int temp = 0;
		if (num < 0)
			return false;
		else if (num <= 1)
			return true;
		x1 = num / 2;
		x2 = (x1 + num / x1) / 2;
		temp = x1 - x2;
		x1 = x2;
		while (temp > 1)
		{
			x2 = (x2 + num / x2) / 2;
			temp = x1 - x2;
			x1 = x2;
		}
		if (x2*x2 == num)
			return true;
		else return false;
	}
};

int main()
{
	Solution s;

	cout << "Valid Perfect Square:" << endl;

	DWORD start = GetTickCount();

	int a[] = { 0, 1, 4, 16, 256, 8 };

	cout << "number   Square?" << endl;
	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		cout << a[i] << " -> " << s.isPerfectSquare(a[i]) << endl;
	}

	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;
	system("pause");
	return 0;
}