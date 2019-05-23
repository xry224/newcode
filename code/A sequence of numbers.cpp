#include <iostream>
using namespace std;
#define MOD 200907
long long Cal(long long q, int K)
{
	long long ans = 1;
	while (K > 0)
	{
		if (K % 2 == 0)
		{
			q = q * q %MOD;
			K /= 2;
		}
		else
		{
			ans = ans * q % MOD;
			K--;
		}
	}
	return ans % MOD;
}
int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		long long a, b, c, K;
		cin >> a >> b >> c >> K;
		long long ans;
		if (a == b)
		{
			cout << c % MOD << endl;
			continue;
		}
		else if (b - a == c - b)
		{
			ans = (a + ((K - 1)*(b - a))) % MOD;
			cout << ans << endl;
		}
		else
		{
			long long q = b / a;
			ans = Cal(q, K - 1);
			cout << ans * a % MOD << endl;
		}
	}
	return 0;
}