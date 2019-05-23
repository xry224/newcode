#include <iostream>
#include <string>
using namespace std;
#define ISLY(x) x % 4 == 0 && x % 100 != 0 || x % 400 == 0 ? 1 : 0
int Month[12][2]
{
	31 ,31,
	28, 29,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31
};

int main()
{
	int year;
	int month;
	//int day;
	int days;
	while (cin >> year >> days)
	{
		month = 1;
		for (int i = 1; i <= 12; i++)
		{
			if (days > Month[i - 1][ISLY(year)])
			{
				month++;
				days -= Month[i - 1][ISLY(year)];

			}
			else
			{
				break;
			}
		}
		cout << year << "-";
		if (month < 10)
		{
			cout << "0" << month << "-";
		}
		else
		{
			cout << month << "-";
		}

		if (days < 10)
		{
			cout << "0" << days << endl;
		}
		else
		{
			cout << days << endl;
		}
	}

	return 0;
}