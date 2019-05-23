#include <iostream>
#include <limits.h>
using namespace std;
class Coin
{
public:
	int value;
	int weight;
	Coin()
	{

	}
};
int min(int a, int b)
{
	return a < b ? a : b;
}
Coin coins[501];
int dp[10001]; //重量恰好为j时硬币的最小价值
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int w, w2;
		cin >> w >> w2;
		int coinw = w2 - w;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> coins[i].value >> coins[i].weight;
		}
		for (int i = 0; i <= coinw; i++)
		{
			dp[i] = INT_MAX;
		}
		dp[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = coins[i].weight; j <= coinw; j++)
			{
				if (dp[j - coins[i].weight] != INT_MAX)
				{
					dp[j] = min(dp[j], dp[j - coins[i].weight] + coins[i].value);
				}
			}
		}
		if (dp[coinw] == INT_MAX)
		{
			cout << "This is impossible." << endl;
		}
		else
		{
			cout << "The minimum amount of money in the piggy-bank is " << dp[coinw] << "." << endl;
		}
	}
	return 0;
}