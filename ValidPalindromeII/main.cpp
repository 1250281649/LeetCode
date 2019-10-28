#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	bool validPalindrome(string s) {
		int len = s.length();
		int i = 0, j = len - 1;
		int index = 0;
		int single = 0;
		int tempi = 0, tempj = 0;

		while (i < len / 2 && j > len / 2)
		{
			if (s[i] != s[j])
			{
				if (index == 1 && single == 0)
				{
					return false;
				}
				else if (index == 1 && single == 1)
				{
					single = 0;
					i = tempi;
					j = tempj;
					continue;
				}

				if (s[i] == s[j - 1] && s[i + 1] == s[j])
				{
					index = 1;
					single = 1;
					tempi = i;
					tempj = j - 1;
					i++;
				}
				else if (s[i] == s[j - 1])
				{
					j--;
					index = 1;
				}
				else if (s[i + 1] == s[j])
				{
					i++;
					index = 1;
				}
				else
				{
					return false;
				}
			}
			i++;
			j--;
		}
		return true;
	}
};

void main()
{
	string input = "pidbliassaqozokmtgahluruufwbjdtayuhbxwoicviygilgzduudzgligyviciowxbhuyatdjbwfuurulhagtmkozoqassailbdip";
	bool result;

	cout << "input: " << input << endl;
	Solution leetcode;
	result = leetcode.validPalindrome(input);
	cout << "result: " << result << endl;

	getchar();
}