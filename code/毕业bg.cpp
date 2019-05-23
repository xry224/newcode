#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class bg
{
public:
	int happy;
	int length;
	int leave;
	bg(int a, int b, int c)
	{
		happy = a;
		length = b;
		leave = c;
	}
	bool operator < (const bg &A) const
	{
		return leave < A.leave;
	}
};
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int n;
	while (cin >> n && n >= 0)
	{
		vector<bg> nodes;
		int maxtime = 0;
		for (int i = 0; i < n; i++)
		{
			int h, l, t;
			cin >> h >> l >> t;
			nodes.push_back(bg(h, l, t));
			maxtime = max(maxtime, t);
		}
		sort(nodes.begin(), nodes.end());
		vector<int> dp(maxtime + 1);
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = nodes[i].leave; j >= nodes[i].length; j--)
			{
				dp[j] = max(dp[j], dp[j - nodes[i].length] + nodes[i].happy);
				ans = max(ans, dp[j]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}