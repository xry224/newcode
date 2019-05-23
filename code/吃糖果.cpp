//解题同楼梯问题
#include <iostream>
using namespace std;
long long ans[21];
int main()
{
	ans[1] = 1;
	ans[2] = 2;
	for (int i = 3; i <= 20; i++)
	{
		ans[i] = ans[i - 1] + ans[i - 2];
	}
	int n;
	while (cin >> n)
	{
		cout << ans[n] << endl;
	}
	return 0;
}