#pragma warning(disable:4996)
#include <iostream>
#include<stdio.h>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
int max(double a, double b)
{
	return a > b ? a : b;
}
int main()
{
	double limit;
	int n;
	while (cin >> limit >> n)
	{
		if (n == 0)
		{
			break;
		}
		int cnt = 0;
		vector<int> prices;
		int maxprice = limit * 100;
		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			char c;
			double price;
			double A = 0, B = 0, C = 0;
			bool canuse = true;
			for (int j = 0; j < num; j++)
			{
				scanf(" %c:%lf", &c, &price);
				if (c == 'A')
				{
					A += price;
				}
				else if (c == 'B')
				{
					B += price;
				}
				else if (c == 'C')
				{
					C += price;
				}
				else
				{
					canuse = false;
				}
			}
			double total = A + B + C;
			if (!canuse || A > 600 || B > 600 || C > 600 || total > 1000)
			{
				continue;
			}
			else
			{
				prices.push_back(total * 100);
			}
		}
		vector<int> dp(maxprice + 1);
		for (int i = 0; i < prices.size(); i++)
		{
			for (int j = maxprice; j >= prices[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - prices[i]] + prices[i]);
			}
		}
		std::cout << fixed << setprecision(2) << (double)dp[maxprice] / 100.0 << endl;
	}
	return 0;
}