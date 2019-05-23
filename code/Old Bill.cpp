#include <iostream>
using namespace std;
int main()
{
	int ans, a, b;
	int n, x, y, z;
	while (cin >> n)
	{
		ans = 0;
		cin >> x >> y >> z;
		bool flag = false;
		for (int i = 9; i >= 1 && !flag; i--)
		{
			for (int j = 9; j >= 0; j--)
			{
				int total = i * 10000 + x * 1000 + y * 100 + z * 10 + j;
				if (total % n == 0)
				{
					a = i;
					b = j;
					ans = total / n;
					flag = true;
					break;
				}
			}
		}
		if (!ans)
		{
			cout << ans << endl;
			continue;
		}
		else
		{
			cout << a << " " << b << " " << ans << endl;
		}
	}

	return 0;
}