#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int arrangeCoins(int n) {
		long long sum = 0;
		long long begin=0, end = n;
		long long mid = 0;
		while (end - begin>1)
		{
			mid = (begin + end) / 2;
			sum = mid * (mid + 1) / 2;
			if (sum > n)
				end = mid-1;
			else begin = mid;
		}
		sum = end * (end + 1) / 2;
		if (sum <= n)
			return end;
		return begin;
	}
};

int main()
{
	Solution s;

	cout << "Arranging Coins:" << endl;

	int a1[] = { 5, 8, 15,1804289383 };
	for (int i = 0; i < sizeof(a1) / 4; i++)
	{
		cout << a1[i] << " -> " << s.arrangeCoins(a1[i]) << endl;
	}

	system("pause");
}
