#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
bool visit[7];
char backup[7];
void Solve(int len, string cur)
{
	if (cur.length() == len)
	{
		cout << cur << endl;
		return;
	}
	for (int i = 0; i < len; i++)
	{
		if (!visit[i])
		{
			string t = cur;
			t += backup[i];
			visit[i] = true;
			Solve(len, t);
			visit[i] = false;
			
		}
	}
}
int main()
{
	string str;
	while (cin >> str)
	{
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < str.length(); i++)
		{
			backup[i] = str[i];
		}
		sort(backup, backup + str.length());
		string start = "";
		Solve(str.length(), start);
		cout << endl;
	}
	return 0;
}