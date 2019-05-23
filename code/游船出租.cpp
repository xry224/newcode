#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <math.h>
using namespace std;
class Ship
{
public:
	int id;
	bool pair;
	int intime;
	int outtime;
	Ship()
	{
		pair = false;
		intime = outtime = -1;
		id = -1;
	}
};
int main()
{
	int id;
	char key;
	int hour, minute;
	vector<Ship> ships(105);
	int cnt = 0;
	int time = 0;
	while (cin >> id && id!=-1)
	{
		cin >> key;
		scanf("%d:%d", &hour, &minute);
		if (id == 0)
		{
			if (cnt == 0)
			{
				cout << 0 << " " << 0 << endl;
			}
			else
			{
				cout << cnt << " " << (int)((double)time / (double)cnt + 0.5) << endl;
			}
			ships.clear();
			ships = vector<Ship>(105);
			cnt = 0;
			time = 0;
			continue;
		}
		if (key == 'S')
		{
			ships[id].intime = minute + hour * 60;
		}
		else
		{
			if (ships[id].intime != -1)
			{
				cnt++;
				time += hour * 60 + minute - ships[id].intime;
			}
		}

	}
	return 0;
}