#pragma warning(disable:4996)
#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
class Record
{
public:
	string id;
	int signin;
	int signout;
};
bool cmpin(Record A, Record B)
{
	return A.signin < B.signin;
}
bool cmpout(Record A, Record B)
{
	return A.signout > B.signout;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<Record> people(n);
		for (int i = 0; i < n; i++)
		{
			string id;
			int hour, minute, second;
			cin >> id;
			scanf("%d:%d:%d", &hour, &minute, &second);
			people[i].id = id;
			people[i].signin = second + minute * 60 + hour * 60 * 60;

			scanf("%d:%d:%d", &hour, &minute, &second);
			people[i].signout = second + minute * 60 + hour * 60 * 60;
		}
		sort(people.begin(), people.end(), cmpin);
		cout << people[0].id << " ";
		sort(people.begin(), people.end(), cmpout);
		cout << people[0].id << endl;

	}
	return 0;
}