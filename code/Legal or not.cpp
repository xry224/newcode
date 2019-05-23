#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define SIZE 501
vector<int> Edges[SIZE];
queue<int> q;
void Ini()
{
	while (!q.empty())
	{
		q.pop();
	}
	for (int i = 0; i < SIZE; i++)
	{
		Edges[i].clear();
	}
}
int main()
{

	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		Ini();	
		int inDegree[SIZE] = { 0 };
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			inDegree[b]++;
			Edges[a].push_back(b);
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (inDegree[i] == 0)
			{
				q.push(i);
			}
		}
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			cnt++;
			for (int i = 0; i < Edges[node].size(); i++)
			{
				int t = Edges[node][i];
				inDegree[t]--;
				if (inDegree[t] == 0)
				{
					q.push(t);
				}
			}
		}
		if (cnt == n)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
