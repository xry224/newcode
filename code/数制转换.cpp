#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string Convert(long long num, int m)
{
	string res = "";
	do
	{
		long long t = num % m;
		res += t < 10 ? (t + '0') : (t + 'A' - 10);
		num /= m;
	} while (num > 0);
	return res;
}
int Convert2Decimal(string num, int m)
{
	int res = 0;
	int len = num.length();
	for (int i = len - 1; i >= 0; i--)
	{
		int t;
		if (num[i] <= '9' && num[i] >= '0')
		{
			t = num[i] - '0';
		}
		else if (num[i] <= 'f' && num[i] >= 'a')
		{
			t = num[i] - 'a' + 10;
		}
		else if (num[i] <= 'F' && num[i] >= 'A')
		{
			t = num[i] - 'A' + 10;
		}
		res += t * pow(m, len - 1 - i);
	}
	return res;
}
int main()
{
	int a, b;
	string n;
	while (cin >> a >> n >> b)
	{
		int decimal = Convert2Decimal(n, a);
		string res = Convert(decimal, b);
		for (int i = res.length() - 1; i >= 0; i--)
		{
			cout << res[i];
		}
		cout << endl;
	}
	return 0;
}