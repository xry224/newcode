#include <iostream>
#include <string>
#include <queue>
#include <functional>
using namespace std;
class Record
{
public:
	string name;
	int score;
	Record(string name, int score)
	{
		this->name = name;
		this->score = score;
	}
	bool operator < (const Record &rec) const
	{
		return this->score < rec.score;
	}
	bool operator > (const Record &rec) const
	{
		return this->score > rec.score;
	}
};
//²»Ã÷´íÎó
int main()
{
	int n, way;		
	priority_queue<Record, vector<Record>, greater<Record> > q1;
	priority_queue<Record, vector<Record>, less<Record> > q2;
	while (cin >> n >> way)
	{
		for (int i = 0; i < n; i++)
		{
			string name;
			int s;
			cin >> name >> s;
			Record r = Record(name, s);
			if (way == 0)
			{
				q2.push(r);
			}
			else
			{
				q1.push(r);
			}

		}
		while (!q1.empty())
		{
			Record r = q1.top();
			q1.pop();
			cout << r.name << " " << r.score << endl;
		}
		while (!q2.empty())
		{
			Record r = q2.top();
			q2.pop();
			cout << r.name << " " << r.score << endl;
		}

	}
	return 0;
}