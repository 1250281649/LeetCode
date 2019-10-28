#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int i = 0, j = 0, length;
		if (strs.size() == 0)
			return "";
		else if (strs.size() == 1)
			return strs[0];

		length = strs[0].length();
		for (i = 1; i < strs.size(); i++)
		{
			if (length > strs[i].length())
				length = strs[i].length();
		}

		for (i = 0; i < length; i++)
		{
			for (j = 0; j < strs.size(); j++)
			{
				if (strs[j][i] != strs[0][i])
					break;
			}
			if (j <= strs.size() - 1)
				break;
		}
		return strs[0].substr(0,i);
	}
};

int main()
{
	vector<string> testStr;
	Solution s;

//	testStr.push_back("");
	testStr.push_back("abcfg");
	testStr.push_back("abcfg");
	testStr.push_back("ab");
	testStr.push_back("abc");

	for (int i = 0; i < testStr.size(); i++)
	{
		cout << testStr[i].c_str() << endl;
	}
	cout << "max common str prefix:" << s.longestCommonPrefix(testStr).c_str() << endl;
	system("pause");
}
