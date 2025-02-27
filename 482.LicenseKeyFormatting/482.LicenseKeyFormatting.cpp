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
	string licenseKeyFormatting(string S, int K) {
		string result;
		int i = 0;
		for (i = S.length() - 1; i >= 0; i--)
		{
			if (S[i] != '-')
			{
				if ((result.length() > 0) && (result.length() % (K+1) == K))
					result.push_back('-');
				result.push_back(S[i]>='a' && S[i]<='z' ? S[i]-32:S[i]);
			}
		}
		reverse(result.begin(), result.end());
		return result;
	}
	/*
	string licenseKeyFormatting(string S, int K) {
		string result;
		int i = 0, t = 0, j = 0;
		for (i = 0; i < S.length(); i++)
		{
			if (S[i] != '-')
			{
				if (S[i] >= 'a' && S[i] <= 'z')
					S[j++] = (char)(S[i] - 32);
				else S[j++] = S[i];
			}
		}
		t = j % K;
		if (t != 0)
		{
			result = S.substr(0, t);
		}
		i = t;
		while (i < j)
		{
			if(result.length()>0)
				result.push_back('-');
			result = result + S.substr(i, K);
			i += K;
		}
		return result;
	}
	*/
};

int main()
{
	Solution s;

	cout << "482. License Key Formatting:" << endl;

	string a[] = { "5F3Z-2e-9-w" , "2-5g-3-J" ,"-"};
	int b[] = { 4, 2, 2 };
	//cout << s.licenseKeyFormatting(a[2], b[2]) << endl << endl;
	for (int i = 0; i < sizeof(b) / sizeof(int); i++)
	{
		cout << "S=" << a[i].c_str() << ", K=" << b[i] << endl;
		cout << s.licenseKeyFormatting(a[i], b[i]) << endl << endl;
	}

	system("pause");
}
