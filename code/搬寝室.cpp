#include <iostream>
#include <math.h>
#include <algorithm>
#include <limits.h>
using namespace std;
int tired(int a, int b)
{
	return (a - b)*(a - b);
}
int min(int a, int b)
{
	return a < b ? a : b;
}
int dp[1005][2005];
int main()

{
	int n, k;
	int weight[2005];
	while (cin >> n >> k)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> weight[i];
		}
		for (int i = 1; i <= n; i++)
		{
			dp[0][i] = 0;
		}
		sort(weight + 1, weight + n + 1);
		for (int i = 1; i <= k; i++)
		{
			dp[i][2 * i] = dp[i - 1][2 * i - 2] + tired(weight[2 * i - 1], weight[2 * i]);
			for (int j = 2 * i + 1; j <= n; j++)
			{
				dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 2] + tired(weight[j - 1], weight[j]));
			}
		}
		cout << dp[k][n] << endl;
	}
	return 0;
}