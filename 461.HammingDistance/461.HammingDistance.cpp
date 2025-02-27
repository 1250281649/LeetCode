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
	int hammingDistance(int x, int y) {
		int i = 0;
		int result = 0;
		for (i = 0; i < 31; i++)
		{
			result += ((x >> i) ^ (y >> i)) & 1;
		}
		return result;
	}
};

int main()
{
	Solution s;

	cout << "461. Hamming Distance:" << endl;
	int a[] = {1};
	int b[] = { 4 };
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		cout << "x=" << a[i] << ", y=" << b[i] << " => " << s.hammingDistance(a[i], b[i]) << endl;
	}

	system("pause");
}
