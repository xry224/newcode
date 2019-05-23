#include <iostream>
#include <string>
using namespace std;
#define SIZE 3000
class BigFloat
{
public:
	int Integer[SIZE] = { 0 };
	int Decimal[SIZE] = { 0 };
	BigFloat(string str)
	{
		int index = str.find(".");
		for (int i = index - 1; i >= 0; i--)
		{
			int off = index - 1 - i;
			Integer[SIZE - off - 1] = str[i] - '0';
		}
		for (int i = index + 1; i < str.length(); i++)
		{
			Decimal[i - (index + 1)] = str[i] - '0';
		}
	}
	BigFloat()
	{

	}
	void Output()
	{
		int index;
		int i;
		for (i = 0; i < SIZE; i++)
		{
			if (Integer[i] != 0)
			{
				index = i;
				break;
			}
		}
		if (i == SIZE)  //整数部分全0
		{
			index = SIZE - 1;
		}
		int indexD;
		for (int j = SIZE - 1; j >= 0; j--)
		{
			if (Decimal[j] != 0)
			{
				indexD = j;
				break;
			}
		}
		for (int i = index; i < SIZE; i++)
		{
			cout << Integer[i];
		}
		cout << ".";
		for (int i = 0; i <= indexD; i++)
		{
			cout << Decimal[i];
		}
		cout << endl;
	}
	BigFloat operator + (const BigFloat &b) const
	{
		BigFloat res = BigFloat();
		bool flag = false;//是否往整数进位
		//小数部分相加
		for (int i = SIZE - 1; i >= 0; i--)
		{
			res.Decimal[i] += Decimal[i] + b.Decimal[i];
			if (res.Decimal[i] >= 10)
			{
				res.Decimal[i] -= 10;
				if (i == 0)
				{
					flag = true;
				}
				else
				{
					res.Decimal[i - 1] ++;
				}
			}
		}
		if (flag)
		{
			res.Integer[SIZE - 1]++;
		}
		//整数部分相加
		for (int i = SIZE - 1; i >= 0; i--)
		{
			res.Integer[i] += Integer[i] + b.Integer[i];
			if (res.Integer[i] >= 10)
			{
				res.Integer[i] -= 10;
				res.Integer[i - 1]++;
			}
		}
		return res;
	}
};
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		BigFloat n1 = BigFloat(a);
		BigFloat n2 = BigFloat(b);
		n1 = n1 + n2;
		n1.Output();
	}
	return 0;
}