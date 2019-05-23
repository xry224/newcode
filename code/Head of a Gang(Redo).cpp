#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#define SIZE 2005
int Tree[SIZE];
int head[SIZE];			//可能帮派的根节点
int sum[SIZE];			//各个人的总时间
int cnt[SIZE];     //人数总计
int findRoot(int x)
{
	if (Tree[x] == x)
	{
		return x;
	}
	int t = findRoot(Tree[x]);
	Tree[x] = t;
	return t;
};
void Ini()
{
	for (int i = 0; i < SIZE; i++)
	{
		Tree[i] = i;
		sum[i] = 0;
		cnt[i] = 1;
		head[i] = i;
	}
}
string getName(map<string, int> name2id, int value)
{
	map<string, int>::iterator it;
	for (it = name2id.begin(); it != name2id.end(); it++)
	{
		if (it->second == value)
		{
			return it->first;
		}
	}
	return "NO";
}
class Node
{
public:
	string name;
	int weight;
	Node(string name, int w)
	{
		this->name = name;
		weight = w;
	}
	Node()
	{
		name = "";
		weight = 0;
	}
	bool operator < (const Node &A) const
	{
		return name < A.name;
	}
};
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		map<string, int> name2id;
		Ini();
		string a, b;
		int time;
		int headCnt = 0;		//可能帮派总数
		int numCnt = 1;    //字符串转整型
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b >> time;
			//字符串转整型并记录
			if (name2id[a] == 0)
			{
				name2id[a] = numCnt++;
			}
			if (name2id[b] == 0)
			{
				name2id[b] = numCnt++;
			}
			//获取当前两个名称1的整型
			int n1 = name2id[a];
			int n2 = name2id[b];
			//记录每个节点的总时间
			sum[n1] += time;
			sum[n2] += time;
			n1 = findRoot(n1);
			n2 = findRoot(n2);
			if (n1 != n2)
			{
				Tree[n1] = n2;
				cnt[n2] += cnt[n1];
			}
		}
		//Check(name2id);
		int ans = 0;
		for (int i = 1; i <= numCnt; i++)
		{
			if (cnt[i] > 2 && Tree[i] == i) //集合中总人数大于2且该节点是根节点
			{
				head[headCnt++] = i;    //记录下可能帮派的根节点
			}
		}
		Node node[SIZE];
		//遍历所有集合元素数量大于2的集合
		for (int i = 0; i < headCnt; i++)
		{
			int root = head[i];   //某集合的根节点
			int t = 0; //total weight
			int larw = 0;  //最大重量
			int head = 0;  //head
			for (int j = 1; j <= numCnt; j++)
			{
				if (findRoot(j) == root)
				{
					t += sum[j];
					if (sum[j] > larw)
					{
						larw = sum[j];
						head = j;
					}
				}
			}
			//由于每个关系中，双方的sum值都相加了weight，因此全部元素sum求和为集合总权重的两倍
			if (t / 2 > k)   //总关系大于k，是一个帮派
			{
				string name = getName(name2id, head);
				node[ans++] = Node(name, cnt[root]);  //记录下头
			}
		}
		sort(node, node + ans);
		cout << ans << endl;
		for (int i = 0; i < ans; i++)
		{
			cout << node[i].name << " " << node[i].weight << endl;
		}
	}
	return 0;
}