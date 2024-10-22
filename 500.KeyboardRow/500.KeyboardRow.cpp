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
	unordered_map<char, int> map;
	vector<string> findWords(vector<string>& words) {
		vector<string> result;
		int i = 0, j = 0;
		char c;
		initMap();
		int t = 0;
		for (i = 0; i < words.size(); i++)
		{
			if (words[i].length() <= 1)
				result.push_back(words[i]);
			else
			{
				c = words[i][0];
				if (c >= 'A' && c <= 'Z')
					c = c + 32;
				t = map[c];
				for (j = 1; j < words[i].length(); j++)
				{
					c = words[i][j];
					if (c >= 'A' && c <= 'Z')
						c = c + 32;
					if (map[c] != t)
						break;
				}
				if (j >= words[i].length())
					result.push_back(words[i]);
			}
		}

		return result;
	}

	void initMap()
	{
		map['q'] = 1;
		map['w'] = 1;
		map['e'] = 1;
		map['r'] = 1;
		map['t'] = 1;
		map['y'] = 1;
		map['u'] = 1;
		map['i'] = 1;
		map['o'] = 1;
		map['p'] = 1;

		map['a'] = 2;
		map['s'] = 2;
		map['d'] = 2;
		map['f'] = 2;
		map['g'] = 2;
		map['h'] = 2;
		map['j'] = 2;
		map['k'] = 2;
		map['l'] = 2;

		map['z'] = 3;
		map['x'] = 3;
		map['c'] = 3;
		map['v'] = 3;
		map['b'] = 3;
		map['n'] = 3;
		map['m'] = 3;
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

	cout << "500. Keyboard Row:" << endl;
	string a[] = { "Hello", "Alaska", "Dad", "Peace" };
	vector<string> v(begin(a), end(a));
	cout << "Input: ";
	for (int i = 0; i < v.size(); i++)
	{
		cout << a[i].c_str() << "  ";
	}
	cout << endl;
	cout << "output:";
	vector<string>r;
	r = s.findWords(v);
	for (int i = 0; i < r.size(); i++)
	{
		cout << r[i].c_str() << "  ";
	}
	cout << endl;

	system("pause");
}
