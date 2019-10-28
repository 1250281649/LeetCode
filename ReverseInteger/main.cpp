#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		
	}
};

int main()
{
	Solution s;
	int x1 = 123;
	int x2 = -123;
	int x3 = -2147483647;//-2147483648
	int x4 = 1534236469;
	cout << x1 << ": " << s.reverse(x1) << endl;
	cout << x2 << ": " << s.reverse(x2) << endl;
	cout << x3 << ": " << s.reverse(x3) << endl;
	cout << x4 << ": " << s.reverse(x4) << endl;

	system("pause");
	return 0;
}