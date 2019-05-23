#pragma warning(disable:4996)
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
class Node
{
public:
	int address;
	char value;
	int next;
}words[100005];
int main()
{
	int heada, headb, n;
	while (cin >> heada >> headb >> n)
	{
		for (int i = 0; i < n; i++)
		{
			int head;
			cin >> head;
			cin >> words[head].value >> words[head].next;
			words[head].address = head;
		}
		vector<Node> worda;
		vector<Node> wordb;
		int t = heada;
		while (words[t].next != -1)
		{
			worda.push_back(words[t]);
			t = words[t].next;
		}
		worda.push_back(words[t]);

		t = headb;
		while (words[t].next != -1)
		{
			wordb.push_back(words[t]);
			t = words[t].next;
		}
		wordb.push_back(words[t]);
		int j = wordb.size() - 1;
		int i = worda.size() - 1;
		int ans = -1;
		for (; i >= 0 && j >= 0; i--, j--)
		{
			if (worda[i].value != wordb[j].value)
			{
				break;
			}
			ans = worda[i].address;
		}
		if (ans == -1)
		{
			cout << -1 << endl;
		}
		else
		{
			printf("%05d\n", ans);
		}
	}
	return 0;
}