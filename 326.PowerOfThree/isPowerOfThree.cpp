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
	bool isPowerOfThree(int n) {
		return n>0 && 1162261467%n==0;
	}
};

int main()
{
	Solution s;

	cout << "Power of Three:" << endl;

	DWORD start = GetTickCount();

	int a[] = { 1, 3, 9, 100, 243, 2432428 };

	cout << "number   three?" << endl;
	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		cout << a[i] << " -> " << s.isPowerOfThree(a[i]) << endl;
	}

	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;
	system("pause");
	return 0;
}