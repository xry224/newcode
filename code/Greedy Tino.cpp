#include <iostream>
#include <limits.h>
#define off 2000
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}	
int dp[101][4001];
int main()
{
	int orange[101];
	int T;

	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int n;
		cin >> n;
		int cnt = 0;//统计重0的柑橘的数量
		for (int j = 1; j <= n; j++)
		{
			cin >> orange[j];
			if (orange[j] == 0)
			{
				cnt++;
			}
		}
		for (int i = -2000; i <= 2000; i++)
		{
			dp[0][i + off] = INT_MIN;
		}
		dp[0][0 + off] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = -2000; j <= 2000; j++)
			{
				if (j + orange[i] <= 2000 && j - orange[i] >= -2000)
				{
					dp[i][j + off] = max(dp[i - 1][j + off], max(dp[i - 1][j + off - orange[i]] + orange[i], dp[i - 1][j + off + orange[i]] + orange[i]));
				}

			}
		}
		cout << "Case " << i << ": ";
		if (dp[n][0 + off] == 0)
		{
			int ans = cnt == 0 ? -1 : 0;
			cout << ans << endl;
		}
		else
		{
			cout << dp[n][0 + off] / 2 << endl;
		}
	}
	return 0;
}