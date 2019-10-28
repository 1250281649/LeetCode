#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int result = 0, temp;
		int i = 0, j = height.size() - 1;

		while (i <= j - 1)
		{
			if (height[i] < height[j])
			{
				temp = (j - i)*height[i];
				i++;
			}
			else
			{
				temp = (j - i)*height[j];
				j--;
			}
			result = max(result, temp);
		} 
		return result;
	}

	void printVector(vector<int>& height)
	{
		int i = 0;
		cout << "Input array:";
		for (i = 0; i < height.size(); i++)
			cout << height[i] << "  ";
		cout << endl;
	}
};

int main()
{
	Solution s;
	vector<int>a, b, c;
	a.push_back(1); a.push_back(2);
	b.push_back(2); b.push_back(1); b.push_back(3);
	c.push_back(2); c.push_back(3); c.push_back(4); c.push_back(5);
	c.push_back(18); c.push_back(17); c.push_back(6);

	s.printVector(a);
	cout << "result:" << s.maxArea(a) << endl;
	s.printVector(b);
	cout << "result:" << s.maxArea(b) << endl;
	s.printVector(c);
	cout << "result:" << s.maxArea(c) << endl;

	system("pause");
}
