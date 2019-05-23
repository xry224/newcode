#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	while (cin >> str)
	{
		int countZ = 0;
		int countO = 0;
		int countJ = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == 'Z')
			{
				countZ++;
			}
			else if (str[i] == 'O')
			{
				countO++;
			}
			else if (str[i] == 'J')
			{
				countJ++;
			}
		}
		while (countZ > 0 || countO > 0 || countJ > 0)
		{
			if (countZ > 0)
			{
				cout << 'Z';
				countZ--;
			}
			if (countO > 0)
			{
				cout << 'O';
				countO--;
			}
			if (countJ > 0)
			{
				cout << 'J';
				countJ--;
			}
		}
		cout << endl;
	}
	return 0;
}