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
#include <queue>
#include <map>

using namespace std;

class Solution {
public:

	int maxProfit(vector<int>& prices) {
		vector<int>dif;
		int maxS = 0, sum = 0;
		int i = 0;
		if (!prices.size()) return 0;

		dif.push_back(0);
		i = 1;
		while (i < prices.size())
		{
			dif.push_back(prices[i] - prices[i - 1]);
			i++;
		}
		for (i = 0; i < dif.size(); i++)
		{
			sum += dif[i];
			maxS = max(maxS, sum);
			sum = max(sum,0);
		}
		return maxS;
	}

	void printVector(vector<int> v)
	{
		for (int j = 0; j < v.size(); j++)
			cout << v[j] << "  ";
		cout << endl;
	}
};

int main()
{
	Solution s;
	DWORD start = GetTickCount();

	cout << "Best Time to Buy and Sell Stock:" << endl;
	int a1[] = { 7, 1, 5, 3, 6, 4 };
	int a2[] = { 7};
	int a3[] = { 3, 2, 6, 5, 0, 3 };
	int a4[] = { 1, 2, 11, 4, 7 };

	vector<int> v1(begin(a1), end(a1));
	vector<int> v2(begin(a2), end(a2));
	vector<int> v3(begin(a3), end(a3));
	vector<int> v4(begin(a4), end(a4));
	s.printVector(v1);
	cout << "Profit:" << s.maxProfit(v1) << endl << endl;

	s.printVector(v2);
	cout << "Profit:" << s.maxProfit(v2) << endl << endl;

	s.printVector(v3);
	cout << "Profit:" << s.maxProfit(v3) << endl << endl;

	s.printVector(v4);
	cout << "Profit:" << s.maxProfit(v4) << endl << endl;

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
