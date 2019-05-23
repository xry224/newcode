#include <iostream>
#include <algorithm>
using namespace std;
#define RSIZE 80
#define SIZE 27
int Tree[SIZE];
class Road
{
public:
	int u;
	int v;
	int cost;
	Road()
	{
		u = v = cost = 0;
	}
	bool operator <(const Road &A) const
	{
		return cost < A.cost;
	}
};
void Ini()
{
	for (int i = 0; i < SIZE; i++)
	{
		Tree[i] = i;
	}
}
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
		Road road[RSIZE];
		char v1, v2;
		int vi1, vi2;
		int roads;
		int cost;
		int rcnt = 0;
		for (int i = 0; i < n - 1; i++)
		{
			cin >> v1 >> roads;
			for (int i = 0; i < roads; i++)
			{
				cin >> v2 >> cost;
				vi1 = v1 - 'A';
				vi2 = v2 - 'A';
				road[rcnt].u = vi1;
				road[rcnt].v = vi2;
				road[rcnt++].cost = cost;
			}
		}
		int ans = 0;
		sort(road, road + rcnt);
		for (int i = 0; i < rcnt; i++)
		{
			int a = findRoot(road[i].u);
			int b = findRoot(road[i].v);
			if (a != b)
			{
				Tree[a] = b;
				ans += road[i].cost;
			}
		}
		cout << ans << endl;
	}
}