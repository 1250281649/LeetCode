#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>
#include <ctime>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		if (n < 3) return 0;
		int primecount = 1;
		bool *primeList = (bool*)malloc(n);
		memset(primeList, false, n);
		for (int i = 3; i < n; i+=2)
		{
			if (!primeList[i]) primecount++;
			for (long long j = (long long)i*i; j < n; j += 2*i)
				primeList[j] = true;
		}
		return primecount;
	}

	/*
	int countPrimes(int n) {
		int sum = 0;
		if (n < 2) return 0;
		for (int i = 2; i < n; i++)
		{
			sum += isPrime(i);
		}
		return sum;
	}

	bool isPrime(int n)
	{
		if (n == 2 || n == 3)
			return true;
		if (n % 6 != 1 && n % 6 != 5)
			return false;

		int a = sqrt(n);
		for (int i = 5; i <= a; i+=6)
		{
			if (n%i == 0 || n%(i+2)==0)
				return false;
		}
		return true;
	}
	*/
};

int main()
{
	Solution s;

	cout << "Count Primes:" << endl;

	unsigned int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 23, 53, 87 ,1500000};

	DWORD start = GetTickCount();
	cout << "  number " << "  prime?" << endl;

	for (int i = 0; i < sizeof(a) / 4; i++)
	{
		cout << a[i] << " -> " << s.countPrimes(a[i]) << endl;
	}

	DWORD stop = GetTickCount();
	cout << "total time:" << (stop - start) << endl;
	system("pause");
}
