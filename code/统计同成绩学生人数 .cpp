#include <iostream>
#include<map>
using namespace std;
int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		map<int, int> count;
		for (int i = 0; i < n; i++)
		{
			int t;
			cin >> t;
			count[t]++;
		}
		int t;
		cin >> t;
		cout << count[t] << endl;
	}
	return 0;
}