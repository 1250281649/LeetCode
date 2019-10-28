#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word) {
		if (word[0] >= 'a')
		{
			for (int i = 1; i < word.size(); i++)
			{
				if (word[i] < 'a')
				{
					return false;
				}
			}
		}
		else if (word.size() <= 2)
		{
			return true;
		}
		else
		{
			if (word[1] < 'a')
			{
				for (int i = 2; i < word.size(); i++)
				{
					if (word[i] >= 'a')
					{
						return false;
					}
				}
			}
			else
			{
				for (int i = 2; i < word.size(); i++)
				{
					if (word[i] < 'a')
					{
						return false;
					}
				}
			}
		}
		return true;
	}
};

void main()
{
	string word = "J";
	bool result;

	cout << word << endl;
	Solution leetcode;
	result = leetcode.detectCapitalUse(word);

	cout << "result: " << result << endl;

	getchar();
}