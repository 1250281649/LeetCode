#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int i = 0;
	int a = 0, b = 0;
	string inputline;
	string numstr[2];
	std::vector<int> sumprint;

	printf("A+BÎÊÌâ\n");

	while (true)
	{
		getline(cin, inputline);
		
		sumprint.push_back(a+b);
	}
	for (i = 0; i < sumprint.size(); i++)
	{
		printf("%d\n", sumprint[i]);
	}

	return 0;
}