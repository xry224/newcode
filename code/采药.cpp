#include <iostream>
using namespace std;
class Node
{
public:
	int value;
	int weight;
	Node()
	{

	}
};
Node drug[101];
int dp[101][1001];
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int t, m;
	while (cin >> t >> m)
	{
		for (int i = 1; i <= m; i++)
		{
			cin >> drug[i].weight >> drug[i].value;
		}
		for (int i = 0; i <= t; i++)
		{
			dp[0][i] = 0;
		}
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= t; j++)
			{
				if (j >= drug[i].weight)   //в╟╣цоб
				{
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - drug[i].weight] + drug[i].value);
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		cout << dp[m][t] << endl;
	}
	return 0;
}