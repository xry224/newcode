#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;
#define SIZE 505
class Node
{
public:
	int inDegree;
	int num;
	Node()
	{

	}
	bool operator < (const Node &A) const
	{
		return num > A.num;
	}
};
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		Node nodes[SIZE];
		vector <int> Edges[SIZE];
		priority_queue<Node> q;
		for (int i = 1; i <= n; i++)
		{
			nodes[i].num = i;
			nodes[i].inDegree = 0;
		}
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			nodes[b].inDegree++;
			Edges[a].push_back(b);
		}
		for (int i = 1; i <= n; i++)
		{
			if (nodes[i].inDegree == 0)
			{
				q.push(nodes[i]);
			}
		}
		int ans[SIZE];
		int cnt = 0;
		while (!q.empty())
		{
			Node t = q.top();
			q.pop();
			ans[cnt++] = t.num;
			for (int i = 0; i < Edges[t.num].size(); i++)
			{
				int tn = Edges[t.num][i];
				nodes[tn].inDegree--;
				if (nodes[tn].inDegree == 0)
				{
					q.push(nodes[tn]);
				}
			}
		}
		for (int i = 0; i < cnt - 1; i++)
		{
			cout << ans[i] << " ";
		}
		cout << ans[cnt - 1] << endl;
	}
	return 0;
}