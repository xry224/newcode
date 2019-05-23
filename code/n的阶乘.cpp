#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		long long ans = 1;
		for (int i = 1; i <= n; i++)
		{
			ans = ans * i;
		}
		cout << ans << endl;
	}
	return 0;
}