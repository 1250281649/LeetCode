#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		int table[26] = {0};
		for (int i = 0; i < s.length(); i++)
			table[s[i] - 'a']++;

		for (int i = 0; i < s.length(); i++)
		{
			if (table[s[i]-'a'] == 1)
				return i;
		}

		return -1;
	}
};

int main()
{
	Solution s;
	string s1[] = { "a", "leetcode", "loveleetcode", "fffbfg" };

	for (int i = 0; i < 4; i++)
	{
		cout << s1[i].c_str() << " -> " << s.firstUniqChar(s1[i]) << endl;
	}

	system("pause");
	return 0;
}