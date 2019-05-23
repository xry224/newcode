#include <iostream>
#include <limits.h>
using namespace std;
#define N 605
int cnt1, cnt2;  //两个阵营的城市的数量
int Edge[N][N];
int side[N];   //阵营
bool mark[N];
int dis1[N], dis2[N];
void Ini()
{
	cnt1 = cnt2 = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Edge[i][j] = INT_MAX;
		}
	}
	for (int i = 0; i < N; i++)
	{
		dis1[i] = dis2[i] = -1;
		mark[i] = false;
	}
}
void Dijkstra(int dis[N], int leader)
{
	for (int i = 0; i <= cnt1 + cnt2; i++)
	{
		if (side[i] == leader)
		{
			mark[i] = false;
		}
		else
		{
			mark[i] = true;
		}
	}
	int num = leader == 1 ? cnt1 : cnt2;
	dis[leader] = 0;
	mark[leader] = true;
	int newPoint = leader;	
	for (int i = 0; i < num - 1; i++)
	{
		//更新节点值
		for (int j = 1; j <= cnt1 + cnt2; j++)
		{
			if (!mark[j] && Edge[j][newPoint]!= INT_MAX)
			{
				if (dis[j] == -1 || dis[j] > dis[newPoint] + Edge[j][newPoint])
				{
					dis[j] = dis[newPoint] + Edge[j][newPoint];

				}
			}
		}
		int min = INT_MAX;
		for (int j = 1; j <= cnt1 + cnt2; j++)
		{
			if (mark[j] || dis[j] == -1)
			{
				continue;
			}

			if (dis[j] < min)
			{
				min = dis[j];
				newPoint = j;
			}
		}
		mark[newPoint] = true;
	}
}
void Check()
{
	for (int i = 1; i <= cnt2 + cnt1; i++)
	{
		cout << dis1[i] << " "<<dis2[i] << endl;
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		Ini();
		if (n == 0)
		{
			break;
		}
		int m;
		cin >> m;
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
			int t;
			cin >> t;
			side[i] = t;
			if (t == 1)
			{
				cnt1++;
			}
			else
			{
				cnt2++;
			}
		}
		Dijkstra(dis1, 1);
		Dijkstra(dis2, 2);
		//Check();
		int ans = INT_MAX;
		for (int i = 1; i <= cnt1 + cnt2; i++)
		{
			for (int j = i + 1; j <= cnt1 + cnt2; j++)
			{
				if (Edge[i][j] == INT_MAX)
				{
					continue;
				}
				if (side[i] == 1 && side[j] == 2)
				{
					//cout << "sd2" << endl;
					if (dis1[i] == -1 || dis2[j] == -1)
					{
						continue;
					}
					//cout << "sd" << endl;
					int sum = dis1[i] + dis2[j] + Edge[i][j];
					if (sum < ans)
					{
						ans = sum;
					}
				}
				else if (side[i] == 2 && side[j] == 1)
				{
					if (dis1[j] == -1 || dis2[i] == -1)
					{
						continue;
					}
					int sum = dis1[j] + dis2[i] + Edge[i][j];
					if (sum < ans)
					{
						ans = sum;
					}
				}
			}
		}
		ans = ans == INT_MAX ? -1 : ans;
		cout << ans << endl;
	}
	return 0;
}