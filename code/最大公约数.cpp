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
		cout << gcd(a, b) << endl;
	}
	return 0;
}