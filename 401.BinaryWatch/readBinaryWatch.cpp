#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		string t;
		vector<string> result;
		int a = 0, b = 0;
		for (int i = 0; i <= 11; i++)
		{
			a = countBits(i);
			for (int j = 0; j < 60; j++)
			{
				b = countBits(j);
				if (a + b == num)
				{
					if (i == 0)
						t = t + "0:";
					else if (i<10)
						t = t + (char)(i + '0')+":";
					else
					{
						t = t + (char)(i / 10 + '0') ;
						t = t + (char)(i % 10 + '0') + ":";
					}

					t = t + (char)(j / 10 + '0');
					t = t + (char)(j % 10 + '0');

					result.push_back(t);
					t.clear();
				}
			}
		}

		return result;
	}

	int countBits(int n)
	{
		int sum = 0;
		for (int i = 0; i < 6; i++)
		{
			if (n >> i & 1)
				sum++;
		}
		return sum;
	}

	void PrintVector(vector<string> s)
	{
		cout << "[";
		for (int i = 0; i < s.size(); i++)
			cout << s[i].c_str() << ", ";
		cout << "]" << endl;
	}
};

int main()
{
	Solution s;

	//for (int i = 0; i <= 10; i++)
	//{
		cout << 2 << ":" << endl;
		s.PrintVector(s.readBinaryWatch(2));
	//}

	system("pause");
	return 0;
}