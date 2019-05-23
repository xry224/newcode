#include <iostream>
using namespace std;
int main()
{
	int like[201] = { 0 };
	int book[201] = { 0 };
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> like[i];
			book[like[i]]++;
		}
		for (int i = 1; i <= n; i++)
		{
			if (book[like[i]] > 1)
			{
				cout << book[like[i]] - 1 << endl;
			}
			else
			{
				cout << "BeiJu" << endl;
			}
		}

	}
	return 0;
}