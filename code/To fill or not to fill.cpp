#include <iostream>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <float.h>
using namespace std;
#define MAX DBL_MAX
struct Node
{
	double price;
	double dis; 
}station[501];
bool cmp(Node a, Node b)
{
	if (a.dis==b.dis)
	{
		return a.price < b.price;
	}
	return a.dis < b. dis;
}
void checkStation(int N)
{
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		cout << station[i].dis << " " << station[i].price << endl;
	}
}
int main()
{
	double cap;  //邮箱容量
	double D; //总距离
	double Davg;//每单位油可前进距离
	int N; //加油站总数
	double leftoil; //邮箱剩余油量
	double curdis; //当前已走距离
	double cost; //当前消耗钱
	double maxlen; //满油能走的最大距离
	while (cin >> cap >> D >> Davg >> N)
	{
		bool flag = false;
		curdis = 0;
		leftoil = 0;
		cost = 0;
		maxlen = cap * Davg;
		double curprice = 1000; //当前最便宜油价
		for (int i = 0; i < N; i++)
		{
			cin >> station[i].price >> station[i].dis;
			if (station[i].dis == 0)
			{
				flag = true;
			}
		}
		//将终点设为油价为0，距离为D的加油站
		station[N].price = 0;
		station[N].dis = D;
		if (flag)
		{
			sort(station, station + N, cmp);
			//checkStation(N);
			//int index = 0; //记录之前选中的加油站
			int curindex = 0; //当前选用的最远加油站
			curprice = station[0].price;
			while (curdis < D)
			{
				double curmax = curdis + maxlen;//当前能走到的最远距离
				//cout << cost <<" "<<curdis<< endl;
				double min = MAX;
				bool findbetter = false;
				for (int i = curindex; i <= N; i++)
				{
					if (station[i].dis > curmax)
					{
						break;
					}
					if (station[i].dis == curdis)
					{
						continue;
					}
					if (station[i].price < curprice)
					{
						curindex = i;
						cost += curprice * ((station[curindex].dis - curdis) / Davg - leftoil);
						curdis = station[curindex].dis;
						curprice = station[i].price;
						leftoil = 0;
						findbetter = true;
						break;
					}
					if (station[i].price < min)
					{
						min = station[i].price;
						curindex = i;
					}
				}

				if (!findbetter) //没有比当前更便宜的
				{
					if (min == MAX) //最大距离内没有加油站
					{
						curdis = curmax;
						flag = false;
						break;
					}
					else   //把油加满，跑至下一个加油站
					{
						cost += curprice * (cap - leftoil);
						curprice = station[curindex].price;
						leftoil = cap - (station[curindex].dis - curdis) / Davg;
						curdis = station[curindex].dis;
					}
				}
			}
		}
		
		//起点没加油站
		if (!flag)
		{
			cout << fixed << setprecision(2) << "The maximum travel distance = " << curdis << endl;
		}
		else
		{
			cout << fixed << setprecision(2) << cost << endl;
		}

	}
	return 0;
}