#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i <= 100; i++)
		{
			for (int j = 0; j <= 100 - i; j++)
			{
				int z = 100 - i - j;
				double num = 5 * i + 3 * j + (double)z * (1.0 / 3.0);
				if (num <= n)
				{
					cout << "x=" << i << ",y=" << j << ",z=" << z << endl;
				}
			}
		}
	}
	return 0;
}