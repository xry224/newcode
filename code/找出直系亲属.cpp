#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int Tree[30];
void Ini()
{
	for (int i = 0; i < 30; i++)
	{
		Tree[i] = -1;
	}
}
int find(int first, int second)
{
	int cnt = 0;
	bool match = false;
	while (Tree[first] >= 0)
	{
		if (Tree[first] == second)
		{
			cnt++;
			match = true;
			break;
		}
		cnt++;
		first = Tree[first];
	}
	if (match)
	{
		return cnt;
	}
	return 0;
}
void print(int level, bool senior)
{
	for (int i = 3; i <= level; i++)
	{
		cout << "great-";
	}
	if (level >= 2)
	{
		cout << "grand";
	}
	if (senior)
	{
		cout << "parent";
	}
	else
	{
		cout << "child";
	}
	cout << endl;
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		Ini();
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			int child = str[0] - 'A';
			char par1 = str[1];
			char par2 = str[2];
			if (par1 != '-')
			{
				int t = par1 - 'A';
				Tree[t] = child;
			}
			if (par2 != '-')
			{
				int t = par2 - 'A';
				Tree[t] = child;
			}
		}
		for (int i = 0; i < m; i++)
		{
			string str;
			cin >> str;
			int member1 = str[0] - 'A';
			int member2 = str[1] - 'A';
			int res;
			res = find(member1, member2);
			if (res == 0)
			{
				res = find(member2, member1);
				if (res == 0)
				{
					cout << "-" << endl;
				}
				else
				{
					print(res, false);
				}
			}
			else
			{
				print(res, true);
			}
		}
	}
	return 0;
}