#include <iostream>
#include <string>
using namespace std;
#define SIZE 1005
string Inverse(string original);
class BigInt
{
public:
	int pos;
	int Digit[SIZE] = { 0 };
	BigInt(string ori)
	{
		for (int i = ori.length() - 1; i >= 0; i--)
		{
			int off = ori.length() - 1 - i;
			Digit[SIZE - 1 - off] = ori[i] - '0';
		}
		pos = SIZE - ori.length();
	}
	BigInt()
	{
		pos = SIZE;
	}
	static string ToBinary(BigInt num)
	{
		string ans = "";
		BigInt t = num;
		while (!IsZero(t))
		{
			if (t % 2 == 1)
			{
				ans += '1';
			}
			else
			{
				ans += '0';
			}
			t = t / 2;
			
		}
		return Inverse(ans);
	}
	int operator % (int x) const
	{
		int r = 0; //余数
		int i;
		for (i = pos; i < SIZE; i++)
		{
			int t = (r * 10 + Digit[i]);
			r = t % x;
		}
		return r;
	}
	BigInt operator / (int x) const
	{
		int r = 0; //余数
		int i;
		string ans = "";
		for (i = pos; i < SIZE; i++)
		{
			int t = (r * 10 + Digit[i]);
			int Quotient = t / x;
			ans += (Quotient + '0');
			r = t % x;
		}
		if (ans == "")
		{
			return BigInt("0");
		}
		//结果带前导0
		BigInt res = BigInt(ans);
		return res;
	}
	static bool IsZero(BigInt A)
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (A.Digit[i] != 0)
			{
				return false;
			}
		}
		return true;
	}
	BigInt operator * (int x) const
	{
		BigInt res = BigInt();
		for (int i = SIZE - 1; i >= pos; i--)
		{
			int t = x * this->Digit[i];
			string nt = to_string(t);
			for (int j = nt.length() - 1; j >= 0; j--)
			{
				int off = nt.length() - j - 1;
				res.Digit[i - off] += (nt[j] - '0');
				if (res.Digit[i - off] >= 10)
				{
					res.Digit[i - off] -= 10;
					res.Digit[i - off - 1] ++;
				}
			}
		}
		for (int i = 0; i < SIZE; i++)
		{
			if (res.Digit[i] != 0)
			{
				res.pos = i;
				break;
			}
		}
		return res;

	}
	static BigInt ToDecimal(string bin)
	{
		BigInt base = BigInt("1");
		BigInt ans = BigInt("0");
		for (int i = bin.length() - 1; i >= 0; i--)
		{
			if (bin[i] == '1')
			{
				ans = ans + base;
			}
			
			base = base * 2;
		}
		return ans;
	}
	BigInt operator + (const BigInt &A) const
	{
		BigInt res = BigInt();
		int i, j;
		for (i = SIZE - 1, j = SIZE - 1; i >= pos && j >= A.pos; i--, j--)
		{
			res.Digit[i] += Digit[i] + A.Digit[j];
			if (res.Digit[i] >= 10)
			{
				res.Digit[i] -= 10;
				res.Digit[i - 1]++;
			}
		}
		//被加数较长
		while (i >= pos)
		{
			res.Digit[i] += Digit[i];
			if (res.Digit[i] >= 10)
			{
				res.Digit[i] -= 10;
				res.Digit[i - 1]++;
			}
			i--;
		}//加数较长
		while (j >= A.pos)
		{
			res.Digit[j] += A.Digit[j];
			if (res.Digit[j] >= 10)
			{
				res.Digit[j] -= 10;
				res.Digit[j - 1]++;
			}
			j--;
		}
		for (int i = 0; i < SIZE; i++)
		{
			if (res.Digit[i] != 0)
			{
				res.pos = i;
				break;
			}
		}
		return res;
	}
	void Output()
	{
		int i;
		for (i = 0; i < SIZE; i++)
		{
			if (Digit[i] != 0)
			{
				pos = i;
				break;
			}
		}
		//cout << pos << endl;
		if (i == SIZE)
		{
			pos = SIZE - 1;
		}
		for (i = pos; i < SIZE; i++)
		{
			cout << Digit[i];
		}
		cout << endl;
	}
};
string Inverse(string original)
{
	string ans = "";
	for (int i = original.length() - 1; i >= 0; i--)
	{
		ans += original[i];
	}
	return ans;
}
int main()
{
	string str;
	while (cin >> str)
	{
		BigInt n = BigInt(str);
		string binary = BigInt::ToBinary(n);
		binary = Inverse(binary);
		BigInt ans = BigInt::ToDecimal(binary);
		ans.Output();
	}
	return 0;
}