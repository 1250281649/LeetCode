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
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		int i = 0;
		int m = 0;
		sort(begin(heaters), end(heaters));
		for (i = 0; i < houses.size(); i++)
		{
			m = max(findNear(heaters, houses[i]), m);
		}
		return m;
	}

	//find the nearest number in num
	int findNear(vector<int>num, int target)
	{
		int begin = 0; 
		int end = num.size() - 1;
		int mid = 0;
		while (end > begin+1)
		{
			mid = (begin + end) / 2;
			if (target == num[mid])
				return 0;
			else if (target > num[mid])
				begin = mid;
			else end = mid;
		}
		return min(abs(target - num[begin]), abs(num[end] - target));
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

	cout << "475. Heaters:" << endl;
	int h1[] = { 1,2,3 };
	int t1[] = { 2 };
	vector<int>v1(begin(h1), end(h1));
	vector<int>v2(begin(t1), end(t1));
	s.printVector(v1);
	s.printVector(v2);
	cout << s.findRadius(v1, v2) << endl;

	int h2[] = { 282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923 };
	int t2[] = { 823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612 };
	vector<int>v12(begin(h2), end(h2));
	vector<int>v22(begin(t2), end(t2));
	s.printVector(v12);
	s.printVector(v22);
	cout << s.findRadius(v12, v22) << endl;

	system("pause");
}
