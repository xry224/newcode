#include <iostream>
#include <string>
using namespace std;
string LeadZero(string num)
{
	int index = 0;
	bool flag = false;
	for (int i = 0; i < num.length(); i++)
	{
		if (num[i] != '0')
		{
			flag = true;
			index = i;
			break;
		}
	}
	if (!flag)
	{
		return "0";
	}
	return num.substr(index, num.length() - index);
}
string Divide2(string num)
{
	string ans;
	int left = 0;
	for (int i = 0; i < num.length(); i++)
	{
		int now = num[i] - '0' + left * 10;
		if (now >= 2)
		{
			ans += (now / 2 + '0');
			left = now % 2;
		}
		else
		{
			ans += '0';
			left = now;
		}
	}
	return LeadZero(ans);
}
int main()
{
	string num;
	while (cin >> num)
	{
		string ans = "";
		num = LeadZero(num);
		if (num == "0")
		{
			cout << "0" << endl;
			continue;
		}
		while (num != "0" && num.length() > 0)
		{
			int t = (num[num.length() - 1] - '0') % 2;
			ans += (t + '0');
			num = Divide2(num);
		}
		for (int i = ans.length() - 1; i >= 0; i--)
		{
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}