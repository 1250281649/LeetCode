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
	int compress(vector<char>& chars) {
		int count = 0;
		int j = 0;
		int i = 0;
		if (chars.size() == 0)
			return 0;
		if (chars.size() == 1)
			return 1;
		count = 1;
		j = 1;
		for (i = 1; i < chars.size(); i++)
		{
			if (chars[i] != chars[i-1])
			{
				if (count > 1)
				{
					vector<char> v = int2Char(count);
					for (int k = v.size() - 1; k >= 0; k--)
					{
						chars[j++]= (char)('0' + v[k]);
					}
					
				}
				count = 1;
				chars[j++] = chars[i];
			}
			else
				count++;
		}
		if (count>1)
		{
			vector<char> v = int2Char(count);
			for (int k = v.size() - 1; k >= 0; k--)
			{
				chars[j++] = (char)('0' + v[k]);
			}
		}
		return j;
	}

	vector<char>int2Char(int n)
	{
		vector<char> v;
		while (n > 0)
		{
			v.push_back(n % 10);
			n = n / 10;
		}
		return v;
	}

	void printVector(vector<char>& chars)
	{
		cout << "[";
		for (int i = 0; i < chars.size(); i++)
		{
			cout << chars[i] << ", ";
		}
		cout << "]" << endl;
	}
};

int main()
{
	Solution s;

	cout << "String Compression:" << endl;

	char c1[] = { 'a','a','b','b','c','c','c' };
	vector<char> v1(begin(c1), end(c1));
	s.printVector(v1);
	cout << s.compress(v1) << endl;
	s.printVector(v1);
	cout << endl;


	char c2[] = { 'a' };
	vector<char> v2(begin(c2), end(c2));
	s.printVector(v2);
	cout << s.compress(v2) << endl;
	s.printVector(v2);
	cout << endl;


	char c3[] = { 'a','b','b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };
	vector<char> v3(begin(c3), end(c3));
	s.printVector(v3);
	cout << s.compress(v3) << endl;
	s.printVector(v3);
	cout << endl;

	char c4[] = { 'a','a','a','b','b','a','a' };
	vector<char> v4(begin(c4), end(c4));
	s.printVector(v4);
	cout << s.compress(v4) << endl;
	s.printVector(v4);
	cout << endl;

	char c5[] = { 'a','b','c' };
	vector<char> v5(begin(c5), end(c5));
	s.printVector(v5);
	cout << s.compress(v5) << endl;
	s.printVector(v5);
	cout << endl;

	system("pause");
}
