// 263.UglyNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

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
	
	bool isUgly(int num) 
	{
		int dev[3] = { 2, 3, 5 };
		for (int i = 0; i < 3 && num; i++)
		{
			while (num%dev[i] == 0)
				num = num / dev[i];
		}
		return num == 1;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;

	cout << "Ugly Number:" << endl;

	int a[] = { 1, 2, 3, 5, 6, 8, 14, 18, 73, 214797179};

	DWORD start = GetTickCount();
	cout << "number " << "ugly?" << endl;

	//cout << s.isUgly(73) << endl;
	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		cout << a[i] << " -> " << s.isUgly(a[i]) << endl;
	}

	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;
	system("pause");
	return 0;
}

