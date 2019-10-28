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
	bool isPowerOfFour(int num) {
		if (num <= 0) return false;
		int count = 0;
		int index = 0;
		for (int i = 1; i < 32; i++)
		{
			if (num & 1)
			{
				count++;
				index = i;
			}
			num = num >> 1;
		}
		return count==1 && index%2;
	}
};

int main()
{
	Solution s;

	cout << "Power of Four:" << endl;

	DWORD start = GetTickCount();

	int a[] = { 0, 1, 4, 16, 256, 8 };

	cout << "number   4?" << endl;
	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		cout << a[i] << " -> " << s.isPowerOfFour(a[i]) << endl;
	}

	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;
	system("pause");
	return 0;
}