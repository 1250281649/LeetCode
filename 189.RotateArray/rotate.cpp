#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int temp = 0;
		int length = nums.size();
		k = k % length;
		for (int i = 0; i < length-k; i++)
		{
			temp = nums[0];
			nums.push_back(temp);
			nums.erase(nums.begin());
		}
	}

	void printVector(vector<int>& numbers)
	{
		cout << "[";
		for (int i = 0; i < numbers.size(); i++)
		{
			cout << numbers[i] << ", ";
		}
		cout << "]" << endl;
	}
};

int main()
{
	Solution s;

	cout << "Rotate Array:" << endl;

	int a[] = { 1,2};
	vector<int> v(begin(a), end(a));
	s.printVector(v);
	s.rotate(v, 3);
	s.printVector(v);


	system("pause");
}
