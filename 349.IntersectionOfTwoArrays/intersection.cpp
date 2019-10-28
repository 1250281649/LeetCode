#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		unordered_map<int, int>table;

		for (int i = 0; i < nums1.size(); i++)
			table[nums1[i]]++;

		for (int i = 0; i < nums2.size(); i++)
		{
			if (table[nums2[i]] > 0)
			{
				result.push_back(nums2[i]);
				table[nums2[i]]=-1;
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

	cout << "Intersection of Two Arrays:" << endl;

	int a[] = { 1, 2 , 2, 1};
	int b[] = {2, 2};
	vector<int> v1(begin(a), end(a));
	vector<int> v2(begin(b), end(b));
	s.printVector(v1);
	s.printVector(v2);
	cout << "Intersection:" << endl;
	s.printVector(s.intersection(v1, v2));

	system("pause");
}
