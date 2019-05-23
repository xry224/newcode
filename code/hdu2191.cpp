#include <iostream>
using namespace std;
class Rice
{
public:
	int v;
	int w;
	Rice()
	{

	}
};
Rice r[2001];

int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int dp[101] = { 0 };
		int cnt = 0;
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= m; i++)
		{
			int val, wei, num;
			cin >> wei >> val >> num;
			int c = 1;
			while (num - c > 0)
			{
				num -= c;
				r[++cnt].v = c * val;
				r[cnt].w = c * wei;
				c *= 2;
			}
			r[++cnt].v = num * val;
			r[cnt].w = num * wei;
		}
		for (int i = 1; i <= cnt; i++)
		{
			for (int j = n; j >= r[i].w; j--)
			{
				dp[j] = max(dp[j], dp[j - r[i].w] + r[i].v);
				//cout << dp[j] << endl;
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}