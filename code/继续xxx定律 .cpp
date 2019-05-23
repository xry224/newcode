#include <iostream>
#include <vector>
#define N 505;
#define MAX 100000
using namespace std;
int getNum(int x)
{
	if (x % 2 == 0)
	{
		return x / 2;
	}
	return (3 * x + 1) / 2;
}
int main()
{
	int n;
	while (cin >> n && n!=0)
	{
		vector<int> cover(MAX);
		vector<int> ans;
		for (int i = 0; i < n; i++)
		{
			int t;
			cin >> t;
			ans.push_back(t);
			if (cover[t] == 0)
			{
				int temp = t;
				while (temp != 1)
				{
					temp = getNum(temp);
					cover[temp]++;
				}
			}
		}
		for (int i = ans.size() - 1; i >= 0; i--)
		{
			if (cover[ans[i]] == 0)
			{
				cout << ans[i];
				if (i != 0)
				{
					cout << " ";
				}
			}

		}
		cout << endl;
	}
	return 0;
}