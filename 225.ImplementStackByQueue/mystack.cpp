#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <ctime>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	queue<int> q;
	MyStack() {
		
	}

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {

	}

	/** Get the top element. */
	int top() {

	}

	/** Returns whether the stack is empty. */
	bool empty() {

	}
};

int main()
{
	DWORD start = GetTickCount();

	cout << "Implement Stack using Queues:" << endl;
	

	//Sleep(10);
	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;

	system("pause");
}
