#include <iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.size() <= 1) return true;
		int begin = 0, end = s.length() - 1;
		char c1 = 0, c2 = 0;
		bool flag = true;
		while (begin < end)
		{
			flag = true;
			while (flag)
			{
				if (s[begin] >= '0' && s[begin] <= '9')
				{
					c1 = s[begin];
					flag = false;
				}
				else if (s[begin] >= 'A' && s[begin] <= 'Z')
				{
					c1 = s[begin];
					flag = false;
				}
				else if (s[begin] >= 'a' && s[begin] <= 'z')
				{
					c1 = s[begin] - 32;
					flag = false;
				}
				else
				{
					begin++;
					flag = true;
				}
			}
			flag = true;
			while (flag)
			{
				if (s[end] >= '0' && s[end] <= '9')
				{
					c2 = s[end];
					flag = false;
				}
				else if (s[end] >= 'A' && s[end] <= 'Z')
				{
					c2 = s[end];
					flag = false;
				}
				else if (s[end] >= 'a' && s[end] <= 'z')
				{
					c2 = s[end] - 32;
					flag = false;
				}
				else
				{
					end--;
					flag = true;
				}
			}

			if (end >= begin)
			{
				if (c2 != c1)return false;
				begin++;
				end--;
			}
			else return true;	
		}
		return true;
	}
};

int main()
{
	Solution s;
	string s1 = "A man, a plan, a canal: Panama";
	string s2 = "race a car";		
	string s3 = "a, b a";
	string s4 = "o";
	string s5 = "";

	cout << "s1: " << s.isPalindrome(s1) << "(1)" << endl;
	cout << "s2: " << s.isPalindrome(s2) << "(0)" << endl;
	cout << "s3: " << s.isPalindrome(s3) << "(1)" << endl;
	cout << "s4: " << s.isPalindrome(s4) << "(1)" << endl;
	cout << "s5: " << s.isPalindrome(s5) << "(1)" << endl;

	system("pause");
	return 0;
}