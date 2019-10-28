#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int>result;
		int i = 0;
		int j = numbers.size() - 1;
		int sum = 0;

		while (j > i)
		{
			sum = numbers[i] + numbers[j];
			if (target == sum)
			{
				result.push_back(i+1);
				result.push_back(j+1);
				return result;
			}
			else if (target < sum)
			{
				j--;
			}
			else
			{
				i++;
			}
		}

		return result;
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

	int a[] = { 2, 7, 11, 15 };
	int b[] = { 1, 2, 3 };

	vector<int>v1(begin(a), end(a));
	vector<int>v2(begin(b), end(b));
	vector<int>result;

	cout << "Two Sum II-Input array is sorted:" << endl;
	s.printVector(v1);
	cout << "Target:" << "9:" << endl;
	result = s.twoSum(v1,9);
	if (result.size() > 0)
		cout << "index1=" << result[0] << ",index2=" << result[1] << endl;
	else cout << "none" << endl;

	result.clear();
	s.printVector(v2);
	cout << "Target:" << "6:" << endl;
	result = s.twoSum(v2, 9);
	if (result.size() > 0)
		cout << "index1=" << result[0] << ",index2=" << result[1] << endl;
	else cout << "none" << endl;

	system("pause");
}
