#include <iostream>
#include <list>
#include <map>
#include <hash_map>
using namespace std;

//I-1
//X-10
//C-100
//M-1000
//V-5
//L-50
//D-500
class Solution {
public:
	int romanToInt(string s) {
		char i;
		int result = 0;
		int temp = 0;

		std::map<char, int> romanNumber;
		romanNumber['I'] = 1;
		romanNumber['V'] = 5;
		romanNumber['X'] = 10;
		romanNumber['L'] = 50;
		romanNumber['C'] = 100;
		romanNumber['D'] = 500;
		romanNumber['M'] = 1000;

		for (i = s.length()-1; i >=0; i--)
		{
			if (i < s.length()-1)
			{
				if (romanNumber[s[i]] < temp)
				{
					result = result - romanNumber[s[i]];
				}
				else result = result + romanNumber[s[i]];
			}
			else
			{
				result = result + romanNumber[s[i]];
			}
			temp = romanNumber[s[i]];
		}
		return result;
	}
};

int main()
{
	string a[] = { "III", "IV", "VI", "XIX", "XX", "XLV", "MCMLXXX", "MCX", "MCC", "CXI" };
	Solution s;

	for (int i = 0; i < 10; i++)
	{
		cout<< ":  " << s.romanToInt(a[i]) << endl;
	}
	cout << endl;
	system("pause");
}
