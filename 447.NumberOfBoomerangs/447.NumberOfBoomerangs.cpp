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
	
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int i = 0, j = 0;
		int result = 0;
		
		for (i = 0; i < points.size(); i++)
		{
			unordered_map<int, int>table;
			for (j = 0; j < points.size(); j++)
			{
				if (i == j)
					continue;
				
				table[(points[i].first - points[j].first) * (points[i].first - points[j].first) +
					  (points[i].second - points[j].second) * (points[i].second - points[j].second)] ++;
			}
			unordered_map<int, int>::iterator it;
			for (it = table.begin(); it != table.end(); it++)
			{
				result += it->second*(it->second - 1);
			}
		}
		return result;
	}
	
	/*
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int result = 0;
		int i = 0, j = 0, k = 0;
		for (i = 0; i < points.size(); i++)
		{
			for (j = 0; j < points.size(); j++)
			{
				if (i == j)
					continue;
				for (k = 0; k < points.size(); k++)
				{
					if (k == i || k == j)
						continue;
					if (pow((points[i].first - points[j].first), 2) +
						pow((points[i].second - points[j].second), 2) ==
						pow((points[i].first - points[k].first), 2) +
						pow((points[i].second - points[k].second), 2)
						)
						result++;
				}
			}
		}

		return result;
	}
	*/
	void printVector(vector<pair<int, int>> v)
	{
		cout << "[";
		for (int i = 0; i < v.size(); i++)
		{
			cout << "[" << v[i].first << "," << v[i].second << "],";
		}
		cout << "]" << endl;
	}
};

int main()
{
	Solution s;

	cout << "Number of Boomerangs:" << endl;

	pair<int, int> a1[] = { {0,0},{1,0},{2,0} };
	vector<pair<int, int>> v1(begin(a1),end(a1));
	s.printVector(v1);
	cout << s.numberOfBoomerangs(v1) << endl << endl;

	pair<int, int> a2[] = { { 1,1 },{ 2,2 },{ 3,3 } };
	vector<pair<int, int>> v2(begin(a2), end(a2));
	s.printVector(v2);
	cout << s.numberOfBoomerangs(v2) << endl << endl;

	pair<int, int> a3[] = { { 0,0 },{ 1,0 },{ -1,0 },{0,1},{0,-1} };
	vector<pair<int, int>> v3(begin(a3), end(a3));
	s.printVector(v3);
	cout << s.numberOfBoomerangs(v3) << endl << endl;

	system("pause");
}
