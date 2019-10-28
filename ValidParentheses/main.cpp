#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		vector<char> vec;
		int i = 0;
		//if (s.length() <= 1)
		//	return false;

		vec.push_back(s[0]);
		for (i = 1; i < s.length(); i++)
		{
			if (vec.size())
			{
				if (vec[vec.size()-1] == '(')
				{
					if (s[i] == ')')
						vec.pop_back();
					else vec.push_back(s[i]);
				}
				else if (vec[vec.size() - 1] == '[')
				{
					if (s[i] == ']')
						vec.pop_back();
					else vec.push_back(s[i]);
				}
				else if (vec[vec.size() - 1] == '{')
				{
					if (s[i] == '}')
						vec.pop_back();
					else vec.push_back(s[i]);
				}
			}
			else
				vec.push_back(s[i]);
		}

		return vec.empty();
	}
};

int main()
{
	vector<string> testStr;
	Solution s;

	testStr.push_back("()");
	testStr.push_back("[]");
	testStr.push_back("");
	testStr.push_back("([})");
	testStr.push_back("[(]");

	for (int i = 0; i < testStr.size(); i++)
	{
		cout << testStr[i].c_str() << ":" << s.isValid(testStr[i]) << endl;
	}
	
	system("pause");
}
