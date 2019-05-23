#include <iostream>
using namespace std;
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		if (a == 0 && b == 0)
		{
			break;
		}
		int ans = 1;
		a = a % 1000;
		while (b > 0)
		{
			if (b % 2 == 0)
			{
				a = (a * a) % 1000;
				b /= 2;
			}
			else
			{
				ans = (ans * a) % 1000;
				b -- ;
			}
		}
		cout << ans % 1000 << endl;
	}
	return 0;
}