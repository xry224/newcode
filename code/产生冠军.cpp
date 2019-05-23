#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define SIZE 2100
using namespace std;
int cnt = 1; //—° ÷±‡∫≈¿Î…¢ªØ
queue<int> q;
int number = 0;
void Ini()
{
	while (!q.empty())
	{
		q.pop();
	}
	cnt = 1;
	number = 0;
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		Ini();
		int inDegree[SIZE] = { 0 };
		map<string, int> name2id;
		for (int i = 0; i < n; i++)
		{
			string a, b;
			cin >> a >> b;
			if (name2id[a] == 0)
			{
				number++;
				name2id[a] = cnt++;
			}
			if (name2id[b] == 0)
			{
				number++;
				name2id[b] = cnt++;
			}
			int n1 = name2id[a];
			int n2 = name2id[b];
			inDegree[n2]++;
		}
		int flag = 0;
		for (int i = 1; i <= number; i++)
		{
			if (inDegree[i] == 0)
			{
				flag++;
			
			}
		}

		if ( flag == 1)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}