#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int i = 0, j = 0;
		int index = 0, len = 1, maxlen = 1;
		if (s.length() <= 1)
			return s;//空字符串和单个字符直接返回

		string substr;
		for (i = 0; i < s.length() - 1; i++)
		{
			//先考虑奇对称
			for (j = i + 1, len = 0; j < s.length() && j <= 2 * i; j++)
			{
				if (s[j] == s[2 * i - j])
				{
					len++;
				}
				else
				{
					break;
				}
			}
			len = 2 * len + 1;
			if (len > maxlen)
			{
				maxlen = len;
				index = i;
			}
			//再考虑偶对称
			for (j = i, len = 0; j < s.length() && j <= 2 * i; j++)
			{
				if (s[2 * i - j] == s[j + 1])
					len++;
				else break;
			}
			len = 2 * len;
			if (len > maxlen)
			{
				maxlen = len;
				index = i;
			}
		}
		if (maxlen == 1)
			substr = s.substr(0,1);
		else substr = s.substr(index - (maxlen-1) / 2, maxlen);
		return substr;
	}
};

int main()
{
	Solution s;
	string s1 = "babad";
	string s2 = "cbbd";
	string s3 = "abbad";
	string s4 = "abc";
	string s5 = "a";
	string s6 = "bb";

	cout << s1 <<"  " << s.longestPalindrome(s1) << endl;
	cout << s2 << "  " << s.longestPalindrome(s2) << endl;
	cout << s3 << "  " << s.longestPalindrome(s3) << endl;
	cout << s4 << "  " << s.longestPalindrome(s4) << endl;
	cout << s5 << "  " << s.longestPalindrome(s5) << endl;
	cout << s6 << "  " << s.longestPalindrome(s6) << endl;
	system("pause");
	return 0;
}