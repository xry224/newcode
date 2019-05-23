#include <iostream>
using namespace std;
#define SIZE 1000000
int check[SIZE] = { 0 };
int prime[SIZE];
int cnt = 0;
void Prime()
{
	for (int i = 2; i < SIZE; i++)
	{
		if (!check[i])
		{
			prime[cnt++] = i;
		}
		for (int j = 0; j < cnt && i*prime[j] < SIZE; j++)
		{
			check[i * prime[j]] = 1;
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
	for (int i = 0; prime[i] <= n / 2 && i < cnt; i++)
	{
		int left = n - prime[i];
		
		if (!check[left])	//差也是质数
		{
			ans++;
		}
	}
	return ans;
}
int main()
{
	int n;
	Prime();
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		cout << Solve(n) << endl;
	}
	return 0;
}