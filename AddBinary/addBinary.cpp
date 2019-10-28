#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string result;
		string x1, x2;
		string r;

		int i = 0;
		int over = 0, temp = 0;


		if (a.length() > b.length())
		{
			x1 = a;
			x2 = b;
		}
		else
		{
			x1 = b;
			x2 = a;
		}

		for (i = 0; i < x2.length(); i++)
		{
			temp = (x2[x2.length() - 1 - i] - '0') + (x1[x1.length() - 1 - i] - '0') + over;
			if (temp == 3)
			{
				over = 1;
				result.push_back('1');
			}
			else if (temp == 2)
			{
				over = 1;
				result.push_back('0');
			}
			else
			{
				result.push_back('0' + temp);
				over = 0;
			}
		}
		for (i = x2.length(); i < x1.length(); i++)
		{
			temp = (x1[x1.length() - 1 - i] - '0') + over;
			if (temp == 3)
			{
				over = 1;
				result.push_back('1');
			}
			else if (temp == 2)
			{
				over = 1;
				result.push_back('0');
			}
			else
			{
				result.push_back('0' + temp);
				over = 0;
			}
		}
		if (over != 0)
			result.push_back('1');

		for (i = 0; i < result.length(); i++)
			r.push_back(result[result.length() - 1 - i]);

		return r;
	}
};

int main()
{
	Solution s;
	string a1 = "11001";
	string b1 = "1111";
	cout << "add binary" << endl;
	cout << a1.c_str() << " + " << b1.c_str() << " = " << s.addBinary(a1, b1).c_str() << endl;

	string a2 = "0";
	string b2 = "0";
	cout << a2.c_str() << " + " << b2.c_str() << " = " << s.addBinary(a2, b2).c_str() << endl;
	string a3 = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
	string b3 = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
	cout << a3.c_str() << " + " << b3.c_str() << " = " << s.addBinary(a3, b3).c_str() << endl;

	system("pause");
}
