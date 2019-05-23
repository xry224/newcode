#include <iostream>
using namespace std;
char map[100][100];
int shift[8][2]=
{
	0,1,
	0,-1,
	1,0,
	-1,0,
	-1,-1,
	-1,1,
	1,-1,
	1,1
};
void Fill(int x, int y, int m, int n)
{
	map[x][y] = '*';
	for (int i = 0; i < 8; i++)
	{
		int nx = x + shift[i][0];
		int ny = y + shift[i][1];
		if (nx >= 0 && ny >= 0 && nx < m && ny < n)
		{
			if (map[nx][ny] == '@')
			{
				Fill(nx, ny, m, n);
			}
		}
	}
}
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		if (m == n && n == 0)
		{
			break;
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] == '@')
				{
					ans++;
					Fill(i, j, m, n);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}