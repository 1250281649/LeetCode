#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int index = 0, begin = 0, end = nums.size();
		index = (begin + end) / 2;
		while (end > begin+1)
		{
			if (target > nums[end-1])
			{
				return end;
			}
			else if (target < nums[begin])
			{
				return begin;
			}
			else
			{
				if (target < nums[index])
				{
					end = index;
				}
				else if (target == nums[index])
				{
					return index;
				}
				else
				{
					begin = index;
				}
				index = (begin + end) / 2;
			}
		}
		if (begin != end)
		{
			if (target > nums[begin])
				index = begin+1;
			else if (target == nums[begin])
				index = begin;
			else index = begin;
		}
		return index;
	}
};

int main()
{
	Solution s;
	vector<int> v1;
	int i = 0;
	int t1 = 5, t2 = 2, t3 = 7,t4 = 0;
	v1.push_back(1); v1.push_back(3); v1.push_back(5); v1.push_back(6);

	cout << "Input:[";
	for (i = 0; i < v1.size() - 1; i++)
	{
		cout << v1[i] << ",";
	}
	cout << v1[v1.size() - 1] << "]," << endl;

	cout << "Output:" << t1<<"->"<< s.searchInsert (v1, t1)<< endl;
	cout << "Output:" << t2 << "->" << s.searchInsert(v1, t2) << endl;
	cout << "Output:" << t3 << "->" << s.searchInsert(v1, t3) << endl;
	cout << "Output:" << t4 << "->" << s.searchInsert(v1, t4) << endl;
	
	system("pause");
}
