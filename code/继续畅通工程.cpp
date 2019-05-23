#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 100
#define RSIZE 5000
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
	int isBuild;
	Road()
	{

	}
	bool operator < (const Road &A) const
	{
		if (isBuild != A.isBuild)
		{
			return isBuild > A.isBuild;			//造好的路优先级比没造好的高
		}
		return cost < A.cost;
	}
};
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		Initialize();
		Road road[RSIZE];
		int rsize = n * (n - 1) / 2;
		for (int i = 0; i < rsize; i++)
		{
			cin >> road[i].u >> road[i].v >> road[i].cost >> road[i].isBuild;
		}
		sort(road, road + rsize);
		int ans = 0;
		for (int i = 0; i < rsize; i++)
		{
			int a = road[i].u;
			int b = road[i].v;
			a = findRoot(a);
			b = findRoot(b);
			if (a != b)
			{
				Tree[a] = b;
				if (road[i].isBuild == 0)
				{
					ans += road[i].cost;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}