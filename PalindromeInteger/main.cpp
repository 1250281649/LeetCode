#include <iostream>
#include <list>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		int a = 0;
		if (x < 0 || ((x % 10 == 0) && (x!=0)))
			return false;

		while (x > a)
		{
			a = x % 10 + a * 10;
			x = x / 10;
		}
		return (a == x) || (a / 10 == x);
	}
};

int main()
{
	int a[] = {0, 10, 121,-3, 1, 22, 32, 414, 5445,6666};
	Solution s;

	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		cout << a[i] << "  " << s.isPalindrome(a[i]) <<endl;
	}
	cout << endl;
	system("pause");
}
