#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 105
int Tree[SIZE];
void Initialize()
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
class Road
{
public:
	int u;
	int v;
	int cost;
	Road()
	{
		u = v = cost;
	}
	bool operator < (const Road &A) const
	{
		return cost < A.cost;
	}
};
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0)
		{
			break;
		}
		Initialize();
		Road road[SIZE];
		for (int i = 0; i < n; i++)
		{
			int a, b, cost;
			cin >> a >> b >> cost;
			road[i].u = a;
			road[i].v = b;
			road[i].cost = cost;
		}
		sort(road, road + n);
		int cnt = 1;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int a = road[i].u;
			int b = road[i].v;
			a = findRoot(a);
			b = findRoot(b);
			if (a != b)
			{
				Tree[a] = b;
				cnt++;
				ans += road[i].cost;
			}
		}
		if (cnt == m)
		{
			cout << ans << endl;
		}
		else
		{
			cout << "?" << endl;
		}
	}
	return 0;
}