#include <iostream>
#include <vector>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		vector<int> numbers(n);
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			cin >> numbers[i];
			if (numbers[i] >= 0)
			{
				flag = true;
			}
		}
		if (!flag)
		{
			cout << 0 << " " << numbers[0] << " " << numbers[n - 1] << endl;
			continue;
		}
		int ans = numbers[0];
		vector<int> dp(n + 1);
		dp[0] = numbers[0];
		int last = numbers[0];
		int first = numbers[0];
		int cur = numbers[0];
		for (int i = 1; i < n; i++)
		{
			dp[i] = max(numbers[i], dp[i - 1] + numbers[i]);
			if (dp[i] == numbers[i])
			{
				cur = numbers[i];
			}
			if (ans < dp[i])
			{
				ans = dp[i];
				last = numbers[i];
				if (cur != first)
				{
					first = cur;
				}
			}
		}
		cout << ans << " " << first << " " << last << endl;
	}
	return 0;
}