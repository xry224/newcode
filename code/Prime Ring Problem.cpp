#include <iostream>
#include <string.h>
using namespace std;
int check[45] = { 0 };  //判断某数字是否为素数
int prime[45];
int ans[20];
bool visit[25];
void Prime()
{
	int cnt = 0;
	check[0] = check[1] = 1;
	for (int i = 2; i < 45; i++)
	{
		if (!check[i])
		{
			prime[cnt++] = i;
		}
		for (int j = 0; j < cnt && i*prime[j] < 45; j++)
		{
			check[i*prime[j]]++;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
void PrintCase(int n)
{
	//顺时针输出
	cout << ans[0] << " ";
	for (int i = 1; i < n - 1; i++)
	{
		cout << ans[i] << " ";
	}
	cout << ans[n - 1] << endl;	
	//逆时针输出
	/*cout << ans[0] << " ";
	for (int i = n - 1; i > 1; i--)
	{
		cout << ans[i] << " ";
	}
	cout << ans[1] << endl;*/
}
void Solve(int level, int n)
{
	if (level == n)
	{
		if (!check[1 + ans[n - 1]])
		{
			PrintCase(n);
		}
		return;
	}
	for (int i = 2; i <= n; i++)
	{
		if (!visit[i])
		{
			int left = level - 1;
			if (!check[i + ans[left]])
			{
				visit[i] = true;
				ans[level] = i;
				Solve(level + 1, n);
				visit[i] = false;
				ans[level] = 0;
			}
		}
	}
}
int main()
{
	int n;
	Prime();
	int T = 1;
	while (cin >> n)
	{
		
		memset(ans, 0, sizeof(ans));
		ans[0] = 1;
		memset(visit, false, sizeof(visit));
		visit[1] = true;
		cout << "Case " << T++ << ":" << endl;
		Solve(1, n);	
		cout << endl;
	}
	return 0;
}