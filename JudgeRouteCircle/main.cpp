#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	bool judgeCircle(string moves) {
		int x = 0, y = 0;
		for (int i = 0; i < moves.length(); i++)
		{
			switch (moves[i])
			{
			case 'U':
				y++;
				break;
			case 'D':
				y--;
				break;
			case 'R':
				x++;
				break;
			case 'L':
				x--;
				break;
			default:
				break;
			}
		}
		if (x || y)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

void main()
{
	string input = "UDRLLRUUDRDD";
	bool result;

	cout << "input: " << input << endl;
	Solution leetcode;
	result = leetcode.judgeCircle(input);
	cout << "result: " << result << endl;

	getchar();
}