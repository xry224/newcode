#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	string content;
	while (getline(cin, str) && str != "#")
	{
		getline(cin, content);
		for (int i = 0; i < str.length(); i++)
		{
			int cnt = 0;
			char cur = str[i];
			for (int j = 0; j < content.size(); j++)
			{
				if (content[j] == cur)
				{
					cnt++;
				}
			}
			cout << cur << " " << cnt << endl;
		}
	}
	return 0;
}