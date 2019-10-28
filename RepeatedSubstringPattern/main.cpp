#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		if (s.size() < 2)
		{
			return false;
		}

		string subStr;
		subStr += s[0];

		for (int i = 1; i < s.size(); i++)
		{
			if (subStr.size() > s.size() / 2)
			{
				return false;
			}

			if (checkStr(s, subStr, i))
			{
				return true;
			}
			else
			{
				subStr = s.substr(0, i + 1);
			}
		}
		return false;
	}

	bool checkStr(string A, string B, int start)
	{
		int lenA = A.size();
		int lenB = B.size();

		int i = start;
		int j = 0;
		while (i < lenA)
		{
			for (j = 0; j < lenB; j++, i++)
			{
				if (A[i] != B[j])
				{
					return false;
				}
			}
		}
		return j == lenB;
	}
};

void main()
{
	string word = "abacababacab";
	bool result;

	cout << word << endl;
	Solution leetcode;
	result = leetcode.repeatedSubstringPattern(word);

	cout << "result: " << result << endl;

	getchar();
}