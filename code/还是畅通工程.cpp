#include <iostream>
#include<algorithm>
using namespace std;
#define SIZE 100
#define ESIZE 5000
int Tree[SIZE];
class Edge
{
public:
	int v, u;
	int cost;
	Edge()
	{

	}
	Edge(int u, int v, int cost)
	{
		this->u = u;
		this->v = v;
		this->cost = cost;
	}
	bool operator < (const Edge &A) const
	{
		return cost < A.cost;
	}
};
int findRoot(int x)
{
	if (Tree[x] == x)
	{
		return x;
	}
	int t = findRoot(Tree[x]);
	Tree[x] = t;
	return t;
}
void Ini()
{
	for (int i = 0; i < SIZE; i++)
	{
		Tree[i] = i;
	}
}
int main()
{
	int N;
	while (cin >> N)
	{
		Ini();
		Edge e[ESIZE];
		if (N == 0)
		{
			break;
		}
		int num = N * (N - 1) / 2;
		for (int i = 0; i < num; i++)
		{
			int u, v, cost;
			cin >> u >> v >> cost;
			e[i].u = u;
			e[i].v = v;
			e[i].cost = cost;
		}
		sort(e, e + num);
		int ans = 0;
		for (int i = 0; i < num; i++)
		{
			int a = findRoot(e[i].u);
			int b = findRoot(e[i].v);	//当前边的两个节点不在同一个连通分量中
			if (a != b)
			{
				Tree[a] = b;
				ans += e[i].cost;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
