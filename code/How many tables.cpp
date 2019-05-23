#include <iostream>
#include <string>
using namespace std;
#define SIZE 1005
int Tree[SIZE];
void Ini()
{
	for (int i = 0; i < SIZE; i++)
	{
		Tree[i] = -1;
	}
}
int findRoot(int x)
{
	if (Tree[x] == -1)
	{
		return x;
	}
	int t = findRoot(Tree[x]);
	Tree[x] = t;
	return t;
}
int main()
{
	int T;
	cin >> T;
	string blank;
	while (T--)
	{
		Ini();
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			a = findRoot(a);
			b = findRoot(b);
			if (a != b)   //a与b是朋友但不在一个集合中
			{ 
				Tree[a] = b;   //b作为a的父节点
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			//统计跟节点个数（连通分量个数）
			if (Tree[i] == -1)
			{
				ans++;
			}
		}
		cout << ans << endl;
		getline(cin, blank);
	}
	return 0;
}
