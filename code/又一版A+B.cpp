#include <iostream>
#include <string>
using namespace std;
string Convert(long long num, int m)
{
	string res = "";
	do
	{
		long long t = num % m;
		res += (t + '0');
		num /= m;
	} while (num > 0);
	return res;
}
int main()
{
	long long a, b;
	int m;
	while (cin >> m)
	{
		if (m == 0)
		{
			break;
		}
		cin >> a >> b;

		long long sum = a + b;
		string res = Convert(sum, m);
		for (int i = res.length() - 1; i >= 0; i--)
		{
			cout << res[i];
		}
		cout << endl;
	}
}