#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
	
	int findNthDigit(int n) {
		if (n <= 9)
			return n;
		long long nums[10] = { 9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000, 9000000000 };
		long long count[10] = { 0 };
		int length = 0;
		count[0] = 9;
		for (int i = 1; i < sizeof(count) / 8; i++)
		{
			count[i] = count[i - 1] + (i + 1)*nums[i];
			if (count[i] >= n)
			{
				length = i+1;
				break;
			}
		}
		int a = n - count[length - 2];
		int d = (a-1) / length;
		int m = (a-1) % length;

		a = pow(10, length-1) + d ;
		a = a / pow(10,(length - m - 1));
		a = a % 10;
		return a;
	}
};

int main()
{
	Solution s;
	int a[] = { 3, 11, 12, 194, 195, 196, 197, 198, 199, 200, 10000, 1000000000 };

	//cout << a[4] << " -> " << s.findNthDigit(a[4]) << endl;
	for (int i = 0; i < sizeof(a)/4; i++)
	{
		cout << a[i] << " -> " << s.findNthDigit(a[i]) << endl;
	}

	system("pause");
	return 0;
}