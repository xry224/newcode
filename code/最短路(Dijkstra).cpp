#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
	
class Edge
{
public:
	int next;
	int cost;
	Edge()
	{

	}
};
vector<Edge> edges[101];
bool mark[101];
int dis[101];
void Initialize()
{
	for (int i = 0; i < 101; i++)
	{
		edges[i].clear();
	}
	memset(mark, false, sizeof(mark));
	for (int i = 0; i < 101; i++)
	{
		dis[i] = -1;
	}
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		if (n == m && n == 0)
		{
			break;
		}
		Initialize();
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			Edge t;
			t.next = b;
			t.cost = c;
			edges[a].push_back(t);
			
			t.next = a;
			edges[b].push_back(t);
		}
		dis[1] = 0;
		mark[1] = true;
		int newPoint = 1;
		//添加剩下n-1个节点
		for (int i = 0; i < n - 1; i++)
		{
			//添加节点后更新dis数组
			for (int j = 0; j < edges[newPoint].size(); j++)
			{
				int next = edges[newPoint][j].next;
				int cost = edges[newPoint][j].cost;
				if (mark[next])
				{
					continue;
				}
				if (dis[next] == -1 || dis[next] > dis[newPoint] + cost)
				{
					dis[next] = dis[newPoint] + cost;
				}
			}
			int min = INF;
			//遍历所有节点找最小值
			for (int j = 1; j <= n; j++)
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
		cout << dis[n] << endl;
	}
	return 0;
}