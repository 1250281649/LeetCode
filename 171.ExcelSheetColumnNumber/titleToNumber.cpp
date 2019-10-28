#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int sum = 0;
		for (int i = 0; i < s.length(); i++)
		{
			sum += pow(26,i)*(s[s.length() - 1 - i] - 'A' + 1);
		}
		return sum;
	}
};

int main()
{
	Solution s;

	cout << "Excel Sheet Column Number:" << endl;

	cout << "Z -> " << s.titleToNumber("Z") << endl;
	cout << "AA -> " << s.titleToNumber("AA") << endl;
	cout << "BA -> " << s.titleToNumber("BA") << endl;
	cout << "ZY -> " << s.titleToNumber("ZY") << endl;

	system("pause");
}
