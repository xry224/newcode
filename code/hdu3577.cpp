#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
using namespace std;
#define SIZE 1000000*4+5
class Node
{
public:
	int l;
	int r;
	int val;
	int lazy;
	Node()
	{

	}
}Tree[SIZE];
int max(int a, int b)
{
	return a > b ? a : b;
}
void PushUp(int k)
{
	Tree[k].val = max(Tree[k * 2 + 1].val, Tree[k * 2].val);
}
void Build(int l, int r, int k)
{
	Tree[k].l = l;
	Tree[k].r = r;
	Tree[k].lazy = 0;
	Tree[k].val = 0;
	if (l == r)
	{
		
		return;
	}
	int mid = (l + r) / 2;
	Build(l, mid, 2 * k);
	Build(mid + 1, r, 2 * k + 1);
	PushUp(k);
}
void PushDown(int k)
{
	Tree[2 * k + 1].val += Tree[k].lazy;
	Tree[2 * k].val += Tree[k].lazy;
	if (Tree[2 * k].r != Tree[2 * k].l)
	{
		Tree[2 * k].lazy += Tree[k].lazy;
		Tree[2 * k + 1].lazy += Tree[k].lazy;
	}
	Tree[k].lazy = 0;
}
int Query(int l, int r, int k)
{
	if (Tree[k].l >= l && Tree[k].r <= r)
	{
		return Tree[k].val;
	}
	if (Tree[k].lazy != 0)
	{
		PushDown(k);
	}
	int mid = (Tree[k].l + Tree[k].r) / 2;
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
		int a = Query(l, r, 2 * k);
		int b = Query(l, r, 2 * k + 1);
		return max(a, b);
	}
}
void AddSeg(int l, int r, int k, int num)
{
	if (Tree[k].l >= l && Tree[k].r <= r)
	{
		Tree[k].val += num;
		Tree[k].lazy += num;
		return;
	}
	if (Tree[k].lazy != 0)
	{
		PushDown(k);
	}
	int mid = (Tree[k].l + Tree[k].r) / 2;
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
	PushUp(k);
}
int ans[100000];
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		int k, q;
		Build(1, 1000000 + 2, 1);
		scanf("%d%d", &k, &q);
		int a, b;

		int anslen = 0;
		for (int j = 1; j <= q; j++)
		{
			scanf("%d%d", &a, &b);
			b--;
			int t = Query(a, b, 1);
		//	cout << t << endl;
			if (t < k)
			{
				ans[anslen++] = j;
				AddSeg(a, b, 1, 1);
			}
		}
		printf("Case %d:\n", i);
		for (int j = 0; j < anslen; j++)
		{
			printf("%d ", ans[j]);
		}
		printf("\n\n");
	}
	return 0;
}