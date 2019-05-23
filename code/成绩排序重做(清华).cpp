#include <iostream>
#include <string>
#include <algorithm>
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
	Record()
	{
		name = "";
		score = 0;
	}
}List[500];
//½µÐò
bool cmp1(Record r1, Record r2)
{
	return r1.score > r2.score;
}
//ÉýÐò
bool cmp2(Record r1, Record r2)
{
	return r1.score < r2.score;
}
int main()
{
	int n, method;
	while (cin >> n >> method)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> List[i].name >> List[i].score;
		}
		if (method == 0)  //½µÐò
		{
			stable_sort(List, List + n, cmp1);
		}
		else
		{
			stable_sort(List, List + n, cmp2);
		}
		for (int i = 0; i < n; i++)
		{
			cout << List[i].name << " " << List[i].score << endl;
		}
	}
	return 0;
}
