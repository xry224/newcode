#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000000
class Edge
{
public:
	int next;
	int length;
	int cost;
	Edge()
	{

	}
};
int cost[1001];
int dis[1001];
bool mark[1001];
vector <Edge> edges[1001];
void Initialize()
{
	for (int i = 0; i < 1001; i++)
	{
		mark[i] = false;
		cost[i] = INF;
		edges[i].clear();
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
		int a, b, d, p;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> d >> p;
			Edge t;
			t.cost = p;
			t.length = d;
			t.next = b;
			edges[a].push_back(t);
			t.next = a;
			edges[b].push_back(t);
		}
		int s, t;
		cin >> s >> t;
		dis[s] = 0;
		mark[s] = true;
		int newPoint = s;
		cost[s] = 0;
		for (int i = 0; i < n - 1; i++)
		{
			//更新dis数组
			for (int j = 0; j < edges[newPoint].size(); j++)
			{
				int next = edges[newPoint][j].next;
				int length = edges[newPoint][j].length;
				int c = edges[newPoint][j].cost;
				if (dis[next] == -1 || dis[next] > dis[newPoint] + length || (dis[next] == dis[newPoint] + length && cost[next] > cost[newPoint] + c))
				{
					dis[next] = dis[newPoint] + length;
					cost[next] = cost[newPoint] + c;
				}
			}
			int min = INF;
			//遍历剩余节点
			for (int j = 1; j <= n; j++)
			{
				if (dis[j] == -1 || mark[j])
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
		cout << dis[t] << " " << cost[t] << endl;
	}
	return 0;
}