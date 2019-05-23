#include <iostream>
using namespace std;
bool isprime[10005];
int prime[10005];
int cnt = 0;
void Initialize()
{
	for (int i = 0; i < 10005; i++)
	{
		isprime[i] = true;
	}
	isprime[0] = isprime[1] = false;
}
void Prime()
{
	for (int i = 2; i < 10005; i++)
	{
		if (isprime[i])
		{
			prime[cnt++] = i;
		}
		for (int j = 0; j < cnt && i * prime[j] < 10005; j++)
		{
			isprime[i * prime[j]] = false;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
int main()
{
	int n;
	Initialize();
	Prime();
	while (cin >> n)
	{
		int ans[10000];
		int anscnt = 0;
		for (int i = 2; i < n; i++)
		{
			if (isprime[i])
			{
				if (i % 10 == 1)
				{
					ans[anscnt++] = i;
				}
			}
		}
		if (anscnt == 0)
		{
			cout << -1 << endl;
		}
		else
		{
			for (int i = 0; i < anscnt - 1; i++)
			{
				cout << ans[i] << " ";
			}
			cout << ans[anscnt - 1] << endl;
		}
	}
	return 0;
}