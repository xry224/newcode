/*
某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通的城镇。
省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要互相间接通过道路可达即可）。
问最少还需要建设多少条道路？

测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，分别是城镇数目N ( < 1000 )和道路数目M；随后的M行对应M条道路，每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。为简单起见，城镇从1到N编号。
注意:两个城市之间可以有多条道路相通,也就是说
3 3
1 2
1 2
2 1
这种输入也是合法的
当N为0时，输入结束，该用例不被处理


对每个测试用例，在1行里输出最少还需要建设的道路数目。
*/
#include <iostream>
using namespace std;
#define SIZE 1005
int road[SIZE];

int FindRoot(int x)
{
	if (road[x] == -1)
	{
		return x;
	}
	int t = FindRoot(road[x]);
	road[x] = t;
	return t;
}
void Ini()
{
	for (int i = 0; i < SIZE; i++)
	{
		road[i] = -1;
	}
}
int main()
{
	int N, m;
	while (cin >> N)
	{
		if (N == 0)
		{
			break;
		}
		cin >> m;
		Ini();
		while (m-- > 0)
		{
			int a, b;
			cin >> a >> b;
			a = FindRoot(a);
			b = FindRoot(b);
			if (a != b)   //二者之间有通路但两者不在一个集合之中
			{
				road[a] = b;   //将a视为b的子树
			}
		}
		int ans = 0;
		for (int i = 1; i <= N; i++)    //统计联通分量个数
		{
			if (road[i] == -1)
			{
				ans++;
			}
		}
		cout << ans - 1 << endl;
	}
	return 0;
}