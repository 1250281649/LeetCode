#include <iostream>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		string result;
		for (int i = 0; i < s.length(); i++)
		{
			result.push_back(s[s.length()-i-1]);
		}
		return result;
	}
};

int main()
{
	Solution s;
	string s1[] = {"hello","","abcd","a"};

	for (int i = 0; i < 4; i++)
	{
		cout << s1[i].c_str() << " -> " << s.reverseString(s1[i]).c_str() << endl;
	}

	system("pause");
	return 0;
}