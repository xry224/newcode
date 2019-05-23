#include <iostream>
using namespace std;
long long ans[36] = { 0 };
long long Hanno(int num)
{
	if (ans[num] == 0)
	{
		ans[num] = 3 * Hanno(num - 1) + 2;
	}
	return ans[num];
}
int main()
{
	int n;
	ans[1] = 2;
	Hanno(35);
	while (cin >> n)
	{
		cout << ans[n] << endl;
	}
}