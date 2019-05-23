#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int squre = n * n;
		int num = 0;
		int t = n;
		while (t > 0)
		{
			num++;
			t = t / 10;
		}
		int res = (int)(pow(10, num));
		if ((squre - n) % res == 0)
		{
			cout << "Yes!" << endl;
		}
		else
		{
			cout << "No!" << endl;
		}
	}
	return 0;
}