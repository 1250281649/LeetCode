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
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int i = 0, j = 0;
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		while (i < g.size() && j < s.size())
		{
			if (g[i] <= s[j])
			{
				i++;
				j++;
			}
			else
			{
				j++;
			}
		}
		return i;
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

	cout << "Assign Cookies:" << endl;
	int a1[] = { 1,2,3 };
	int b1[] = { 1,1 };
	vector<int>c1(begin(a1), end(a1));
	vector<int>g1(begin(b1), end(b1));
	s.printVector(c1);
	s.printVector(g1);
	cout << s.findContentChildren(c1, g1) << endl << endl;

	int a2[] = { 1,2 };
	int b2[] = { 1,2,3 };
	vector<int>c2(begin(a2), end(a2));
	vector<int>g2(begin(b2), end(b2));
	s.printVector(c2);
	s.printVector(g2);
	cout << s.findContentChildren(c2, g2) << endl << endl;

	system("pause");
}
