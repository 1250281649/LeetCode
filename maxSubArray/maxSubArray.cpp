#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() < 1)
			return 0;
		int maxS = 0, sum = 0;
		int i = 0;
		maxS = INT_MIN;
		for (i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			maxS = max(maxS, sum);
			sum = max(sum, 0);
		}
		return maxS;
	}

	void printVector(vector<int>& nums)
	{
		int i = 0;
		for (i = 0; i < nums.size(); i++)
			cout << nums[i] << "  ";
		cout << endl;
	}
};

int main()
{
	Solution s;
	int a1[] = { 3, -2, -3, -3, 1, 3, 0 };
	int a2[] = {-2};
	int a3[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	vector<int>a(a1, a1 + sizeof(a1) / sizeof(int));
	vector<int>b(a2, a2 + sizeof(a2)/sizeof(int));
	vector<int>c(a3, a3 + sizeof(a3) / sizeof(int));

	cout << "Max subArray:" << endl;

	s.printVector(a);
	cout << "result:" << s.maxSubArray(a) << endl;

	s.printVector(b);
	cout << "result:" << s.maxSubArray(b) << endl;

	s.printVector(c);
	cout << "result:" <<s.maxSubArray(c)<< endl; 

	system("pause");
}
