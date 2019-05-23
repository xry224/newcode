#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int camp[50001];
class Node
{
public:
	int l;
	int r;
	int v;
	Node()
	{

	}
	Node(int le, int ri, int val)
	{
		l = le;
		r = ri;
		v = val;
	}
}nodes[200005];
void Build(int l, int r, int k)
{
	nodes[k].l = l;
	nodes[k].r = r;
	if (l == r)
	{
		scanf("%d", &nodes[k].v);
		return;
	}
	int mid = (l + r) / 2;
	Build(l, mid, 2 * k);
	Build(mid + 1, r, 2 * k + 1);
	nodes[k].v = nodes[k * 2].v + nodes[k * 2 + 1].v;
}
void Add(int i, int num, int tar)
{
	if (nodes[i].l == nodes[i].r)
	{
		nodes[i].v += num;
		return;
	}
	int mid = (nodes[i].l + nodes[i].r) / 2;
	if (tar <= mid)
	{
		Add(2 * i, num, tar);
	}
	else
	{
		Add(2 * i + 1, num, tar);
	}
	nodes[i].v = nodes[i * 2].v + nodes[i * 2 + 1].v;
}
int Query(int l, int r, int k)
{
	int ans = 0;
	if (nodes[k].l >= l && nodes[k].r <= r)
	{
		return nodes[k].v;
	}
	int mid = (nodes[k].l + nodes[k].r) / 2;
	if (r <= mid)
	{
		return Query(l, r, 2 * k);
	}
	else if (l > mid)
	{
		return Query(l, r, 2 * k + 1);
	}
	else
	{
		return Query(l, r, 2 * k) + Query(l, r, 2 * k + 1);
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		int n;
		scanf("%d", &n);
		Build(1, n, 1);
		printf("Case %d:\n", i);
		while (true)
		{
			int a, b;
			string cmd;
			cin >> cmd;
			if (cmd == "End")
			{
				break;
			}
			cin >> a >> b;
			if (cmd == "Add")
			{
				Add(1, b, a);
			}
			else if (cmd == "Sub")
			{
				Add(1, -b, a);
			}
			else
			{
				printf("%d\n", Query(a, b, 1));
			}

		}
	}
	return 0;
}