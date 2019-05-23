#include <iostream>
using namespace std;
int main()
{
	int n;
	int num[80];
	while (cin >> n)
	{
		int ans[80];
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
		}
		if (num[0] != num[1])
		{
			ans[cnt++] = 0;
		}
		for (int i = 1; i < n - 1; i++)
		{
			if ((num[i] > num[i - 1] && num[i] > num[i + 1]) || (num[i] < num[i - 1] && num[i] < num[i + 1]))
			{
				ans[cnt++] = i;
			}
		}
		if (num[n - 1] != num[n - 2])
		{
			ans[cnt++] = n - 1;
		}
		for (int i = 0; i < cnt - 1; i++)
		{
			cout << ans[i] << " ";
		}
		cout << ans[cnt - 1] << endl;
	}
}