#include <iostream>
#include<algorithm>
#include <string>
using namespace std;
struct student
{
	string sid;
	string name;
	int score;
}S[100000];
bool cmp1(student a, student b)
{
	return a.sid < b.sid;
}

bool cmp2(student a, student b)
{
	if (a.name == b.name)
	{
		return a.sid < b.sid;
	}
	return a.name < b.name;
}

bool cmp3(student a, student b)
{
	if (a.score == b.score)
	{
		return a.sid < b.sid;
	}
	return a.score < b.score;
}

int main()
{
	int n, c;
	while (cin >> n >> c)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> S[i].sid >> S[i].name >> S[i].score;
		}

		switch (c)
		{
		case 1:
		{
			sort(S, S + n, cmp1);
			break;
		}
		case 2:
		{
			sort(S, S + n, cmp2);
			break;
		}
		case 3:
		{
			sort(S, S + n, cmp3);
			break;
		}
		}
		cout << "Case:" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << S[i].sid << " " << S[i].name << " " << S[i].score << endl;
		}

	}
}