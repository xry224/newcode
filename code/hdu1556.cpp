#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
using namespace std;
#define SIZE 4*100000
class Node
{
public:
	int l;
	int r;
	int lazy;
	int time;
	Node()
	{

	}
}nodes[SIZE + 4];
void pushUp(int k)
{
	nodes[k].time = nodes[2 * k].time + nodes[2 * k + 1].time;
}
void Build(int l, int r, int k)
{
	nodes[k].l = l;
	nodes[k].r = r;
	nodes[k].lazy = 0;
	if (nodes[k].l == nodes[k].r)
	{
		nodes[k].time = 0;
		return;
	}
	int mid = (l + r) / 2;
	Build(l, mid, 2 * k);
	Build(mid + 1, r, 2 * k + 1);
	//pushUp(k);
}
void pushDown(int k)
{
	nodes[2 * k].time += (nodes[2 * k].r - nodes[2 * k].l + 1) * nodes[k].lazy;
	nodes[2 * k + 1].time += (nodes[2 * k + 1].r - nodes[2 * k + 1].l + 1) * nodes[k].lazy;
	if (nodes[2 * k].l != nodes[2 * k].r)
	{
		nodes[2 * k].lazy += nodes[k].lazy;
		nodes[2 * k + 1].lazy += nodes[k].lazy;
	}
	nodes[k].lazy = 0;
}
int Query(int l, int r, int k)
{
	if (nodes[k].l >= l && nodes[k].r <= r)
	{
		return nodes[k].time;
	}
	if (nodes[k].lazy != 0)
	{
		pushDown(k);
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
void AddSeg(int l, int r, int k, int num)
{
	if (nodes[k].l >= l && nodes[k].r <= r)
	{
		nodes[k].lazy += num;
		nodes[k].time += num * (nodes[k].r - nodes[k].l + 1);
		return;
	}
	if (nodes[k].lazy != 0)
	{
		pushDown(k);
	}
	int mid = (nodes[k].l + nodes[k].r) / 2;
	if (r <= mid)
	{
		AddSeg(l, r, 2 * k, num);
	}
	else if (l > mid)
	{
		AddSeg(l, r, 2 * k + 1, num);
	}
	else
	{
		AddSeg(l, r, 2 * k, num);
		AddSeg(l, r, 2 * k + 1, num);
	}
	pushUp(k);
}
void Add(int i, int num, int tar)
{
	if (nodes[i].l == nodes[i].r)
	{
		nodes[i].time += num;
		return;
	}
	if (nodes[i].lazy != 0)
	{
		pushDown(i);
	}
	int mid = (nodes[i].l + nodes[i].r) / 2;
	if (tar <= mid)
	{
		Add(2 * i, num, tar);
	}
	if (tar > mid)
	{
		Add(2 * i + 1, num, tar);
	}
	pushUp(i);
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		int a, b;
		int t = n;
		Build(1, n, 1);
		while (t--)
		{
			scanf("%d%d", &a, &b);
			AddSeg(a, b, 1, 1);
		}
		for (int i = 1; i < n; i++)
		{
			printf("%d ", Query(i, i, 1));
		}
		printf("%d\n", Query(n, n, 1));
	}
	return 0;
}