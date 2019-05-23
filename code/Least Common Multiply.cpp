#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	return a % b == 0 ? b : gcd(b, a%b);
}
int main()
{
	int n;
	while (cin >> n)
	{
		int m;
		cin >> m;
		int ans = 1;
		for (int i = 0; i < m; i++)
		{
			int t;
			cin >> t;
			ans = ans * t / gcd(t, ans);
		}
		cout << ans << endl;
	}
	return 0;
}