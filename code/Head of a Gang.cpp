#include <iostream>
#include <string>
#include <map>
using namespace std;
#define SIZE 2005
class Node
{
public:
	string name;
	Node *father;
	Node(string n)
	{
		name = n;
		father = NULL;
	}
	Node()
	{
		name = "";
		father = NULL;
	}
}Tree[SIZE];
Node findRoot(Node n)
{
	if (n.father == NULL)
	{
		return n;
	}
	Node t = findRoot(*(n.father));
	*n.father = t;
	return t;
}
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		string a, b;
		int time;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b >> time;

		}
	}

}