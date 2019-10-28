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
	bool isPowerOfTwo(int n) {
		int count = 0;
		if (n < 0) return false;
		for (int i = 0; i < 31; i++)
		{
			if (n >> i & 1)
				count++;
		}
		return count == 1;
	}
};

int main()
{
	Solution s;

	cout << "Power of Two:" << endl;

	unsigned int a[] = { 0, 1, 2, 3, 4, 8, 16, 31, 64, 65536 };

	DWORD start = GetTickCount();
	cout << "  number " << " 2^n?" << endl;

	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		cout << a[i] << " -> " << s.isPowerOfTwo(a[i]) << endl;
	}

	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;
	system("pause");
}
