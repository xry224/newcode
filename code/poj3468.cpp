#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
using namespace std;
#define SIZE 100000
class Node
{
public:
	long long l;
	long long r;
	long long lazy;
	long long val;
	Node()
	{

	}
}Tree[4 * SIZE + 1];
void PushUp(long long k)
{
	Tree[k].val = Tree[2 * k + 1].val + Tree[2 * k].val;
}
void Build(long long l, long long r, long long k)
{
	Tree[k].l = l;
	Tree[k].r = r;
	Tree[k].lazy = 0;
	if (l == r)
	{
		scanf("%I64d", &Tree[k].val);
		return;
	}
	long long mid = (l + r) / 2;
	Build(l, mid, 2 * k);
	Build(mid + 1, r, 2 * k + 1);
	PushUp(k);
}
void PushDown(long long k)
{
	Tree[2 * k].val += (Tree[2 * k].r - Tree[2 * k].l + 1) * Tree[k].lazy;
	Tree[2 * k + 1].val += (Tree[2 * k + 1].r - Tree[2 * k + 1].l + 1) * Tree[k].lazy;
	if (Tree[2 * k].r != Tree[2 * k].l)
	{
		Tree[2 * k].lazy += Tree[k].lazy;
		Tree[2 * k + 1].lazy += Tree[k].lazy;
	}
	Tree[k].lazy = 0;
}
long long Query(long long l, long long r, long long k)
{
	if (Tree[k].l >= l && Tree[k].r <= r)
	{
		return Tree[k].val;
	}
	if (Tree[k].lazy != 0)
	{
		PushDown(k);
	}
	long long mid = (Tree[k].l + Tree[k].r) / 2;
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
void AddSeg(long long l, long long r, long long num, long long k)
{
	if (Tree[k].l >= l && Tree[k].r <= r)
	{
		Tree[k].val += num * (Tree[k].r - Tree[k].l + 1);
		Tree[k].lazy += num;
		return;
	}
	if (Tree[k].lazy != 0)
	{
		PushDown(k);
	}
	long long mid = (Tree[k].l + Tree[k].r) / 2;
	if (r <= mid)
	{
		AddSeg(l, r, num, 2 * k);
	}
	else if (l > mid)
	{
		AddSeg(l, r, num, 2 * k + 1);
	}
	else
	{
		AddSeg(l, r, num, 2 * k);
		AddSeg(l, r, num, 2 * k + 1);
	}
	PushUp(k);
}
int main()
{
	int n, q;
	while (scanf("%d%d",&n,&q)!=EOF)
	{
		char op;
		long long a, b, c;
		Build(1, n, 1);
		while (q--)
		{
			scanf("%c", &op);
			if (op == 'C')
			{
				scanf("%I64d%I64d%I64d", &a, &b, &c);
				AddSeg(a, b, c, 1);
			}
			else if (op == 'Q')
			{
				scanf("%I64d%I64d", &a, &b);
				printf("%I64d\n", Query(a, b, 1));
			}
		}
	}
	return 0;
}