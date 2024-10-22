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
	bool repeatedSubstringPattern(string s) {
		return (s + s).substr(1, s.size() * 2 - 2).find(s) != -1;
	}
};

int main()
{
	Solution s;

	cout << "459. Repeated Substring Pattern:" << endl;
	string a[] = {"babbaaabbbbabbaaabbbbabbaaabbbbabbaaabbbbabbaaabbbbabbaaabbbbabbaaabbbbabbaaabbbbabbaaabbbbabbaaabbb",
		"abaababaab", "aabaaba", "abab", "abc", "abcabcabcabc","abaaba","aaabbb" };
	int b[] = {1, 1, 0, 1, 0, 1, 1, 0 };
	for (int i = 0; i < sizeof(b)/sizeof(int); i++)
	{
		cout << a[i].c_str() << endl;
		cout << b[i] << "->" << s.repeatedSubstringPattern(a[i]) << endl << endl;
	}

	system("pause");
}
