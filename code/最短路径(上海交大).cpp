#include <iostream>
#include <string>
using namespace std;
#define SIZE 400
#define CSIZE 100
string INF = "";
class BigInt
{
public:
	int Digit[SIZE] = { 0 };
	int cur;
	BigInt(string ori)
	{
		int length = ori.length();
		for (int i = length - 1; i >= 0; i--)
		{
			int off = length - i - 1;
			Digit[SIZE - off - 1] = ori[i] - '0';
		}
		cur = SIZE - ori.length();
	}
	BigInt()
	{
		cur = SIZE;
	}
	BigInt operator * (int x) const
	{
		BigInt res = BigInt();
		for (int i = SIZE - 1; i >= cur; i--)
		{
			int t = Digit[i] * x;
			string n = to_string(t);
			for (int j = n.length() - 1; j >= 0; j--)
			{
				int off = n.length() - 1 - j;
				res.Digit[i - off] += n[j] - '0';
				if (res.Digit[i - off] >= 10)
				{
					res.Digit[i - off] -= 10;
					res.Digit[i - off - 1]++;
				}
			}
		}
		for (int i = 0; i < SIZE; i++)
		{
			if (res.Digit[i] != 0)
			{
				res.cur = i;
				break;
			}
		}
		//res.Output();
		return res;
	}
	int operator % (int x) const
	{
		int r = 0;
		for (int i = cur; i < SIZE; i++)
		{
			int t = (r * 10 + Digit[i]);
			r = t % x;
		}
		return r;
	}
	BigInt operator + (const BigInt &A) const
	{
		BigInt res = BigInt();
		int i, j;
		for (i = SIZE - 1, j = SIZE - 1; i >= cur && j >= A.cur; i--, j--)
		{
			res.Digit[i] += Digit[i] + A.Digit[j];
			if (res.Digit[i] >= 10)
			{
				res.Digit[i] -= 10;
				res.Digit[i - 1]++;
			}
		}
		//被加数较长
		while (i >= cur)
		{
			res.Digit[i] += Digit[i];
			if (res.Digit[i] >= 10)
			{
				res.Digit[i] -= 10;
				res.Digit[i - 1]++;
			}
			i--;
		}//加数较长
		while (j >= A.cur)
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
				res.cur = i;
				break;
			}
		}
		return res;
	}
	bool operator == (const BigInt &A) const
	{
		if (cur != A.cur)
		{
			return false;
		}
		for (int i = cur; i < SIZE; i++)
		{
			if (Digit[i] != A.Digit[i])
			{
				return false;
			}
		}
		return true;
	}
	bool operator > (const BigInt &A) const
	{
		if (cur < A.cur)
		{
			return true;
		}
		else if (cur > A.cur)
		{
			return false;
		}
		else
		{
			for (int i = cur; i < SIZE; i++)
			{
				if (Digit[i] > A.Digit[i])
				{
					return true;
				}
				else if (Digit[i] == A.Digit[i])
				{
					continue;
				}
				else
				{
					return false;
				}
			}
		}
		return false;
	}
	void Output()
	{
		int i;
		for (i = 0; i < SIZE; i++)
		{
			if (Digit[i] != 0)
			{
				cur = i;
				break;
			}
		}
		//cout << cur << endl;
		if (i == SIZE)
		{
			cur = SIZE - 1;
		}
		for (i = cur; i < SIZE; i++)
		{
			cout << Digit[i];
		}
		cout << endl;
	}
	string ToString()
	{
		string res = "";
		for (int i = 0; i < SIZE; i++)
		{
			if (Digit[i] != 0)
			{
				cur = i;
				break;
			}
		}
		for (int i = cur; i < SIZE; i++)
		{
			res += (Digit[i] + '0');
		}
		if (res == "")
		{
			return "0";
		}
		return res;
	}
};
BigInt Edge[CSIZE][CSIZE];
void Initialize()
{
	for (int i = 0; i < CSIZE; i++)
	{
		for (int j = 0; j < CSIZE; j++)
		{
			Edge[i][j] = BigInt(INF);
		}
	}
}
void Check(int n)
{
	for (int i = 0; i < n/2; i++)
	{
		for (int j = 0; j < n/2; j++)
		{
			cout << i << " " << j << " ";
			Edge[i][j].Output();
		}
	}
}
void calINF()
{
	for (int i = 0; i < 160; i++)
	{
		INF += "9";
	}
}
int main()
{
	int n, m;
	calINF();
	while (cin >> n >> m)
	{
		BigInt base = BigInt("1");
		Initialize();
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			if (Edge[a][b] > base)
			{
				Edge[a][b] = base;
				Edge[b][a] = base;
			}
			//cout << base.ToString() << endl;
			base = base * 2;
		}
		//Check(n);
		BigInt t = BigInt("0");
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (Edge[i][k] == t || Edge[k][j] == t)
					{
						continue;
					}
					if (Edge[i][j] == t || (Edge[i][j] > Edge[i][k] + Edge[k][j]))
					{
						Edge[i][j] = Edge[i][k] + Edge[k][j];
					}
				}
			}
		}
		for (int i = 1; i < n; i++)
		{
			cout << Edge[0][i] % 100000 << endl;
		}
	}
	return 0;
}