#include <iostream>
#include <algorithm>
using namespace std;
int river[1000];
int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> river[i];
		}
		int ans = 0;
		sort(river, river + n);
		int num = n;
		while (num > 3)
		{
			ans += min(river[1] + river[0] + river[num - 1] + river[1], river[num - 1] + river[0] + river[num - 2] + river[0]);

			num -= 2;
		}
		if (num == 1)
		{
			ans += river[0];
		}
		else if (num == 2)
		{
			ans += river[1];
		}
		else
		{
			ans += river[2] + river[0] + river[1];
		}
		cout << ans << endl;
	}

}