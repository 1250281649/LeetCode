#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
	
	string toHex(int num) {
		char table[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
			'9', 'a', 'b', 'c', 'd', 'e', 'f' };
		string str;
		if (num == 0)
			return "0";
		int a = 0;
		for (int i = 7; i >=0; i--)
		{
			a = (num >> (4 * i)) & 0x0F;
			if (a == 0)
			{
				if (str.length() > 0)
					str = str + table[a];
			}
			else str = str + table[a];
		}
		return str;
	}
};

int main()
{
	Solution s;
	int a[] = {0, 3, 11, 12, 26, -1,-100 };

	cout << "Convert a Number to Hexadecimal:" << endl;
	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		cout << a[i] << " -> " << s.toHex(a[i]).c_str() << endl;
	}

	system("pause");
	return 0;
}