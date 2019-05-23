#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> money(n);
		for (int i = 0; i < n; i++)
		{
			cin >> money[i];
		}
		sort(money.begin(), money.end(), greater<int>());
		for (int i = 0; i < money.size() && i < m; i++)
		{
			cout << money[i] << " ";
		}
		cout << endl;
	}
	return 0;
}