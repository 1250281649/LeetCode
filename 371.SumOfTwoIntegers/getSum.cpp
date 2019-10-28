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
	int getSum(int a, int b) {
		return b == 0 ? a : getSum(a^b, (a&b)<<1);
	}
};

int main()
{
	Solution s;

	cout << "Sum of Two Integers:" << endl;

	DWORD start = GetTickCount();

	int a[] = { 0, 1, 4, 16, 256, 8 };
	int b[] = { -1,3, 4, 10, 20000, 4888};

	cout << "  a  +  b  = ?" << endl;
	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		cout << a[i] << " + " << b[i] << "=" << s.getSum(a[i], b[i]) << endl;
	}

	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;
	system("pause");
	return 0;
}