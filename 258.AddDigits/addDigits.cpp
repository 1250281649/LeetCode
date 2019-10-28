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
	int addDigits(int num) {
		if (num == 0) return 0;
		if (num % 9 == 0) return 9;
		return (num - 1) % 9 + 1;
	}
};

int main()
{
	Solution s;

	cout << "Add digits:" << endl;

	unsigned int a[] = { 0, 1, 4, 10,23, 134, 999, 1543 };

	DWORD start = GetTickCount();
	cout << "  number " << "add Digits?" << endl;

	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		cout << a[i] << " -> " << s.addDigits(a[i]) << endl;
	}

	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;
	system("pause");
}
