/*写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。*/
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
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
	string num;
	while (cin >> num)
	{
		num = num.substr(2, num.length() - 2);
		int res = Convert2Decimal(num, 16);
		cout << res << endl;
	}
	return 0;
}