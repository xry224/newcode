#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class State
{
public:
	int id;
	int gold;
	int medal;
	int people;
	int bestrank;
	int bestway;
	int trank;
	double rateG;
	double rateM;
	State()
	{

	}
};
bool cmpglod(State a, State b)
{
	return a.gold > b.gold;
}
bool cmpmedal(State a, State b)
{
	return a.medal > b.medal;
}
bool cmpproportion(State a, State b)
{
	return a.rateM > b.rateM;
}
bool cmpproportiong(State a, State b)
{
	return a.rateG > b.rateG;
}
bool cmp(State a, State b)
{
	return a.id < b.id;
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<State> states(n);
		for (int i = 0; i < n; i++)
		{
			states[i].id = i;
			cin >> states[i].gold >> states[i].medal >> states[i].people;
			states[i].rateG = states[i].gold * 1.0 / (1.0 * states[i].people);
			states[i].rateM = states[i].medal * 1.0 / (1.0 * states[i].people);
		}
		vector<int> counted(m);
		for (int i = 0; i < m; i++)
		{
			cin >> counted[i];
		}
		sort(states.begin(), states.end(), cmpglod);
		states[0].bestrank = 1;
		states[0].bestway = 1;
		for (int i = 1; i < states.size(); i++)
		{
			if (states[i].gold == states[i - 1].gold)
			{
				states[i].bestrank = states[i - 1].bestrank;
			}
			else
			{
				states[i].bestrank = i + 1;
			}
			states[i].bestway = 1;
		}

		sort(states.begin(), states.end(), cmpmedal);
		if (states[0].bestrank > 1)
		{
			states[0].bestrank = 1;
			states[0].bestway = 2;
		}
		states[0].trank = 1;
		for (int i = 1; i < states.size(); i++)
		{
			int trank;
			if (states[i].medal == states[i - 1].medal)
			{
				states[i].trank = states[i - 1].trank;
			}
			else
			{
				states[i].trank = i + 1;
			}
			if (states[i].trank < states[i].bestrank)
			{
				states[i].bestrank = states[i].trank;
				states[i].bestway = 2;
			}
		}

		sort(states.begin(), states.end(), cmpproportiong);
		if (states[0].bestrank > 1)
		{
			states[0].bestrank = 1;
			states[0].bestway = 3;
		}
		states[0].trank = 1;
		for (int i = 1; i < states.size(); i++)
		{
			int trank;
			if (states[i].rateG == states[i - 1].rateG)
			{
				states[i].trank = states[i - 1].trank;
			}
			else
			{
				states[i].trank = i + 1;
			}
			if (states[i].trank < states[i].bestrank)
			{
				states[i].bestrank = states[i].trank;
				states[i].bestway = 3;
			}
		}

		sort(states.begin(), states.end(), cmpproportion);
		if (states[0].bestrank > 1)
		{
			states[0].bestrank = 1;
			states[0].bestway = 4;
		}
		states[0].trank = 1;
		for (int i = 1; i < states.size(); i++)
		{
			int trank;
			if (states[i].rateM == states[i - 1].rateM)
			{
				states[i].trank = states[i - 1].trank;
			}
			else
			{
				states[i].trank = i + 1;
			}
			if (states[i].trank < states[i].bestrank)
			{
				states[i].bestrank = states[i].trank;
				states[i].bestway = 4;
			}
		}
		sort(states.begin(), states.end(), cmp);
		for (int i = 0; i < m; i++)
		{
			int id = counted[i];
			cout << states[id].bestrank << ":" << states[id].bestway << endl;
		}
		cout << endl;
	}
	return 0;
}