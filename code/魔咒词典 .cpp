#include<iostream>
#include<string>
#include<map>
using namespace std;
string process(string str)
{
	return str.substr(1, str.length() - 2);
}
int main()
{
	map<string, string> dictionary;
	string content;
	while (getline(cin, content))
	{
		if (content == "@END@")
		{
			break;
		}
		int index = content.find(']');
		string first = content.substr(0, index + 1);
		first = process(first);
		string second = content.substr(index + 2);
		dictionary[first] = second;
	}
	int n;
	cin >> n;
	getline(cin, content);//³Ô»Ø³µ
	for (int i = 0; i < n; i++)
	{
		getline(cin, content);
		if (content[0] == '[')
		{
			content = process(content);
			if (dictionary[content] == "")
			{
				cout << "what?" << endl;
			}
			else
			{
				cout << dictionary[content] << endl;
			}
		}
		else
		{
			map<string, string>::iterator it;
			bool flag = true;
			for (it = dictionary.begin(); it != dictionary.end(); it++)
			{
				if (it->second == content)
				{
					cout << it->first << endl;
					flag = false;
					break;
				}
			}
			if (flag)
			{
				cout << "what?" << endl;
			}
		}
	}
	system("pause");
	return 0;
}