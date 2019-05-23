#include <iostream>
#include <math.h>
using namespace std;
bool Judge(int n)
{
	if (n == 1)
	{
		return false;
	}
	int bound = sqrt(n);
	for (int i = 2; i < bound + 1; i++)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	while (cin >> n)
	{
		bool res = Judge(n);
		if (res)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
	return 0;
}