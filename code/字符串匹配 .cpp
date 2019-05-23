#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Node
{
public:
	string ori;
	string str;
	Node(string a, string b)
	{
		ori = a;
		str = b;
	}
	Node()
	{
		
	}
};
string process(string t)
{
	for (int i = 0; i < t.length(); i++)
	{
		if (t[i] <= 'Z' && t[i] >= 'A')
		{
			t[i] = t[i] - 'A' + 'a';
		}
	}
	return t;
}
int Bracket(string s, string b, int &pos_s, int &pos_b)//对比括号内的内容
{
	int i = pos_b + 1;//指向'['之后的位置，准备开工
	while (b[pos_b] != ']') pos_b++;//找到']'
	pos_b++;//b的指针指向']'之后
	while (i<pos_b - 1)
	{
		if (b[i] == s[pos_s])
		{
			pos_s++;
			return 1;
		}
		i++;
	}
	return 0;
}

bool MatchWith(string s, string b)//判断两个串是否匹配
{
	int ls = s.length(), lb = b.length();
	int pos_s = 0, pos_b = 0;
	for (; pos_s < ls && pos_b < lb;)
	{
		if (b[pos_b] == s[pos_s])
		{
			pos_s++;
			pos_b++;
		}
		else if (b[pos_b] == '[')//准备处理括号
		{
			if (!Bracket(s, b, pos_s, pos_b))
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	if (pos_s == s.length() && pos_b == b.length())
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<Node> data(n);
		for (int i = 0; i < n; i++)
		{
			string t;
			cin >> t;
			string at = process(t);
			data[i] = Node(t, at);
		}
		string mode;
		cin >> mode;
		mode = process(mode);
		for (int i = 0; i < n; i++)
		{
			if (MatchWith(data[i].str, mode))
			{
				cout << i + 1 << " " << data[i].ori << endl;
			}
		}
	}
	return 0;
}