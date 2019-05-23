#include <iostream>
using namespace std;
int A[20], B[20];
int alen, blen;
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		alen = blen = 0;
		int ta = a;
		int tb = b;
		while (ta > 0)
		{
			A[alen++] = ta % 10;
			ta /= 10;
		}
		while (tb > 0)
		{
			B[blen++] = tb % 10;
			tb /= 10;
		}
		int ans = 0;
		for (int i = 0; i < alen; i++)
		{
			for (int j = 0; j < blen; j++)
			{
				ans += A[i] * B[j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}