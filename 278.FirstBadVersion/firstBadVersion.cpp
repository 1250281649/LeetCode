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
	int firstBadVersion(int n) {
		return findBad(1,n);
	}

	//数据类型的问题
	int findBad(long long begin, long long end)
	{
		if (end - begin <= 1)
		{
			return isBadVersion(begin)?begin:end;
		}
		else
		{
			if (isBadVersion((end + begin) / 2))
				return findBad(begin, (end + begin) / 2 );
			else return findBad((end + begin) / 2 , end);
		}
	}

	bool isBadVersion(int version)
	{
		if (version >= 1702766719)
			return true;
		else return false;
	}
};

int main()
{
	Solution s;

	cout << "First Bad Version:" << endl;

	DWORD start = GetTickCount();

	cout << s.firstBadVersion(2126753390) << endl;

	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;
	system("pause");
	return 0;
}