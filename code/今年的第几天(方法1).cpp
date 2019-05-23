#include <iostream>
using namespace std;
#define ISLY(x)		x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0
int Month[12][2] =
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
struct Date
{
	int year;
	int month;
	int day;
	void NextDay()
	{
		day++;
		if (day > Month[month - 1][ ISLY(year) ])
		{
			month++;
			day = 1;
		}
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
};
int buff[3001][13][32];
int main()
{
	int year, month, day;
	Date date;
	date.year = 0;
	date.month = 1;
	date.day = 1;
	int cnt = 0;
	while (date.year <= 3000)
	{
		buff[date.year][date.month][date.day] = cnt;
		date.NextDay();
		cnt++;
	}
	while (cin >> year >> month >> day)
	{
		int ans = buff[year][month][day] - buff[year][1][1];
		cout << ans + 1 << endl;
	}
	return 0;
}