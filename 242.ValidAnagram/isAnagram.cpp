#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int>table;
		if (s.length() != t.length())
			return false;
		for (int i = 0; i < s.length(); i++)
		{
			table[s[i]]++;
		}
		for (int i = 0; i < t.length(); i++)
		{
			table[t[i]]--;
			if (table[t[i]] < 0)
				return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	string s1[] = { "anagram", "rat", "are", "paper" };
	string t1[] = { "nagaram", "car", "ear", "rapper" };

	cout << "Valid Anagram:" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << s1[i].c_str() << ", " << t1[i].c_str() << " -> " << s.isAnagram(s1[i], t1[i]) << endl;
	}

	system("pause");
}
