#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include <ctime>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <hash_map>
#include <stack>

using namespace std;



class MinStack {
public:
	vector<int>org;
	vector<int>m;
	
	MinStack() {
		org.clear();
		m.clear();
		m.push_back(INT_MAX);
	}

	void push(int x) {
		org.push_back(x);
		m.push_back(min(x, m.back()));
	}

	void pop() {
		org.pop_back();
		m.pop_back();
	}

	int top() {
		return org.back();
	}

	int getMin() {
		return m.back();
	}
};

int main()
{
	//clock_t start, stop;
	DWORD start = GetTickCount();
	cout << "Min statck:" << endl;

	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);

	cout << "get min:" << minStack.getMin() << endl;
	minStack.pop();
	cout << "top:" << minStack.top() << endl;
	cout << "get min:" << minStack.getMin() << endl;

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
