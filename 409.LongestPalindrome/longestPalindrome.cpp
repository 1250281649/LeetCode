#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		int table[127] = {0};
		int sum = 0;
		bool hasOdd = false;
		for (int i = 0; i < s.length(); i++)
			table[s[i]]++;
		for (int i = 'A'; i <= 'z'; i++)
		{
			sum += (table[i] / 2)*2;
			if (!hasOdd && table[i] % 2)
				hasOdd = true;
		}
		return sum+hasOdd;
	}
};

int main()
{
	Solution s;
	string str[] = { "abccccdd" ,"AaA"};

	cout << "Longest Palindrome:" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << str[i].c_str() << " -> " << s.longestPalindrome(str[i]) << endl;
	}

	system("pause");
	return 0;
}