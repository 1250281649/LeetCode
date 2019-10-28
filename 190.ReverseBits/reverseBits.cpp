#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
	unsigned int reverseBits(unsigned int n) {
		unsigned int a; 
		unsigned int b;
		for (int i = 0; i < 16; i++)
		{
			a = n>>i & 1;
			b = n >> (31 - i) & 1;
			if (a^b)
			{
				if (a)
				{
					n = n & (~(1 << i));
					n = n | (1 << (31 - i));
				}
				else
				{
					n = n & (~(1 << (31 - i)));
					n = n | (1 << i);
				}
			}
		}

		return n;
	}
};

int main()
{
	Solution s;

	cout << "Reverse Bits:" << endl;

	int a[] = { 43261596, 11 };
	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		cout << a[i] << " -> " << s.reverseBits(a[i]) << endl;
	}


	system("pause");
}
