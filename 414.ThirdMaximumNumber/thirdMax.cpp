#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
	struct node
	{
		int num;
		int count;
	};

	int thirdMax(vector<int>& nums) {
		node n[3] = { INT_MIN,0, INT_MIN,0, INT_MIN,0};
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > n[0].num)
			{
				n[2] = n[1];
				n[1] = n[0];
				n[0].num = nums[i];
				n[0].count = 1;
			}
			else if (nums[i] == n[0].num)
			{
				n[0].count++;
			}
			else if (nums[i] > n[1].num)
			{
				n[2] = n[1];
				n[1].num = nums[i];
				n[1].count = 1;
			}
			else if (nums[i] == n[1].num)
			{
				n[1].count++;
			}
			else if (nums[i] > n[2].num)
			{
				n[2].num = nums[i];
				n[2].count = 1;
			}
			else if (nums[i] == n[2].num)
			{
				n[2].count++;
			}
		}
		if (n[2].count)
			return n[2].num;
		else return n[0].num;
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

	cout << "Third Maximum Number:" << endl;

	int a1[] = { INT_MIN, 1, 1 };
	int a2[] = { 1, 2 };
	int a3[] = { 2, 2, 3, 1 };
	int a4[] = { 1, 2, INT_MIN };
	int a5[] = { 1, INT_MIN, INT_MIN };
	int a6[] = { INT_MIN,INT_MIN,INT_MIN,INT_MIN,1,1,1 };
	vector<int> v1(begin(a1), end(a1));
	vector<int> v2(begin(a2), end(a2));
	vector<int> v3(begin(a3), end(a3));
	vector<int> v4(begin(a4), end(a4));
	vector<int> v5(begin(a5), end(a5));
	vector<int> v6(begin(a6), end(a6));
	s.printVector(v1);
	cout << s.thirdMax(v1) << "  excepted:1" << endl;

	s.printVector(v2);
	cout << s.thirdMax(v2) << "  excepted:2" << endl;

	s.printVector(v3);
	cout << s.thirdMax(v3) << "  excepted:1" << endl;

	s.printVector(v4);
	cout << s.thirdMax(v4) << "  excepted:INT_MIN" << endl;

	s.printVector(v5);
	cout << s.thirdMax(v5) << "  excepted:1" << endl;

	s.printVector(v6);
	cout << s.thirdMax(v6) << "  excepted:1"<< endl;

	system("pause");
}
