#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
	int countSegments(string s) {
		int count = 0;
		if (s.length() < 1)
			return 0;
		else if (s.length() == 1)
			return s[0] == ' ' ? 0 : 1;
		for (int i = 1; i < s.length(); i++)
		{
			if ((s[i] == ' ') && (s[i - 1] != ' '))
				count++;
		}
		if (s[s.length() - 1] != ' ')
			count++;
		return count;
	}
};

int main()
{
	Solution s;

	string s1[] = { "Hello, my name is John","helloworld, guo","hello","a","  " };

	cout << "Add Strings:" << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << s1[i].c_str() <<" -> " << s.countSegments(s1[i]) << endl;
	}

	system("pause");
}
