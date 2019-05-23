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
int Solve(int n)
{
	int ans = 0;
	int i;
	for ( i = 1; i*i < n; i++)
	{
		if (n % i == 0)
		{
			ans += 2;
		}
	}
	if (i*i == n)
	{
		ans++;
	}
	return ans;
}
int main()
{
	//Prime();
	int N;
	while (cin >> N)
	{
		int num[1001];
		int ans[1001];
		if (N == 0)
		{
			break;
		}
		for (int i = 0; i < N; i++)
		{
			cin >> num[i];
			ans[i] = Solve(num[i]);
		}
		for (int i = 0; i < N; i++)
		{
			cout << ans[i] << endl;
		}
	}
	return 0;
}