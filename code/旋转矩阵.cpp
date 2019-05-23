#include<iostream>
#include <vector>
using namespace std;
int matrix1[10][10];
int matrix2[10][10];
void turn90(int n)
{
	int res[10][10];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int off = n - j;
			res[i][j] = matrix1[off][i + 1];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix1[i + 1][j + 1] = res[i][j];
		}
	}
}
bool check(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (matrix1[i][j] != matrix2[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
void output(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << matrix1[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> matrix1[i][j];
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> matrix2[i][j];
			}
		}
		int angle = 0;
		bool flag = false;
		while (angle <= 270)
		{
			if (check(n))
			{
				flag = true;
				break;
			}
			turn90(n);
			//output(n);
			angle += 90;
		}
		if (flag)
		{
			cout << angle << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}