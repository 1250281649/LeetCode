#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		int table[26] = { 0 };
		for (int i = 0; i < s.length(); i++)
			table[s[i] - 'a']++;
		for (int i = 0; i < t.length(); i++)
			table[t[i] - 'a']-=1;
		for (int i = 0; i < 26; i++)
			if (table[i] != 0)
				return i + 'a';
		return 'a';
	}
};

int main()
{
	Solution s;
	string s1[] = { "a", "abcd" };
	string s2[] = { "ab", "abcde"};

	for (int i = 0; i < 2; i++)
	{
		cout << s1[i].c_str() << ", " << s2[i].c_str() << " -> " << s.findTheDifference(s1[i], s2[i]) << endl;
	}

	system("pause");
	return 0;
}