#include <iostream>
using namespace std;
#define SIZE 100000
int check[SIZE + 5] = { 0 };
int cnt = 0;
int prime[SIZE + 5];
int primeCnt[1001] = { 0 };
int primeCntN[1001] = { 0 };
void Prime()
{
	for (int i = 2; i <= SIZE; i++)
	{
		if (!check[i])
		{
			prime[cnt++] = i;
		}
		for (int j = 0; j < cnt && prime[j] * i <= SIZE; j++)
		{
			check[prime[j] * i] ++;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
void TakeA(int a)
{
	for (int i = 0; i < cnt; i++)
	{
		if (a == 1)
		{
			break;
		}
		while (a % prime[i] == 0)
		{
			primeCnt[prime[i]] ++;
			a /= prime[i];
		}
	}
	if (a != 1)
	{
		primeCnt[a]++;
	}
}
void TakeN(int n)
{
	for (int i = 2; i <= n; i++)
	{
		int t = i;
		for (int j = 0; j < cnt; j++)
		{
			if (t == 1)
			{
				break;
			}
			while (t % prime[j] == 0)
			{
				primeCntN[prime[j]]++;
				t /= prime[j];
			}
		}
		if (t != 1)
		{
			primeCntN[t]++;
		}
	}
}
int main()
{
	int n, a;
	Prime();
	while (cin >> n >> a)
	{
		TakeA(a);
		TakeN(n);
		int ans = 10000000;
		for (int i = 2; i <= 1000; i++)
		{
			if (primeCnt[i] != 0 && primeCntN[i] != 0)
			{
				int t = primeCntN[i] / primeCnt[i];
				if (t < ans)
				{
					ans = t;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}