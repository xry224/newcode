#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int p, t, g1, g2, g3, gj;
	double ans;
	while (cin >> p >> t >> g1 >> g2 >> g3 >> gj)
	{
		if (abs(g1 - g2) <= t)
		{
			ans = (g1 + g2) * 1.0 / 2.0;
		}
		else if (abs(g3 - g1) <= t && abs(g3 - g2) <= t)
		{
			ans = max(g1, max(g1, g2));
		}
		else if (abs(g3 - g1) > t && abs(g3 - g2) > t)
		{
			ans = gj;
		}
		else
		{
			if (abs(g3 - g1) < abs(g3 - g2))
			{
				ans = (g3 + g1) * 1.0 / 2.0;
			}
			else
			{
				ans = (g3 + g2) * 1.0 / 2.0;
			}
		}
		cout << fixed << setprecision(1) << ans << endl;
	}
	return 0;
}