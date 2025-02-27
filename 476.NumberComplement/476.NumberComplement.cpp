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
	int findComplement(int num) {
		int x;
		int i = 0;
		for (i = 31; i >=0; i--)
		{
			if (((num >> i) & 1) != 0)
				break;
			num = num | (1 << i);
		}
		x = ~num;
		return x;
	}

	void printVector(vector<int> v)
	{
		cout << "[";
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << ",";
		}
		cout << "]" << endl;
	}
};

int main()
{
	Solution s;

	cout << "Number Complement:" << endl;
	
	int a[] = { 5, 1};
	int b[] = { 2, 0};
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		cout << a[i] << "  ->  " << s.findComplement(a[i]) << "  (excepted:" << b[i] << ")" << endl;
	}

	system("pause");
}
