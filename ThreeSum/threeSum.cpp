#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int>a;
		int i = 0, j = 0, k = 0;
		map<int,int> ma, mb, mc;
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
				mb[nums[i]] = nums[i];
			else if (nums[i] > 0)
				ma[nums[i]] = nums[i];
			else mc[nums[i]] = nums[i];
		}
		cout << "ma size:" << ma.size() << endl;
		printMap(ma);
		cout << "mb size:" << mb.size() << endl;
		printMap(mb);
		cout << "mc size:" << mc.size() << endl;
		printMap(mc);
		//正，0，负
		map<int, int>::iterator ia, ic;
		if (mb.size() > 0)
		{
			for (ia = ma.begin(); ia != ma.end(); ia++)
			{
				for (ic = mc.begin(); ic != mc.end(); ic++)
				{
					if (ia->second + ic->second == 0)
					{
						a.push_back(ic->second);
						a.push_back(0);
						a.push_back(ia->second);
						result.push_back(a);
						a.clear();
					}
				}
			}
		}
		//正，负, *
		map<int, int>::iterator it;
		for (ia = ma.begin(); ia != ma.end(); ia++)
		{
			for (ic = mc.begin(); ic != mc.end(); ic++)
			{
				it = ia;
				for (it; it != ma.end(); it++)
				{
					if (it == ia) break;
					if (ia->second + ic->second + it->second == 0)
					{
						a.push_back(ic->second);
						a.push_back(it->second);
						a.push_back(ia->second);
						result.push_back(a);
						a.clear();
					}
					if (it == ma.end())
						break;
				}
				it = ic;
				for (it; it != mc.end(); it++)
				{
					if (it == ic) break;
					if (ia->second + ic->second + it->second == 0)
					{
						a.push_back(ic->second);
						a.push_back(it->second);
						a.push_back(ia->second);
						result.push_back(a);
						a.clear();
					}
					it++;
				}
			}
		}


		return result;
	}
	//vector<vector<int>> threeSum(vector<int>& nums) {
	//	vector<vector<int>> result;
	//	vector<int>a;
	//	int i = 0, j = 0, k = 0, t = 0;
	//	for (i = 0; i < nums.size() - 2; i++)
	//	{
	//		for (j = i + 1; j < nums.size() - 1; j++)
	//		{
	//			t = nums[j] + nums[i];
	//			for (k = j + 1; k < nums.size(); k++)
	//			{
	//				if (nums[k] + t == 0)
	//				{
	//					a.push_back(nums[i]);
	//					a.push_back(nums[j]);
	//					a.push_back(nums[k]);
	//					result.push_back(a);
	//					a.clear();
	//				}
	//			}
	//		}
	//	}
	//	return result;
	//}

	void printVector(vector<int>& nums)
	{
		int i = 0;
		for (i = 0; i < nums.size(); i++)
			cout << nums[i] << "  ";
		cout << endl;
	}
	void printMap(map<int, int>&m)
	{
		map<int, int>::iterator it;
		it = m.begin();
		while (it != m.end())
		{
			cout << it->second << "  ";
			it++;
		}
		cout << endl;
	}
};

int main()
{
	Solution s;
	vector<int>a;
	vector<vector<int>> result;
	a.push_back(-1); a.push_back(0); a.push_back(1);
	a.push_back(2); a.push_back(-1); a.push_back(4); a.push_back(-2);

	cout << "Input array:";
	s.printVector(a);
	result = s.threeSum(a);
	cout << "A solution set is:" << endl;
	for (int i = 0; i < result.size(); i++)
	{
		s.printVector(result[i]);
	}

	system("pause");
}
