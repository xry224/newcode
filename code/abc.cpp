#include <iostream>
using namespace std;
int main()
{
	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= 9; k++)
			{
				int t1 = i * 100 + j * 10 + k;
				int t2 = j * 100 + k * 10 + k;
				if (t1 + t2 == 532)
				{
					cout << i << " " << j << " " << k << endl;
				}
			}
		}
	}
	return 0;
}