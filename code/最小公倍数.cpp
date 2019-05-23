#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	return a % b == 0 ? b : gcd(b, a%b);
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		if (a < b)
		{
			int t = a;
			a = b;
			b = t;
		}
		int ans = gcd(a, b);
		cout << a * b / ans << endl;
	}
	return 0;
}