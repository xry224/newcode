#include <iostream>
using namespace std;
int sx, sy, dx, dy;
bool flag;
char map[8][8];
int r, c, t;
int go[4][2] = 
{
	0,1,
	0,-1,
	1,0,
	-1,0
}; 
void DFS(int x, int y, int time)
{
	if (flag)
	{
		return;
	}
	if (time >= t)
	{
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = go[i][0] + x;
		int ny = go[i][1] + y;
		if (nx >= 0 && ny >= 0 && nx < r && ny < c)
		{
			if (map[nx][ny] != 'X')
			{
				if (map[nx][ny] == 'D')
				{
					if (time + 1 == t)
					{
						flag = true;
						return;
					}
					else
					{
						//continue;
					}
				}
				map[nx][ny] = 'X';
				DFS(nx, ny, time + 1);
				map[nx][ny] = '.';
			}
		}
	}
}
int main()
{
	while (cin >> r >> c >> t)
	{
		if (r == c && c == t && t == 0)
		{
			break;
		}
		flag = false;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 'S')
				{
					sx = i;
					sy = j;
				}
				if (map[i][j] == 'D')
				{
					dx = i;
					dy = j;
				}
			}
		}
		map[sx][sy] = 'X';
		if ((sx + sy) % 2 == ((dx + dy) % 2 + t % 2) % 2)
		{
			DFS(sx, sy, 0);
		}
		
		if (flag)
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