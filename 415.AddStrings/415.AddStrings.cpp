#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		string result;
		string s1, s2;
		int carryOut = 0;
		int sum = 0;
		if (num1.length() > num2.length())
		{
			s1 = num1;
			s2 = num2;
		}
		else
		{
			s1 = num2;
			s2 = num1;
		}

		for (int i = 0; i < s2.length(); i++)
		{
			sum = carryOut + s1[s1.length() - 1 - i] + s2[s2.length() - 1 - i] - 96;
			if (sum >= 10)
			{
				carryOut = 1;
				sum = sum - 10;
			}
			else carryOut = 0;
			result = (char)(sum+'0')+result;

		}
		for (int i = s2.length(); i < s1.length(); i++)
		{
			sum = carryOut + s1[s1.length() - 1 - i] - '0';
			if (sum >= 10)
			{
				carryOut = 1;
				sum = sum - 10;
			}
			else carryOut = 0;
			result = (char)(sum + '0') + result;
		}
		if (carryOut)
			result = '1' + result;
		return result;
	}
};

int main()
{
	Solution s;

	string s1[] = { "1","13","1108","999" };
	string s2[] = { "1","9","3234" ,"1"};

	cout << "Add Strings:" << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << s1[i].c_str() << " + " << s2[i].c_str() << " = " << s.addStrings(s1[i], s2[i]).c_str() << endl;
	}

	system("pause");
}
