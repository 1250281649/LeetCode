#include <iostream>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxLen = 0,lastLen;
		int begin = 0,end = 0;
		
		int i = 0,j = 0;
		
		if (s.length() == 0) return 0;
		if (s.length() == 1) return 1;
		maxLen = 1;
		for (i = 1; i < s.length(); i++)
		{
			for (j = begin; j <= end; j++)
			{
				if (s[j] == s[i])
					break;
			}
			if (j > end)
			{
				// not in substr
				end++;
				lastLen = end - begin +1;
				maxLen = lastLen >= maxLen ? lastLen : maxLen;
			}
			else
			{
				// in the substr
				if (j == begin)
				{
					end++;
					begin++;
				}
				else if (j == end)
				{
					end++;
					begin = end;
				}
				else
				{
					end++;
					begin = j+1;
				}
				//if (begin > end) end = begin;
			}
		}
		return maxLen;
	}
};

int main()
{
	Solution s;
	string s1 = "abcabc";//3
	string s2 = "bbbbb";//1
	string s3 = "pwwkew";//3
	string s4 = "ohomm";//3
	string s5 = "dvdf";//3
	string s6 = "biidygcc";//5
	string s7 = "jbpnbwwd";//4
	string s8 = "ckilbkd";//5

	cout << "s1: " << s.lengthOfLongestSubstring(s1) << endl;
	cout << "s2: " << s.lengthOfLongestSubstring(s2) << endl;
	cout << "s3: " << s.lengthOfLongestSubstring(s3) << endl;
	cout << "s4: " << s.lengthOfLongestSubstring(s4) << endl;
	cout << "s5: " << s.lengthOfLongestSubstring(s5) << endl;
	cout << "s6: " << s.lengthOfLongestSubstring(s6) << endl;
	cout << "s7: " << s.lengthOfLongestSubstring(s7) << endl;
	cout << "s8: " << s.lengthOfLongestSubstring(s8) << endl;

	system("pause");
	return 0;
}