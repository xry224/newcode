#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int reverse;
	for (int i = 1000; i < 10000; i++)
	{
		int a = i % 10;
		int b = (i / 10) % 10;
		int c = (i / 100) % 10;
		int d = (i / 1000);
		reverse = d + c * 10 + b * 100 + a * 1000;
		if (reverse == i * 9)
		{
			cout << i << endl;
		}
	}
	system("pause");
	return 0;
}