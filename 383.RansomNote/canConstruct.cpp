#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> table;
		for (int i = 0; i < magazine.length(); i++)
			table[magazine[i]]++;
		for (int i = 0; i < ransomNote.length(); i++)
		{
			table[ransomNote[i]]--;
			if (table[ransomNote[i]] < 0)
				return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	string s1[] = { "a", "aa", "aa", "fffbfg"};
	string s2[] = { "b", "ab", "aab", "effjfggbffjdgbjjhhdegh"};


	cout << s1[0].c_str() << ", " << s2[0].c_str() << " -> " << s.canConstruct(s1[0], s2[0]) << endl;
	cout << s1[1].c_str() << ", " << s2[1].c_str() << " -> " << s.canConstruct(s1[1], s2[1]) << endl;
	cout << s1[2].c_str() << ", " << s2[2].c_str() << " -> " << s.canConstruct(s1[2], s2[2]) << endl;
	cout << s1[3].c_str() << ", " << s2[3].c_str() << " -> " << s.canConstruct(s1[3], s2[3]) << endl;

	system("pause");
	return 0;
}