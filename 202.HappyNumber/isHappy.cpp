#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		set<int> temp;
		int a = n;
		while (a != 1)
		{
			if (temp.find(a) == temp.end())
				temp.insert(a);
			else return false;
			a = change(a);
		}

		return true;
	}

	int change(int n)
	{
		vector<int>result;
		while (n > 0)
		{
			result.push_back(n%10);
			n = n / 10;
		}
		int sum = 0;
		for (int i = 0; i < result.size(); i++)
		{
			sum += result[i]*result[i];
		}
		return sum;
	}

	void printVector(vector<int> nums)
	{
		cout << "[";
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << "  ";
		}
		cout << "]" << endl;
	}
};

int main()
{
	Solution s;

	cout << "Happy Number:" << endl;

	unsigned int a1[] = { 19, 0, 1, 118, 8987 };
	
	for (int i = 0; i < sizeof(a1) / 4; i++)
	{
		cout << a1[i] << "->";
		cout << "is Happy number:" << s.isHappy(a1[i]) << endl;
	}

	system("pause");
}
