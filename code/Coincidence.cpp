#include <iostream>
#include <string>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{

	string a, b;
	while (cin >> a >> b)
	{
		int dp[101][101] = { 0 };
		for (int i = 1; i <= a.length(); i++)
		{
			for (int j = 1; j <= b.length(); j++)
			{
				if (a[i - 1] == b[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[a.length()][b.length()] << endl;
	}
	return 0;
}