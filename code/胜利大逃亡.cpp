#pragma warning(disable:4996)
#include <stdio.h>
#include <queue>
#include <string.h>
int map[50][50][50];
using namespace std;
class Node
{
public:
	int x, y, z;
	int t;
	Node(int x, int y, int z, int t)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->t = t;
	}
};
int go[6][3] = {
   1,0,0,
  -1,0,0,
   0,1,0,
   0,-1,0,
   0,0,1,
   0,0,-1
};
bool visit[50][50][50];
int BFS(int a, int b, int c)
{
	queue<Node> q;
	visit[0][0][0] = true;
	q.push(Node(0, 0, 0, 0));
	while (!q.empty())
	{
		Node start = q.front();
		q.pop();
		if (start.x == a - 1 && start.y == b - 1 && start.z == c - 1)
		{
			return start.t;
		}
		for (int i = 0; i < 6; i++)
		{
			int nx = start.x + go[i][0];
			int ny = start.y + go[i][1];
			int nz = start.z + go[i][2];
			if (nx < a && nx >= 0 && ny < b && ny >= 0 && nz < c && nz >= 0)
			{
				if (map[nx][ny][nz] == 0 && !visit[nx][ny][nz])
				{
					Node t = Node(nx, ny, nz, start.t + 1);
					visit[nx][ny][nz] = true;
					q.push(t);
				}

			}

		}
	}
	return -1;
}
int main()
{
	int K;
	scanf("%d", &K);
	while (K--)
	{
		int a, b, c, t;
		scanf("%d%d%d%d", &a, &b, &c, &t);
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				for (int k = 0; k < c; k++)
				{
					scanf("%d", &map[i][j][k]);
					visit[i][j][k] = false;
				}
			}
		}
		int ans = BFS(a, b, c);
		if (ans <= t)
		{
			printf("%d\n", ans);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}