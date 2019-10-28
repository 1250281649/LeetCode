#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>
#include <ctime>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<string, char> t1;
		unordered_map<char, string> t2;
		vector<string> splitStr;

		splitStr = split(str);
		if (pattern.length() != splitStr.size())
			return false;
		for (int i = 0; i < splitStr.size(); i++)
		{
			if (t1.count(splitStr[i]) <= 0)
			{
				t1[splitStr[i]] = pattern[i];
			}
			else
			{
				if (t1[splitStr[i]] != pattern[i])
					return false;
			}

			if (t2.count(pattern[i]) <= 0)
			{
				t2[pattern[i]] = splitStr[i];
			}
			else if (t2[pattern[i]] != splitStr[i])
				return false;
		}

		return true;
	}

	vector<string>split(string str)
	{
		vector<string> result;
		string temp;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				result.push_back(temp);
				temp.clear();

			}
			else temp.push_back(str[i]);
		}
		if (temp.length()>0)
		{
			result.push_back(temp);
		}
		return result;
	}
};

int main()
{
	Solution s;

	cout << "Word Pattern:" << endl;

	string testStr[] = { 
		"dog cat cat dog" ,
		"dog cat cat fish", 
		"dog cat cat dog",
		"dog dog dog dog"
	};

	string testPat[] = {
		"abba",
		"abba",
		"aaaa",
		"abba"
	};

	DWORD start = GetTickCount();
	
	cout << "pattern" << "  str" << endl;
	//s.wordPattern(testPat[0], testStr[0]);
	
	for (int i = 0; i < 4; i++)
	{
		cout << testPat[i].c_str() << ", " << testStr[i].c_str() << " -> " 
			<< s.wordPattern(testPat[i], testStr[i]) << endl;
	}
	
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;
	system("pause");
	return 0;
}