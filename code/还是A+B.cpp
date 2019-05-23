#include <iostream>
#include<math.h>
using namespace std;
int main()
{
	int a, b, k;
	while (cin >> a >> b >> k)
	{
		if (a == b && a == 0)
		{
			break;
		}
		if ((a - b) % (int)pow(10, k) == 0)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << a + b << endl;
		}		
	}
	return 0;
}