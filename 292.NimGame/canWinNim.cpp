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
	bool canWinNim(int n) {
		return n & 3 ? true : false;
	}
};

int main()
{
	Solution s;

	cout << "Nim Game:" << endl;

	DWORD start = GetTickCount();

	int a[] = {2,4,10,100,19787,2432428};

	cout << "  stones   canWind?" << endl;
	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		cout << a[i] << " -> " << s.canWinNim(a[i]) << endl;
	}

	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;
	system("pause");
	return 0;
}