#include <iostream>
using namespace std;
#define SIZE 100000
int check[SIZE + 5] = { 0 };
int cnt = 0;
int prime[SIZE + 5];
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
int main()
{
	Prime();
	int n;
	while (cin >> n)
	{
		int t = n;
		int ans = 0;
		for (int i = 0; i < cnt; i++)
		{
			if (t == 1)
			{
				break;
			}
			while (t % prime[i] == 0)
			{
				t = t / prime[i];
				ans++;
			}
		}
		if (t != 1)
		{
			ans++;
		}
		cout << ans << endl;	
	}

	return 0;
}