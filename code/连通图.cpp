#include <iostream>
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
	int n, m;
	while (cin >> n >> m)
	{
		int a, b;
		Ini();
		while (m-- > 0)
		{
			cin >> a >> b;
			a = findRoot(a);
			b = findRoot(b);
			if (a != b)
			{
				Tree[a] = b;  //将a作为b的子树
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n && cnt <= 1; i++)
		{
			if (Tree[i] == -1)
			{
				cnt++;
			}
		}
		if (cnt == 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}