#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int p=0, i=0, l=0, t = 0;
		if (needle.size() == 0) return 0;
		l = haystack.size() - needle.size();
		while (p <= l)
		{
			if (haystack[p + i] == needle[0])
			{
				for (i = 0; i < needle.size(); i++)
				{
					if ((haystack[p + i] == needle[0]) && (t==0))
					{
						t = i;
					}
					if (haystack[p + i] != needle[i])
						break;
				}
				if (i >= needle.size())
					return p;
				if (t>0) p = p + t;
				else p++;
			}
			else p++;
			i = 0;
			t = 0;
		}
		return -1;
	}
};

int main()
{
	Solution s;
	string s1 = "mississippi";
	string needle = "issip";

	cout << "input:" << s1.c_str() << "    needle:"<<needle.c_str() << endl;
	cout << s.strStr(s1, needle) << endl;

	system("pause");
}
