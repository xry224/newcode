#include <iostream>
#include <string>
using namespace std;
#define SIZE 3000
class BigInt
{
public:
	int digit[SIZE] = { 0 };
	int cur;
	int len;
	BigInt()
	{
		cur = SIZE;
		len = SIZE - cur;
	}
	BigInt(string str)
	{
		cur = SIZE;
		for (int i = str.length() - 1; i >= 0; i--)
		{
			digit[--cur] = str[i] - '0';
		}
		len = SIZE - cur;
	}
	void Add(BigInt b)
	{
		int i, j;
		for (i = SIZE - 1, j = SIZE - 1; i >= this->cur && j >= b.cur; i--, j--)
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
					len = SIZE - cur;
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
			len = SIZE - cur;
		}

	}
	string ToString()
	{
		string res = "";
		for (int i = cur; i <= SIZE - 1; i++)
		{
			res += (digit[i] + '0');
		}
		return res;
	}
	BigInt operator * (int x) const
	{
		BigInt res = BigInt();
		for (int i = SIZE - 1; i >= cur; i--)
		{
			int t = x * this->digit[i];
			string nt = to_string(t);
			for (int j = nt.length() - 1; j >= 0; j--)
			{
				int off = nt.length() - j - 1;
				res.digit[i - off] += (nt[j] - '0');
				if (res.digit[i - off] >= 10)
				{
					res.digit[i - off] -= 10;
					res.digit[i - off - 1] ++;
				}
			}
		}
		for (int i = 0; i < SIZE; i++)
		{
			if (res.digit[i] != 0)
			{
				res.cur = i;
				break;
			}
		}
		return res;	
	}
};
int main()
{
	int N;
	while (cin >> N)
	{
		BigInt a = BigInt("1");
		if (N == 0 || N == 1)
		{
			cout << 1 << endl;
			continue;
		}
		for (int i = 1; i <= N; i++)
		{
			a = a * i;
		}
		cout << a.ToString() << endl;
	}
	return 0;
}