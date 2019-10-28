#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <ctime>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		vector<int>temp;
		int i = 0;
		for (i = 0; i < n+1; i++)
		{
			if (i < 3)
			{
				temp.push_back(i);
			}
			else
			{
				temp.push_back(temp[i-1] + temp[i-2]);
			}
		}
		return temp[n];
	}
};

int main()
{
	Solution s;
	//clock_t start, stop;
	DWORD start = GetTickCount();

	int a[] = { 2, 3,20,30,40, 44};
	cout << "climping stairs:" << endl;
	
	for (int i = 2; i < 45; i++)
	{
		cout << "input:" << i << "  output:" << s.climbStairs(i) << endl;
	}
	
	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
