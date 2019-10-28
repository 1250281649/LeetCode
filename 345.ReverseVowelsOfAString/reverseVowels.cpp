#include <iostream>

using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		int p = 0, q = s.length()-1;
		char t;
		while (q > p)
		{
			while (!isVowels(s[p]))
				p++;
			while (!isVowels(s[q]))
				q--;
			if (q > p){
				t = s[q];
				s[q] = s[p];
				s[p] = t;
				p++;
				q--;
			}
		}
		return s;
	}

	bool isVowels(char c)
	{
		if (c == 'a' || c == 'A' ||
			c == 'e' || c == 'E' || 
			c == 'i' || c == 'I' ||
			c == 'o' || c == 'O' ||
			c == 'u' || c == 'U')
			return true;
		else return false;
	}
};

int main()
{
	Solution s;
	string s1[] = { "hello", "", "leetcode", "aA" };

	//cout << s.isVowels('a') << "  ";
	//cout << s.isVowels('k') << "  ";

	for (int i = 0; i < 4; i++)
	{
		cout << s1[i].c_str() << " -> " << s.reverseVowels(s1[i]).c_str() << endl;
	}

	system("pause");
	return 0;
}