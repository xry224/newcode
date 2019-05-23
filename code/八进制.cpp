#include <iostream>
#include <string>
using namespace std;
string Convert2O(int num)
{
	string res = "";
	do
	{
		int t = num % 8;
		res += (t + '0');
		num /= 8;
	} while (num > 0);
	return res;
}
int main()
{
	int n;
	while (cin >> n)
	{
		string ans = Convert2O(n);
		for (int i = ans.length() - 1; i >= 0; i--)
		{
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}