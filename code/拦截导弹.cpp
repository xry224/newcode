#include <iostream>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int n;
	int missile[26];
	
	while (cin >> n)
	{
		int dp[26];
		int res[26];
		for (int i = 1; i < 26; i++)
		{
			res[i] = i;
			dp[i] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> missile[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < i; j++)
			{
				if (missile[i] <= missile[j])
				{
					dp[i] = max(dp[i], dp[j] + 1);
					if (dp[i] == dp[j] + 1)
					{
						res[i] = j;
					}
				}

			}
		}
		int ans = 0;
		int pos;
		for (int i = 1; i <= n; i++)
		{
			ans = max(ans, dp[i]);
			if (ans = dp[i])
			{
				pos = i;
			}
		}
		cout << ans << endl;
		/*while (res[pos] != pos)
		{
			cout << missile[res[pos]] << " ";
			pos = res[pos];
		}
		cout << missile[res[pos]]<< endl;*/
	}
	return 0;
}