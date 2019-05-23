#include <iostream>
using namespace std;
int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		while (x != y)
		{
			if (x < y)
			{
				y = y / 2;
			}
			else
			{
				x = x / 2;
			}
		}
		cout << x << endl;
	}
}