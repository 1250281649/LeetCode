#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int i = 0;
		map<char, char>t1;
		map<char, char>t2;
		if (s.length() != t.length())return false;
		for (i = 0; i < s.length(); i++)
		{
			if (t1.find(s[i]) == t1.end())
			{
				t1[s[i]] = t[i];
			}
			else if (t1[s[i]] != t[i]) return false;

			if (t2.find(t[i]) == t2.end())
			{
				t2[t[i]] = s[i];
			}
			else if (t2[t[i]] != s[i]) return false;
		}

		return true;
	}
};

int main()
{
	Solution s;
	string s1[] = {"ab", "egg", "foo", "paper" };
	string t1[] = {"aa", "add", "bar", "title"};

	cout << "Isomorphic Strings:" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << s1[i].c_str() << ", " << t1[i].c_str() << " -> " << s.isIsomorphic(s1[i], t1[i]) << endl;
	}

	system("pause");
}
