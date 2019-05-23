#include <iostream>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int n;
	int height1[101];
	int height2[101];
	while (cin >> n)
	{
		int dp1[101];
		int dp2[101];
		for (int i = 0; i <= 100; i++)
		{
			dp1[i] = dp2[i] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> height1[i];
			height2[n - i + 1] = height1[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < i; j++)
			{
				//正序最长递增子序列
				if (height1[i] > height1[j])
				{
					dp1[i] = max(dp1[i], dp1[j] + 1);
				}
				//逆序最长递增子序列
				if (height2[i] > height2[j])
				{
					dp2[i] = max(dp2[i], dp2[j] + 1);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans = max(ans, dp1[i] + dp2[n - i + 1] - 1);
		}
		cout << n - ans << endl;
	}
	return 0;
}