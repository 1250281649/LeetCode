#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:

	vector<int> findAnagrams(string s, string p) {
		vector<int> result;
		int j = 0,i=0;
		bool lastPattern = false;
		int table[26] = { 0 };
		int temp[26] = { 0 };
		if (p.length() > s.length())
			return result;

		for (int i = 0; i < p.length(); i++)
			table[p[i]-'a']++;
		for (i = 0; i <= s.length() - p.length(); i++)
		{
			
			if (lastPattern)
			{
				if (s[i - 1] == s[i + p.length()-1])
				{
					result.push_back(i);
					continue;
				}
				else lastPattern = false;
			}
			memcpy(temp, table, 26 * sizeof(int));
			for (j = 0; j < p.length(); j++)
			{
				temp[s[i+j]-'a']--;
				if (temp[s[i+j]-'a'] < 0)
					break;
			}
			if (j == p.length())
			{
				result.push_back(i);
				lastPattern = true;
			}
			else lastPattern = false;
		}
		return result;
	}
	
	void printVector(vector<int> v)
	{
		cout << "[" ;
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << "  ";
		}
		cout << "]" << endl;
	}
};

int main()
{
	Solution s;

	cout << "Find All Anagrams in a String:" << endl;

	string s1[] = { "cbaebabacd" ,"abab","abacbabc" };
	string s2[] = { "abc" ,"ab", "abc" };
	//s.printVector(s.findAnagrams(s1[2], s2[2]));
	for (int i = 0; i < 3; i++)
	{
		cout << s1[i].c_str() << "," << s2[i].c_str() << ":" << endl;
		s.printVector(s.findAnagrams(s1[i], s2[i]));
	}

	system("pause");
}
