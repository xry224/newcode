#include<iostream>
#include <string>

using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			for (int j = 0; j < s.length() - i - 1; j++)
			{
				if (s[j] > s[j + 1])
				{
					char t = s[j];
					s[j] = s[j + 1];
					s[j + 1] = t;
				}
			}
		}
		cout << s << endl;
	}

}