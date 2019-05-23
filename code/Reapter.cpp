#include <iostream>
#include <string>
#include <string.h> 
using namespace std;
//尝试使用自定义数据结构
char res[3001][3001];
char basic[5][5];
void dupli(int x, int y, int size, char (*temp)[1001])
{

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			res[i + x][j + y] = temp[i][j];
		}
	}	
	//system("pause");
}
void check(int x, int y, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			res[i + x][j + y] = ' ';
		}
	}
}
void repeat(int n, int size, char (*temp)[1001])
{
	int nsize = size * n;
	int offx = 0;
	int offy = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{				
			offx = i * size;
			offy = j * size;
			if (basic[i][j] != ' ')
			{
				dupli(offx, offy, size, temp);
			}
			else
			{
				check(offx, offy, size);
			}

		}
	}
	for (int i = 0; i < nsize; i++)
	{
		for (int j = 0; j < nsize; j++)
		{
			temp[i][j] = res[i][j];
		}
	}
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
		getchar();    //吃换行
		for (int i = 0; i < n; i++)
		{
			gets_s(basic[i]);

		}		
		char temp[1001][1001];		
		for (int i = 0; i < 3001; i++)
		{
			for (int j = 0; j < 3001; j++)
			{
				res[i][j] = ' ';
			}
		}
		int Q;
		cin >> Q;
		getchar();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				res[i][j] = basic[i][j];
				temp[i][j] = basic[i][j];
			}

		}
		int size = n;
		for (int i = 1; i < Q; i++)
		{
			repeat(n, size, temp);
			size = size * n;
		}
		
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << res[i][j];
			}
			cout << endl;
		}

	}
	return 0;
}

