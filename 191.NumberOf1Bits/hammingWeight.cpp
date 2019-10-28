#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
	int hammingWeight(unsigned int n) 
	{
		int result = 0;
		unsigned int a;
		for (int i = 0; i < 32; i++)
		{
			a = (n >> i);
			if (a & 1)
				result++;
		}
		return result;
	}
};

int main()
{
	Solution s;

	cout << "Reverse Bits:" << endl;

	unsigned int a[] = { 10, 11, 2147483648 };
	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		cout << a[i] << " -> " << s.hammingWeight(a[i]) << endl;
	}


	system("pause");
}
