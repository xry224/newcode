#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;
#define SIZE 105
#define ESIZE 5000
int Tree[SIZE];
class Point
{
public:
	double x;
	double y;
	Point(double a, double b)
	{
		x = a;
		y = b;
	}
	double Distance(Point A)
	{
		double squar = (x - A.x)*(x - A.x) + (y - A.y)*(y - A.y);
		return sqrt(squar);
	}
	Point()
	{
		x = y = 0;
	}
};
class Edge
{
public:
	int a;
	int b;
	double cost;
	Edge()
	{
		cost = 0;
	}
	Edge(double value)
	{
		cost = value;
	}
	bool operator < (const Edge &A) const
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
	int N;
	while (cin >> N)
	{
		Ini();
		Point p[SIZE];
		Edge e[ESIZE];
		for (int i = 0; i < N; i++)
		{
			cin >> p[i].x >> p[i].y;
		}
		int eCnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				e[eCnt].a = i;
				e[eCnt].b = j;
				e[eCnt++].cost = p[i].Distance(p[j]);
			}
		}
		sort(e, e + eCnt);
		double ans = 0;
		for (int i = 0; i < eCnt; i++)
		{
			int a = findRoot(e[i].a);
			int b = findRoot(e[i].b);
			if (a != b)				//两点未连在一起
			{
				Tree[a] = b;
				ans += e[i].cost;
			}
		}
		cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}
