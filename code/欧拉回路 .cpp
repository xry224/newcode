#include <iostream>
#include <string.h>
using namespace std;
int Tree[1005];
int Degree[1005];
void Ini()
{
	for (int i = 0; i < 1005; i++)
	{
		Tree[i] = i;
		Degree[i] = 0;
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
	int n, m;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		cin >> m;
		Ini();
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			Degree[a]++;
			Degree[b]++;
			a = findRoot(a);
			b = findRoot(b);
			if (a != b)
			{
				Tree[a] = b;
			}
		}
		int start;
		for (int i = 1; i <= n; i++)
		{
			if (Degree[i] != 0)
			{
				start = i;
				break;
			}
		}
		int set = findRoot(start);
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			if ((Degree[i] != 0 && findRoot(i) != set) || (findRoot(i) == set && Degree[i] % 2 != 0))
			{
				flag = 0;
				break;
			}
		}
		cout << flag << endl;
	}
	return 0;
}