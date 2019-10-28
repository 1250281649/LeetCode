#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string s;
		int a = 0, b = 0;
		b = (n - 1) % 26;
		a = (n - 1) / 26;
		s = char(('A' + b)) + s;
		while (a > 0)
		{
			b = a % 26;
			a = a / 26;
			if (b == 0)
			{
				s = 'Z' + s;
				a--;
			}
			else
				s = char(('A' + b - 1)) +s;
		}

		return s;
	}
};

int main()
{
	Solution s;

	cout << "Excel Sheet Column Title:" << endl;
	
	cout << 26 << " -> " << s.convertToTitle(26).c_str() << endl;
	cout << 27 << " -> " << s.convertToTitle(27).c_str() << endl;
	cout << 53 << " -> " << s.convertToTitle(53).c_str() << endl;
	cout << 701 << " -> " << s.convertToTitle(701).c_str() << endl;

	system("pause");
}
