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
	int guessNumber(int n) {
		long long begin = 1, end = n;
		long long mid = 0;
		int guessResult = 0;
		while (end > begin)
		{
			mid = (end + begin) / 2;
			guessResult = guess(mid);
			if (guessResult == 0)
				return mid;
			else if (guessResult == -1)
			{
				end = mid - 1;
			}
			else
			{
				begin = mid + 1;
			}
		}
		return begin;
	}


	int guess(int num)
	{
		if (num > 1702766719)
			return 1;
		else if (num == 1702766719)
			return 0;
		else return -1;
	}
};

int main()
{
	Solution s;

	cout << "Guess Number Higher or Lower:" << endl;

	DWORD start = GetTickCount();

	int a[] = { 10, 1, 4, 16, 256, 8 ,2126753390};

	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		cout << a[i] << "->" << s.guessNumber(a[i]) << endl;
	}

	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;
	system("pause");
	return 0;
}