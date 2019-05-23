#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define SIZE 1005
class BigInt
{
public:
	string ori;
	int Digit[1005] = { 0 };
	int pos;
	BigInt(string str)
	{
		ori = str;
		for (int i = str.length() - 1; i >= 0; i--)
		{
			int off = (str.length() - 1) - i;
			Digit[SIZE - 1 - off] = str[i] - '0';
		}
		pos = SIZE - str.length();
	}
	BigInt()
	{
		ori = "";
		pos = SIZE - 1;
	}
	bool operator < (const BigInt &A) const
	{
		//长度大的更大
		if (ori.length() < A.ori.length())
		{
			return true;
		}
		else if (ori.length() > A.ori.length())
		{
			return false;
		}
		
		int i;
		//长度相同的情况
		for (i = pos; i < SIZE; i++)
		{
			if (Digit[i] < A.Digit[i])
			{
				return true;
			}
			else if (Digit[i] > A.Digit[i])
			{
				return false;
			}
			else
			{
				//两者相等
				if (i == SIZE - 1)
				{
					return false;
				}
				continue;
			}
		}
		return false;
	}
	void Output()
	{
		for (int i = pos; i < SIZE; i++)
		{
			cout << Digit[i];
		}
		cout << endl;
	}
};
int main()
{
	int n;
	BigInt num[100];
	while (cin >> n)
	{
		string t;
		for (int i = 0; i < n; i++)
		{
			cin >> t;
			num[i] = BigInt(t);
		}
		sort(num, num + n);
		for (int i = 0; i < n; i++)
		{
			num[i].Output();
		}
	}
	return 0;
}