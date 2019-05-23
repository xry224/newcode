#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		int step = 0;
		while (n != 1)
		{
			if (n % 2 == 0)
			{
				n /= 2;
			}
			else
			{
				n = 3 * n + 1;
				n /= 2;
			}
			step++;
		}
		cout << step << endl;
	}
	return 0;
}