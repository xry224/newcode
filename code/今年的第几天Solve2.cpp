#include <iostream>
using namespace std;
#define ISLY(x) x % 4 == 0 && x % 100 != 0 || x % 400 == 0 ? 1 : 0
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

int main()
{
	int year;
	int month;
	int day;
	while (cin >> year >> month >> day)
	{
		int ans = 0;
		for (int i = 1; i < month; i++)
		{
			ans += Month[i - 1][ ISLY(year) ];
		}
		ans += day;
		cout << ans << endl;
	}
}