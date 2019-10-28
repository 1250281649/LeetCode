#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> result;
		if (n <= 0)
			return result;
		for (int i = 1; i <= n; i++)
		{
			if (i % 15 == 0)
				result.push_back("FizzBuzz");
			else if (i % 3 == 0)
				result.push_back("Fizz");
			else if (i % 5 == 0)
				result.push_back("Buzz");
			else
			{
				
				string s;
				char c[12];
			
				_itoa_s(i, c, 10);
				s = c;
				result.push_back(s);
			}
		}

		return result;
	}

	void PrintVector(vector<string>s)
	{
		cout << "[" <<endl;
		for (int i = 0; i < s.size(); i++)
		{
			cout << "\"" << s[i].c_str() << "\"," << endl;
		}
		cout << "]" << endl;
	}
};

int main()
{
	Solution s;

	cout << "Fizz Buzz:" << endl;
	
	cout << "n=15" << endl;
	s.PrintVector(s.fizzBuzz(15));

	system("pause");
	return 0;
}