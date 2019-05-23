#include <iostream>
#include <string>
using namespace std;
class BigInt
{
public:
	int digit[1005] = { 0 };
	int cur;
	BigInt()
	{
		cur = 1004;
	}
	BigInt(string str)
	{
		cur = 1005;
		for (int i = str.length() - 1; i >= 0; i--)
		{
			digit[--cur] = str[i] - '0';
		}
	}
	void Add(BigInt b)
	{
		int i, j;
		for (i = 1004, j = 1004; i >= this->cur && j >= b.cur; i--, j--)
		{
			digit[i] = digit[i] + b.digit[i];
			if (digit[i] >= 10)
			{
				digit[i - 1]++;
				digit[i] -= 10;
				//最高位发生进位，总位数增加
				if (i == this->cur)
				{
					cur = i - 1;
				}
			}
		}
		//位数小于加数
		if (j >= b.cur)
		{
			while (j >= b.cur)
			{
				digit[j] += b.digit[j];
				j--;
			}
			cur = b.cur;   //更新位数
		}

	}
	string ToString()
	{
		string res = "";
		for (int i = cur; i <= 1004; i++)
		{
			res += (digit[i] + '0');
		}
		return res;
	}
};
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		BigInt num1 = BigInt(a);
		BigInt num2 = BigInt(b);
		num1.Add(b);
		string ans = num1.ToString();
		cout << ans << endl;
	}
	return 0;
}