#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int sum = 0;
		int a = 0;
		a = n / 5;
		while (a > 0)
		{
			a = n / 5;
			sum += a;
			n = n / 5;
		}
		return sum;
	}
};

int main()
{
	Solution s;

	cout << "Factorial Trailing Zeroes:" << endl;

	int a[] = { 4, 6, 11, 26, 25*5, 255*25+1 };
	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		cout << a[i] << " : " << s.trailingZeroes(a[i]) << endl;
	}

	system("pause");
}
