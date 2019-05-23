#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int L, N;
	int blocks[600];
	
	while (cin >> L >> N)
	{
		int sum = 0;
		for (int i = 0 ; i < N ; i ++)
		{
			cin >> blocks[i];
			sum+=blocks[i];
		}
		if (sum < L)
		{
			cout << "impossible" << endl;
			continue;
		}
		int t = L;
		int ans = 0;
		sort(blocks, blocks+N, cmp);
		for (int i = 0; i < N ; i++)
		{
			L -= blocks[i];
			ans++;
			if (L <= 0)
			{
				break;
			}
		}
		cout << ans << endl;

	}
	return 0;
}