#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define SIZE 300
int cnt = 0;
int isPrime[SIZE] = { 0 };
int prime[SIZE];
void Prime()
{
	isPrime[0] = isPrime[1] = 1;
	for (int i = 2; i < SIZE; i++)
	{
		if (isPrime[i] == 0)
		{
			prime[cnt++] = i;
		}
		for (int j = 0; j < cnt && i * prime[j] < SIZE; j++)
		{
			isPrime[i * prime[j]]++;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
class Number
{
public:
	int Digit[30] = { 0 };
	int pos;
	Number(string str)
	{
		string t = "";
		int curpos = 29;
		for (int i = str.length() - 1; i >= 0; i--)
		{
			if (str[i] == ',')
			{
				reverse(t.begin(), t.end());
				Digit[curpos--] = atoi(t.c_str());
				t = "";
			}
			t += str[i];
		}
		reverse(t.begin(), t.end());
		Digit[curpos--] = atoi(t.c_str());
		pos = curpos;
		//cout << pos << endl;
	}
	Number()
	{
		pos = 29;
	}
	Number operator + (const Number &A) const
	{
		Number t;
		int i = 29, j = 29;
		int k = 29;
		for (; i >= pos && j >= A.pos; i--, j--)
		{
			int off = 29 - k;
			t.Digit[k] += Digit[i] + A.Digit[j];
			if (t.Digit[k] >= prime[off])
			{
				t.Digit[k] -= prime[off];
				t.Digit[k - 1]++;
			}
			k--;
		}
		while (i >= pos)
		{
			int off = 29 - k;
			t.Digit[k] += Digit[i];
			if (t.Digit[k] >= prime[off])
			{
				t.Digit[k] -= prime[off];
				t.Digit[k - 1]++;
			}
			i--;
			k--;
		}
		while (j >= A.pos)
		{
			int off = 29 - k;
			t.Digit[k] += A.Digit[j];
			if (t.Digit[k] >= prime[off])
			{
				t.Digit[k] -= prime[off];
				t.Digit[k - 1]++;
			}
			j--;
			k--;
		}
		for (int i = 0; i < 30; i++)
		{
			if (t.Digit[i] != 0)
			{
				t.pos = i;
				break;
			}
		}
		return t;
	}
	void Output()
	{
		for (int i = pos; i < 30; i++)
		{
			cout << Digit[i];
			if (i != 29)
			{
				cout << ",";
			}
		}
		cout << endl;
	}
};
int main()
{
	string n1, n2;
	Prime();
	while (cin >> n1 >> n2)
	{
		if (n1 == "0" || n2 == "0")
		{
			break;
		}
		Number num1 = Number(n1);
		Number num2 = Number(n2);
		Number ans = num1 + num2;
		ans.Output();
	}
	return 0;
}