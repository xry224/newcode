#include <iostream>
using namespace std;
int Edge[105][105];
void Initialize()
{
	for (int i = 0; i < 105; i++)
	{
		for (int j = 0; j < 105; j++)
		{
			Edge[i][j] = 1005;
		}
	}
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		Initialize();
		if (n == m && n == 0)
		{
			break;
		}
		for (int i = 0; i < m; i++)
		{
			int a, b, cost;
			cin >> a >> b >> cost;
			if (cost < Edge[a][b])
			{
				Edge[a][b] = Edge[b][a] = cost;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int k = 1; k <= n; k++)
				{
					if (Edge[j][i] == 1005 || Edge[i][k] == 1005)
					{
						continue;
					}
					else
					{
						if (Edge[j][k] == 1005 || (Edge[j][k] > Edge[j][i] + Edge[i][k]))
						{
							Edge[j][k] = Edge[j][i] + Edge[i][k];
						}
					}
				}
			}
		}
		cout << Edge[1][n] << endl;
	}
	return 0;
}