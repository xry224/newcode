#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
class Node
{
public:
	string content;
	int cnt;
	Node()
	{
		cnt = 0;
		content = "";
	}
	bool operator < (const Node &A)const
	{
		if (cnt == A.cnt)
		{
			if (content.length() == A.content.length())
			{
				return content < A.content;
			}
			return content.length() < A.content.length();
		}
		return cnt < A.cnt;
	}
	Node(string con, int num)
	{
		content = con;
		cnt = num;
	}
};
bool isDigit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return true;
	}
	return false;
}
int main()
{
	string str;
	while (cin >> str)
	{
		vector<Node> container;
		string t = "";
		string count = "";
		for (int i = 0; i < str.length(); i++)
		{
			if (isDigit(str[i]))
			{
				int j = i;
				for (j; j < str.length(); j++)
				{
					if (!isDigit(str[j]))
					{
						break;
					}
				}
				count = str.substr(i, j - i + 1);
				int cnt = atoi(count.c_str());
				container.push_back(Node(t, cnt));
				t = "";
				i = j - 1;
				continue;
			}
			t += str[i];
		}
		sort(container.begin(), container.end());
		for (int i = 0; i < container.size(); i++)
		{
			Node t = container[i];
			for (int j = 0; j < t.cnt; j++)
			{
				cout << t.content;
			}
		}
		cout << endl;
	}
	return 0;
}